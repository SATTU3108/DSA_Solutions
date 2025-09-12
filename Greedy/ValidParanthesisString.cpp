#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int open=0,stars=0; //open bracket and stars count
    //Left to right:Treat * as (
    for (char c:s) {
        if (c=='(') open++;
        else if (c=='*') stars++;
        else {
            if (open>0) open--;
            else if (stars>0) stars--;
            else return false;
        }
    }
    //Right to Left: Treat * as )
    open=0,stars=0;
    for (int i=s.length()-1;i>=0;i--) {
        if (s[i]==')') open++;
        else if (s[i]=='*') stars++;
        else {
            if (open>0) open--;
            else if (stars>0) stars--;
            else return false;
        }
    }
    return true;
}