//
//  partitionList.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "partitionList.h"

ListNode *partition(ListNode *head, int x) {
    if (!head) return head;
    ListNode* pivot = new ListNode(x);
    ListNode* dummy = new ListNode(0);
    dummy->next = pivot;
    ListNode* prev = dummy;
    ListNode* end = pivot;
    while (head) {
        ListNode* temp = head;
        head = head->next;
        if (temp->val<pivot->val) {
            prev->next = temp;
            temp->next = pivot;
            prev = temp;
        } else {
            end->next = temp;
            temp->next = NULL;
            end = temp;
        }
    }
    prev->next = pivot->next;
    pivot->next = NULL;
    delete pivot;
    return dummy->next;
}