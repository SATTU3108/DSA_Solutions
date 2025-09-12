#include <bits/stdc++.h>
using namespace std;

/*
A string is a valid parentheses string (denoted VPS ) if is meets any one of the following:

It is an empty string "", or a single character not equals to " ( "  or  " ) " ,
It can be written as AB (A concatenated with B ),
where A and B are VPS's , or
It can be written as (A) , where A is a VPS.
We can similarly define the nesting depth depth (S) of any VPS S as follows:

depth ("") = 0
depth (C) = 0, where C is a string with a single character excluding "(" and ")" ,
depth (A + B) = max (depth (A) , depth (B)) , where A and B are VPS's.
depth ( "(" + A + ")" ) = 1 + depth (A) , where A is a VPS.
For example , "" , " ( ) ( ) " , and " ( ) ( ( ) ( ) ) " and VPS's (with nesting depths 0 , 1, and 2), and " ) ( " and " ( ( ) "   are not VPS's.


Given a VPS represented as string S , return the nesting depth of S.
*/

int maxDepth(string s) {
    int current_max=0,max=0;
    int n=s.length();
    for (int i=0;i<n;i++) {
        if (s[i]=='(') {
            current_max++;
            if (current_max>max) max=current_max;
        }
        else if (s[i]==')') {
            if (current_max>0) current_max--;
            else return -1;
        }
    }
    if (current_max!=0) return -1;
    return max;
}