/*
You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < n and set the value of arr at index i to x.
You may repeat this procedure as many times as needed.
Return true if it is possible to construct the target array from arr, otherwise, return false.

Example 1:
Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done

Example 2:
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].

Example 3:
Input: target = [8,5]
Output: true
*/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (n == 1) return target[0] == 1;
        priority_queue<int> pq (target.begin(), target.end());
        long long sum = 0;
        for(int i : target)
            sum += i;
        
        while(sum > 0)
        {
            int biggest = pq.top();
            pq.pop();
            int k = (biggest - 1)/ (sum - biggest);             // How many times replaced the same location
            if (k == 0)
                return false;
            int replaced_num = biggest - k * (sum - biggest);   
            if (replaced_num < 1)
                return false;
            pq.push(replaced_num);
            sum = sum - biggest + replaced_num;                 
            if(sum == n)
                return true;
        }
        return false;
    }
};