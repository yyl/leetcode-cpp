//
//  flattenBinaryTreetoLinkedList.h
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__flattenBinaryTreetoLinkedList__
#define __leetcode__flattenBinaryTreetoLinkedList__

#include <stdio.h>
#include "Structure.h"

class Solution {
public:
    TreeNode* flattenThisNode(TreeNode* node);
    void flatten(TreeNode *root);
};
#endif /* defined(__leetcode__flattenBinaryTreetoLinkedList__) */
