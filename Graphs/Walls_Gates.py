from typing import List
from collections import deque


class Solution:
    def walls_and_gates(self, rooms: List[List[int]]):
        ROWS, COLS = len(rooms), len(rooms[0])
        visit = set()
        q = deque()

        def addRoom(i, j):
            if (
                i < 0
                or j < 0
                or i >= ROWS
                or j >= COLS
                or (i, j) in visit
                or rooms[i][j] == -1
            ):
                return
            q.append([i, j])
            visit.add((i, j))

        for i in range(ROWS):
            for j in range(COLS):
                if rooms[i][j] == 0:
                    q.append([i, j])
                    visit.add((i, j))

        distance = 0

        while q:
            for i in range(len(q)):
                r, c = q.popleft()
                rooms[r][c] = distance

                addRoom(r + 1, c)
                addRoom(r - 1, c)

                addRoom(r, c + 1)
                addRoom(r, c - 1)

            distance += 1
