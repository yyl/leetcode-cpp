//
//  flattenBinaryTreetoLinkedList.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "flattenBinaryTreetoLinkedList.h"

TreeNode* Solution::flattenThisNode(TreeNode* node) {
    if (!node->left && !node->right)
        return node;
    // initialize pointer as NULL to avoid unexpected problem
    TreeNode* left_bottom = NULL;
    TreeNode* right_bottom = NULL;
    if (node->left) left_bottom = flattenThisNode(node->left);
    if (node->right) right_bottom = flattenThisNode(node->right);
    if (left_bottom) {
        TreeNode* temp = node->right;
        node->right = node->left;
        left_bottom->right = temp;
    }
    node->left = NULL;
    if (right_bottom) return right_bottom;
    return left_bottom;
};

void Solution::flatten(TreeNode *root) {
    if (root) flattenThisNode(root);
};