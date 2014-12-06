//
//  NQueens.h
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#ifndef __leetcode__NQueens__
#define __leetcode__NQueens__

#include <stdio.h>
#include <vector>

class Solution {
private:
    int result;
public:
    int totalNQueens(int n);
    void posQueen(std::vector<int> &board, int i, int n);
};

#endif /* defined(__leetcode__NQueens__) */
