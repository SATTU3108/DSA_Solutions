/*
N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.

Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.

You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.
*/

#include <bits/stdc++.h>
using namespace std;

int bulbs(vector<int> &A) {
    int presses=0,flip=0;
    // presses: total number of presses of switch
    // flip: determines if future bulbs are toggled or not; if we flip it even number of times, the output remains the same but if flip is odd, the state of future bulbs is toggled
    for (int i=0;i<A.size();i++) {
        int effective=A[i]^(flip%2); // if only one of them is 1, the state of that bulb is ON
        if (effective==0) {
            presses++;
            flip++;
        }
    }
    return presses;
}
//time:O(n),space:O(1)
