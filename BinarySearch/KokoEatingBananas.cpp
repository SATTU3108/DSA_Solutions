#include <bits/stdc++.h>
using namespace std;

/*
A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
*/

// Naive Method
int minimumRateToEatBananas(vector<int> &arr,int h) {
    int n=arr.size();
    int maxi=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>maxi) maxi=arr[i];
    }
    for (int k=1;k<=maxi;k++) {
        int total_hours=0;
        for (int i=0;i<n;i++) {
            total_hours+=ceil((double)arr[i]/(double)k);
        }
        if (total_hours<=h) return k;
    }
}
//time:O(n*max),space:O(1)

// Binary Search
int minimumRateToEatBananas(vector<int> &arr,int h) {
    int n=arr.size();
    int maxi=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>maxi) maxi=arr[i];
    }
    int low=1,high=maxi;
    int ans;
    while (low<=high) {
        int mid=low+(high-low)/2;
        int total_hours=0;
        for (int i=0;i<n;i++) {
            total_hours+=ceil((double)arr[i]/(double)mid);
            if (total_hours<=h) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
    }
    return ans;
}