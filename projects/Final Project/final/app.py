from flask import Flask, render_template, request, redirect, session
from flask_session import Session
from cs50 import SQL
import datetime

from helpers import apology, login_required, lookup, usd
from werkzeug.security import check_password_hash, generate_password_hash

# Configure flask
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///users.db")


@app.route("/")
def index():
    return render_template("index.html")

@app.route("/signup", methods=["GET", "POST"])
def signup():
    if request.method == "GET":
        return render_template("signup.html")
    else:
        username = request.form.get("username")
        email = request.form.get("email")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Check username
        if not username:
            return "Username is required"

        # Check password
        if not password:
            return "Password is required"

        # Check confirmation
        if not confirmation:
            return "Confirmation is required"
        elif password != confirmation:
            return "Password don`t match"

        # Storing a hash of the new user password
        hash = generate_password_hash(password)
        try:
            new = db.execute("INSERT INTO users (username, hash) VALUES (?, ?);", username, hash)
        except:
            return "Username already exists"

        session["user_id"] = new

        return redirect("/")



@app.route("/login", methods=["GET", "POST"])
def login():
    # Forget any user_id
    session.clear()

    # User reaced route via POST
    if request.method == "POST":
        # Ensure email was submitted
        if not request.form.get("email"):
            return "must provide email"
        # Ensure password was submitted
        elif not request.form.get("password"):
            return "must provide password"
        # Query database for email
        rows = db.execute("SELECT * FROM users WHERE email = ?;", request.form.get("email"))
        # Ensure email exists and password is correct
        if len(rows) != 1 or not check_password_hash(row[0]["hash"], request.form.get("password")):
            return "invalid username and/or password"
        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        # Redirect user to home page
        return redirect("/")
    # Use reached route via GET
    else:
        return render_template("login.html")


@app.route("/logout")
@login_required
def logout():
    # Forget any user_id
    session.clear()
    # Redirect user to home page
    return redirect("/")

@app.route("/restorepass")
def restorepass():
    return render_template("restorepass.html")

@app.route("/profile")
@login_required
def profile():
    return render_template("profile.html")

@app.route("/post")
def post():
    return render_template("post.html")

@app.route("/bootcamp")
def bootcamp():
    return render_template("bootcamp.html")

@app.route("/framework")
def freamework():
    return render_template("framework.html")

@app.route("/learn")
def learn():
    return render_template("learn.html")

@app.route("/works")
def works():
    return render_template("works.html")

@app.route("/search")
def search():
    return render_template("search.html")

@app.route("/text")
def text():
    return render_template("text.html")

@app.route("/aboutme")
def aboutme():
    return render_template("aboutme.html")