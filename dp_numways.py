#Let us say that you are given a number N, you've to find the number of different ways to write it as the sum of 1, 3 and 4.
#DP formula: T(n) = T(n-1) + T(n-3) + T(n-4)

import sys
import pdb


if __name__ == "__main__":
    inp = int(sys.argv[1])
    nums = [1, 3, 4] 
    sol_map = {}
    sol_map[0] = 1
    sol_map[1] = 1
    sol_map[2] = 1
    sol_map[3] = 2
    for n in range(4, inp+1):
        sol_map[n] = sol_map[n-1] + sol_map[n-3] + sol_map[n-4]
    print sol_map[n]
