//
//  balancedBinaryTree.h
//  leetcode
//
//  Created by Yulong Yang on 12/1/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__balancedBinaryTree__
#define __leetcode__balancedBinaryTree__

#include <stdio.h>
#include "Structure.h"
#include <vector>
#include <tuple>

class Solution {
public:
    std::tuple<bool, int> isB(TreeNode *root);
    bool isBalanced(TreeNode *root);
};
#endif /* defined(__leetcode__balancedBinaryTree__) */
