//
//  grayCode.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/2/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "grayCode.h"
#include <cmath>
using namespace std;

vector<int> Solution::binaryToDecimal(vector<vector<int>> binaries) {
    vector<int> decimals;
    int n = int(binaries[0].size());
    for (int i=0;i<binaries.size();i++) {
        // convert a vector of binaries to one decimal integer
        // coultd also use std::bitset to represent binary numbers
        int result=0;
        for (int j=0;j<n;j++) {
            result += binaries[i][j]*(pow(2,n-1-j));
        }
        decimals.push_back(result);
    }
    return decimals;
}

vector<int> Solution::grayCode(int n) {
    if (n==0) {
        vector<int> output;
        output.push_back(0);
        return output;
    }
    // 2d vector
    vector<vector<int>> codes;
    vector<int> first;
    first.push_back(0);
    codes.push_back(first);
    vector<int> second;
    second.push_back(1);
    codes.push_back(second);
    bool direction = true;
    while (n>1) {
        vector<vector<int>> new_codes;
        for (int i=0;i<codes.size();i++) {
            vector<int> cur_vec1 = codes[i];
            vector<int> cur_vec2 = codes[i];
            if (direction) {
                cur_vec1.push_back(0);
                cur_vec2.push_back(1);
            } else {
                cur_vec1.push_back(1);
                cur_vec2.push_back(0);
            }
            new_codes.push_back(cur_vec1);
            new_codes.push_back(cur_vec2);
            direction = !direction;
        }
        codes = new_codes;
        n--;
    }
    return binaryToDecimal(codes);
}

vector<int> Solution::grayCode2(int n) {
    vector<int> result;
    result.push_back(0);
    for (int i=0; i<n; i++) {
        int cur_size = int(result.size());
        // shift 1 left i bits
        int cur_increase = 1 << i;
        for (int j=0; j<cur_size; j++) {
            result.push_back(result[cur_size-1-j]+cur_increase);
        }
    }
    return result;
}