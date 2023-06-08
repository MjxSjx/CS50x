@app.route("/add_funds", methods=["GET", "POST"])
@login_required
def add_funds():
    """User add funds"""
    if request.method == "GET":
        return render_template("add.html")
    else:
        new_funds = int(request.form.get("new_funds"))

        if not new_funds:
            return apology("New funds only")

        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cash_db[0]["cash"]


        uptd_cash = user_cash + new_funds

        # Update the user's cash balance
        db.execute("UPDATE users SET cash = ? WHERE id = ?", uptd_cash, user_id)

        flash("Funds added!")
        return redirect("/")
