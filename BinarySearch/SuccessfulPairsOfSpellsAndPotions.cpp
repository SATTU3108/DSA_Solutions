#include <bits/stdc++.h>
using namespace std;

// find the first index in potions where potions[index]>=target
int index(vector<int> &potions,long long target) {
    int m=potions.size();
    int low=0,high=m-1;
    int ans=m; // default to m, if not found
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (potions[mid]>=target) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
}
vector<int> successfulPairs(vector<int> &spells,vector<int> &potions, long long success) {
    int n=spells.size(),m=potions.size();
    // sort potions to enable binary search
    sort(potions.begin(),potions.end());
    vector<int> ans(n);
    for (int i=0;i<n;i++) {
        // calculate minimum potions value needed for a successful pair and then use binary search to find the first index of a potion whose value is greater or equal to this target
        long long target;
        if ((success%spells[i])==0) target=success/spells[i];
        else target=success/spells[i]+1;
        // no. of successful pairs for this spell=no. of potions from idx to end
        ans[i]=m-index(potions,target);
    }
    return ans;
}
