import sys
import pdb

'''
Every number that ends with three follows a very interesting property:

"Any number ending with 3 will always have a multiple that has all 1's".
for eg, for,
       3  : 111
     13  : 111111
and so on.

Now the question is, given a number ending with 3, return this factor, or return the number of 1's in this divisor.

Now as can be seen from the examples given here, this number can be well beyond the range of normal data types like double or long long. Now the approach that immediately comes to mind is to use a user defined data structure like a linked list etc. to store this number. This could be a possible approach but would require tremendous amount of time and space. A very intelligent solution to this question comes by looking at how division works.
'''

last_digit_factors = {0:0, 1:7, 2:4, 3:1, 4:8, 5:5, 6:2, 7:9, 8:6, 9:3 } #for number 3

if __name__ == "__main__":
    in_num = int(sys.argv[1])
    if in_num % 10 != 3:
        print "Wrong Input:", in_num, "input should end with 3"
        sys.exit()
    result = ""
    next_factor = last_digit_factors[1]
    result = str(next_factor)+result
    curr_num = (in_num * next_factor)/10
    #while (not is_num_1s(curr_num)):
    while (True):
        need_factor_for = abs((11 - curr_num)%10)
        next_factor = last_digit_factors[need_factor_for]
        result = str(next_factor)+result
        curr_num = (in_num * next_factor + curr_num)/10
        if curr_num == 0:
            break
    print result
    print long(result)*in_num
