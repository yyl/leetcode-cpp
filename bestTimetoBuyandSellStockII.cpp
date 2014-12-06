//
//  bestTimetoBuyandSellStockII.cpp
//  leetcode
//
//  Created by Yulong Yang on 11/28/14.
//  Copyright (c) 2014 Yulong. All rights reserved.
//

#include "bestTimetoBuyandSellStockII.h"
using namespace std;

int Solution::maxProfitII(vector<int> &prices) {
    // empty(): see if the vector is empty
    // size(): get the size of the vector (different from capacity)
    if (prices.empty() || prices.size() < 2)
        return 0;
    int total_profit = 0;
    for (int i=1; i<prices.size(); i++) {
        if (prices[i] > prices[i-1]) {
            total_profit += prices[i] - prices[i-1];
        }
    }
    return total_profit;
};

int Solution::maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int minp = 0;
    int maxp = 0;
    for (int i=1; i<prices.size(); i++) {
        if (prices[i] - prices[minp] > max_profit && i > minp) {
            max_profit = prices[i] - prices[minp];
            maxp = i;
        } else if (prices[i] < prices[minp]) {
            minp = i;
        }
    }
    return max_profit;
};