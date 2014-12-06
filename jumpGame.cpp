//
//  jumpGame.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "jumpGame.h"

bool canJump(int A[], int n) {
    if (n==0) return false;
    if (n==1) return true;
    if (A[0] == 0) return false;
    int max_reach = A[0];
    for (int i=1;i<n;i++) {
        if (i > max_reach) return false;
        if (A[i]+i > max_reach) max_reach = i + A[i];
        if (max_reach >= n-1) return true;
    }
    return false;
}