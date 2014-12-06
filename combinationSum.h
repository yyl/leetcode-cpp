//
//  combinationSum.h
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__combinationSum__
#define __leetcode__combinationSum__

#include <stdio.h>
#include <vector>

class Solution {
public:
    void getComb(std::vector<std::vector<int>> &result, std::vector<int> candidates, std::vector<int> cur_set, int cur_val, int target);
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target);
};
#endif /* defined(__leetcode__combinationSum__) */
