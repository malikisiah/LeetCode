from collections import defaultdict


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1_map = {chr(i): 0 for i in range(ord("a"), ord("z") + 1)}
        s2_map = {chr(i): 0 for i in range(ord("a"), ord("z") + 1)}
        matches = 0

        for i in range(len(s1)):
            s1_map[s1[i]] += 1
            s2_map[s2[i]] += 1

        for i in s1_map:
            matches += 1 if s1_map[i] == s2_map[i] else 0

        l = 0

        for r in range(len(s1), len(s2)):
            if matches == 26:
                return True

            s2_map[s2[r]] += 1

            if s1_map[s2[r]] == s2_map[s2[r]]:
                matches += 1
            elif s1_map[s2[r]] + 1 == s2_map[s2[r]]:
                matches -= 1

            s2_map[s2[l]] -= 1

            if s1_map[s2[l]] == s2_map[s2[l]]:
                matches += 1
            elif s1_map[s2[l]] - 1 == s2_map[s2[l]]:
                matches -= 1
            l += 1

        return matches == 26
