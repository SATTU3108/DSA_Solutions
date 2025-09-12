#include <bits/stdc++.h>
using namespace std;

/*
Given two arrays, arr[] and dep[], that represent the arrival and departure times of trains respectively, the task is to find the minimum number of platforms required so that no train waits.
*/

// Naive Approach -> 2 loops
int minPlatforms(vector<int> &arr,vector<int> &dep) {
    int n=arr.size();
    int res=0;
    for (int i=0;i<n;i++) {
        int count=1;
        for (int j=0;j<n;j++) {
            if (j!=i) {
                if ((arr[i]>=arr[j] && arr[i]<=dep[j]) || (arr[j]>=arr[i] &&arr[j]<=dep[i])) count++;
            } 
        }
        res=max(res,count);
    }
    return res;
}
//time:O(n^2),space:O(1)

// Sorting + 2 Pointer
int minPlatforms(vector<int> &arr,vector<int> &dep) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int count=0,res=0,i=0,j=0;
    while (i<n && j<n) {
        if (arr[i]<=dep[j]) {
            count++;
            i++;
        }
        else {
            count--;
            j++;
        }
        res=max(res,count);
    }
    return res;
} 
//time:O(nlogn),space:O(1)