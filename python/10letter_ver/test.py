import string, random
from PIL import Image, ImageDraw, ImageFont

class letter_ver:

    def random_let(self):
        letters = ''
        for i in range(4):
            letters += random.choice(string.ascii_letters)
        return letters

    def gene_ver(self):
        w, h = 120, 30
        im = Image.new('RGB', (w, h), (255, 255, 255))
        font = ImageFont.truetype("TIMES.TTF", 25)
        draw = ImageDraw.Draw(im)
        letters = self.random_let()
        font_w, font_h = font.getsize(letters)
        for item in range(4):
            draw.text(((w - font_w) / 5 + item * w / 5, (h - font_h) / 2), letters[item], font = font, fill = (255, 0, 0))
        for w in range(120):
            for h in range(30):
                tmp = random.randint(0, 50)
                if tmp > 50 - 2:
                    draw.point((w, h), fill = (0, 0, 0))
        im.save('letter_ver.jpg')

def main():
    exa = letter_ver()
    exa.gene_ver()

if __name__ == '__main__':
    main()
