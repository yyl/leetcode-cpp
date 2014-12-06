//
//  pascalsTriangle.h
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__pascalsTriangle__
#define __leetcode__pascalsTriangle__

#include <stdio.h>
#include <vector>;

class Solution {
public:
    std::vector<std::vector<int> > generate(int numRows);
    std::vector<std::vector<int>> generate2(int numRows);
    std::vector<int> getRow(int rowIndex);
};
#endif /* defined(__leetcode__pascalsTriangle__) */
