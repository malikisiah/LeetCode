from collections import defaultdict


class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False

        countS = defaultdict(int)
        countT = defaultdict(int)

        for i in range(len(s)):
            countS[s[i]] += 1
            countT[t[i]] += 1

        return countT == countS
