import pdb
if __name__ == "__main__":
    while(True):
        instring = raw_input()
        if instring == "\n" or "":
            break
        inarr = instring.split(" ")
        revline = ""
        for elem in inarr:
            elem1 = elem.replace("\n", "")
            revline = elem1 + " " + revline
        print revline
