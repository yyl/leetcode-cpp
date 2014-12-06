//
//  minimumDepthofBinaryTree.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "minimumDepthofBinaryTree.h"
#include <algorithm>
using namespace std;

int Solution::minDepth(TreeNode *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    if (root->left && root->right)
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    if (root->right)
        return minDepth(root->right)+1;
    if (root->left)
        return minDepth(root->left)+1;
    return NULL;
};