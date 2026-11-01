class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = 0;
        for(int i=0;i<candies.size();i++){
            max_candies = max(max_candies,candies[i]);
        }

        vector<bool> ans;

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=max_candies){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;

    }
};