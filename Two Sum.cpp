vector <int> twoSum(vector <int> & nums,int target) {
    int n=nums.size();
    unordered_map <int,int> mp;
    for (int i=0;i<n;i++) mp[nums[i]]=i;
    for (int i=0;i<n;i++) {
        int remaining_sum=target-nums[i];
        if (mp.count(remaining_sum) && mp[remaining_sum]!=i) return {i,mp[remaining_sum]};
    }
    return {};
}
