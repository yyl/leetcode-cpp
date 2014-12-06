//
//  containerWithMostWater.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "containerWithMostWater.h"
using namespace std;

int Solution::maxArea(vector<int> &height) {
    int i = 0;
    int j = int(height.size())-1;
    int max_area = min(height[i], height[j]) * (j-i);
    while (i<j) {
        int cur_area = min(height[i], height[j]) * (j-i);
        if (cur_area > max_area)
            max_area = cur_area;
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return max_area;
}