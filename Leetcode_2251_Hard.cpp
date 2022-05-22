/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). 
You are also given a 0-indexed integer array persons of size n, where persons[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.
*/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = persons.size();
        int m = flowers.size();
        vector<int> bloom_flowers (n);
        vector<vector<int>> flowers_start_sorted = flowers;
        vector<vector<int>> flowers_end___sorted = flowers;
        sort(flowers_start_sorted.begin(), flowers_start_sorted.end(), [](auto& a, auto& b){return a[0] < b[0];});      //sorted flowers based on start so that we can binary search and find the start of flowers that are too late
        sort(flowers_end___sorted.begin(), flowers_end___sorted.end(), [](auto& a, auto& b){return a[1] < b[1];});      //sorted flowers based on the end so that we can binary search and find the end of the flowers that are too early
        for(int i = 0; i < n; i++) {                                                                                    //iterate over persons O(n) and will be multiplied by O(logn) for the binary searches
            int low  = 0;
            int high = m - 1;
            int first_late_flower = -1;
            while(low <= high) {                                        //...first binary search to find the flowers that are too late
                int mid = low + (high - low)/2;
                if(flowers_start_sorted[mid][0] > persons[i]) {
                    first_late_flower = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            int number_of_later_flowers = first_late_flower == -1 ? 0 : m - first_late_flower;
            low  = 0;
            high = m - 1;
            int last_too_early_flower = -1;
            while(low <= high) {                                        //...second binary search to find the flowers that are too early
                int mid = low + (high - low)/2;
                if(flowers_end___sorted[mid][1] < persons[i]) {
                    last_too_early_flower = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            int number_of_too_early_flowers = last_too_early_flower == -1 ? 0 : last_too_early_flower + 1;
            bloom_flowers[i] = m - number_of_too_early_flowers - number_of_later_flowers;
        }
    return bloom_flowers;
    }
};