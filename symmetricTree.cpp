//
//  symmetricTree.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "symmetricTree.h"

bool Solution::subtreeSymmetric(TreeNode *left, TreeNode *right) {
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    if (left->val != right->val)
        return false;
    if (!subtreeSymmetric(left->left, right->right) || !subtreeSymmetric(left->right, right->left))
        return false;
    return true;
}
bool Solution::isSymmetric(TreeNode *root) {
    if ((!root) || (!root->left && !root->right))
        return true;
    if (!root->left || !root->right)
        return false;
    return subtreeSymmetric(root->left, root->right);
}