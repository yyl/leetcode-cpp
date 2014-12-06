//
//  MaximumDepthofBinaryTree.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/28/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "MaximumDepthofBinaryTree.h"

int Solution::maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    int m_left = maxDepth(root->left);
    int m_right = maxDepth(root->right);
    // find the larger one among two values
    return m_left > m_right ? m_left + 1 : m_right + 1;
};