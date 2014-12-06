//
//  SameTree.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/28/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "SameTree.h"

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    if (p->val == q->val) {
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        else
            return false;
    } else {
        return false;
    }
};