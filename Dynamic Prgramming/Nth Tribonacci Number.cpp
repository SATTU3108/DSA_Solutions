/*
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
*/

//Recursive solution
int tribonacci(int n) {
  if (n==0) return 0;
  if (n==1 || n==2) return 1;
  return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
}

int tribonacci(int n) {
  if (n==0) return 0;
  if (n==1 || n==2) return 1;
  vector <int> dp(n+1);
  dp[0]=0,dp[1]=1,dp[2]=1;
  for (int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
  return dp[n];
}
//Time complexity:O(N),Space complexity:O(N)

int tribonacci(int n) {
  if (n==0) return 0;
  if (n==1 || n==2) return 1;
  int prev2=0,prev1=1,prev=1;
  for (int i=3;i<=n;i++) {
      int curr=prev2+prev1+prev;
      prev2=prev1;
      prev1=prev;
      prev=curr;
  }
  return prev;
}
//Time complexity:O(N),Space complexity:O(1)
