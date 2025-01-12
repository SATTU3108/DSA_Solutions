/*
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'
However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:
"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).

Note: there may be strings that are impossible to decode.
Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
The test cases are generated so that the answer fits in a 32-bit integer.
*/

//Approach 1
bool validMapping(string s) {
if (s.empty() || s[0]=='0') return false;
    int num=stoi(s);
    return (num>=1 && num<=26);
}
int numDecodings(string s) {
    int l=s.length();
    if (l==1) {
       if (validMapping(s)) return 1;
       return 0;
    }
    vector <int> dp(l+1,0);
    dp[0]=1;
    string temp=s.substr(0,1);
    if (validMapping(temp)) dp[1]=1;
    for (int i=2;i<=l;i++) {
        string temp1=s.substr(i-1,1);
        if (validMapping(temp1)) dp[i]+=dp[i-1];
        string temp2=s.substr(i-2,2);
        if (validMapping(temp2)) dp[i]+=dp[i-2];
    }
    return dp[l];
}
//Time complexity:O(N),Space complexity:O(N)

//Approach 2
bool validMapping(string s) {
  if (s.empty() || s[0]=='0') return false;
  int num=stoi(s);
  return (num>=1 && num<=26);
}
int numDecodings(string s) {
  int l=s.length();
  if (l==1) {
      if (validMapping(s)) return 1;
      return 0;
  }
  int prev_prev=1;
  string temp=s.substr(0,1);
  int prev;
  if (validMapping(temp)) prev=1;
  else prev=0;
  for (int i=2;i<=l;i++) {
      int curr=0;
      string temp1=s.substr(i-1,1);
      if (validMapping(temp1)) curr+=prev;
      string temp2=s.substr(i-2,2);
      if (validMapping(temp2)) curr+=prev_prev;
      prev_prev=prev;
       prev=curr;
  }
  return prev;
}
//Time complexity:O(N),Space complexity:O(1)
