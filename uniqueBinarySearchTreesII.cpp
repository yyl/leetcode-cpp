//
//  uniqueBinarySearchTreesII.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/29/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "uniqueBinarySearchTreesII.h"
using namespace std;

vector<TreeNode *> getTree(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        for (int i=start; i<=end; i++) {
            vector<TreeNode *> l_subtree = getTree(start, i-1);
            vector<TreeNode *> r_subtree = getTree(i+1, end);
            for (int x=0; x<l_subtree.size(); x++) {
                for (int y=0; y<r_subtree.size(); y++) {
                    // here we allocated objects, instead of pointers
                    // TreeNode root(i);
                    // root.left = l_subtree[x];
                    // root.right = r_subtree[y];
                    // result.push_back(&root);
                    // dynamically allocate new memory for single variable
                    TreeNode *root = new TreeNode(i);
                    root->left = l_subtree[x];
                    root->right = r_subtree[y];
                    result.push_back(root);
                }
            }
        }
        return result;
};

vector<TreeNode *> Solution::generateTrees(int n) {
    if (n==0) {
        vector<TreeNode *> t;
        return t;
    }
    return getTree(1, n);
};