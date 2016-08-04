def simple_decorator(f):
    def wrapper():
        print "entering function"
        f()
        print "exited function"

    return wrapper

@simple_decorator
def hello():
    print "hello world"

hello()
