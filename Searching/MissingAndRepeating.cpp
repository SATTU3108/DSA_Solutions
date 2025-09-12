#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b.

Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n].
*/

// XOR Approach-Time complexity:O(N),Space complexity:O(1)
vector<int> findTwoElement(vector<int>& arr) {
    int n=arr.size();
    int xor_result=0;
    for (int i=0;i<n;i++) {
        xor_result^=arr[i];
        xor_result^=(i+1);
    }
    int right_most_set_bit=xor_result&(~(xor_result- 1));
    int x=0,y=0;
    for (int i=0;i<n;i++) {
        if (arr[i] & right_most_set_bit) x^=arr[i];
        else y ^= arr[i];
        if ((i+1) & right_most_set_bit) x^=(i+1);
        else y^=(i+1);
    }
    int duplicate=0,missing=0;
    for (int i=0;i<n;i++) {
        if (arr[i]==x) {
            duplicate=x;
            missing=y;
            break;
        } 
        else if (arr[i]==y) {
            duplicate=y;
            missing=x;
            break;
        }
    }
    return {duplicate,missing};
}

//Array Marking - Time complexity:O(N),Space complexity:O(1)
vector<int> findTwoElement(vector<int>& arr) {
    int n=arr.size();
    int repeating=-1;
    for (int i=0;i<n;i++) {
        int index=abs(arr[i])-1;
        if (arr[index]>0) arr[index]=-arr[index];
        else {
            repeating=index+1;
        }
    }
    int missing=-1;
    for (int i=0;i<n;i++) {
        if (arr[i]>0) {
            missing=i+1;
            break;
        }
    }
    return {repeating,missing};
}