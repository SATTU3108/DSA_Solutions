/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
*/

//Approach: Think of breaking the string at the places where you encounter an operator and compute the value for the left half and then for right half as well and depening on the operator, compute the final value. SO think of this approach like this: consider the operators as tree nodes and the values on left and right of it as the leaves of it
vector<int> diffWaysToCompute(string expression) {
  vector <int> res;
  for (int i=0;i<expression.length();i++) {
      char c=expression[i];
      if (c=='+' || c=='-' || c=='*') {
          vector <int> s1=diffWaysToCompute(expression.substr(0,i));
          vector <int> s2=diffWaysToCompute(expression.substr(i+1));
          for (int a:s1) {
              for (int b:s2) {
                  if (c=='+') res.push_back(a+b);
                  else if (c=='-') res.push_back(a-b);
                  else if (c=='*') res.push_back(a*b);
              }
          }
      }
  }
  if (res.size()==0) res.push_back(stoi(expression));
  return res;
}
