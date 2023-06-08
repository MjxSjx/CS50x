@app.route("/history") 
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transaction_db = db.execute("SELECT * FROM transactions WHERE user_id = :id", id=user_id)
    return render_template("history.html",  transaction = transaction_db)
