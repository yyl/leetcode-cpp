//
//  NQueens.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "NQueens.h"
#include <vector>
#include <set>
using namespace std;

void Solution::posQueen(vector<int> &board, int i, int n) {
    if (i==n)
        result++;
    else {
        set<int> valid;
        for (int j=0;j<n;j++)
            valid.insert(j);
        for (int j=0;j<i;j++) {
            valid.erase(board[j]);
            if (board[j]+(i-j)<n)
                valid.erase(board[j]+(i-j));
            if (board[j]-(i-j)>=0)
                valid.erase(board[j]-(i-j));
        }
        set<int>::iterator it;
        for (it=valid.begin(); it!=valid.end(); it++) {
            board[i] = *it;
            posQueen(board, i+1, n);
        }
    }
};

// maintain remaining valid positions as 1 in a 1d vector
int Solution::totalNQueens(int n) {
    // initialize the board
    vector<int> board(n,-1);
    for (int i=0; i<n; i++) {
        board[0] = i;
        // here we pass-by-reference
        posQueen(board, 1, n);
    }
    return result;
};