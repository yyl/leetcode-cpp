//
//  setMatrixZeroes.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "setMatrixZeroes.h"
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
    int row = int(matrix.size());
    if (row == 0)
        return;
    int col = int(matrix[0].size());
    // check if 1st row and 1st col has zero
    bool row_zero = false;
    bool col_zero = false;
    for (int i=0;i<row;i++) {
        if (matrix[i][0] == 0) {
            row_zero = true;
            break;
        }
    }
    for (int i=0;i<col;i++) {
        if (matrix[0][i] == 0) {
            col_zero = true;
            break;
        }
    }
    // mark zero rows and cols
    for (int i=1;i<row;i++) {
        for (int j=1;j<col;j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // make matrix zeros starting from 2nd row and 2nd col
    for (int i=1;i<row;i++) {
        if (matrix[i][0] == 0) {
            fill(matrix[i].begin(), matrix[i].end(), 0);
        }
    }
    for (int i=1;i<col;i++) {
        if (matrix[0][i] == 0) {
            for (int j=1;j<row;j++)
                matrix[j][i] = 0;
        }
    }
    // make 1st row and 1st col zeros if necessary
    if (row_zero) {
        for (int j=0;j<row;j++)
            matrix[j][0] = 0;
    }
    if (col_zero)
        fill(matrix[0].begin(), matrix[0].end(), 0);
}