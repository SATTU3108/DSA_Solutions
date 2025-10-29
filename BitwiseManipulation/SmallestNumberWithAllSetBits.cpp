/*
You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits
*/

#include <bits/stdc++.h>
using namespace std;

int smallestNumber(int n) {
  // our objective is to increase the number to 2^power-1
  while ((n&(n+1))!=0) { 
      n|=n+1; // this sets the rightmost unset bit
  }
  return n;
}
