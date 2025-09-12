#include <bits/stdc++.h>
using namespace std;

/*
Given two strings denoting non-negative numbers s1 and s2. Calculate the sum of s1 and s2.
*/

string findSum(string &s1, string &s2) {
    if (s1.empty()) return s2;
    if (s2.empty()) return s1;
    string res="";
    int i=s1.length()-1,j=s2.length()-1; // traverse from the right end of both the strings, simulate the addition process
    int carry=0;
    while (i>=0 || j>=0 || carry>0) {
        // only if indices are within the string boundaries, consider that digit, else it will be consdered at 0 only
        int digit1=(i>=0) ? (s1[i]-'0') : 0; 
        int digit2=(j>=0) ? (s2[j]-'0') : 0;
        int sum=digit1+digit2+carry;
        carry=sum/10;
        sum%=10;
        res+='0'+sum; // note that although, we are traversing from right, we are pushing from the beginning only, in the final result -> we need to reverse in the end
        i--;
        j--;
    }
    while (res.size()>1 && res[res.size()-1]=='0') res.pop_back(); // remove the leading zeros (they exist at the end in the reversed string)
    reverse(res.begin(),res.end());
    return res;
}