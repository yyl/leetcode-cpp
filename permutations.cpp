//
//  permutations.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "permutations.h"
using namespace std;

void getPermutation(vector<vector<int>> &result, vector<int> &cur_str, int cur_index) {
    if (int(cur_str.size())==0)
        return;
    if (cur_index == int(cur_str.size())-1) {
        result.push_back(cur_str);
    } else {
        for (int i=cur_index; i<int(cur_str.size()); i++) {
            int temp = cur_str[i];
            cur_str[i] = cur_str[cur_index];
            cur_str[cur_index] = temp;
            getPermutation(result, cur_str, cur_index+1);
            // swap back
            if (i!=cur_index) {
                int temp2 = cur_str[i];
                cur_str[i] = cur_str[cur_index];
                cur_str[cur_index] = temp2;
            }
        }
    }
    
}

vector<vector<int>> permute(vector<int> &num){
    vector<vector<int>> result;
    getPermutation(result, num, 0);
    return result;
};