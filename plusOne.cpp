//
//  plusOne.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "plusOne.h"

std::vector<int> Solution::plusOne(std::vector<int> &digits) {
    int carry = 0;
    int end = int(digits.size())-1;
    digits[end]++;
    for (int i=end;i>=0;i--) {
        digits[i] += carry;
        if (digits[i] >= 10) {
            digits[i] -= 10;
            carry = 1;
        } else
            carry = 0;
    }
    // vector insert a value, first paramter is the position
    if (carry!=0)
        digits.insert(digits.begin(), carry);
    return digits;
}