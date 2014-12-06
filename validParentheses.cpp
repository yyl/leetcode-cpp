//
//  validParentheses.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "validParentheses.h"
#include <stack>
#include <unordered_map>
using namespace std;

bool Solution::isValid(string s) {
    if (s.empty()) return true;
    stack<string> st;
    int size = int(s.size());
    if (size%2 == 1) return false;
    unordered_map<string, bool> is_left = {{"(",true}, {"{",true}, {"[",true}};
    unordered_map<string, bool> is_right = {{")",true}, {"}",true}, {"]",true}};
    unordered_map<string, string> par_map = {{"(",")"}, {"{","}"}, {"[","]"}};
    for (int i=0;i<size;i++) {
        // convert char to string
        string cur_str(1, s[i]);
        if (is_left.count(cur_str)!=0) {
            // push will create a new full copy of the element
            st.push(cur_str);
            continue;
        }
        if (is_right.count(cur_str)!=0) {
            if (st.empty() || cur_str != par_map[st.top()]) return false;
            st.pop();
        }
    }
    if (st.empty()) return true;
    return false;
}