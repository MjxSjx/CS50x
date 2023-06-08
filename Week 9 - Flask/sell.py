@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell(): 
    """Sell shares of stock"""
    if request.method == "GET":
        user_id = session["user_id"]
        symbols_user = db.execute("SELECT symbol FROM transactions WHERE user_id = :id GROUP BY symbol HAVING SUM(shares) > 0", id=user_id)
        return render_template("sell.html", symbols = [row["symbol"] for row in symbols_user])

    else:
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not symbol:
            abort(400, "Missing symbol")

        # Look up the stock information
        stock = lookup(symbol.upper())

        if not stock:
            abort(400, "Invalid symbol entry")

        if shares < 1:
            abort(400, "Minimum purchase is 1")

        transaction_value = shares * stock["price"]

        # Get the user's current cash balance from the database
        user_id = session["user_id"]
        try:
            user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        except:
            abort(500, "Database error")

        user_cash = user_cash_db[0]["cash"]

        user_shares = db.execute("SELECT SUM(shares) AS shares FROM transactions WHERE user_id = :id AND symbol = :symbol", id=user_id, symbol=symbol)
        user_shares_real = user_shares[0]["shares"]

        if shares > user_shares_real:
                return apology("You do not own that many")

        uptd_cash = user_cash + transaction_value

        # Update the user's cash balance
        try:
            db.execute("UPDATE users SET cash = ? WHERE id = ?", uptd_cash, user_id)
            date =datetime.datetime.now()
            db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", user_id, stock["symbol"], (-1)*shares, stock["price"], date)
        except:
            abort(500, "Database error")

        flash("Sold!")

        return redirect("/")
