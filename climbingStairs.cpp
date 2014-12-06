//
//  climbingStairs.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/1/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "climbingStairs.h"
#include <unordered_map>
using namespace std;

int Solution::climbStairs(int n) {
    // DP: s[n] = s[n-1] + s[n-2]
    unordered_map<int, int> jumps;
    jumps[0] = 1;
    jumps[1] = 1;
    for (int i=2; i<=n; i++) {
        jumps[i] = jumps[i-1] + jumps[i-2];
    }
    return jumps[n];
};