class Solution(object):
    def longestIncreasingPath(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        dpm = [[-1] * n for _ in range(m)]
        maxlength = 0
        
        def dp(i, j, matrix):

            if dpm[i][j] != -1:    return dpm[i][j]

            res = 1
            if i - 1 >= 0 and matrix[i-1][j] > matrix[i][j]:
                res = max(res, 1 + dp(i-1, j, matrix))

            if i + 1 <  m and matrix[i+1][j] > matrix[i][j]:
                res = max(res, 1 + dp(i+1, j, matrix))

            if j - 1 >=0 and matrix[i][j-1] > matrix[i][j]:
                res = max(res, 1 + dp(i, j-1, matrix))

            if j + 1 < n and matrix[i][j+1] > matrix[i][j]:
                res = max(res, 1 + dp(i, j+1, matrix))

            dpm[i][j] = res
            return res
        
        for i in range(m):
            for j in range(n):
                maxlength = max(maxlength, dp(i, j, matrix))
        return maxlength