/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.
Return true if and only if Alice wins the game, assuming both players play optimally.
*/

//Approach 1
bool divisorGame(int n) {
  if (n==1) return false;
  if (n==2) return true;
  vector <int> dp(n+1,0);
  dp[1]=0,dp[2]=1;
  for (int i=3;i<=n;i++) {
      for (int j=1;j<i;j++) {
          if (i%j==0 && dp[i-j]==0) {
              dp[i]=1;
              break;
          }
      }
  }
  return dp[n];
}
//Time complexity:O(N),Space complexity:O(N)

//Approach 2
bool divisorGame(int n) {
  return (n%2==0);
}
