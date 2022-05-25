"""
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
Return the number of distinct islands.

Example 1:
Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1

Example 2:
Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
Output: 3
"""
class Solution(object):
    def __init__(self):
        self.n = 0
        self.m = 0
        self.path = ""
        self.paths = {}
        
    def numDistinctIslands(self, grid):
        self.m = len(grid)
        self.n = len(grid[0])
        visited = [[-1] * self.n for _ in range(self.m)] 
        for i in range(self.m):
            for j in range(self.n):
                if visited[i][j] == -1 and grid[i][j] == 1:
                    self.path = "S"
                    self.dfs(i, j, visited, grid)
                    if self.path not in self.paths.keys():
                        self.paths[self.path] = 1
        return len(self.paths)
                    
    def dfs(self, i, j, visited, grid):
        visited[i][j] = 1
        if i - 1 >= 0 and visited[i-1][j] == -1 and grid[i-1][j] == 1:
            self.path += 'U'
            self.dfs(i-1,j, visited, grid)
        if i + 1 < self.m and visited[i+1][j] == -1 and grid[i+1][j] == 1:
            self.path += 'D'
            self.dfs(i+1,j, visited, grid)
        if j - 1 >= 0 and visited[i][j-1] == -1 and grid[i][j-1] == 1:
            self.path += 'L'
            self.dfs(i,j-1, visited, grid)
        if j + 1 < self.n and visited[i][j+1] == -1 and grid[i][j+1] == 1:
            self.path += 'R'
            self.dfs(i,j+1, visited, grid)
        self.path += 'B'
        return
        
        