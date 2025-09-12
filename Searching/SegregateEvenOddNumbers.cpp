#include <bits/stdc++.h>
using namespace std;

/*Order of numbers should be first even numbers, then odd numbers*/

void segregateEvenOdd(vector<int> &arr) {
    int n=arr.size();
    int low=0,high=n-1;
    while (low<=high) {
        if (arr[low]%2!=0) {
            if (arr[high]%2==0) {
                swap(arr[low],arr[high]);
                low++;
                high--;
            }
            else high--;
        }
        else low++;
    }
} 