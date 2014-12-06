//
//  searchforaRange.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/6/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "searchforaRange.h"
using namespace std;

vector<int> Solution::searchRange(int A[], int n, int target) {
    vector<int> range;
    double lower = double(target) - 0.5;
    double upper = double(target) + 0.5;
    int start = 0;
    int end = n-1;
    int mid = (start + end)/2;
    while (mid!=end && mid!=start) {
        if (A[mid] > lower) end = mid;
        if (A[mid] < lower) start = mid;
        mid = (start+end)/2;
    }
    if (A[mid] == target) range.push_back(mid);
    else if (mid<n-1 && A[mid+1] == target) range.push_back(mid+1);
    else {
        range.push_back(-1);
        range.push_back(-1);
        return range;
    }
    start = 0;
    end = n-1;
    // make the mid so that it will equal to end eventually
    mid = (1 + start + end)/2;
    while (mid!=end && mid!=start) {
        if (A[mid] > upper) end = mid;
        if (A[mid] < upper) start = mid;
        mid = (1 + start + end)/2;
    }
    if (A[mid] == target) range.push_back(mid);
    else if (mid>0 && A[mid-1] == target) range.push_back(mid-1);
    return range;
}