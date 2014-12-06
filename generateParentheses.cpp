//
//  generateParentheses.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "generateParentheses.h"
using namespace std;

// a function to recursive:
// given how many left parenthesis have left unsued and left unclosed
// if left_remain==0, print out parathesis
// if left_open=0, add left
// otherwise add right

// vector variable is passing by reference
// string variable is a copy made every time the function is called
void printParenthesis(vector<string> &output, string cur_p, int left_open, int left_remain) {
    if (left_remain == 0 && left_open == 0)
        output.push_back(cur_p);
    if (left_open > 0)
        printParenthesis(output, cur_p+")", left_open-1, left_remain);
    if (left_remain > 0)
        printParenthesis(output, cur_p+"(", left_open+1, left_remain-1);
    
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> result;
    printParenthesis(result, "", 0, n);
    return result;
}