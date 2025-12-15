/*
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.
A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.
Return the number of smooth descent periods.
*/

#include <bits/stdc++.h>
using namespace std;

long long getDescentPeriods(vector<int>& prices) {
  int n=prices.size();
  int start=0,end=0;
  long long count=n;
  for (int i=1;i<n;i++) {
      if (prices[i]==prices[end]-1) {
          count+=(end-start+1);
          end=i;
      }
      else {
          start=i;
          end=i;
      }
  }
  return count;
}
