class Solution:
    def reverse(self, x: int) -> int:
        s = str(abs(x))

        rev = int(s[::-1])

        if rev > 2147483647:
            return 0

        if x > 0:
            return rev
        else:
            return rev * -1
