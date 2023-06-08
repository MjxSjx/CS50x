@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        # Show registration form for GET requests
        return render_template("register.html")

    # Handle POST requests
    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    # Check for input errors
    if not username:
        return apology("Please provide username", 403)
    elif not password or not confirmation:
        return apology("Please provide password", 403)
    elif password != confirmation:
        return apology("Your passwords do not match", 403)

    # Generate password hash and insert user
    hash = generate_password_hash(password)
    try:
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
    except ValueError:
        return apology("The username already exists", 403)

    # Set session id and redirect to quotes page
    session["user_id"] = db.execute("SELECT id FROM users WHERE username = ?", username)
    return redirect("/quote")
