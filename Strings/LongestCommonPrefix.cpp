#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strings arr[], the task is to return the longest common prefix among each and every strings present in the array. If there’s no prefix common in all the strings, return “”.
*/

string longestCommonPrefix(vector<string> &arr) {
    sort(arr.begin(),arr.end());
    string first=arr[0];
    string last=arr[arr.size()-1];
    int min_length=min(first.size(),last.size());
    int i=0;
    while (i<min_length && first[i]==last[i]) i++;
    return first.substr(0,i);
}
//time:O(n*m*logn) -> n is number of strings, m is length of longest string
//space:O(m)