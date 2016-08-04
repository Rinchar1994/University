#coding = utf-8
import urllib2, os
from bs4 import BeautifulSoup

class html_func:

    def __init__(self, url):
        self.url = url

    def ready(self):
        page = urllib2.urlopen(self.url)
        soup = BeautifulSoup(page)
        return soup

    def get_text(self):
        soup = self.ready()
        try:
            f = open('htmltext.txt', 'w')
        except:
            print 'fail to open htmltext'
            exit(-1)
        try:
            f.write(soup.body.text.encode('utf8'))
        except:
            print 'fail to write htmltext'
            exit(-1)
        finally:
            f.close()

    def get_link(self):
        soup = self.ready()
        try:
            f = open('htmllink.txt', 'w')
        except:
            print 'fail to open htmllink'
            exit(-1)
        try:
            links = soup.findAll('link')
            temp = 'href of Tag link:\n'
            for link in links:
                temp += link['href'] + '\n'
            temp += '\n\n\n\n\nhref of Tag a:\n'
            a = soup.findAll('a')
            for item in a:
                temp += item['href'] + '\n'
            f.write(temp)
        except:
            print type(links[0])
            print 'fail to write htmllink'
            exit(-1)
        finally:
            f.close()

def main():
    #url = raw_input('Please input the url: ')
    url = 'http://github.com'
    example = html_func(url)
    #example.get_text()
    example.get_link()

if __name__ == '__main__':
    main()
