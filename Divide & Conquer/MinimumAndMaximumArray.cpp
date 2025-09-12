#include <bits/stdc++.h>
using namespace std;

/*Find the mimimum element and the maximum element in the array*/

// Method 1 -> Sorting (worst)

// Method 2 -> Linear Search (no. of comparisions are higher then method 3)

// Method 3 -> Divide and Conquer (comparing in pairs)
pair <int,int> getMinMax(vector<int> &arr) {
    int n=arr.size();
    int min_element,max_element;
    int i;
    if (n%2==0) {
        if (arr[0]>arr[1]) {
            max_element=arr[0];
            min_element=arr[1];
        }
        else {
            max_element=arr[1];
            min_element=arr[0];
        }
        i=2;
    }
    else {
        max_element=arr[0];
        min_element=arr[0];
        i=1;
    }
    while (i<n-1) {
        if (arr[i]>arr[i+1]) {
            if (arr[i]>max_element) max_element=arr[i];
            if (arr[i+1]<min_element) min_element=arr[i+1];
        }
        else {
            if (arr[i+1]>max_element) max_element=arr[i+1];
            if (arr[i]<min_element) min_element=arr[i];
        }
        i+=2;
    }
    return {min_element,max_element};
}