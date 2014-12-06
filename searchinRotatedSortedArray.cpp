//
//  searchinRotatedSortedArray.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "searchinRotatedSortedArray.h"

int Solution::search(int A[], int n, int target) {
    int start = 0;
    int end = n-1;
    int mid = (start+end)/2;
    while (start<end) {
        if (A[mid] == target)
            return mid;
        // if array contains duplicates
//        if (A[mid]==A[start] && A[mid]==A[end]) {
//            start++;
//            continue;
//        }
        // normal: start < mid < end
        if (A[start]<=A[mid] && A[mid]<=A[end]) {
            if (A[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        // pivot in 1st half: mid < end < start
        else if (A[mid]<=A[end] && A[end]<=A[start]) {
            // in 2nd half
            if (A[mid]<target && target<=A[end])
                start = mid+1;
            else
                end = mid-1;
        }
        // pivot in 2nd half or in the middle: mid > start > end
        else if (A[mid]>=A[start] && A[start]>=A[end]) {
            // in 1st half
            if (A[start]<=target && target<A[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        mid = (start+end)/2;
    }
    if (A[start]==target)
        return start;
    return -1;
}
