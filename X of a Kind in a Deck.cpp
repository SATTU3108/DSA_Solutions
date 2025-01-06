bool hasGroupsSizeX(vector<int>& deck) {
    int n=deck.size();
    unordered_map <int,int> mp;
    for (int i=0;i<n;i++) mp[deck[i]]++;
    int x=INT_MAX;
    for (int i=0;i<mp.size();i++) {
        for (int j=i+1;j<mp.size();j++) {
            int temp=__gcd(mp[i],mp[j]);
            x=min(x,temp);
        }
    }
    if (mp.size()==1) x=n;
    if (x==1) return false;
    for (auto it:mp) {
        int y=it.second;
        if (y%x!=0) return false;
    }
    return true;
}
