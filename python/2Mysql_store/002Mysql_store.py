# -*- coding: utf-8 -*-
import MySQLdb
import uuid

def activecode(num = 200):
    code = []
    i = 0
    while True:
        tempcode = str(uuid.uuid1()).replace('-', '')
        if tempcode not in code:
            code.append((i, tempcode))
            i = i + 1
        if len(code) is num:
            break
    return code

conn = MySQLdb.connect(host = 'localhost', user = 'root', passwd = '', db = 'python_activecode')
cursor = conn.cursor()

sql = "drop table if exists activecode"
cursor.execute(sql)

sql = "create table activecode(num int(10) primary key, code varchar(128))"
cursor.execute(sql)

sql = "insert into activecode(num, code) values(%s,%s)"
param = activecode()
n = cursor.executemany(sql,param)
print 'insert',n

n = cursor.execute("select * from activecode")
for row in cursor.fetchall():
    print row

cursor.close()

#提交
conn.commit()
#关闭
conn.close()
