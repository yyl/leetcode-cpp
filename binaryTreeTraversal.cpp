//
//  binaryTreePreorderTraversal.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "binaryTreeTraversal.h"
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> Solution::preorderTraversal(TreeNode *root) {
    vector<int> result;
    if (!root)
        return result;
    // use STL std::stack
    // push(item): push item
    // top(): gain access to the top item in stack
    // pop(): pop off the first item, but DOES NOT return it
    // empty(): check if it is empty
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return result;
};

void inorder(TreeNode* node, vector<int>* output) {
    if (node->left)
        inorder(node->left, output);
    output->push_back(node->val);
    if (node->right)
        inorder(node->right, output);
};

vector<int> Solution::inorderTraversal(TreeNode *root) {
    // dynamically allocate vector without declaring size
    vector<int> *result = new vector<int>();
    if (root)
        inorder(root, result);
    return *result;
};

// a stack with a hash map to check if node has been visited or not
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if (!root) {
        return result;
    }
    unordered_map<TreeNode*, bool> visited;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if ((!node->left || (node->left && visited.count(node->left) != 0)) &&
            (!node->right || (node->right && visited.count(node->right) != 0)))
        {
            st.pop();
            result.push_back(node->val);
            visited[node] = true;
        }
        if (node->right && visited.count(node->right) == 0) {
            st.push(node->right);
        }
        if (node->left && visited.count(node->left) == 0) {
            st.push(node->left);
        }
    }
    return result;
};

// std::deque behaves the same as deque in python
vector<vector<int> > Solution::levelOrderBottom(TreeNode *root) {
    vector<vector<int>> output;
    if (!root)
        return output;
    deque<TreeNode*> q;
    deque<TreeNode*> q2;
    q.push_back(root);
    while (!q.empty()) {
        vector<int> cur_level;
        // use reverse_iterator to iterate from last to first
        deque<TreeNode*>::reverse_iterator it;
        for (it=q.rbegin();it!=q.rend();it++)
            cur_level.push_back((*it)->val);
        // costly insertion
        output.insert(output.begin(), cur_level);
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (node->right)
                q2.push_back(node->right);
            if (node->left)
                q2.push_back(node->left);
            q.pop_front();
        }
        // switch content of two containers, O(1)
        swap(q, q2);
    }
    return output;
};