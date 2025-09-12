#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[],int n) {
    int max_element=arr[0];
    for (int i=0;i<n;i++) {
        if (max_element<arr[i]) max_element=arr[i];
    }
    return max_element;
}
void radixHelper(int arr[],int n,int place) {
    const int base=10;
    int output[n];
    int count[10]={0};
    for (int i=0;i<n;i++) {
        int digit=(arr[i]/place)%base;
        count[digit]++;
    }
    for (int i=1;i<base;i++) count[i]+=count[i-1];
    for (int i=n-1;i>=0;i--) {
        int digit=(arr[i]/place)%base;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }
    for (int i=0;i<n;i++) arr[i]=output[i];
}
void radixSort(int arr[], int n) {
    int max_val=getMax(arr,n);
    for (int place=1;(max_val/place)>0;place*=10) {
        radixHelper(arr,n,place);
    }
}
//time:O(n+b),space:O(1)