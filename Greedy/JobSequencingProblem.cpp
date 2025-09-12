#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id; 
    int deadline;
    int profit;
};

bool static compare(Job a,Job b) {
    return (a.profit>b.profit);
}

pair <int,int> JobScheduling(Job arr[],int n) {
    sort(arr,arr+n,compare);
    int max_deadline=arr[0].deadline;
    for (int i=1;i<n;i++) max_deadline=max(max_deadline,arr[i].deadline);
    int slots[max_deadline+1];
    for (int i=0;i<=max_deadline;i++) slots[i]=-1;
    int countJobs=0,jobProfit=0;
    for (int i=0;i<n;i++) {
        for (int j=arr[i].deadline;j>0;j--) {
            if (slots[j]==-1) {
                slots[j]=1;
                countJobs++;
                jobProfit+=arr[i].profit;
                break;
            }
        }
    }
    return {countJobs,jobProfit};
}