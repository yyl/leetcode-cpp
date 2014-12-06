//
//  sumRoottoLeafNumbers.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "sumRoottoLeafNumbers.h"
using namespace std;

void getSum(TreeNode* root, int* sump, string cur_str) {
    // int to string
    cur_str += to_string(root->val);
    if (!root->left && !root->right) {
        // string to int
        // deference
        *(sump) += stoi( cur_str );
        return;
    }
    if (root->left)
        getSum(root->left, sump, cur_str);
    if (root->right)
        getSum(root->right, sump, cur_str);
}

int sumNumbers(TreeNode *root) {
    int sum=0;
    // pointer to int variable
    int*sum_p = &sum;
    if (!root)
        return sum;
    // pass a pointer instead of the real value so that we could modify the value in the function
    getSum(root, sum_p, "");
    return sum;
}