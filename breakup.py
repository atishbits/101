#https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/breakup-app/

import sys
if __name__ == "__main__":
    N = int(raw_input())
    num_dict = {}
    for i in range(1, 31):
        num_dict[str(i)] = 0
    while(N):
        string = raw_input()
        is_girl = False
        strs = string.split(':', 1)
        if strs[0] == 'G':
            is_girl = True
        arr  = strs[1].split(' ')
        for elem in arr:
            if elem in num_dict:
                if is_girl:
                    num_dict[elem] = num_dict[elem] + 2
                else:
                    num_dict[elem] = num_dict[elem] + 1
        N = N - 1
    #brute force 2-pass over the num_dict to check if multple dates have max wt
    max_wt = 0
    max_dt = 0
    for date in num_dict:
        count = num_dict[date]
        if count > max_wt:
            max_dt =  date
            max_wt = count
    for date in num_dict:
        count = num_dict[date]
        if count == max_wt:
            if date != max_dt:
                print "No Date"
                sys.exit(0)
    if max_dt == '19' or max_dt == '20':
        print "Date"
    else:
        print "No Date"
        
