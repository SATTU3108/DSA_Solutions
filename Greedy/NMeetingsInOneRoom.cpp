#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int startTime,endTime,pos;
};

bool compare(meeting m1,meeting m2) {
    return m1.endTime<m2.endTime;
}

vector <int> maxMeetings(vector <int> &start,vector<int> &end) {
    vector <int> res;
    int n=start.size();
    vector <meeting> meets(n);
    for (int i=0;i<n;i++) {
        meets[i].startTime=start[i];
        meets[i].endTime=end[i];
        meets[i].pos=i+1;
    }
    sort(meets.begin(),meets.end(),compare);
    int curr_time=01;
    for (int i=0;i<n;i++) {
        if (meets[i].startTime>curr_time) {
            curr_time=meets[i].endTime;
            res.push_back(meets[i].pos);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
// Time complexity:O(NlogN),Space complexity:O(N)