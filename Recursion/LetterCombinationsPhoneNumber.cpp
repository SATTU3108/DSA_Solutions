#include <bits/stdc++.h>
using namespace std;

void possibleWordsRec(vector<int> &arr,vector<string> &padMap,int index,string &prefix,vector<string> &res) {
    if (index==arr.size()) {
        res.push_back(prefix);
        return;
    }
    int digit=arr[index];
    if (digit<2 || digit>9) {
        possibleWordsRec(arr,padMap,index+1,prefix,res);
        return;
    }
    for (char ch:padMap[digit]) {
        prefix.push_back(ch);
        possibleWordsRec(arr,padMap,index+1,prefix,res);
        prefix.pop_back();
    }
}
vector<string> possibleWords(vector<int> &arr) {
    vector<string> padMap={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    string prefix;
    possibleWordsRec(arr,padMap,0,prefix,res);
    return res;
}