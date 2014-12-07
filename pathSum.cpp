//
//  pathSum.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "pathSum.h"
using namespace std;

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

void Solution::getSum(TreeNode* root, vector<vector<int>> &result, vector<int> cur_set, int cur_val, int s) {
    if (!root) return;
    else {
        if (!root->left && !root->right && cur_val + root->val == s) {
            cur_set.push_back(root->val);
            result.push_back(cur_set);
            cur_set.pop_back();
            return;
        }
        cur_set.push_back(root->val);
        if (root->left)
            getSum(root->left, result, cur_set, cur_val+root->val, s);
        if (root->right)
            getSum(root->right, result, cur_set, cur_val+root->val, s);
        cur_set.pop_back();
    }
}
vector<vector<int> > Solution::pathSum(TreeNode *root, int sum) {
    vector<vector<int>> result;
    getSum(root, result, vector<int>(), 0, sum);
    return result;
}