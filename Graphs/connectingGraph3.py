class ConnectingGraph3:
    """
    @param a: An integer
    @param b: An integer
    @return: nothing
    """

    def __init__(self, n):
        # initialize your data structure here.
        self.numConnected = n
        self.parent = []
        self.rank = []

        for i in range(n + 1):
            self.parent.append(i)
            self.rank.append(1)

    def find(self, n):
        p = self.parent[n]

        while p != self.parent[p]:
            self.parent[p] = self.parent[self.parent[p]]
            p = self.parent[p]
        return p

    def union(self, n1, n2):
        p1 = self.find(n1)
        p2 = self.find(n2)

        if p1 == p2:
            return False
        if self.rank[p1] > self.rank[p2]:
            self.parent[p2] = p1
            self.rank[p1] += self.rank[p2]
        else:
            self.parent[p1] = p2
            self.rank[p2] += self.rank[p1]
        return True

    def connect(self, a, b):
        if self.union(a, b):
            self.numConnected -= 1

        # write your code here

    """
    @return: An integer
    """

    def query(self):
        return self.numConnected
        # write your code here
