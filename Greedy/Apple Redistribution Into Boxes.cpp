/*
You are given an array apple of size n and an array capacity of size m.
There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
Note that, apples from the same pack can be distributed into different boxes.
*/

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
  int total_apples=0;
  for (int i=0;i<apple.size();i++) total_apples+=apple[i];
  sort(capacity.begin(),capacity.end(),greater <int> ());
  int total_cap=0;
  for (int i=0;i<capacity.size();i++) {
      if (total_cap>=total_apples) return i;
      total_cap+=capacity[i];
  }
  return capacity.size();
}
//Time complexity:O(NlogN),Space complexity:O(1)
