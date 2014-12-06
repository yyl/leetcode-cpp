//
//  uniquePaths.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "uniquePaths.h"
using namespace std;

int Solution::uniquePaths(int m, int n) {
    if (m==1 || n==1)
        return 1;
    int result = 1;
    int r = n-1;
    int total = m+n-2;
    for (int i=1;i<r+1;i++) {
        result *= (total - (r-i));
    }
    for (int i=1;i<r+1;i++) {
        result /= i;
    }
    return result;
}

void getPath(vector<vector<int>> &visited, int i, int j, int *sum) {
    int row = int(visited.size());
    int col = int(visited[0].size());
    if (i==row-1 && j==col-1) {
        (*sum)++;
        return;
    }
    //right
    if (j<col-1 && visited[i][j+1]==0) {
        visited[i][j+1] = 1;
        getPath(visited, i, j+1, sum);
        visited[i][j+1] = 0;
    }
    //down
    if (i<row-1 && visited[i+1][j]==0) {
        visited[i+1][j] = 1;
        getPath(visited, i+1, j, sum);
        visited[i+1][j] = 0;
    }
}
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int row = int(obstacleGrid.size());
    if (row<=1) return 1;
    int col = int(obstacleGrid[0].size());
    if (col<=1) return 1;
    int sum=0;
    int *sump = &sum;
    getPath(obstacleGrid, 0, 0, sump);
    return sum;
}

int uniquePathsWithObstacles2(vector<vector<int> > &obstacleGrid) {
    int row = int(obstacleGrid.size());
    if (row==0) return 0;
    int col = int(obstacleGrid[0].size());
    if (obstacleGrid[0][0]==1 || obstacleGrid[row-1][col-1]==1) return 0;
    vector<vector<int>> visited(row, vector<int>(col));
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            if (i==0 && j==0) {
                visited[i][j] = 1;
                continue;
            }
            if (obstacleGrid[i][j]!=1) {
                int ways = 0;
                if (i>0 && obstacleGrid[i-1][j]!=1) ways += visited[i-1][j];
                if (j>0 && obstacleGrid[i][j-1]!=1) ways += visited[i][j-1];
                visited[i][j] = ways;
            }
        }
    }
    return visited[row-1][col-1];
}