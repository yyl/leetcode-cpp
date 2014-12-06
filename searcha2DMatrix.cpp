//
//  searcha2DMatrix.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "searcha2DMatrix.h"
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.empty())
        return false;
    int row = int(matrix.size());
    int col = int(matrix[0].size());
    // search rows
    int start = 0;
    int end = row-1;
    int mid = (start + end)/2;
    while (start<end) {
        if (matrix[mid][0] == target || matrix[mid][col-1] == target)
            return true;
        if (start == mid || mid == end)
            break;
        if (matrix[mid][0] < target && matrix[mid][col-1] > target)
            break;
        if (matrix[mid][col-1] < target)
            start = mid;
        if (matrix[mid][0] > target)
            end = mid;
        mid = (start + end)/2;
    }
    if (matrix[row-1][0] == target || matrix[row-1][col-1] == target)
        return true;
    if (matrix[row-1][0] < target && matrix[row-1][col-1] > target)
        mid = row-1;
    if ((mid == 0 && target < matrix[mid][0]) ||
        (mid == row-1 && target > matrix[mid][col-1])) {
        return false;
    }
    // search cols
    start = 0;
    end = col-1;
    int mid2 = (start + end)/2;
    while (start<end) {
        if (matrix[mid][mid2] == target)
            return true;
        if (start == mid2 || mid2 == end)
            break;
        if (matrix[mid][mid2] < target)
            start = mid2;
        if (matrix[mid][mid2] > target)
            end = mid2;
        mid2 = (start + end)/2;
    }
    if (matrix[mid][mid2] == target || matrix[mid][col-1] == target)
        return true;
    return false;
};