#using utf-8
from flask import Flask, url_for, render_template, redirect, request, flash
from flask_sqlalchemy import SQLAlchemy
from config import Config

app = Flask(__name__)
app.config.from_object('config.Config')
db = SQLAlchemy(app)

from models import MessBoard

@app.route('/', methods = ['POST', 'GET'])
def index():
    if request.method == 'POST':
        name = request.form['name']
        email = request.form['email']
        content = request.form['content']
        title = request.form['title']
        mess = MessBoard(name = name, email = email, content = content, title = title)
        db.session.add(mess)
        db.session.commit()
        flash("Add Message Sucess!!")
        return redirect(url_for('index'))
    else:
        mess = MessBoard.query.all()
        return render_template("index.html", message = mess)

@app.route('/show/<int:id>')
def show(id):
    mess = MessBoard.query.filter_by(id = id).first()
    if mess != None:
        return render_template('show.html', message = mess)
    else:
        return redirect(url_for('index'))
