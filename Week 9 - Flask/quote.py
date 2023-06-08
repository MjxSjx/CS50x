@app.route("/quote", methods=["GET", "POST"])
@login_required 
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")

    else:
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("Missing symbol", 403)
        # use helpers.py look fn
        stock = lookup(symbol.upper())

        if not stock:
            return apology("Invalid symbol entry", 403)
        # if info found render
        return render_template("quoted.html", stock=stock)
