int lengthOfLastWord(string s) {
    int l=s.length();
    int idx=l-1;
    while (s[idx]==' ') idx--;
    int count=0;
    for (int i=idx;i>=0;i--) {
        if (s[i]!=' ') count++;
        else break;
    }
    return count;
}
