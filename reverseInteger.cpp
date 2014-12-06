//
//  reverseInteger.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/29/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "reverseInteger.h"
#include <vector>
#include <cmath>
#include <stdlib.h>

int Solution::reverse(int x) {
    if (-10 < x && x < 10)
        return 0;
    // handle negative digit
    bool negative = false;
    if (x < 0) {
        x = 0 - x;
        negative = true;
    }
    int cur_x = x;
    std::vector<int> digits;
    bool is_trailing = true;
    while (cur_x >= 10) {
        int cur_digit = cur_x - (cur_x / 10) * 10;
        if (cur_digit == 0 && is_trailing == true) {
            cur_x /= 10;
            continue;
        } else
            is_trailing = false;
        digits.push_back(cur_digit);
        cur_x /= 10;
    }
    // handle the last digit
    digits.push_back(cur_x);
    int result = 0;
    int pos = 0;
    for (int i=digits.size()-1;i>=0;i--) {
        long long c = (long long) result + digits[i] * pow(10, pos);
        if (c <= INT_MIN || c >= INT_MAX) return 0;
        result += digits[i] * pow(10, pos);
        pos++;
    }
    if (negative == true)
        return 0 - result;
    else
        return result;
};

int Solution::reverse2(int x) {
    if (-10 < x&& x < 10)
        return x;
    // handle negative digit
    bool negative = x>0?false:true;
    // use abs from stdlib.h for absolute value
    int cur_x = abs(x);
    int result = 0;
    while (cur_x > 0) {
        int cur_digit = cur_x % 10;
        // handle integer overflow
        long long c = (long long) result*10 + cur_digit;
        if (c <= INT_MIN || c >= INT_MAX)
            return 0;
        result = result*10 + cur_digit;
        cur_x /= 10;
    }
    if (negative == true)
        result = 0 - result;
    return result;
};

