#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int n=arr.size();
    int count=0,ans=0;
    int i=0,j=0;
    while (i<n && j<n) {
        if (arr[i]<=dep[j]) {
            count++;
            i++;
        }
        else {
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return ans;
}