/*
(This problem is an interactive problem.)

Each ship is located at an integer point on the sea represented by a cartesian plane, and each integer point may contain at most 1 ship.

You have a function Sea.hasShips(topRight, bottomLeft) which takes two points as arguments and returns true If there is at least one ship in the rectangle represented by the two points, including on the boundary.

Given two points: the top right and bottom left corners of a rectangle, return the number of ships present in that rectangle. It is guaranteed that there are at most 10 ships in that rectangle.

Submissions making more than 400 calls to hasShips will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

Example:
Input: 
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
Output: 3
Explanation: From [0,0] to [4,4] we can count 3 ships within the range.
/*

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    if(topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1])      return 0;
    if(sea.hasShips(topRight, bottomLeft) == false)                     return 0;
    if(topRight[0] == bottomLeft[0] || topRight[1] == bottomLeft[1])    return sea.hasShips(topRight, bottomLeft);
    
    //split the area into 4 smaller rectangles
    //define the coordinates to make calculation easier
    int x0 = bottomLeft[0]; int y0 = bottomLeft[1];
    int x4 = topRight[0]; int y4 = topRight[1];
    int xm = (x0 + x4) / 2;         //mid point x
    int ym = (y0 + y4) / 2;         //mid point y
    
    int t_l{0}, t_r{0}, b_l{0}, b_r{0};
    if(xm - 1 >= x0 && y4 >= ym +1)
        t_l = countShips(sea, {xm -1, y4}, {x0, ym + 1});
    
    if(x4 >= xm && y4 >= ym +1)
        t_r = countShips(sea, {x4, y4}, {xm, ym + 1});
    
    if(xm - 1 >= x0 && ym >= 0)
        b_l = countShips(sea, {xm -1, ym}, {x0, y0});
    
    if(x4 >= xm && ym >= y0)
        b_r = countShips(sea, {x4, ym}, {xm, y0});
    
    return t_l + t_r + b_l + b_r;   //combine the numbers from 2x2 rectangles
    }
};