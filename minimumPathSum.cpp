//
//  minimumPathSum.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "minimumPathSum.h"
using namespace std;

int Solution::minPathSum(vector<vector<int> > &grid) {
    if (grid.size()==0)
        return 0;
    int m = int(grid.size());
    int n = int(grid[0].size());
    // initialize a fixed length 2d array for DP
    // if we use a hash map, as the key will be 2d, we have to write a cusomized hash function
    int costs[m][n];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i==0 && j==0) {
                costs[0][0] = grid[0][0];
                continue;
            }
            int cost = 0;
            if (i>0 && j==0)
                cost = costs[i-1][j]+grid[i][j];
            else if (i==0 && j>0)
                cost = costs[i][j-1]+grid[i][j];
            else
                cost = min(costs[i-1][j], costs[i][j-1]) + grid[i][j];
            costs[i][j] = cost;
        }
    }
    return costs[m-1][n-1];
}
