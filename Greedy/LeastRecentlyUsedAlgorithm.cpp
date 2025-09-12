#include <bits/stdc++.h>
using namespace std;

int pageFaults(vector <int> &pages,int capacity) {
    unordered_set <int> memory; // Set to hold current page
    unordered_map <int,int> lastUsedIndex;
    int faults=0;
    for (int i=0;i<pages.size();i++) {
        int page=pages[i];
        if (memory.size()<capacity) {
            if (memory.find(page)==memory.end()) {
                memory.insert(page);
                faults++;
            }
        }
        else {
            if (memory.find(page)==memory.end()) {
                int lruIndex=INT_MAX;
                int lruPage=-1;
                for (int p:memory) {
                    if (lastUsedIndex[p]<lruIndex) {
                        lruIndex=lastUsedIndex[p];
                        lruPage=p;
                    }
                }
                memory.erase(lruPage);
                memory.insert(page);
                faults++;
            }
        }
        lastUsedIndex[page]=i;
    }
    return faults;
}