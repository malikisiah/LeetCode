from typing import List
from collections import defaultdict, deque


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets.sort()
        adj = defaultdict(deque)
        res = ["JFK"]

        for source, target in tickets:
            adj[source].append(target)

        def dfs(node):
            if len(res) == len(tickets) + 1:
                return True
            if node not in adj:
                return False

            temp = list(adj[node])

            for v in temp:
                adj[node].popleft()
                res.append(v)

                if dfs(v):
                    return res
                res.pop()
                adj[node].append(v)

        dfs("JFK")
        return res
