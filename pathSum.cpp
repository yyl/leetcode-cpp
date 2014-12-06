//
//  pathSum.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "pathSum.h"

bool Solution::equalSum(TreeNode* node, int cur_sum, int target) {
    cur_sum += node->val;
    if (!node->left && !node->right && cur_sum == target)
        return true;
    bool leftSum = false;
    bool rightSum = false;
    if (node->left)
        leftSum = equalSum(node->left, cur_sum, target);
    if (node->right)
        rightSum = equalSum(node->right, cur_sum, target);
    return leftSum || rightSum;
}

bool Solution::hasPathSum(TreeNode *root, int sum) {
    if (!root)
        return false;
    return equalSum(root, 0, sum);
}