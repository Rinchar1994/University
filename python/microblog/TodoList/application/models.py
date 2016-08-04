from app import db
from datetime import datetime

class TodoList(db.Model):
    __tablename__ = "TodoList"
    __table_args__ = {"useexisting":True}
    id = db.Column(db.Integer, primary_key = True)
    task = db.Column(db.String(255), nullable = False)
    time = db.Column(db.DateTime, default = datetime.now())

    #def __init__(self, task):
    #    self.task = task

    #def __repr__(self):
    #    return "<Task:%s>" %self.task


if __name__ == '__main__':
    db.create_all()
