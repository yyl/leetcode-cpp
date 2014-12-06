//
//  subsets.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "subsets.h"
using namespace std;

vector<vector<int>> Solution::combine(vector<int> &input, int k) {
    vector<vector<int>> result;
    int n = int(input.size());
    for (int i=0;i<n;i++)
        result.push_back(vector<int>(1,i));
    for (int i=1;i<k;i++) {
        vector<vector<int>> temp;
        for (int j=0;j<int(result.size());j++) {
            // push back larger value
            for (int g=result[j][i-1]+1;g<n;g++) {
                // vector copy constructor
                vector<int> new_vec(result[j]);
                new_vec.push_back(g);
                temp.push_back(new_vec);
            }
        }
        // swap 2 vectors
        swap(result, temp);
    }
    for (int i=0;i<int(result.size());i++) {
        for (int j=0;j<int(result[0].size());j++) {
            result[i][j] = input[result[i][j]];
        }
    }
    return result;
}

vector<vector<int>> Solution::subsets(vector<int> &S) {
    // sort vector
    sort(S.begin(), S.end());
    vector<vector<int>> result;
    result.push_back(vector<int>());
    int size = int(S.size());
    for (int i=1;i<size;i++) {
        vector<vector<int>> temp = combine(S, i);
        // extend a vector with another
        result.reserve(result.size() + distance(temp.begin(), temp.end()));
        result.insert(result.end(), temp.begin(), temp.end());
    }
    result.push_back(S);
    return result;
}