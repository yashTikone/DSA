class Solution {
public:
    bool func(vector<int>&bloomDay,int n,int day,int m,int k){
        int flowers = 0;
        int bouquets = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                flowers++;
                if(flowers==k){
                    bouquets++;
                    flowers = 0;
                }
            }
            else{ // flowers not bloomed
                flowers = 0;
            }
            if(bouquets>=m){
                return true;
            }
        }
        return false;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k>n){
            return -1;
        }
        int low = bloomDay[0];
        int high = bloomDay[0];
        for(int i=0;i<n;i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }
        int res = -1;
        while(low<=high){
            int guess = low+(high-low)/2;
            if(func(bloomDay,n,guess,m,k)){
                res = guess;
                high = guess-1;
            }
            else{
                low = guess+1;
            }
        }
        return res;
    }
};