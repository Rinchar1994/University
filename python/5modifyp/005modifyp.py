import Image
import os
import glob

class modifyp:

    def __init__(self, picpath):
        self.picpath = picpath

    def pic_find(self, path):
        target = []
        for im in glob.glob(path + "/*.jpg"):
            pic_path, pic_name = os.path.split(im)
            target.append(pic_name)
        return target

    def pic_info(self, img):
        w, h = img.size
        if w > h:
            return w, h, 0
        else:
            return w, h, 1

    def comp_num(self, x, y):
        x = float(x)
        y = float(y)
        return float(x/y)

    def resize_pic(self, pic_name, pic_w, pic_h):
        img = Image.open(pic_name)
        w, h, isVertical = self.pic_info(img)
        if isVertical:
            pic_w, pic_h = pic_h, pic_w
        if self.comp_num(pic_w, pic_h) > self.comp_num(w, h):
            pic_w = int(self.comp_num(w, h) * float(pic_h))
        else:
            pic_h = int(float(h) * float(pic_w) / float(w))
        target = img.resize((int(pic_w), int(pic_h)), Image.ANTIALIAS)
        return target

    def modify_many(self, pic_w, pic_h):
        imglist = self.pic_find(self.picpath)
        for img in imglist:
            imgfile = self.picpath + "/" + img
            cwd = os.getcwd()
            os.chdir(self.picpath)
            temp = self.resize_pic(img, pic_w, pic_h)
            temp.save(self.picpath + "/" + img + '_duplicate', 'jpeg')
            os.chdir(cwd)

def main():
    picpath = "/home/rinchar1994/Documents/Python/0head_num"
    resizer = modifyp(picpath)
    resizer.modify_many(300, 320)

if __name__ == "__main__":
    main()


