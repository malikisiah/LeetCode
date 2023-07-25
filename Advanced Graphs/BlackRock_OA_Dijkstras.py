import heapq
from collections import defaultdict


def maxConversion(start, end, adj):
    visit = set()
    maxRate = defaultdict(int)

    maxRate[start] = 1

    Q = [(-1, start)]

    while Q:
        rate, curr = heapq.heappop(Q)

        rate = -rate

        if curr in visit:
            continue

        visit.add(curr)

        for nextRate, nextNode in adj[curr]:
            newRate = rate * nextRate
            if newRate > maxRate[nextNode]:
                maxRate[nextNode] = newRate

            if nextNode not in visit:
                heapq.heappush(Q, (-newRate, nextNode))

    if end in visit:
        return maxRate[end]
    else:
        return -1


start = "USD"
end = "JPY"
hashmap = defaultdict(list)
hashmap["USD"] = [(0.71, "GBP"), (109, "JPY")]
hashmap["GBP"] = [(155, "JPY")]
print(hashmap)

print(maxConversion(start, end, hashmap))
