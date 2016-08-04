#coding = utf-8
import string

class senseWord():
    def __init__(self):
        self.list=[]
        try:
            inputfile = open('filtered_word.txt', 'r')
        except:
            print 'fail to open filtered_word.txt'
            exit(-1)
        try:
            for lines in inputfile.readlines():
                self.list.append(lines)
        finally:
            inputfile.close()
        self.list=map(string.strip,self.list)
        for item in self.list:
            print item

    def checkWord(self,word):
        for words in self.list:
           if words in word:
               word = word.replace(words, '**')
        return word

if __name__=='__main__':
    myCheck=senseWord()
    while True:
        word = raw_input('Please input the word:\n')
        if word == ':q':
            break
        print myCheck.checkWord(word)
