import heapq
from typing import List


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        hashmap = {}
        minHeap = []

        for i in hand:
            if i in hashmap:
                hashmap[i] += 1
            else:
                hashmap[i] = 1

        minHeap = list(hashmap.keys())
        heapq.heapify(minHeap)

        while minHeap:
            curr = minHeap[0]

            for i in range(curr, curr + groupSize):
                if i not in hashmap:
                    return False
                hashmap[i] -= 1
                if hashmap[i] == 0:
                    if i != minHeap[0]:
                        return False
                    heapq.heappop(minHeap)
        return True
