//
//  pascalsTriangle.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "pascalsTriangle.h"
using namespace std;

vector<vector<int> > Solution::generate(int numRows) {
    vector<vector<int>> result(numRows);
    if (numRows == 0)
        return result;
    result[0].push_back(1);
    if (numRows == 1)
        return result;
    for (int i=1;i<numRows;i++) {
        for (int j=0;j<i+1;j++) {
            int cur_val = 0;
            if (j!=0)
                cur_val += result[i-1][j-1];
            if (j!=i)
                cur_val += result[i-1][j];
            result[i].push_back(cur_val);
        }
    }
    return result;
}

void piscal(vector<vector<int>> &result, int cur_row, int n) {
    if (cur_row == n)
        return;
    vector<int> this_row;
    this_row.push_back(1);
    for (int i=1;i<cur_row;i++) {
        this_row.push_back(result[cur_row-1][i] + result[cur_row-1][i-1]);
    }
    if (cur_row!=0)
        this_row.push_back(1);
    result.push_back(this_row);
    piscal(result, cur_row+1, n);
}

vector<vector<int>> Solution::generate2(int numRows) {
    vector<vector<int>> result;
    piscal(result, 0, numRows);
    return result;
}

vector<int> Solution::getRow(int rowIndex) {
    vector<int> result;
    for (int i=0; i<=rowIndex; i++) {
        if (i<=rowIndex/2) {
            // potential integer overflow problem
            // long double > double > long long > long > int
            long double cur_val = 1;
            for (int k=1; k<=i; k++)
                cur_val *= (rowIndex-(i-k));
            for (int t=1; t<=i; t++)
                cur_val /= t;
            result.push_back(int(cur_val));
        } else {
            result.push_back(int(result[rowIndex-i]));
        }
    }
    return result;
}