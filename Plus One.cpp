vector<int> plusOne(vector<int>& digits) {
 int n=digits.size();
 if (digits[n-1]!=9) {
        digits[n-1]++;
        return digits;
    }
    else {
        int idx=n-1;
        while (idx>=0 && digits[idx]==9) {
            digits[idx]=0;
            idx--;
        }
        if (idx<0) digits.insert(digits.begin(),1);
        else digits[idx]++;
        return digits;
    }
}
