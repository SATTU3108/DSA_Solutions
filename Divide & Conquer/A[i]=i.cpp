#include <bits/stdc++.h>
using namespace std;

/*Given sorted array with all elements distinct, find index i such that X[i]=i*/

int pos(vector <int> X) {
    int low=0,high=X.size()-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if ((X[mid]-mid)==0) return mid;
        else if (X[mid]-mid<0) low=mid+1;
        else high=mid-1;
    }
    return -1;
}