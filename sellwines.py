'''
Given an array containing prices of wine bottles, given that each wine gets better X times in X years, output the sequence in which to sell the wines over years. You can sell only one wine bottle per year and the bottle must be chosen between the left most and right most bottles remaining in the array. 
Sample array: [2, 3, 5, 1, 4], Sample output: b1, b5, b4, b2, b3 (earnings: 50)

Approach: Greedy algo will not work as can be seen from above input/output examples. We can use backtrack to compute all possible earnings and return the best one. However, there will be several overlapping paths. We should memorize the best earning from a given path everytime we compute one. Recursion + backtracking with memoization (dynamic programming) can be used.
'''

if __name__ == "__main__":
    in_arr = [2, 3, 5, 1, 4]
