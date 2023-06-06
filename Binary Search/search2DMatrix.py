from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        top = 0
        bottom = len(matrix) - 1

        while top <= bottom:
            mid = top + (bottom - top) // 2

            if target < matrix[mid][0]:
                bottom = mid - 1
            elif target > matrix[mid][-1]:
                top = mid + 1
            else:
                break

        if not (top <= bottom):
            return False

        row = top + (bottom - top) // 2

        l = 0
        r = len(matrix[row]) - 1

        while l <= r:
            mid = l + (r - l) // 2

            if matrix[row][mid] < target:
                l = mid + 1

            elif matrix[row][mid] > target:
                r = mid - 1

            else:
                return True

        return False
