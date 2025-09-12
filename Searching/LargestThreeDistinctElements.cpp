#include <bits/stdc++.h>
using namespace std;

/*
You are given an array arr[], you need to find the top three largest distinct integers present in the array and return an array of size three in descending order.

Note: If there are less than three distinct elements in the array, then return the available distinct numbers in descending order.
*/

vector<int> getThreeLargest(vector<int>& arr) {
    int n=arr.size();
    int first=INT_MIN,second=INT_MIN,third=INT_MIN;
    for (int i=0;i<n;i++) {
        if (arr[i]>first) {
            third=second;
            second=first;
            first=arr[i];
        }
        else if (arr[i]>second && arr[i]!=first) {
            third=second;
            second=arr[i];
        }
        else if (arr[i]>third && arr[i]!=second && arr[i]!=first) {
            third=arr[i];
        }
    }
    vector <int> res={};
    if (first==INT_MIN) return res;
    res.push_back(first);
    if (second==INT_MIN) return res;
    res.push_back(second);
    if (third==INT_MIN) return res;
    res.push_back(third);
    return res;
}