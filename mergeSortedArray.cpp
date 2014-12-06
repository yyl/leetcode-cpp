//
//  mergeSortedArray.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/3/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "mergeSortedArray.h"

void merge(int A[], int m, int B[], int n) {
    int AB[m+n];
    int a = 0;
    int b = 0;
    int i = 0;
    while (a<m && b<n) {
        if (A[a] < B[b]) {
            AB[i] = A[a];
            a++;
        } else {
            AB[i] = B[b];
            b++;
        }
        i++;
    }
    while (a<m) {
        AB[i] = A[a];
        a++;
        i++;
    }
    while (b<n) {
        AB[i] = B[b];
        b++;
        i++;
    }
    for (int k=0; k<m+n; k++) {
        A[k] = AB[k];
    }
}

void merge2(int A[], int m, int B[], int n) {
    int a = m-1;
    int b = n-1;
    int i = m+n-1;
    while (a>=0 && b>=0) {
        if (A[a] < B[b]) {
            A[i] = B[b];
            b--;
        } else {
            A[i] = A[a];
            a--;
        }
        i--;
    }
    while (b>=0) {
        A[i] = B[b];
        b--;
        i--;
    }
}