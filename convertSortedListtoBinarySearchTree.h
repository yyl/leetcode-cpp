//
//  convertSortedListtoBinarySearchTree.h
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__convertSortedListtoBinarySearchTree__
#define __leetcode__convertSortedListtoBinarySearchTree__

#include <stdio.h>
#include "Structure.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head);
    TreeNode *sortedListToBST2(ListNode *head);
    TreeNode* toBST(ListNode* &head, int start, int end);
};
#endif /* defined(__leetcode__convertSortedListtoBinarySearchTree__) */