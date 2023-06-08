@app.route("/")
@login_required
def index():
    """Show portfolio of stocks""" 
    user_id = session["user_id"]

    transactions_db = db.execute("SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = cash_db[0]["cash"]

    #show index page
    return render_template("index.html", database = transactions_db, cash = cash)
