#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr[], sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. If the frequencies of two elements are the same, then the smaller number comes first.
*/

static bool compare(const pair<int,int> p1,const pair<int,int> p2) {
    if (p1.second==p2.second) return p1.first<p2.first;
    return (p1.second>p2.second);
}
vector<int> sortByFreq(vector<int>& arr) {
    int n=arr.size();
    unordered_map<int,int> mp;
    for (int i=0;i<n;i++) mp[arr[i]]++;
    vector<pair<int,int>> p;
    for (auto element:mp) p.push_back({element.first,element.second});
    sort(p.begin(),p.end(),compare);
    vector<int> ans;
    for (int i=0;i<p.size();i++) {
        while (p[i].second!=0) {
            ans.push_back(p[i].first);
            p[i].second--;
        }
    }
    return ans;
}