#include <bits/stdc++.h>
using namespace std;

/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/

vector<int> store;

// Approach 1 -> Sorting
void addNum(int num) {
    store.push_back(num);
}
double findMedian() {
    sort(store.begin(),store.end());
    int n=store.size();
    if (n%2!=0) return store[n/2];
    else return ((double)store[n/2]+store[n/2-1])*0.5;
}
//time:O(nlogn) for finding median,O(1) for adding number

// Approach 2 -> Insertion Sort
void addNum(int num) {
    if (store.empty()) store.push_back(num);
    else {
        auto idx=lower_bound(store.begin(),store.end(),num);
        store.insert(idx,num);
    }
}
double findMedian() {
    int n=store.size();
    if (n%2!=0) return store[n/2];
    else return ((double)store[n/2]+store[n/2-1])*0.5;
}
//time:O(1) for finding median,O(nlogn) for adding number

// Approach 3 -> Heap
priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int>> minHeap;
void addNum(int num) {
    if (maxHeap.empty() || num<=maxHeap.top()) maxHeap.push(num);
    else minHeap.push(num);
    if (maxHeap.size()>minHeap.size()+1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size()>maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}
double findMedian() {
    if (maxHeap.size()>minHeap.size()) return maxHeap.top();
    else return (maxHeap.top()+minHeap.top())*0.5;
}