//
//  grayCode.h
//  leetcode
//
//  Created by Yulong Yang on 12/2/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__grayCode__
#define __leetcode__grayCode__

#include <stdio.h>
#include <vector>

class Solution {
public:
    std::vector<int> binaryToDecimal(std::vector<std::vector<int>> binaries);
    std::vector<int> grayCode(int n);
    std::vector<int> grayCode2(int n);
};

#endif /* defined(__leetcode__grayCode__) */
