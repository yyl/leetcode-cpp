//
//  rotateImage.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/2/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "rotateImage.h"
using namespace std;

void Solution::rotate(vector<vector<int> > &matrix) {
    int n = int(matrix.size());
    for (int i=0; i<n/2; i++) {
        for (int j=i; j<n-i-1; j++) {
            // swap 4 elements
            int top = matrix[i][j];
            int right = matrix[j][n-1-i];
            int bottom = matrix[n-1-i][n-1-j];
            int left = matrix[n-1-j][i];
            matrix[i][j] = left;
            matrix[j][n-1-i] = top;
            matrix[n-1-i][n-1-j] = right;
            matrix[n-1-j][i] = bottom;
        }
    }
}