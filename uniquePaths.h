//
//  uniquePaths.h
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__uniquePaths__
#define __leetcode__uniquePaths__

#include <stdio.h>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n);
    int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid);
    void getPath(std::vector<std::vector<int>> &visited, int i, int j, int *sum);
    int uniquePathsWithObstacles2(std::vector<std::vector<int> > &obstacleGrid);
};
#endif /* defined(__leetcode__uniquePaths__) */
