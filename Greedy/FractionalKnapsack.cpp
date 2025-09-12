#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    bool static compare(Item a,Item b) {
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
    }

    double fractionalKnapsack(int W,Item arr[],int n) {
        sort(arr,arr+n,compare);
        int curr_weight=0;
        double final_value=0;
        for (int i=0;i<n;i++) {
            if ((curr_weight+arr[i].weight)<=W) {
                curr_weight+=arr[i].weight;
                final_value+=arr[i].value;
            }
            else {
                int remaining=W-curr_weight;
                final_value+=(arr[i].value/(double)arr[i].weight)*(double)remaining;
                break;
            }
        }
        return final_value;
    }
};