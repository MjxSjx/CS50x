@app.route("/buy", methods=["GET", "POST"]) 
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")

    else:
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not symbol:
            abort(400, "Missing symbol")

        stock = lookup(symbol.upper())

        if not stock:
            abort(400, "Invalid symbol entry")

        if shares < 1:
            abort(400, "Minimum purchase is 1")

        transaction_value = shares * stock["price"]

        user_id = session["user_id"]
        try:
            user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        except:
            abort(500, "Database error")

        user_cash = user_cash_db[0]["cash"]

        if user_cash < transaction_value:
            abort(403, "Not enough money")

        uptd_cash = user_cash - transaction_value

        try:
            db.execute("UPDATE users SET cash = ? WHERE id = ?", uptd_cash, user_id)
            date =datetime.datetime.now()
            db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", user_id, stock["symbol"], shares, stock["price"], date)
        except:
            abort(500, "Database error")

        flash("Purchased!")
        return redirect("/")
