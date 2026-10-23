class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());

        if(nums == sorted){
            return 0;
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(nums[i]!= i)
            ans &= nums[i];
        }
        return ans;

    }
};