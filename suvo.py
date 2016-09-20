'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
def countOccurances(string):
    pat1 = "SUVO"
    pat2 = "SUVOJIT"
    i = 0
    suvo = 0
    suvojit = 0
    for elem in string:
        if elem == pat2[i]:
            i +=1 
            if i == len(pat2):
                suvojit += 1
                i = 0
        else:
            if i >= 4:
                suvo += 1
            i = 0
            if elem == pat2[i]:
                i += 1
    if i >= 4:
        suvo += 1
    return suvo, suvojit

if __name__ == "__main__":
    T = int(raw_input())
    while(T):
        string = raw_input()
        suvo, suvojit = countOccurances(string)
        print "SUVO = " + str(suvo) + ", SUVOJIT = " + str(suvojit)
        T = T-1

