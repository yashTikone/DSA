class Solution {
public:
    bool func(vector<int>&candies,int n,long long k,int guess){
        long long count = 0;
        for(int i=0;i<n;i++){
            count = count + candies[i]/guess;
        }
        if(count>=k){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low = 1;
        int high = 0;
        for(int i=0;i<n;i++){
            high = max(high,candies[i]);
        }
        int res  = 0;
        while(low<=high){
            int guess = low + (high-low)/2;
            if(func(candies,n,k,guess)){
                res = guess;
                low = guess+1;
            }
            else{
                high = guess - 1;
            }
        }
        return res;

    }
};