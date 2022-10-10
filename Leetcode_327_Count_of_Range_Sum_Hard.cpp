class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        vector<long> acc_sum;
        long running_sum = 0;
        int length = nums.size();
        this->lower = lower;
        this->upper = upper;
        this->nums = nums;
        acc_sum.push_back(0);
        for(int& num:nums)
        {
            running_sum += num;
            acc_sum.push_back(running_sum);
        }
        return mergeCountSort(acc_sum, 0, length);
        
    }
    
    int lower, upper;
    vector<int> nums;
    int mergeCountSort(vector<long>& acc_sum, int start, int end)
    {
        if (start >= end)    return 0;
        int mid = (start + end) / 2;
        long count = mergeCountSort(acc_sum, start, mid) + mergeCountSort(acc_sum, mid + 1, end);
        
        int m = mid + 1;
        int n = mid + 1;
        
        for (int index = start; index <= mid; index++)
        {
            while (m <= end && acc_sum[m] - acc_sum[index] < lower) m++;
            while (n <= end && acc_sum[n] - acc_sum[index] <= upper) n++;
            count += n - m;
        }
        
        int pointer1 = start, pointer2 = mid+1;
        vector<long> merged;
        while(pointer1 <= mid && pointer2 <= end)
        {
            if (acc_sum[pointer1] <= acc_sum[pointer2])
            {
                merged.push_back(acc_sum[pointer1]);
                pointer1++;
            }
            else
            {
                merged.push_back(acc_sum[pointer2]);
                pointer2++;
            }
        }
        while(pointer1 <= mid)
        {
            merged.push_back(acc_sum[pointer1]);
            pointer1++;
        }
        while(pointer2 <= end)
        {
            merged.push_back(acc_sum[pointer2]);
            pointer2++;
        }
        for (int index = start; index <= end; index++)
        {
            acc_sum[index] = merged[index - start];
        }
        
        return count;
    }
};