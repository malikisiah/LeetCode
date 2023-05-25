from typing import List


class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def min_meeting_rooms(self, intervals: List[Interval]) -> int:
        startTimes = sorted([i.start for i in intervals])
        endTimes = sorted([i.end for i in intervals])

        result, count = 0, 0

        i, j = 0, 0

        while i < len(startTimes):
            if startTimes[i] < endTimes[j]:
                count += 1
                i += 1
            else:
                count -= 1
                j += 1
            result = max(result, count)
        return result
