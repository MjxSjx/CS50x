# Week 9 – Flask
Algorithm: A step-by-step set of instructions for solving a problem

### Introduction 
The reality is web development (websites and applications) is the largest sector of coding, right now.

## Flask (is a framework a 3rd party library)
We will be controlling a server and how it behaves in response to user’s requests. URLs use key value pairs
	
Example.com/route?key=value&key=value

Here I’m searching for two things with the & being the visual divider in the URL. Reading the URL can be part of understanding what the user is looking for.
This week will be Python and we will be combining it with SQLite, HTML, CSS, JS and a new framework called Jinja.
Starting today we will be using flask run in the terminal in Python using the flask framework. 

At bare minimum you would need 1 file and a folder:
*	app.py
*	templates/ aka HTML files

### Uses a single route app.py
```
from flask import Flask, render_template, request

app = Flask(__name__)  # transform name into a flask item
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
    return render_template("index.html")
```
## Forms
	
### Templates
Depending on the framework you are using. There’s syntax to cut the amount of duplication you have in all your HTML coding files. Meaning when you have a website that has multiple pages (as most all do) you can use frameworks syntax to copy the bulk of the HTML that is identical to other HTML pages, shrinking the amount of typing needed, cleaning the pages, and allowing us to focus on only the important lines.

This is an HTML file while using the framework Jinja saving space, time, and efficiency 
```
{% extends "layout.html %}
 
 {% block body%}

    hello, {{name}}

{% endblock %}
```
This is generic HTML code broken down into smaller code

## Request Methods
When GET is used to get user data info. That data is visible in the URL, which is a problem when shopping or using passwords. 
	
The solution is POST, which hides the info deeper in the data. Using POST stops private info from ever being visible in the URL. 
`@app.route("/", methods=["GET", "POST"])`
 Allowing the route to accept requests methods that are GET or POST
	
 Last nugget, when you go back on a website and receive an alert stating “ confirm Form Resubmission.” What’s really happened is you submitted a POST which is means you added something to the database and will get lost if you leave the page. Also, it could because your sent data is hidden and unretrievable thus meaning you must enter it again.
*	GET: receive data
*	POST: send data

## Frosh IMs
```
from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():

    # Forget registrant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():

    # Validate submission
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html")

    # Remember registrant
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    # Confirm registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants) 
```
Must use server-side validation

### SQLite and Python
Using HTML files, an SQLite .db all run with Python to store users that are registering for IM sports. 

## Cookies and Sessions
When you first log in successfully to a website a “cookie” is planted on your computer. Metaphorically its akin to a handstamp. So, if you log back in to that website, you have a cookie from the page and as such, your browser is showing that handstamp to that website. Saying, I’ve been here before and this is all my settings and info.
`Set-Cookie: session=value # the actual line of code`
* session is a term that means maintenance of information across HTTP

All that’s required for logging in and logging out of a website.
```
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    if not session.get("name"):                     # if no name return to log in
        return redirect("/login")
    return render_template("index.html")

@app.route("/login", methods=["GET", "POST"]) # if the user logs in via GET/ POST
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")
@app.route("/logout") # if logout change to none
def logout():
    session["name"] = None
    return redirect("/")
```
Cookies are how you are identified and kept track of when shopping and the like.

### Shopping Cart
Bookstore
```
from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///store.db")

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)

@app.route("/cart", methods=["GET", "POST"])
def cart():

    # Ensure cart exists
    if "cart" not in session:
        session["cart"] = []

    # POST
    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")
    # GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)
```
## APIs (Application Programming Interfaces)
API just specifies how you interact with some service. Nowadays there’s a lot of web-based services that you can use to get back data, like weather or current time or a database of amazon books, all might have API’s all web based that allow you, using URLs or some other tech to just get data from someone else as though it’s a function you’re calling remotely.
	
HTTP is very often the mechanism used to get data from servers. The way the data can come back is as follows.

### This is based off the SQL week and the database of tv shows. 
```
from cs50 import SQL
from flask import Flask, jsonify, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///shows.db")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return jsonify(shows)
```



## AJAX
AJAX: Asynchronous, JavaScript, and XML. AJAX is a technique whereby you don’t have to submit forms anymore to get more data from the server. You can use JS, per last week, and listen for an event like a key press. You can secretly in JS code send a request to the server to get back more data, and then plug it into the DOM, this makes things more seamless. The example here is an auto-complete search. Where you type in O and many listings start to form and guess you’re completed word.

## JSON (JavaScript Object Notation)
JSON: A generic format file of data. It is a very standard super popular format that’s just text, that uses:
*	[] square brackets for lists, a.k.a. arrays. 
*	{} curly braces for key value pairs a.k.a. objects
JSON is just the better way in general, the more generic, ,multipurpose, user agnostic, language agnostic way of returning data from a server because it’s just text. The coding language doesn’t matter, ALL can process JSON. 

There is always a solution to coding problems
