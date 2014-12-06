//
//  linkedListCycle.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/29/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "linkedListCycle.h"

bool Solution::hasCycle(ListNode *head) {
    if (!head || !head->next)
        return false;
    // two new pointers of listNode
    ListNode* slow = head;
    ListNode* fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        // compare 2 pointers instead of values to avoid raising null pointer error
        if (fast == slow)
            return true;
    }
    return false;
};

ListNode* Solution::detectCycle(ListNode *head) {
    if (!head)
        return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
        if (slow==fast)
            break;
    }
    if (!fast)
        return NULL;
    ListNode* node = head;
    while (node!=slow) {
        node = node->next;
        slow = slow->next;
    }
    return node;
}