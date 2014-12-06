//
//  lengthofLastWord.cpp
//  leetcode
//
//  Created by Yulong Yang on 12/5/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "lengthofLastWord.h"
#include <string>
using namespace std;

int Solution::lengthOfLastWord(const char *s) {
    if (!s)
        return 0;
    // copy a the char sequence this char pointer pointing to into a string
    string str(s);
    int count=0;
    // const string
    const string space(" ");
    bool first_nonspace = false;
    for (int i=int(str.length())-1;i>=0;i--) {
        // str[i] returns a char pointer, therefore cannot do str[i]==" "
        if (!first_nonspace && str.compare(i, 1, space)==0)
            continue;
        if (str.compare(i, 1, space)!=0) {
            first_nonspace = true;
            count++;
        }
        if (first_nonspace && str.compare(i, 1, space)==0)
            return count;
    }
    return count;
}