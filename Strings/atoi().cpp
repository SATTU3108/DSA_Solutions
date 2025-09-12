#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, the task is to convert it into integer format without utilizing any built-in functions. 
*/

int myAtoi(string s) {
    int sign=1,res=0,idx=0;
    // ignore leading whitespaces
    while (s[idx]==' ') idx++;
    if (s[idx]=='-' || s[idx]=='+') {
        if (s[idx]=='-') sign=-1;
        idx++;
    }
    while (s[idx]>='0' && s[idx]<='9') {
        if (res>INT_MAX/10 || (res==INT_MAX/10 && s[idx]-'0'>7)) {
            if (sign==1) return INT_MAX;
            else return INT_MIN;
        }
        res=10*res+(s[idx]-'0');
        idx++;
    }
    return res*sign;
}