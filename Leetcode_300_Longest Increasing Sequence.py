# Greedy with Binary Search
class Solution(object):
    def lengthOfLIS(self, nums):
        n = len(nums)
        sub = [nums[0]]
        for i in range(1, n, 1):
            if nums[i] > sub[-1]:
                sub.append(nums[i])
            else:
                low = 0
                high = len(sub) - 1
                ans = -1
                while low <= high:
                    mid = low + (high - low) // 2
                    if nums[i] <= sub[mid]:
                        ans = mid
                        high = mid - 1
                    else:
                        low = mid + 1
                if ans != -1:
                    sub[ans] = nums[i]
        return len(sub)


"""
# DP bottom up - O(n2)
class Solution(object):
    def lengthOfLIS(self, nums):
        n = len(nums)
        dp = [1] * n 
        res = 1
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], 1 + dp[j])
                    res = max(res, dp[i])
        return res
"""