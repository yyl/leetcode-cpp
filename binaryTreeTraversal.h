//
//  binaryTreePreorderTraversal.h
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__binaryTreeTraversal__
#define __leetcode__binaryTreeTraversal__

#include <stdio.h>
#include "Structure.h"
#include <vector>

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode *root);
    std::vector<int> inorderTraversal(TreeNode *root);
    std::vector<int> postorderTraversal(TreeNode *root);
    std::vector<std::vector<int> > levelOrderBottom(TreeNode *root);
};

#endif /* defined(__leetcode__binaryTreeTraversal__) */
