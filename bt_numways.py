#Let us say that you are given a number N, you've to find the number of different ways to write it as the sum of 1, 3 and 4.

import sys
import pdb

def sum_of(seq):
    ss = 0
    for elem in seq:
        ss += elem
    return ss

def num_ways(nums, number, cur_sum, ways, seq):
    if cur_sum == number:
        ways += 1 
        return ways
    elif cur_sum > number:
        return ways
    for num in nums:
        if cur_sum + num > number:
            continue
        cur_sum += num
        seq.append(num)
        nways = num_ways(nums, number, cur_sum, ways, seq)
        if nways > ways:
            if sum_of(seq) == number:
                print seq
                print nways, ways
            cur_sum -= num
            ways = nways
        seq.pop()
    return ways

if __name__ == "__main__":
    number = int(sys.argv[1])
    nums = [1, 3, 4]
    seq = []
    print num_ways(nums, number, 0, 0, seq)
