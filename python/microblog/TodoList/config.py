class Config(object):
    DEBUG = True
    SQLALCHEMY_DATABASE_URI = "mysql://root:@localhost:3306/TodoList"
    SECRET_KEY = 'Now you see me!'
    SQLALCHEMY_TRACK_MODIFICATIONS = True
