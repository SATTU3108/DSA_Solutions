#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector <int> &arr,int target,int start,int end) {
    while (start<=end) {
        int mid=start+(end-start)/2;
        if (arr[mid]==target) return mid;
        if (arr[mid]>target) end=mid-1;
        else start=mid+1;
    }
    return -1;
}
int findPos(vector <int> &arr,int target) {
    int start=0,end=1;
    while (target>arr[end]) {
        int temp=end+1;
        end=end+(end-start+1)*2;
        start=temp;
    }
    return binarySearch(arr,target,start,end);
}
// Time complexity:O(log p), Space complexity:O(1)