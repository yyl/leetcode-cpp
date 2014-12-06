//
//  populatingNextRightPointersinEachNode.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "populatingNextRightPointersinEachNode.h"
#include <stack>
using namespace std;

// root points to NULL
// all left children point to right children
// all right children point to left children of the nodes their parent point to
void Solution::connect(TreeLinkNode *root) {
    if (!root)
        return;
    stack<ModifiedNode*> st;
    ModifiedNode* new_root = new ModifiedNode();
    new_root->node = root;
    st.push(new_root);
    while (!st.empty()) {
        ModifiedNode* n = st.top();
        st.pop();
        if (n->node->right) {
            ModifiedNode* right = new ModifiedNode();
            right->node = n->node->right;
            right->parent = n->node;
            if (n->parent && n->parent->next)
                n->node->right->next = n->parent->next->left;
            st.push(right);
        }
        if (n->node->left) {
            n->node->left->next = n->node->right;
            ModifiedNode* left = new ModifiedNode();
            left->node = n->node->left;
            left->parent = n->node;
            st.push(left);
        }
        delete n;
        
    }
};

void Solution::connect2(TreeLinkNode *root) {
    if (!root)
        return;
    stack<TreeLinkNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeLinkNode* node = st.top();
        st.pop();
        if (node->left) {
            node->left->next = node->right;
            st.push(node->left);
        }
        if (node->right) {
            if (node->next)
                node->right->next = node->next->left;
            st.push(node->right);
        }
    }
};

// has bug
void Solution::connectII(TreeLinkNode *root) {
    if (!root || (!root->left && !root->right))
        return;
    deque<TreeLinkNode*> q1;
    deque<TreeLinkNode*> q2;
    q1.push_back(root);
    while (!q1.empty()) {
        for (int i=int(q1.size())-1;i>=0;i--) {
            if (i<int(q1.size())-1)
                q1[i]->next = q1[i+1];
        }
        while (!q1.empty()) {
            TreeLinkNode* node = q1.front();
            if (node->right)
                q2.push_back(node->right);
            if (node->left)
                q2.push_back(node->left);
            q1.pop_front();
        }
        swap(q1, q2);
    }
};

void connectII2(TreeLinkNode *root) {
    if (!root || (!root->left && !root->right))
        return;
    TreeLinkNode* node = root->next;
    while (node && !node->left && !node->right) {
        node = node->next;
    }
    // for right child
    if (root->right && node) {
        if (node->left) {
            root->right->next = node->left;
        } else if (node->right) {
            root->right->next = node->right;
        }
    }
    connectII2(root->right);
    // for left child
    if (root->left) {
        if (root->right) {
            root->left->next = root->right;
        } else if (node) {
            if (node->left) {
                root->left->next = node->left;
            } else if (node->right) {
                root->left->next = node->right;
            }
        }
        connectII2(root->left);
    }
}