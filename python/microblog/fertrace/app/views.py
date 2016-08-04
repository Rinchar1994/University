#coding: utf-8
from flask import Flask, url_for, render_template, redirect, request, flash
from flask_sqlalchemy import SQLAlchemy
from werkzeug import secure_filename
import os

app = Flask(__name__)
app.config.from_object('config.default')
db = SQLAlchemy(app)

VAR_ROLE = 0
USRNAME = 'rinchar'

from models import Planter, Seed, Fertilizer, Pestcide, Storage, Transport, Seller, Product, Admin

def allowed_file(filename):
    return '.' in filename and filename.rsplit('.', 1)[1] in app.config['ALLOWED_EXTENSIONS']

def upload(file):
    File = secure_filename(file.filename)
    filepath = os.path.join(app.config['UPLOAD_FOLDER'], File)
    file.save(filepath)
    return filepath


@app.route('/', methods = ['POST', 'GET'])
def index():
    return render_template("index.html")

@app.route('/login', methods = ['POST', 'GET'])
def login():
    if request.method == 'POST':
        #为了修正request得到的中文乱码的错误
        if request.form.get('login', None) is not None:
            if not request.form['username']:
                flash("Username is empty!")
                return redirect(url_for('login'))
            elif not request.form['password']:
                flash("Password is empty!")
                return redirect(url_for('login'))
            else:
                username = request.form['username']
                password = request.form['password']
                temp = Admin.query.filter_by(username = username, password = password).first()
                if temp is not None:
                    return render_template('background.html', username = username, role = temp.role)
                else:
                    flash("Your account is wrong!")
                    return redirect(url_for('login'))
        #elif request.form.get('register', None) is not None:
            #role = request.form['obj']
            #return render_template('register.html', role = role)
    else:
        return render_template('login.html')

@app.route('/register', methods = ['POST', 'GET'])
def register():
    global VAR_ROLE
    if request.method == 'POST':
        if request.form.get('register', None) is not None:
            VAR_ROLE = request.form['obj']
            return render_template('register.html', get_role = VAR_ROLE)
        if VAR_ROLE == '1' and request.form['username'] and request.form['password'] and request.form['realname'] and request.files['pos']:
            files = request.files['pos']
            username = request.form['username']
            password = request.form['password']
            admin = Admin.query.filter_by(username = username).first()
            if admin == None and allowed_file(files.filename):
                admin = Admin(username = username, password = password, role = VAR_ROLE)
                planter = Planter(name = request.form['realname'], pos = upload(files))
                db.session.add(admin)
                db.session.add(planter)
                db.session.commit()
                flash('Register Sucess!')
                return render_template('background.html', username = username, role = VAR_ROLE)
            elif admin != None:
                flash('Admin is already existed!')
            else:
                flash('Format of file uploaded is wrong!')
        elif request.form['username'] and request.form['password'] and request.form['realname']:
            username = request.form['username']
            password = request.form['password']
            admin = Admin.query.filter_by(username = username).first()
            if admin != None:
                flash('Admin is already existed!')
                return redirect(url_for('register'))
            admin = Admin(username = username, password = password, role = VAR_ROLE)
            if VAR_ROLE == '2':
                storage = Storage(name = request.form['realname'])
                db.session.add(storage)
            elif VAR_ROLE == '3':
                transport = Transport(name = request.form['realname'])
                db.session.add(transport)
            elif VAR_ROLE == '4':
                seller = Seller(name = request.form['realname'])
                db.session.add(seller)
            db.session.add(admin)
            db.session.commit()
            flash('Register Sucess!')
            return render_template('background.html', username = username, role = VAR_ROLE)
        return redirect(url_for('register'))
    elif request.method == 'GET':
        return render_template('register.html', get_role = VAR_ROLE)

@app.route('/background', methods = ['POST', 'GET'])
def background():
    global VAR_ROLE
    global USRNAME
    return render_template('background.html', username = USRNAME, role = VAR_ROLE)

@app.route('/information/<user>', methods = ['POST', 'GET'])
def information(user):
    admin = Admin.query.filter_by(username = user).first()
    return render_template('information.html', username = user)

@app.route('/welcome', methods = ['POST', 'GET'])
def welcome():
    return render_template('welcome.html')
