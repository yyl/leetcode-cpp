//
//  convertSortedArraytoBinarySearchTree.h
//  leetcode
//
//  Created by Yulong Yang on 12/1/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__convertSortedArraytoBinarySearchTree__
#define __leetcode__convertSortedArraytoBinarySearchTree__

#include <stdio.h>
#include "Structure.h"
#include <vector>

class Solution {
public:
    TreeNode *sortedArrayToBST(std::vector<int> &num);
    TreeNode* getBST(std::vector<int> &num, int start, int end);
};
#endif /* defined(__leetcode__convertSortedArraytoBinarySearchTree__) */
