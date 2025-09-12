#include <bits/stdc++.h>
using namespace std;

// Ascending Order Heap-sort
void heapify(vector<int> &arr,int n,int i) {
    int largest=i;
    int l=2*i+1,r=2*i+2; // left=2i+1,right=2i+2
    // if left child is larger than root
    if (l<n && arr[l]>arr[largest]) largest=l;
    // if right child is larger than largest so far
    if (r<n && arr[r]>arr[largest]) largest=r;
    // if largest is not root
    if (largest!=i) {
        swap(arr[i],arr[largest]);
        // recursivdly heapify the affected subtree
        heapify(arr,n,largest);
    }
}
void heapSort(vector<int> &arr) {
    int n=arr.size();
    // build heap (rearrange array)
    for (int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    // one by one extract an element from heap
    for (int i=n-1;i>0;i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

// Descending Order Heap-sort
void heapify(vector<int> &arr,int n,int i) {
    int smallest=i;
    int left=2*i+1,right=2*i+2;
    if (left<n && arr[left]<arr[smallest]) smallest=left;
    if (right<n && arr[right]<arr[smallest]) smallest=right;
    if (smallest!=i) {
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}
void heapSort(vector<int> &arr) {
    int n=arr.size();
    for (int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for (int i=n-1;i>=0;i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    } 
}
