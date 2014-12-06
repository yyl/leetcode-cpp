//
//  removeDuplicatesfromSortedArray.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/2/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "removeDuplicatesfromSortedArray.h"

int Solution::removeDuplicates(int A[], int n) {
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    int length = 0;
    for (int i=1; i<n; i++) {
        if (A[i] == A[length]) {
            continue;
        } else {
            length++;
            // swap 2 elements in array
            int temp = A[i];
            A[i] = A[length];
            A[length] = temp;
        }
    }
    return length+1;
};

int Solution::removeDuplicatesII(int A[], int n) {
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    int length = 0;
    int count = 1;
    for (int i=1; i<n; i++) {
        if (A[i] == A[length]) {
            if (count==1) {
                length++;
                int temp = A[i];
                A[i] = A[length];
                A[length] = temp;
            }
            count++;
            continue;
        } else {
            length++;
            int temp = A[i];
            A[i] = A[length];
            A[length] = temp;
            count = 1;
        }
    }
    return length+1;
}