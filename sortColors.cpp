//
//  sortColors.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "sortColors.h"

// define a function that only belongs to this cpp file
// all arrays as arguments are pass-by-reference by default
void sortOneColor(int A[], int n, int color) {
    int last = 0;
    if (color!=0) {
        for (int i=0;i<n;i++) {
            if (A[i] != color-1) {
                last = i;
                break;
            }
        }
    }
    for (int i=last;i<n;i++) {
        if (A[i] == color) {
            int temp = A[last];
            A[last] = A[i];
            A[i] = temp;
            last++;
        }
    }
}

void Solution::sortColors(int A[], int n) {
    sortOneColor(A, n, 0);
    sortOneColor(A, n, 1);
}