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

class Solution {
public:
    bool equalSum(TreeNode* node, int cur_sum, int target);
    bool hasPathSum(TreeNode *root, int sum);
};
#endif /* defined(__leetcode__pathSum__) */
