class Solution(object):
    def maxEnvelopes(self, envelopes):
        env = sorted(envelopes, key = lambda x : (x[0], -x[1]))
        sub = [env[0][1]]
        for i in range(1, len(env), 1):
            if env[i][1] > sub[-1]:
                sub.append(env[i][1])
            else:
                low = 0
                high = len(sub) - 1
                ans = -1
                while low <= high:
                    mid = low + (high - low) // 2
                    if sub[mid] >= env[i][1]:
                        ans = mid
                        high = mid - 1
                    else:
                        low = mid + 1
                if ans != -1:
                    sub[ans] = env[i][1]
        return len(sub)