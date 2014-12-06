//
//  SingleNumber.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/27/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "SingleNumber.h"
#include <unordered_map>
using namespace std;

Solution::Solution() {
    
}

int Solution::singleNumber(int A[], int n){
    int result = 0;
    for (int i=0; i<n ;i++) {
        // exclusive or operation
        result ^= A[i];
    }
    return result;
}

int Solution::singleNumber2(int A[], int n) {
    // implementation of hash table in c++
    unordered_map<int, int> hashtable;
    for (int i=0; i<n ;i++) {
        // one way to check if a specific key exists
        if (hashtable.find(A[i]) == hashtable.end())
            // create and insert a key value pair
            hashtable.emplace(A[i], 1);
        else
            hashtable[A[i]]++;
    }
    for (int i=0; i<n ;i++) {
        // another way to search the key
        if (hashtable.count(A[i]) == 1)
            return A[i];
    }
    return 0;
};