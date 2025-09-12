#include <bits/stdc++.h>
using namespace std;

// Naive aproach -> Sorting
int getSecondLargest(vector <int> &arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for (int i=n-2;i>=0;i--) {
        if (arr[i]!=arr[n-1]) return arr[i];
    }
    return -1;
}
// Time Complexity:O(nlogn),Space complexity:O(1)

// Better approach -> Two Pass Search
int getSecondLargest(vector<int> &arr) {
    int n=arr.size();
    int largest=-1,secondLargest=-1;
    for (int i=0;i<n;i++) {
        if (arr[i]>largest) largest=arr[i];
    }
    for (int i=0;i<n;i++) {
        if (arr[i]>secondLargest && arr[i]!=largest) secondLargest=arr[i];
    }
    return secondLargest;
}
// Time complexity:O(N),Space complexity:O(1)

// Optimal approach -> One Pass Search
int getSecondLargest(vector <int> &arr) {
    int n=arr.size();
    int largest=-1,secondLargest=-1;
    for (int i=0;i<n;i++) {
        if (arr[i]>largest) {
            secondLargest=largest;
            largest=arr[i];
        }
        else if (arr[i]<largest && arr[i]>secondLargest) secondLargest=arr[i];
    }
    return secondLargest;
}
