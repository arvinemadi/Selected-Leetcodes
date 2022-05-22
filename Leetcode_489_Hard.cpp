/*
489. Robot Room Cleaner - Hard 

You are controlling a robot that is located somewhere in a room. The room is modeled as an m x n binary grid where 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be empty, and you do not have access to the grid, but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.

Design an algorithm to clean the entire room using the following APIs:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}

Note that the initial direction of the robot will be facing up. You can assume all four edges of the grid are all surrounded by a wall.

*/


/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        visited.resize(201, vector<bool>(401, false));
        x_dir = {-1, 0, 1, 0};
        y_dir = {0, -1, 0, 1};
        dfs(100, 200, 0, robot);
        return;
    }
    
    void dfs (int x, int y, int dir, Robot& robot) { 
        robot.clean();
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int newdir = (dir + i) % 4;
            int newx = x + x_dir[newdir];
            int newy = y + y_dir[newdir];
            if(i != 0)
                robot.turnLeft();
            if(!visited[newx][newy] && robot.move()) {
                dfs(newx, newy, newdir, robot);
                robot.turnRight();
                robot.turnRight();
            }
        }
        robot.turnRight();
        robot.move();
        return;
    }
    vector<vector<bool>> visited;
    vector<int> x_dir;
    vector<int> y_dir;
};