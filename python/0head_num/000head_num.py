from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import sys

def hp_num(file_path, num = 1):
    hp = Image.open(file_path)
    hp_draw = ImageDraw.Draw(hp)
    font_size = hp.size[0] / 20
    hp_ft = ImageFont.truetype("TIMES.TTF", font_size)
    num_str = str(num) + ' '
    pos_x = hp.size[0] - hp_ft.getsize(num_str)[0] - font_size
    pos_y = font_size
    hp_draw.text((pos_x, pos_y), num_str, fill = 'red', font = hp_ft)
    return hp

def main():
    hp_num("head_portrait.jpg", 130).show()

if __name__ == "__main__":
    main()
