#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[], where arr[i] represents the number of pages in the i-th book, and an integer k denoting the total number of students, allocate all books to the students such that:

Each student gets at least one book.
Books are allocated in a contiguous sequence.
The maximum number of pages assigned to any student is minimized.
If it is not possible to allocate all books among k students under these conditions, return -1.
*/

// Naive Approach -> iterate over all possible page limits
int countStudents(vector<int> &arr,int pages) {
    int n=arr.size(),students=1;
    long long pages_student=0;
    for (int i=0;i<n;i++) {
        if (pages_student+arr[i]<=pages) pages_student+=arr[i];
        else {
            students++;
            pages_student=0;
        }
    }
    return students;
}
int findPages(vector<int> &arr,int m) {
    if (m>arr.size()) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    for (int pages=low;pages<=high;pages++) {
        if (countStudents(arr,pages)==m) return pages;
    }
    return -1;
}