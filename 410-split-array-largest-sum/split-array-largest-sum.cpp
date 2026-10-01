class Solution {
public:
    bool func(vector<int>& nums,int k , int maxSum ){
        int subArray = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i]<=maxSum){
                sum += nums[i];
            }
            else{
                subArray++;
                sum = nums[i];

            }
        }
        return subArray <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        for(int x : nums){
            low = max(low, x);
            high += x; 
        }
        while(low<=high){
            int guess = low + (high-low)/2;
            if(func(nums,k,guess)){
                high = guess-1;
            }
            else{
                low = guess+1;
            }
        }
        return low;
    }
};