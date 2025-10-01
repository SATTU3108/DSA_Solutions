/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &words,int maxWidth) {
    int n=words.size();
    vector<string> ans;
    int i=0;
    while (i<n) {
        int line_len=0; // sum of lengths of words in current line
        int j=i; // index to find how many words fit in the current line
        // find the maximum words that fit in the line, including minimum spaces between words
        while (j<n && line_len+words[j].size()+(j-i)<=maxWidth) {
            line_len+=words[j].size();
            j++;
        }
        int count=j-i; // number of words in current line
        int total_gap=maxWidth-line_len; // total spaces to distribute
        string line;
        // if last line or line has onnly one word, left-justify
        if (j==n || count==1) {
            for (int k=i;k<j;k++) {
                line+=words[k];
                if (k<j-1) line+=' '; // single space between words
            }
            // pad the end with spaces to reach maxWidth
            line+=string(maxWidth-line.size(),' ');
        }
        else {
            // full justification: distibute spaces evenly
            int base_gap=total_gap/(count-1); // minimum spaces per gap
            int remaining_gap=total_gap%(count-1); // xtra spaces to distribute from left
            for (int k=i;k<j;k++) {
                line+=words[k];
                if (k<j-1) {
                    int gap=base_gap;
                    if ((k-i)<remaining_gap) gap++; // distribute extra spaces to left gaps
                    line+=string(gap,' ');
                }
            }
            // no extra padding needed here because spaces are fully distributed
        }
        ans.push_back(line);
        i=j; // move to next line
    }
    return ans;
}
