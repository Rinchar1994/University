from views import db
from datetime import datetime

class Planter(db.Model):
    __tablename__ = 'Planter'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(15))
    pos = db.Column(db.String(63))

class Seed(db.Model):
    __tablename__ = 'Seed'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    breed = db.Column(db.String(31))
    producer = db.Column(db.String(31))
    market_time = db.Column(db.DateTime)
    valid_date = db.Column(db.DateTime)
    transgenosis = db.Column(db.Boolean)
    product_id = db.Column(db.Integer, db.ForeignKey('Product.id'))

class Fertilizer(db.Model):
    __tablename__ = 'Fertilizer'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(31))
    producer = db.Column(db.String(31))
    effect = db.Column(db.String(255))
    element = db.Column(db.String(255))
    produce_date = db.Column(db.DateTime)
    valid_date = db.Column(db.DateTime)
    usage_date = db.Column(db.DateTime)
    usage_method = db.Column(db.String(127))
    usage_amount = db.Column(db.String(15))
    produc_id = db.Column(db.Integer, db.ForeignKey('Product.id'))

class Pestcide(db.Model):
    __tablename__ = 'Pestcide'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(31))
    producer = db.Column(db.String(31))
    effect = db.Column(db.String(255))
    element = db.Column(db.String(255))
    produce_date = db.Column(db.DateTime)
    valid_date = db.Column(db.DateTime)
    usage_date = db.Column(db.DateTime)
    usage_method = db.Column(db.String(127))
    usage_amount = db.Column(db.String(15))
    produc_id = db.Column(db.Integer, db.ForeignKey('Product.id'))

class Storage(db.Model):
    __tablename__ = 'Storage'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(15))

class Transport(db.Model):
    __tablename__ = 'Transport'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(15))

class Seller(db.Model):
    __tablename__ = 'Seller'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(15))

class Product(db.Model):
    __tablename__ = 'Product'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    breed = db.Column(db.String(31))
    brand = db.Column(db.String(31))
    vert = db.Column(db.Boolean)
    plow_date = db.Column(db.DateTime)
    machine = db.Column(db.String(31))
    seed_date = db.Column(db.DateTime)
    seed_weather = db.Column(db.String(15))
    grow_method = db.Column(db.String(255))
    grow_time = db.Column(db.DateTime)
    trans_date = db.Column(db.DateTime)
    water_method = db.Column(db.String(63))
    water_date = db.Column(db.DateTime)
    gather_method = db.Column(db.String(63))
    gather_date = db.Column(db.DateTime)
    pack_method = db.Column(db.String(63))
    pack_date = db.Column(db.DateTime)
    planter_id = db.Column(db.Integer, db.ForeignKey('Planter.id'))
    storage_id = db.Column(db.Integer, db.ForeignKey('Storage.id'))
    transport_id = db.Column(db.Integer, db.ForeignKey('Transport.id'))
    seller_id = db.Column(db.Integer, db.ForeignKey('Seller.id'))
    attachment = db.Column(db.String(31))

class Admin(db.Model):
    __tablename__ = 'Admin'
    __table_args__ = {'useexisting':True}
    id = db.Column(db.Integer, primary_key = True)
    username = db.Column(db.String(63))
    password = db.Column(db.String(63))
    role = db.Column(db.Integer)

if __name__ == '__main__':
    db.create_all()
