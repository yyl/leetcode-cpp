//
//  removeElement.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/1/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "removeElement.h"

int Solution::removeElement(int A[], int n, int elem) {
    int swapper = n-1;
    for (int i=0; i<n; i++) {
        if (i == swapper) {
            break;
        }
        if (A[i] == elem) {
            while (swapper>0 && A[swapper] == elem) {
                swapper--;
            }
            // swap elements in the array
            if (swapper > i) {
                A[i] = A[swapper];
                A[swapper] = elem;
            }
        }
    }
    int i=0;
    while (A[i]!=elem && i<n) {
        i++;
    }
    return i;
};