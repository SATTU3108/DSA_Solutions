/*
Given a string s containing only digits, return the lexicographically smallest string that can be obtained after swapping adjacent digits in s with the same parity at most once.
Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.
*/

string getSmallestString(string s) {
  int l=s.length();
  for (int i=0;i<(l-1);i++) {
      int fd=s[i]-'0';
      int sd=s[i+1]-'0';
      if (((fd%2==0 && sd%2==0) || (fd%2!=0 && sd%2!=0)) && fd>sd) {
          s[i]=sd+'0';
          s[i+1]=fd+'0';
          break;
      } 
  }
  return s;
}
//Time complexity:O(N),Space compelxity:O(1)
