#coding=utf-8
import urllib2
from bs4 import BeautifulSoup
import re, os

class get_pic:

    def __init__(self, url):
        self.url = url

    def ready(self):
        page = urllib2.urlopen(self.url)
        soup = BeautifulSoup(page)
        return soup

    def GetPic(self):
        soup = self.ready()
        target = soup.findAll('img')
        imgList = []
        str_flag = "杉本有美吧"
        for _item in target:
            temp = _item.get('bdwater')
            if temp is None:
                continue
            if str_flag in temp.encode('utf8'):
                imgList.append(_item)
        cwd = os.getcwd()
        os.chdir("./Picture")
        i = 0
        for item in imgList:
            temp = urllib2.urlopen(item['src']).read()
            try:
                p = open( str(i) +'.jpg', 'wb')
            except:
                print 'fail to create ' + str(i) + '.jpg'
                exit(-1)
            try:
                p.write(temp)
            finally:
                p.close()
            i += 1
        os.chdir(cwd)

def main():
    exam = get_pic('http://tieba.baidu.com/p/2166231880')
    exam.GetPic()

if __name__ == '__main__':
    main()
