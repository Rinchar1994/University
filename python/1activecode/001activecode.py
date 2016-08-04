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

result = activecode(10)
for i in range(10):
    print result[i]
