#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array of rational numbers, where each rational number is represented in the form p/q (where p is the numerator and q is the denominator), the task is to find the index of a given rational number x in the array. If the number does not exist in the array, return -1.
*/

class Rational {
    public:
    int p,q;
    Rational(int num,int den) {
        p=num;
        q=den;
    }
};

int compare(Rational a,Rational b) {
    if ((a.p*b.q)==(b.p*a.q)) return 0;
    else if ((a.p*b.q)>(b.p*a.q)) return 1;
    else return -1;
}

int binarySearch(vector<Rational> &arr,Rational &x) {
    int low=0,high=arr.size()-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (compare(arr[mid],x)==0) return mid;
        else if (compare(arr[mid],x)>0) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
// Time complexity:O(logN),Aux. space:O(1)