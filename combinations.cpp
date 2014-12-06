//
//  combinations.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/4/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "combinations.h"
using namespace std;

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> result;
    for (int i=1;i<=n;i++)
        result.push_back(vector<int>(1,i));
    for (int i=2;i<=k;i++) {
        vector<vector<int>> temp;
        for (int j=0;j<int(result.size());j++) {
            // push back larger value
            for (int k=result[j][i-2]+1;k<=n;k++) {
                // vector copy constructor
                vector<int> new_vec(result[j]);
                new_vec.push_back(k);
                temp.push_back(new_vec);
            }
        }
        // swap 2 vectors
        swap(result, temp);
    }
    return result;
};