//
//  romanInteger.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/30/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "romanInteger.h"
#include <unordered_map>
#include <vector>
using namespace std;

//TODO: after unordered map and iterator
int Solution::romanToInt(string s) {
    // initialize a map given a list
    unordered_map<string, int> roman_dict = { {"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000} };
    // a unordered map of string as key and vector as value
    unordered_map<string, vector<string>> special_dict = { {"I",{"V","X"}}, {"X",{"L","C"}}, {"C", {"D","M"}}};
    int result = 0;
    for (int i=0;i<s.length();i++) {
        // need to convert s[i] to string class, as it is originally char class
        string cur_str = string(1, s[i]);
        int val = roman_dict[cur_str];
        // count() to find a specific key in a unordered map
        if (special_dict.count(cur_str)==1){
            vector<string> cur_vec = special_dict[cur_str];
            string next_str = string(1, s[i+1]);
            // find() to find a specfic element in a vector
            if (i<s.length()-1 && find(cur_vec.begin(), cur_vec.end(), next_str)!=cur_vec.end()) {
                val = 0 - val;
            }
        }
        result += val;
    }
    return result;
};