#include <bits/stdc++.h>
using namespace std;

/*
Given a text and a pattern, write a function that prints all the occurrences of the pattern in the text. Assume the length of text  > pattern and both are given in the form of strings.
*/

// Naive Approach
void searchPatternNaive(string &text,string &pattern) {
    int n=text.length(),m=pattern.length();
    int j;
    for (int i=0;i<=(n-m);i++) {
        for (j=0;j<m;j++) {
            if (pattern[j]!=text[i+j]) break;
        }
        if (j==m) {
            cout<<"index= "<<i<<endl;
        }
    }
}
//time:O(m*(n-m+1)),space:O(1)

// RabinK Karp Algorithm - Single Hashing
class RabinKarpHash {
  private:
    const int mod=1e9+7;
    const int base=31;
    vector<int> hash;
    vector<int> power;
    int add(int a,int b) {
        a+=b;
        if (a>=mod) a-=mod;
        return a;
    }
    int sub(int a,int b) {
        a-=b;
        if (a<0) a+=mod;
        return a;
    }
    int mul(int a,int b) {
        return (int)((1LL*a*b)%mod);
    }
    int charToInt(char c) {
        return c-'a'+1;
    }
  public:
    RabinKarpHash(string &s) {
        int n=s.size();
        hash.resize(n);
        power.resize(n);
        hash[0]=charToInt(s[0]);
        power[0]=1;
        for (int i=1;i<n;i++) {
            hash[i]=add(mul(hash[i-1],base),charToInt(s[i]));
            power[i]=mul(power[i-1],base);
        }
    }
    int getSubHash(int l,int r) {
        int h=hash[r];
        if (l>0) h=sub(h,mul(hash[l-1],power[r-l+1]));
        return h;
    }
};
vector<int> searchPattern(string &text,string &pattern) {
    int n=text.size(),m=pattern.size();
    RabinKarpHash textHash(text);
    RabinKarpHash patHash(pattern);
    int patternHash=patHash.getSubHash(0,m-1);
    vector<int> result;
    for (int i=0;i<=n-m;i++) {
        int subHash=textHash.getSubHash(i,i+m-1);
        if (subHash==patternHash) result.push_back(i);
    }
    return result;
}
//time:O(n+m),space:O(n+m)

// Rabin Karp Algorithm - Double Hashing
class RabinKarpHashDouble {
  private:
    const int mod1=1e9+7,mod2=1e9+9;
    const int base1=31,base2=37;
    vector<int> hash1,hash2;
    vector<int> power1,power2;
    int add(int a,int b,int mod) {
        a+=b;
        if (a>=mod) a-=mod;
        return a;
    }
    int sub(int a,int b,int mod) {
        a-=b;
        if (a<0) a+=mod;
        return a;
    } 
    int mul(int a,int b,int mod) {
        return (int)((1LL*a*b)%mod);
    }
    int charToInt(char c) {
        return c-'a'+1;
    }
  public:
    RabinKarpHashDouble(string &s) {
        int n=s.length();
        hash1.resize(n);
        hash2.resize(n);
        power1.resize(n);
        power2.resize(n);
        hash1[0]=charToInt(s[0]);
        hash2[0]=charToInt(s[0]);
        power1[0]=1;
        power2[0]=1;
        for (int i=1;i<n;i++) {
            hash1[i]=add(mul(hash1[i-1],base1,mod1),charToInt(s[i]),mod1);
            hash2[i]=add(mul(hash2[i-1],base2,mod2),charToInt(s[i]),mod2);
            power1[i]=mul(power1[i-1],base1,mod1);
            power2[i]=mul(power2[i-1],base2,mod2);
        }
    }
    vector<int> getSubHash(int l,int r) {
        int h1=hash1[r],h2=hash2[r];
        if (l>0) {
            h1=sub(h1,mul(hash1[l-1],power1[r-l+1],mod1),mod1);
            h2=sub(h2,mul(hash2[l-1],power2[r-l+1],mod2),mod2);
        }
        return {h1,h2};
    }
};
