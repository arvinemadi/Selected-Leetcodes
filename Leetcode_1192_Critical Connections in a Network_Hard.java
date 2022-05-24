/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.

Example:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
*/

class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        criticals = new ArrayList<>();
        time = 0;
        int[] disc   = new int[n];    Arrays.fill(disc, -1);
        int[] low    = new int[n];    Arrays.fill(low, -1);
        int[] parent = new int[n];    Arrays.fill(parent, -1);
        List<List<Integer>> adjacency = new ArrayList<>(); 
        for(int i = 0; i < n; i++) adjacency.add(new ArrayList<>());
        for(List<Integer> edge : connections) {
            adjacency.get(edge.get(0)).add(edge.get(1));
            adjacency.get(edge.get(1)).add(edge.get(0));
        }
        dfs(0, disc, low, parent, adjacency);
        return criticals;
    }
    
    void dfs(int node, int[] disc, int[] low, int[] parent, List<List<Integer>> adjacency) {
        
        disc[node] = low[node] = time++;
        List<Integer> neighbors = adjacency.get(node);
        for(int neighbor : neighbors) {
            if(disc[neighbor] == -1) {
                parent[neighbor] = node;
                dfs(neighbor, disc, low, parent, adjacency);
                low[node] = Math.min(low[neighbor], low[node]);
                if(low[neighbor] > disc[node])
                    criticals.add(Arrays.asList(node, neighbor));
            }
            else if(neighbor != parent[node])
                low[node] = Math.min(disc[neighbor], low[node]);
        }
        return;
    }
    List<List<Integer>> criticals;
    int time;
}