#include <bits/stdc++.h>
using namespace std;

/*
Generate all strings of n bits
*/

void generateBinaryStrings(int n,string current) {
    if (current.length()==n) {
        cout<<current<<endl;
        return;
    }
    generateBinaryStrings(n,current+'0');
    generateBinaryStrings(n,current+'1');
}
//time:O(n*2^n),space:O(n)

// Iterative Approach - Bit Manipulation
void generateBinaryStrings(int n) {
    int total=(1<<n);
    for (int i=0;i<total;i++) { // i goes from 0 to 2^n-1; each value of i represents one binary string in its binary represenation
        for (int j=n-1;j>=0;j--) { // j goes from n-1 to 0 (to print bits from MSB to LSB)
            cout<<((i>>j)&1);
        }
        cout<<endl;
    }
}
//time:O(n*2^n),space:O(1)