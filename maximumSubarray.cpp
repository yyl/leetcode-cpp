//
//  maximumSubarray.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "maximumSubarray.h"

int Solution::maxSubArray(int A[], int n) {
    if (n==1)
        return A[0];
    int cur_sum = 0;
    int max_sum = A[0];
    // check if all elements are negative
    for (int i=1; i<n; i++) {
        if (A[i] > max_sum)
            max_sum = A[i];
    }
    if (max_sum < 0)
        return max_sum;
    for (int i=0; i<n; i++) {
        cur_sum += A[i];
        if (cur_sum < 0)
            cur_sum = 0;
        if (cur_sum > max_sum)
            max_sum = cur_sum;
    }
    return max_sum;
};