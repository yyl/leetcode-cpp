//
//  populatingNextRightPointersinEachNode.h
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__populatingNextRightPointersinEachNode__
#define __leetcode__populatingNextRightPointersinEachNode__

#include <stdio.h>
#include "Structure.h"

struct ModifiedNode {
    TreeLinkNode *node, *parent;
    ModifiedNode() : node(NULL), parent(NULL) {};
};

class Solution {
public:
    void connect(TreeLinkNode *root);
    void connect2(TreeLinkNode *root);
    void connectII(TreeLinkNode *root);
    void connectII2(TreeLinkNode *root);
};

#endif /* defined(__leetcode__populatingNextRightPointersinEachNode__) */
