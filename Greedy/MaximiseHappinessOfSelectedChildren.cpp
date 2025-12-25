#include <bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {
  long long ans=0;
  sort(happiness.begin(),happiness.end(),greater<int> ());
  int count=1;
  while (count<=k) {
      ans+=max(0,happiness[count-1]-(count-1));
      count++;
  }
  return ans;
}
