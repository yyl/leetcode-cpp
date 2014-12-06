//
//  swapNodesinPairs.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/1/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "swapNodesinPairs.h"

ListNode* Solution::swapPairs(ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    // use 4 pointers in total
    ListNode* prev = dummy;
    ListNode* node1 = head;
    ListNode* node2 = head->next;
    ListNode* anchor = node2->next;
    while (node2) {
        prev->next = node2;
        node1->next = anchor;
        node2->next = node1;
        if (!anchor || !anchor->next)
            break;
        prev = node1;
        node1 = anchor;
        node2 = anchor->next;
        anchor = node2->next;
    }
    return dummy->next;
};