#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers arr[]. You need to find the count of the special numbers in arr[].
A number is said to be a special number if it is divisible by atleast one other element of arr[]. 
*/

int cntSpecialNum(vector<int>& arr) {
    int maxVal=*max_element(arr.begin(),arr.end());
    vector<int> freq(maxVal+1,0);
    for (int num:arr) freq[num]++;
    vector<bool> isSpecial(maxVal+1,false);
    for (int i=1;i<=maxVal;i++) {
        if (freq[i]==0) continue;
        for (int j=2*i;j<= maxVal;j+=i) {
            if (freq[j]>0) isSpecial[j] = true;
        }
    }
    int count=0;
    for (int num:arr) {
        if (isSpecial[num] || freq[num]>1) count++;
    }
    return count;
}