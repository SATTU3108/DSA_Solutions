/*
Given an array representing a queue of customers and the value of bills they hold, determine if it is possible to provide correct change to each customer. Customers can only pay with 5$, 10$ or 20$ bills and we initially do not have any change at hand. Return true, if it is possible to provide correct change for each customer otherwise return false.
*/

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills) {
    int fives=0,tens=0;
    for (int i=0;i<bills.size();i++) {
        if (bills[i]==5) fives++;
        else if (bills[i]==10) {
            if (fives>0) {
                fives--;
                tens++;
            }
            else return false;
        }
        else {
            if (fives>0 && tens>0) {
                fives--;
                tens--;
            }
            else if (fives>=3) fives-=3;
            else return false;
        }
    }
    return true;
}