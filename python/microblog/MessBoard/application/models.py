from app import db
from datetime import datetime

class MessBoard(db.Model):

    __tablename__ = "message"
    __table_args__ = {"useexisting":True}
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(200))
    time = db.Column(db.DateTime, default = datetime.now())
    email = db.Column(db.String(100))
    title = db.Column(db.String(255))


    def __init__(self, name, content, email, title):
        self.name = name
        self.content = content
        self.email = email
        self.title = title

    def __repr__(self):
        return "<User:%s>" %self.name

if __name__ == '__main__':
    db.create_all()
