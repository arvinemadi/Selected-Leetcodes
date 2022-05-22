/*
LeetCode wants to give one of its best employees the option to travel among n cities to collect algorithm problems. But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks. Your job is to schedule the traveling to maximize the number of vacation days you could take, but there are certain rules and restrictions you need to follow.

Rules and restrictions:

You can only travel among n cities, represented by indexes from 0 to n - 1. Initially, you are in the city indexed 0 on Monday.
The cities are connected by flights. The flights are represented as an n x n matrix (not necessarily symmetrical), called flights representing the airline status from the city i to the city j. If there is no flight from the city i to the city j, flights[i][j] == 0; Otherwise, flights[i][j] == 1. Also, flights[i][i] == 0 for all i.
You totally have k weeks (each week has seven days) to travel. You can only take flights at most once per day and can only take flights on each week's Monday morning. Since flight time is so short, we do not consider the impact of flight time.
For each city, you can only have restricted vacation days in different weeks, given an n x k matrix called days representing this relationship. For the value of days[i][j], it represents the maximum days you could take a vacation in the city i in the week j.
You could stay in a city beyond the number of vacation days, but you should work on the extra days, which will not be counted as vacation days.
If you fly from city A to city B and take the vacation on that day, the deduction towards vacation days will count towards the vacation days of city B in that week.
We do not consider the impact of flight hours on the calculation of vacation days.
Given the two matrices flights and days, return the maximum vacation days you could take during k weeks.
*/

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    int n = flights.size();
    int m = days[0].size();
    dpm.resize(n, vector<int> (m + 1,-1));
    int value = 0;
    for(int i = 0; i < flights[0].size(); i++)
            if(flights[0][i] || i == 0)
                value = max(value, dp(i, 0, flights, days));
    return value;
    }
    
public:
    bool start = true;
    vector<vector<int>> dpm;
    
    int dp(int city, int week, vector<vector<int>>& flights, vector<vector<int>>& days){
        if(dpm[city][week]!=-1) return dpm[city][week];
        
        if(week == days[0].size() - 1) 
                            return dpm[city][week] = days[city][week];
                            
        int max_vacation = 0;
        int max_vacation_0 = 0;
        if(start){
            start = false;
            for(int i = 0; i < flights[city].size(); i++)
                if(flights[city][i])
                    max_vacation_0 = max(max_vacation, dp(i, week, flights, days));
        }
        
        for(int i = 0; i < flights[city].size(); i++)
            if(flights[city][i] || city == i)
                max_vacation = max(max_vacation, dp(i, week + 1, flights, days));
        
	max_vacation += days[city][week];
        max_vacation = max(max_vacation, max_vacation_0);
        
        return dpm[city][week] = max_vacation;
        }
};