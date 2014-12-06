//
//  findMinimuminRotatedSortedArray.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/2/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "findMinimuminRotatedSortedArray.h"
using namespace std;

// pass by reference does not affect the way of coding
int Solution::findMin(vector<int> &num) {
    if (num.size() == 1)
        return num[0];
    for (int i=1; i<num.size(); i++) {
        if (num[i] < num[i-1]) {
            return num[i];
        }
    }
    return num[0];
};