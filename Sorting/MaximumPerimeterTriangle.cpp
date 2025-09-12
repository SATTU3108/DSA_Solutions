#include <bits/stdc++.h>
using namespace std;

// Naive metihod -> Nested Loops
int findMaxPerimeter(vector<int> &arr) {
    int n=arr.size();
    int ans=-1;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                if (arr[i]+arr[j]>arr[k] && (arr[j]+arr[k]>arr[i]) && arr[k]+arr[i]>arr[j]) ans=max(ans,arr[i]+arr[j]+arr[k]);
            }
        }
    }
    return ans;
}
//time:O(n^3),space:O(1)

// Optimal Method -> Sorting
int findMAxPerimeter(vector<int> &arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end(),greater<int>());
    for (int i=0;i<n-2;i++) {
        if (arr[i]<arr[i+1]+arr[i+2]) return (arr[i]+arr[i+1]+arr[i+2]);
    }
    return -1;
}
//time:O(nlogn),space:O(1)