int uniqueMorseRepresentations(vector<string>& words) {
    vector <string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set <string> st;
    for (int i=0;i<words.size();i++) {
        string word=words[i];
        string temp="";
        for (char c:word) {
            int pos=c-'a';
            temp+=morse[pos];
        }
        st.insert(temp);
    } 
    return st.size();
}
