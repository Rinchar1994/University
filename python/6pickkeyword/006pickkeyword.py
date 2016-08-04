import glob
import os
import re
from collections import Counter

class pickkeyword:

    def __init__(self, filepath):
        self.filepath = filepath

    def findalltxt(self, path):
        target = []
        for item in glob.glob(path + "/*.txt"):
            txtpath, txtname = os.path.split(item)
            target.append(txtname)
        return target

    def setstopword(self, path):
        try:
            f = open(path)
        except:
            print 'fail to open file'
            exit(-1)
        try:
            word = f.read().split('\n')
        finally:
            f.close()
        return word

    def count_word(self, txtname):
        #pattern = r'([\w]+)|([\w]+(\'|\-)*[\w]+)'
        #pattern = r'[\w]+'
        pattern = r'[A-Za-z]+'
        for item in self.findalltxt(self.filepath):
            try:
                f = open(item)
            except:
                print 'fail to open file'
                exit(-1)
            try:
                p = re.compile(pattern)
                r = p.findall(f.read().lower())
            finally:
                f.close()
        return Counter(r)

    def count_all(self):
        cwd = os.getcwd()
        os.chdir(self.filepath)
        total_count = Counter()
        txtname = self.findalltxt(self.filepath)
        for item in txtname:
            total_count += self.count_word(item)
        print total_count
        print len(total_count)
        stopword = self.setstopword("/home/rinchar1994/Documents/Python/6pickkeyword/stopword.txt")
        for i in stopword:
            total_count[i] = 0
        print total_count.most_common()[0][0]
        os.chdir(cwd)


def main():
    example = pickkeyword("/home/rinchar1994/Documents/Python/6pickkeyword/diary")
    example.count_all()

if __name__ == '__main__':
    main()
