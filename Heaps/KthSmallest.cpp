#include <bits/stdc++.h>
using namespace std;

// Naive Approach -> Sorting
int KthSmallest(int arr[],int n,int k) {
    sort(arr,arr+n);
    return arr[k-1];
}
//time:O(nlogn),space:O(k)

// Expected Approach -> Priority Queue
int KthSmallest(int arr[],int n,int k) {
    priority_queue<int> pq;
    for (int i=0;i<n;i++) {
        pq.push(arr[i]);
        if (pq.size()>k) pq.pop();
    }
    return pq.top();
}
//time:O(k+(n-k)*(logk)),space:O(k)

// Other Approach -> Counting Sort -> Not efficient for large range of elements
int KthSmallest(int arr[],int n,int k) {
    int max_element=arr[0];
    for (int i=1;i<n;i++) max_element=max(max_element,arr[i]);
    vector<int> freq(max_element+1,0);
    for (int i=0;i<n;i++) freq[arr[i]]++;
    int count=0;
    for (int i=0;i<=max_element;i++) {
        if (freq[i]!=0) {
            count+=freq[i];
            if (count>=k) return i;
        }
    }
    return -1;
}
//time:O(n+max),space:O(max)