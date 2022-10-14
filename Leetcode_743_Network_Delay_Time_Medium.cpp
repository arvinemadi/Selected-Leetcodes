/*
743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

*/

class Solution {
public:
    class Neighbor {
    public:
        int node;
        int cost;
        Neighbor (int n, int c) : node(n), cost(c) {}
    };
    
    struct NeighborComp {
        bool operator() (Neighbor const& a, Neighbor const& b) const {
            return a.cost > b.cost;    
        }
    };
        
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Neighbor>> adjacency (n + 1);
        vector<int> captured (n + 1, -1);
        vector<int> receive_times (n + 1, -1);
        
        for (auto& time:times)
        {
            adjacency[time[0]].push_back(Neighbor(time[1], time[2]));
        }
        
        priority_queue<Neighbor, vector<Neighbor>, NeighborComp> pq;
        
        for (Neighbor n:adjacency[k])
        {
            pq.push(n);
        }
        captured[k] = 1;
        receive_times[k] = 0;
        
        while (!pq.empty())
        {
            Neighbor current_node = pq.top();
            pq.pop();
            if (captured[current_node.node] == 1)   continue;
            receive_times[current_node.node] = current_node.cost;
            captured[current_node.node] = 1;
            for (Neighbor n : adjacency[current_node.node])
            {
                pq.push(Neighbor(n.node, n.cost + current_node.cost));
            }
        }
        
        int minTime = -1;
        for (int index = 1; index <= n; index++)
        {
            if (receive_times[index] == -1) return -1;
            minTime = max(minTime, receive_times[index]);
        }
        return minTime;
    }
};