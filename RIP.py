T = int(raw_input())
while(T):
    num = raw_input()
    if int(num)%21 == 0:
        print "The streak is broken!"
    elif num.find("21") is not -1:
        print "The streak is broken!"
    else:
        print "The streak lives still in our heart!"
    T = T - 1
