# -*- coding: utf-8 -*-
import redis
import uuid

def activecode(num = 200):
    code = []
    while True:
        tempcode = str(uuid.uuid1()).replace('-', '')
        if tempcode not in code:
            code.append(tempcode)
        if len(code) is num:
            break
    return code

r = redis.Redis(host = '127.0.0.1', port = 6379, db = 1)

temp = activecode(200)
for item in temp:
    r.sadd('activecode', item)

print r.smembers('activecode')
