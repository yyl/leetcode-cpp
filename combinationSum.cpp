//
//  combinationSum.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "combinationSum.h"
using namespace std;

void getComb(vector<vector<int>> &result, vector<int> candidates, vector<int> cur_set, int cur_val, int target) {
    if (cur_val>target) return;
    else if (cur_val==target) result.push_back(cur_set);
    else {
        int cur_size = int(cur_set.size());
        vector<int>::iterator it;
        for (it=candidates.begin();it!=candidates.end();it++) {
            if (cur_set.empty() || *it >= cur_set[cur_size-1]) {
                cur_set.push_back(*it);
                getComb(result, candidates, cur_set, cur_val+*it, target);
                cur_set.pop_back();
            }
        }
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    getComb(result, candidates, vector<int>(), 0, target);
    return result;
}