/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

class Solution(object):
    def letterCombinations(self, digits):
        if len(digits) == 0:
            return []
        list = ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        options = [""]
        for digit in digits:
            newoptions = []
            for key in list[ord(digit)-ord('2')]:
                for option in options:
                    newoptions.append(option + key)
            options = newoptions
        return options