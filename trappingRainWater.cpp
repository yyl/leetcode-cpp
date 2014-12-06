//
//  trappingRainWater.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "trappingRainWater.h"
#include <unordered_map>
using namespace std;

int Solution::trap(int A[], int n) {
    unordered_map<int, int> left(n), right(n);
    left[0] = 0;
    right[n-1] = 0;
    int trapped = 0;
    for (int i=1; i<n; i++)
        left[i] = max(A[i-1], left[i-1]);
    for (int i=n-2; i>=0; i--)
        right[i] = max(A[i+1], right[i+1]);
    for (int i=1;i<n-1;i++)
        trapped += max(min(left[i], right[i]) - A[i], 0);
    return trapped;
}