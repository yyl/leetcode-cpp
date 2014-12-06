//
//  linkedListCycle.h
//  leetcode
//
//  Created by Yulong Yang on 11/29/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__linkedListCycle__
#define __leetcode__linkedListCycle__

#include <stdio.h>
#include "Structure.h"

class Solution
{
public:
    bool hasCycle(ListNode *head);
    ListNode *detectCycle(ListNode *head);
};

#endif /* defined(__leetcode__linkedListCycle__) */
