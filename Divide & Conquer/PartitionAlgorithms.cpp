#include <bits/stdc++.h>
using namespace std;

// Naive Partition Algorithm
void parition(vector <int> &arr) {
    int n=arr.size();
    // Consider the last element as the pivot
    int pivot=arr[n-1];
    vector <int> temp(n);
    int idx=0;
    for (int i=0;i<n;i++) {
        if (arr[i]<pivot) {
            temp[idx]=arr[i];
            idx++;
        }
    }
    temp[idx]=pivot;
    for (int i=0;i<n;i++) {
        if (arr[i]>pivot) {
            temp[idx]=arr[i];
            idx++;
        }
    }
    arr=temp;
}
// Time complexity:O(n),Space complexity:O(n)

// Lomuto Partition Algorithm
void partition(vector <int> &arr) {
    int n=arr.size();
    int pivot=arr[n-1];
    int i=-1;
    for (int j=0;j<n;j++) {
        if (arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[n-1]);
}
// Time complexity:O(n),Space complexity:O(1)

// Hoare Parition Algorithm
void partition(vector <int> &arr) {
    int n=arr.size();
    int pivot=arr[0];
    int i=-1,j=n;
    while (true) {
        do {
            i++;
        } while (arr[i]<pivot);
        do {
            j--;
        } while (arr[j]>pivot);
        if (i>j) break;
        swap(arr[i],arr[j]);
    }
}
// Time complexity:O(n),Space complexity:O(1)