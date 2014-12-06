//
//  convertSortedListtoBinarySearchTree.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "convertSortedListtoBinarySearchTree.h"

// O(logn)
TreeNode* Solution::sortedListToBST(ListNode *head) {
    if (!head) return NULL;
    TreeNode* root = new TreeNode(head->val);
    if (!head->next) return root;
    if (!head->next->next) {
        TreeNode* right = new TreeNode(head->next->val);
        root->right = right;
        return root;
    }
    ListNode* prev = head;
    ListNode* mid = head;
    ListNode* fast = head;
    while (fast->next) {
        prev = mid;
        mid = mid->next;
        fast = fast->next;
        if (fast->next) fast = fast->next;
    }
    prev->next = NULL;
    TreeNode *left = sortedListToBST(head);
    TreeNode *right = sortedListToBST(mid->next);
    root->val = mid->val;
    root->left = left;
    root->right = right;
    return root;
}

// O(n)
TreeNode* Solution::toBST(ListNode* &head, int start, int end) {
    if (start>end) return NULL;
    int mid = (start + end)/2;
    TreeNode* left = toBST(head, start, mid-1);
    TreeNode* root = new TreeNode(head->val);
    root->left = left;
    head = head->next;
    TreeNode* right = toBST(head, mid+1, end);
    root->right = right;
    return root;
}

TreeNode* Solution::sortedListToBST2(ListNode *head) {
    int n = 0;
    ListNode* node = head;
    while (node) {
        node = node->next;
        n++;
    }
    return toBST(head, 0, n-1);
}