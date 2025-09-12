#include <bits/stdc++.h>
using namespace std;

// Naive Approach
double median(vector<int> &a,vector<int> &b) {
    int n1=a.size(),n2=b.size();
    vector<int> arr3;
    int i=0,j=0;
    while (i<n1 && j<n2) {
        if (a[i]<b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }
    while (i<n1) arr3.push_back(a[i++]);
    while (j<n2) arr3.push_back(b[j++]);
    int n=n1+n2;
    if (n%2!=0) {
        return (double)arr3[n/2];
    }
    double median=((double)arr3[n/2]+(double)arr3[(n/2)-1])/2.0;
    return median;
}
// Time complexity:O(n1+n2),Space complexity:O(n1+n2)

// Better Approach
double median(vector<int> &a,vector<int> &b) {
    int n1=a.size(),n2=b.size();
    int n=n1+n2;
    int ind2=n/2,ind1=ind2-1;
    int ind1_element=-1,ind2_element=-1;
    int count=0;
    int i=0,j=0;
    while (i<n1 && j<n2) {
        if (a[i]<b[j]) {
            if (count==ind1) ind1_element=a[i];
            if (count==ind2) ind2_element=a[i];
            count++;
            i++;
        }
        else {
            if (count==ind1) ind1_element=b[j];
            if (count==ind2) ind2_element=b[j];
            count++;
            j++;
        }
    }
    while (i<n1) {
        if (count==ind1) ind1_element=a[i];
        if (count==ind2) ind2_element=a[i];
        i++;
        count++;
    }
    while (j<n2) {
        if (count==ind1) ind1_element=b[j];
        if (count==ind2) ind2_element=b[j];
        count++;
        j++;
    }
    if (n%2!=0) return (double)ind2_element;
    return (double)((double)(ind1_element+ind2_element))/2.0;
}
// Time complexity:O(n1+n2),Space complexity:O(1)

// Optimal Approach -> Binary Search
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
    int len1=nums1.size(),len2=nums2.size();
    int left=0,right=len1;
    while (left<=right) {
        int part1=(left+right)/2;
        int part2=(len1+len2+1)/2-part1;
        int max_left1=(part1==0) ?INT_MIN:nums1[part1-1];
        int min_right1=(part1==len1) ?INT_MAX:nums1[part1];
        int max_left2=(part2==0) ?INT_MIN:nums2[part2-1];
        int min_right2=(part2==len2) ?INT_MAX:nums2[part2];
        if (max_left1<=min_right2 && max_left2<=min_right1) {
            if ((len1+len2)%2==0) {
                return (max(max_left1,max_left2)+min(min_right1,min_right2))/2.0;
            }
            else {
                return max(max_left1,max_left2);
            }
        }
        else if (max_left1>min_right2) right=part1-1;
        else left=part1+1;
    }
    return 0.0;
}