/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i
*/


vector<int> countBits(int n) {
  vector <int> ans(n+1);
  ans[0]=0;
  for (int i=1;i<=n;i++) {
      int x=log(i)/log(2);
      if (i-pow(2,x)==0) ans[i]=1;
      else ans[i]=ans[pow(2,x)]+ans[i-pow(2,x)];
  }
  return ans;
}

//Efficient solution
vector<int> countBits(int n) {
  vector <int> ans(n+1);
  for (int i=0;i<=n;i++) {
      if (i%2==0) ans[i]=ans[i/2];
      else ans[i]=ans[i-1]+1;
  }
  return ans;
}
