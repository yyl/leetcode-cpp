//
//  triangle.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "triangle.h"
#include <climits>
#include <unordered_map>
#include <iostream>
using namespace std;

int Solution::minimumTotal(vector<vector<int>> &triangle) {
    unordered_map<int, int> min_cost;
    int size = int(triangle.size());
    for (int i=0;i<size;i++) {
        int tri_size = int(triangle[i].size());
        if (i==0) {
            for (int j=0;j<tri_size;j++) min_cost[j] = triangle[i][j];
        } else {
            unordered_map<int, int> temp;
            for (int j=0;j<tri_size;j++) {
                int cost = INT_MAX;
                if (j!=tri_size-1 && cost>min_cost[j]) cost = min_cost[j];
                if (j!=0 && cost>min_cost[j-1]) cost = min_cost[j-1];
                temp[j] = cost + triangle[i][j];
            }
            min_cost.swap(temp);
        }
    }
    int cost_size = int(min_cost.size());
    int min_val = min_cost[0];
    for (int i=1;i<cost_size;i++) {
        if (min_cost[i] < min_val) min_val = min_cost[i];
    }
    return min_val;
};