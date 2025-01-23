int maxArea(vector<int>& height) {
  int n=height.size();
  int ans=INT_MIN;
  int left=0,right=n-1;
  while (left<right) {
      int current_height=(right-left)*min(height[left],height[right]);
      ans=max(ans,current_height);
      if (height[left]>height[right]) right--;
      else left++;
  }
  return ans;
}
