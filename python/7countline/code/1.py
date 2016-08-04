#encoding=utf-8
 
import ctypes
import os
 
kernel=ctypes.windll.kernel32
 
class CmdColor(object):
    '''
改变CMD输出环境的颜色
示例：
初始化时指定颜色：a=CmdColor(5,0xf,0,0xf)    ------屏幕背景色为紫色，前景色（即默认字符颜色）为白色，输出前景色为白色，输出背景色为白色
初始化之后改变颜色：a.set_screen(bg_s=0,fg_s=0xf) -----改变屏幕颜色
                    a.set_text_color(bg_t=0,fg_s=0xf)   ------改变文本显示颜色
 
    '''
    def __init__(self,bg_s=0,fg_s=0xf,bg_t=0,fg_t=0xf):
        self.bg_s=bg_s
        self.fg_s=fg_s
        self.bg_t=bg_t
        self.fg_t=fg_t
        self.set_screen_color(bg_s=self.bg_s,fg_s=self.fg_s)
        self.set_text_color(bg_t=self.bg_t,fg_t=self.fg_t)
    def hex_to_str(self,int_num):
        return hex(int_num).strip('0x')
    def set_screen_color(self,bg_s=0x0,fg_s=0xf):
        os.system('color %s%s'%(self.hex_to_str(bg_s),self.hex_to_str(fg_s)))
    def set_text_color(self,bg_t=0,fg_t=0xf):
        hnd=kernel.GetStdHandle(-11)
        print hnd
        kernel.SetConsoleTextAttribute(hnd,bg_t*16+fg_t)
if __name__=='__main__':        
    a=CmdColor(5,15,0,0xf)
    #a.set_screen_color(5,0xb)
    #a.set_text_color(3,0xf)
    print 'hello'
