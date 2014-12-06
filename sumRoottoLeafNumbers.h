//
//  sumRoottoLeafNumbers.h
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__sumRoottoLeafNumbers__
#define __leetcode__sumRoottoLeafNumbers__

#include <stdio.h>
#include "Structure.h"
#include <string>

class Solution {
public:
    void getSum(TreeNode* root, int* sump, std::string cur_str);
    int sumNumbers(TreeNode *root);
};

#endif /* defined(__leetcode__sumRoottoLeafNumbers__) */
