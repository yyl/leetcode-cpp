//
//  subsets.h
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__subsets__
#define __leetcode__subsets__

#include <stdio.h>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(std::vector<int> &input, int k);
    std::vector<std::vector<int>> subsets(std::vector<int> &S);
};
#endif /* defined(__leetcode__subsets__) */
