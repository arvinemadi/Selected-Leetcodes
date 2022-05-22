/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    int n = routes.size();
    if(source == target)    return 0;
    unordered_map<int, vector<int>> map;
    for(int i = 0; i < n; i++)
        for(auto& stop:routes[i])
            map[stop].push_back(i);
        
            
    if(map[target].size() == 0 || map[source].size() == 0)     return -1;
    
    vector<bool> taken (n, false);
    queue<int> mq;
    for(int i = 0; i < map[source].size(); i++)         
        {
            mq.push(map[source][i]);
            taken[map[source][i]] = true;
        }
        
    int level{0};
    while(!mq.empty())
        {
            level++;
            int size = mq.size();
            for(int i = 0; i < size; i++)
                {
                    int currentbus = mq.front();
                    mq.pop();
                    for(int j = 0; j < routes[currentbus].size(); j++)
                        {
                            int stop = routes[currentbus][j];
                            if(stop == target)     return level;
                            for(int k = 0; k < map[stop].size(); k++)
                                {
                                    int bus = map[stop][k];
                                    if(!taken[bus])
                                        {
                                            taken[bus] = true;
                                            mq.push(bus);
                                        }
                                }
                        }
                }
        }
    return -1;
    }
};