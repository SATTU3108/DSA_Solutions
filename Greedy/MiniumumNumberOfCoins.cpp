#include <bits/stdc++.h>
using namespace std;

int findMin(int W,vector <int> denomination) {
    int count=0;
    for (int i=denomination.size()-1;i>=0;i--) {
        while (W>=denomination[i]) {
            W-=denomination[i];
            count++;
        }
    }
    return count;
}