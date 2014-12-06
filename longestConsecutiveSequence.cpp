//
//  longestConsecutiveSequence.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "longestConsecutiveSequence.h"
#include <unordered_map>
using namespace std;

int Solution::longestConsecutive(vector<int> &num) {
    unordered_map<int, bool> has_num, valid;
    vector<int>::iterator it;
    // iterate vector using iterator
    for (it=num.begin();it!=num.end();it++) {
        has_num[*it] = true;
        valid[*it] = true;
    }
    int max_len = 0;
    for (it=num.begin();it!=num.end();it++) {
        int cur_val = *it;
        int cur_len = 1;
        while (true) {
            cur_val++;
            if (has_num.count(cur_val) == 1 && valid[cur_val]) {
                cur_len++;
                valid[cur_val] = false;
            } else
                break;
        }
        cur_val = *it;
        while (true) {
            cur_val--;
            if (has_num.count(cur_val) == 1 && valid[cur_val]) {
                cur_len++;
                valid[cur_val] = false;
            } else
                break;
        }
        if (cur_len > max_len)
            max_len = cur_len;
        
    }
    return max_len;
}