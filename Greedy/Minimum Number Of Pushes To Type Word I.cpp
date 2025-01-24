/*
You are given a string word containing distinct lowercase English letters.
Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
Return the minimum number of pushes needed to type word after remapping the keys.
An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.
*/

int minimumPushes(string word) {
  int l=word.size();
  if (l<=8) return l;
  else if (l<=16) return (2*l-8);
  else if (l<=24) return (3*l-24);
  else if (l==25) return 52;
  else if (l==26) return 56;
  return -1;
}
//Time complexity:O(1),Space complexity:O(1)
