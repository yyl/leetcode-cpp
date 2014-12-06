//
//  palindromeNumber.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "palindromeNumber.h"
#include <cmath>

bool Solution::isPalindrome(int x) {
    if (x<0) return false;
    if (x<10) return true;
    // get length of integer
    int size = floor(log10(x)) + 1;
    int digit = 0;
    while (digit<size/2) {
        // pow returns double by default
        int least = (x/int(pow(10, digit))%10);
        int most = (x/int(pow(10, size-digit-1))%10);
        if (least != most) return false;
        digit++;
    }
    return true;
};