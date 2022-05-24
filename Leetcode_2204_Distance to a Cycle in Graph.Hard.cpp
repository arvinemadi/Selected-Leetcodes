/*
You are given a positive integer n representing the number of nodes in a connected undirected graph containing exactly one cycle. The nodes are numbered from 0 to n - 1 (inclusive).
You are also given a 2D integer array edges, where edges[i] = [node1i, node2i] denotes that there is a bidirectional edge connecting node1i and node2i in the graph.
The distance between two nodes a and b is defined to be the minimum number of edges that are needed to go from a to b.
Return an integer array answer of size n, where answer[i] is the minimum distance between the ith node and any node in the cycle.

Example 1:
Input: n = 7, edges = [[1,2],[2,3],[3,4],[4,1],[0,1],[5,2],[6,5]]
Output: [1,0,0,0,0,1,2]
Explanation:
The nodes 1, 2, 3, and 4 form the cycle.
The distance from 0 to 1 is 1.
The distance from 1 to 1 is 0.
The distance from 2 to 2 is 0.
The distance from 3 to 3 is 0.
The distance from 4 to 4 is 0.
The distance from 5 to 2 is 1.
The distance from 6 to 2 is 2.
*/

class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<int> dist(n, -1), times(n, -1), parent(n, -1);
        for(auto& edge : edges) {                                       //create adjacency list from edges
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> BackEdge = bfs(0, times, parent);                   //doing a BFS we can find a back-edge that forms the loop
        
        FindLoop(BackEdge, parent, dist, times);                        //Find the common ancestors between the nodes of the back-edge
                                                                        //and assign the distance of all of them to the loop to be zero
        vector<bool> visited(n, false);
        dfs(BackEdge[0], dist, visited, 0);                             //Do a DFS to assign the distance of any unvisited node to +1 the distance of its parent
                                                                        //Unless they are in the loop
        return dist;
    }
    
    vector<int> bfs(int node, vector<int>& times, vector<int>& parent) {
        queue<int> mq;
        mq.push(node);
        int time = 0;
        times[node] = time++;
        while(!mq.empty()) {
            int current = mq.front();
            mq.pop();
            for(int neighbour : adj[current]) {
                if(times[neighbour] == -1) {
                    times[neighbour] = time++;
                    parent[neighbour] = current;
                    mq.push(neighbour);
                }
                else if(neighbour != parent[current])
                    return {current, neighbour};
            }
        }
        return {0,0};
    }
    
    void FindLoop(vector<int>& BackEdge, vector<int>& parent, vector<int>& dist, vector<int>& times) {
        int node1 = BackEdge[0];
        int node2 = BackEdge[1];
        dist[node1] = dist[node2] = 0;
        
        while(node1 != node2) {
            if(times[node1] > times[node2]) {
                node1 = parent[node1];
                dist[node1] = 0;
            }
            else {
                node2 = parent[node2];
                dist[node2] = 0;
            }
        }
        return;
    }
    
    void dfs(int node, vector<int>& dist, vector<bool>& visited, int d) {
        visited[node] = true;
        if(dist[node] != 0)     dist[node] = d;
        else                    d = 0;
        for(int neighbour : adj[node]) 
            if(!visited[neighbour]) {
                dfs(neighbour, dist, visited, d + 1);
            }
        return;
    }
        
    unordered_map<int, vector<int>> adj;
};