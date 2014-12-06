//
//  convertSortedArraytoBinarySearchTree.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/1/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "convertSortedArraytoBinarySearchTree.h"
using namespace std;

TreeNode* Solution::getBST(vector<int> &num, int start, int end) {
    int mid = (start+end)/2;
    TreeNode* root = new TreeNode(num[mid]);
    if (start == end)
        return root;
    if (mid > start) {
        TreeNode* left = getBST(num, start, mid-1);
        root->left = left;
    }
    TreeNode* right = getBST(num, mid+1, end);
    root->right = right;
    return root;
};

// function argument with &: pass by reference
TreeNode* Solution::sortedArrayToBST(vector<int> &num) {
    if (num.empty())
        return nullptr;
    return getBST(num, 0, int(num.size())-1);
};