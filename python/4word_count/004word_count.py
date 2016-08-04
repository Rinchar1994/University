def word_count(fpath):
    fopen = open(fpath)
    fstr = fopen.read()
    for i in fstr:
        if not ((i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z') or i == ' '):
            fstr = fstr.replace(i, ' ')
    fresult = fstr.split()
    fopen.close()
    #return len(fresult)
    return fresult

fpath = raw_input("Please input the file path:\n")
#print word_count(fpath)
final = word_count(fpath)
for item in final:
    print item
