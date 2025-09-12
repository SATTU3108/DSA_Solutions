#include <bits/stdc++.h>
using namespace std;

/*
Given an array of N integers and Q queries, print the number of next greater elements to the right of the given index element. 
*/

// Naive Approach -> Iterate for every query from index to end and fund out the number of next greater elements to right
int nextGreaterElements(vector<int> &a,int index) {
    int n=a.size();
    int count=0;
    for (int i=index+1;i<n;i++) {
        if (a[i]>a[index]) count++;
    }
    return count;
}

void merge(vector<pair<int,int>> &vec,vector<int> &ans,int low,int mid,int high) {
    int n1=mid-low+1,n2=high-mid;
    vector<pair<int,int>> arr(n1);
    vector<pair<int,int>> brr(n2);
    for (int i=0;i<n1;i++) arr[i]=vec[i+low];
    for (int i=0;i<n2;i++) brr[i]=vec[i+mid+1];
    int i=0,j=0,k=low;
    while (i<n1 && j<n2) {
        if (arr[i].first<brr[j].first) {
            ans[arr[i].second]+=n2-j;
            vec[k]=arr[i];
            i++;
            k++;
        }
        else {
            vec[k]=brr[j];
            j++;
            k++;
        }
    }
    while (i<n1) {
        vec[k]=arr[i];
        i++;
        k++;
    }
    while (j<n2) {
        vec[k]=brr[j];
        j++;
        k++;
    }
}
void mergesort(vector<pair<int,int>> &vec,vector<int> &ans,int low,int high) {
    int mid;
    if (low<high) {
        mid=low+(high-low)/2;
        mergesort(vec,ans,low,mid);
        mergesort(vec,ans,mid+1,high);
        merge(vec,ans,low,mid,high);
    }
}
void nextGreaterElements(int n,vector<int> &nums, int queries,vector<int> &indices) {
    vector<pair<int,int>> vec;
    for (int i=0;i<n;i++) {
        vec.push_back({nums[i],i});
    }
    vector<int> ans(n,0);
    mergesort(vec,ans,0,n-1);
    for (int i=0;i<queries;i++) {
        int j=indices[i];
        cout<<ans[j]<<" ";
    }
}