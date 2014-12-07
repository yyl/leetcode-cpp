//
//  pathSum.h
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__pathSum__
#define __leetcode__pathSum__

#include <stdio.h>
#include "Structure.h"
#include <vector>

class Solution {
public:
    bool equalSum(TreeNode* node, int cur_sum, int target);
    bool hasPathSum(TreeNode *root, int sum);
    std::vector<std::vector<int> > pathSum(TreeNode *root, int sum);
    void getSum(TreeNode* root, std::vector<std::vector<int>> &result, std::vector<int> cur_set, int cur_val, int s);
};
#endif /* defined(__leetcode__pathSum__) */
