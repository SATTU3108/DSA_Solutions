/*
N children are standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum number of candies you must give?
*/

#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &A) {
    int n=A.size();
    // left to right traversal
    vector<int> candies(n,1);
    for (int i=1;i<n;i++) {
        if (A[i]>A[i-1]) candies[i]=candies[i-1]+1;
    }
    // right to left traversal
    for (int i=n-2;i>=0;i--) {
        if (A[i]>A[i+1]) candies[i]=max(candies[i],candies[i+1]+1);
    }
    int total=0;
    for (int i=0;i<n;i++) {
        total+=candies[i];
    }
    return total;
}
//time:O(n)->2 traversals,space:O(n)
