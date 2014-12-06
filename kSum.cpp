//
//  kSum.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "kSum.h"
#include <numeric>
#include <stdlib.h>
using namespace std;

int threeSumClosest(vector<int> &num, int target) {
    int size = int(num.size());
    // sum up any given range of a vector
    if (size<3) return accumulate(num.begin(), num.end(), 0);
    sort(num.begin(), num.end());
    int closest = accumulate(num.begin(), num.begin()+3, 0);
    for (int i=0;i<size-2;i++) {
        int start = i+1;
        int end = size-1;
        while (start!=end) {
            int cur_val = num[i] + num[start] + num[end];
            if (abs(cur_val-target) < abs(closest-target))
                closest = cur_val;
            if (cur_val == target)
                return target;
            else if (cur_val > target)
                end--;
            else
                start++;
        }
    }
    return closest;
}