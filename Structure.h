//
//  Structure.h
//  leetcode
//
//  Created by Yulong Yang on 11/28/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef leetcode_Structure_h
#define leetcode_Structure_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
#endif
