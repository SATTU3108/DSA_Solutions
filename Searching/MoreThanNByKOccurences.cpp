#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr and an element k. The task is to find the count of elements in the array that appear more than n/k times and n is length of arr.
*/

// Method 1 -> Moore's Voting Algorithm (suitable for small values of k)
int countOccurence(vector<int>& arr, int k) {
    int n=arr.size();
    vector<pair<int,int>> candidates(k-1,{-1,0});
    for (int num:arr) {
        bool found=false;
        for (auto &candidate:candidates) {
            if (candidate.first==num) {
                candidate.second++;
                found=true;
                break;
            }
        }
        if (!found) {
            bool placed=false;
            for (auto &candidate:candidates) {
                if (candidate.second==0) {
                    candidate={num,1};
                    placed=true;
                    break;
                }
            }
            if (!placed) {
                for (auto &candidate:candidates) candidate.second--;
            }
        }
    }
    set <int> st;
    for (auto &candidate:candidates) {
        int count=0;
        for (int num:arr) {
            if (num==candidate.first) count++;
            if (count>n/k) st.insert(candidate.first);
        }
    }
    return st.size();
}
// Time complexity:O(N*k),Space complexity:O(k)

// Method 2- Maps
