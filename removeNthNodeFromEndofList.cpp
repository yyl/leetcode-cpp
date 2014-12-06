//
//  removeNthNodeFromEndofList.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "removeNthNodeFromEndofList.h"

ListNode* Solution::removeNthFromEnd(ListNode *head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* end = head;
    while (n>1) {
        end = end->next;
        n--;
    }
    ListNode* start = head;
    ListNode* prev = dummy;
    while (end->next) {
        prev = start;
        start = start->next;
        end = end->next;
    }
    ListNode* temp = start;
    prev->next = start->next;
    temp->next = NULL;
    return dummy->next;
}