#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> &arr) {
    int n=arr.size();
    vector<int> left(n),right(n);
    stack<int> st;
    // Previous smaller
    for (int i=0;i<n;i++) {
        while (!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if (!st.empty()) left[i]=st.top();
        else left[i]=-1;
        st.push(i);
    }
    // Next smaller
    while (!st.empty()) st.pop(); // clear the stack
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if (!st.empty()) right[i]=st.top();
        else right[i]=n;
        st.push(i);
    }
    int max_area=0;
    for (int i=0;i<n;i++) {
        int width=right[i]-left[i]-1;
        max_area=max(max_area,arr[i]*width);
    }
    return max_area;
}
int maximalRectangle(vector<vector<int>> &matrix) {
    if (matrix.empty()) return 0;
    int rows=matrix.size(),cols=matrix[0].size();
    vector<int> height(cols,0);
    int max_area=0;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (matrix[i][j]==0) height[j]=0;
            else height[j]++;
        }
        max_area=max(max_area,getMaxArea(height));
    }
    return max_area;
}