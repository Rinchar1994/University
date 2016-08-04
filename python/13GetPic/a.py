#coding=utf-8
import urllib2
from bs4 import BeautifulSoup
import re, os

class get_pic:

    def __init__(self, url):
        self.url = url

    def GetPic(self):
        page = urllib2.urlopen(self.url).read()
        pattern = re.compile(r'src="(.+?\.jpg)"\s.*?bdwater')
        test = re.findall(pattern, page)
        print len(test)
        p = re.compile(u'[\u4e00-\u9fa5]{5}')
        a = p.findall(page.decode('utf-8'))
        for item in a:
            print item.encode('utf-8')

def main():
    exam = get_pic('http://tieba.baidu.com/p/2166231880')
    exam.GetPic()

if __name__ == '__main__':
    main()
