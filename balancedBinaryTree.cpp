//
//  balancedBinaryTree.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/1/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "balancedBinaryTree.h"
#include <cstdlib>
using namespace std;

// tuple library in cpp
tuple<bool, int> Solution::isB(TreeNode *root) {
    if (!root)
        // make_tuple to create a tuple
        return make_tuple(true, 0);
    if (!root->left && !root->right)
        return make_tuple(true, 1);
    tuple<bool, int> left_tuple, right_tuple;
    int ld, rd;
    ld = 0;
    rd = 0;
    bool lt, rt;
    lt = true;
    rt = true;
    if (root->left) {
        left_tuple = isB(root->left);
        // get<index>(t) to get specific element in the tuple
        ld = get<1>(left_tuple);
        lt = get<0>(left_tuple);
    }
    if (root->right) {
        right_tuple = isB(root->right);
        rd = get<1>(right_tuple);
        rt = get<0>(right_tuple);
    }
    if (!lt || !rt || abs(ld-rd)>1)
        return make_tuple(false, 0);
    // get the larger value of two
    int cur_d = ld > rd ? ld + 1 : rd + 1;
    return make_tuple(true, cur_d);
};

bool Solution::isBalanced(TreeNode *root) {
    tuple<bool, int> t = isB(root);
    return get<0>(t);
};