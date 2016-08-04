from flask import Flask, url_for, render_template, redirect, request, flash
from flask_sqlalchemy import SQLAlchemy
from config import Config

app = Flask(__name__)
app.config.from_object('config.Config')
db = SQLAlchemy(app)

from models import TodoList

@app.route('/', methods = ['POST', 'GET'])
def index():
    if request.method == 'POST':
        task = request.form['task']
        todo = TodoList(task = task)
        db.session.add(todo)
        db.session.commit()
        flash("Add Task Sucess!")
        print 'good boy'
        return redirect(url_for('index'))
    else:
        todo = TodoList.query.all()
        print 'bad boy'
        return render_template("index.html", todo = todo)

@app.route('/delete/<int:id>')
def delete(id):
    task = TodoList.query.filter_by(id = id).first()
    if task != None:
        db.session.delete(task)
        db.session.commit()
        flash("Delete Task Sucess!")
        return redirect(url_for('index'))
    else:
        flash("Delete Task Fail!")
        return redirect(url_for('index'))

