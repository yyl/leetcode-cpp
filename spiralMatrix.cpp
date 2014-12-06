//
//  spiralMatrix.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "spiralMatrix.h"
using namespace std;

// another idea is to consider n*n matrix, and keep going on one direction until hitting the end
vector<vector<int> > Solution::generateMatrixII(int n) {
    vector<vector<int>> matrix(n,vector<int>(n,0));
    if (n==0)
        return matrix;
    // old way to initialize 2d vector
//    for (int i=0;i<n;i++)
//        matrix.push_back(vector<int>());
//    for (int i=0;i<n;i++) {
//        for (int j=0;j<n;j++) {
//            matrix[i].push_back(0);
//        }
//    }
    matrix[0][0] = 1;
    if (n==1)
        return matrix;
    // direction: right(0), down(1), left(2), up(3)
    int direction = 0;
    int row = 0;
    int col = 0;
    int val = 2;
    for (int i=n-1;i>0;i--) {
        int j = 2;
        if (i==n-1)
            j++;
        while (j>0) {
            switch(direction) {
                    // right
                case 0: {
                    for(int k=0;k<i;k++) {
                        matrix[row][col+1+k] = val;
                        val++;
                    }
                    col += i;
                    direction = 1;
                    break;
                }
                    // down
                case 1: {
                    for(int k=0;k<i;k++) {
                        matrix[row+k+1][col] = val;
                        val++;
                    }
                    row += i;
                    direction = 2;
                    break;
                }
                    // left
                case 2: {
                    for(int k=0;k<i;k++) {
                        matrix[row][col-1-k] = val;
                        val++;
                    }
                    col -= i;
                    direction = 3;
                    break;
                }
                    // up
                case 3: {
                    for(int k=0;k<i;k++) {
                        matrix[row-1-k][col] = val;
                        val++;
                    }
                    row -= i;
                    direction = 0;
                    break;
                }
            }
            j--;
        }
    }
    return matrix;
}
