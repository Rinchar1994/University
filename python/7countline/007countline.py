import glob
import os

class countline:

    def __init__(self, filepath):
        self.filepath = filepath

    def findallcode(self, path):
        target = []
        for item_py in glob.glob(path + '/*.py'):
            codepath, codename = os.path.split(item_py)
            target.append(codename)
        return target

    def line_counter(self, codename):
        line_all = 0
        line_code = 0
        line_blank = 0
        line_note = 0
        try:
            f = open(codename)
        except:
            print 'fail to open code file'
            exit(-1)
        try:
            lines = f.readlines()
            note_flag = 0 #note is #
            for line in lines:
                line = line.strip()
                line_all += 1
                if note_flag:
                    line_note += 1
                    if len(line) > 3 and line[(len(line)-3):(len(line))] is '\'\'\'':
                        note_flag = 0
                    continue
                elif len(line) == 0:
                    line_blank += 1
                    continue
                elif line[0] is '#':
                    line_note += 1
                    continue
                elif len(line) > 3 and line[0:3] is '\'\'\'':
                    line_note +=1
                    note_flag = 1
                    if line[(len(line)-3):(len(line))] is '\'\'\'':
                        note_flag = 0
                else:
                    line_code += 1
        finally:
            f.close()
        return line_all, line_code, line_note, line_blank

    def counter(self):
        cwd = os.getcwd()
        os.chdir(self.filepath)
        codename = self.findallcode(self.filepath)
        _all_, _code_, _note_, _blank_ = 0, 0, 0, 0
        for item in codename:
            _all, _code, _note, _blank = self.line_counter(item)
            _all_ += _all
            _code_ += _code
            _note_ += _note
            _blank_ += _blank
        print '_all: ', _all_
        print '_code: ', _code_
        print '_note: ', _note_
        print '_blank: ', _blank_
        os.chdir(cwd)


def main():
    example = countline("/home/rinchar1994/Documents/Python/7countline/code")
    example.counter()

if __name__ == '__main__':
    main()
