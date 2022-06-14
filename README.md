# Selected Leetcodes
Not all, but some leetcodes that I did and found them interesting would be added here with explanation.
If you had questions please contact me.
Leetcode profile with all posted solutions: https://leetcode.com/arvinemadi/

## Leetcode 489 - Robot Room Cleaner - Hard
Initially thought that it has to be an A* or other shortest path but first tried a DFS and it was the solution.
The challenge is to be careful with backtracking and the direction after returns. Also, budgetting eough space for the 2D vectors twice the max size, because the initial location is unknown and max direction could come from either side

## Leetcode 568 - Hard
Relatively complicated Problem and the solution based in Dynamic Programming.

## Leetcode 2251 - Hard
Very intersting problem that I solved in one of weekly contests. The problem seems easy to understand. 
The solution is based on binary search. Need to find the flowers that are too late and also flowers. And then find the ones that are too early. There are some comments in the file also

## Leetcode 815 - Bus Routes - Hard
Usual Breadth First Search (BFS) type of problem. The tricky part was that initially you are not in any bus and need to push all possible bus optioins into the queue and mark those buses as taken. 

## Leetcode 17 - Letter Combinations of a Phone Number - Medium
It is probably more an easy problem than a Medium problem. Added here because it was one of my most viewed posted solutions.

## Leetcode 474 - Ones and Zeros - Medium/Hard
Added this as it could be on the Hard side if not familiar with Knapsack problem. Solved it with easier DP approach. It can be optimized for space.

## Leetcode 1192 - Critical Connections in a Network - Hard
Applying Tarjan algorithm with discovery and low times.

## Leetcode 2204 - Distance to a cycle in Undirected Graph - Hard
Very interesting question. Only one back-edge existed in the graph and if removed it is a tree.
Approach was to: 1- Do a BFS to find the back-edge. While doing BFS store the time each node is visited 2- When the back-edge is found, find the common ancestor between the nodes of the back-edge; these will be the nodes in the loop 3- do a DFS and assign the distance of each node to +1 of its parent, unless they are in the loop

## Leetcode 694 - Number of Distinct Islands - Medium
If distinct islands were not requested, it was pretty easy to count the islands with simple DFS. 
Asking for distinct islands makes this a little bit more challenging. The approach I used was to hash the path each island is traversed and store the paths in a dict.
If a new island's path does not exists in the dict, it would be added as a new distint island.

## Leetcode 300 - Longest Increasing Sequence - Medium
Classic problem. Solved in two approaches:
1- Dynamic Programming (DP) bottom up. O(n2)
2- Greedy + Binary Search: Try to create the sub array in a greedy way. But sinc sub is by definition sorted can use Binary Search to find the biggest element at each step. O(nlogn)

## Leetcode 354 - Russian Doll Envelopes - Hard
Based on previous problem, Longest Increasing Sequence. Need to sort first, ascending for width and descending for length. Descending for length is done to avoid the situation of same width envelopes fitting the next coming envelope if the width is the same. 

## Leetcode 329 - Longest Increasing Path in a Matrix - Hard
Although it seems similar but it is a much easier problem compared the previous two problems, 300 and 354. This can be solved by normal dynamic programming.

## Leetcode 1279 - Number of Ships in a Rectangle - Hard
Interesting question. The trick is to cut down each rectangle into a smaller 2x2 rectangles and do recursion. Order complexity: O(logn x logm)


