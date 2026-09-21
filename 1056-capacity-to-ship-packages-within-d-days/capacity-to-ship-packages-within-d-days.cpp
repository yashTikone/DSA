class Solution {
public: 
    bool func(vector<int>&weights,int n, int days,int capacity){
        int dayUsed = 1;
        int currentWeight = 0;
        for(int i=0;i<n;i++){
            if(currentWeight+weights[i]<=capacity){
                currentWeight = currentWeight + weights[i];
            }
            else{
                dayUsed++;
                currentWeight = weights[i];
            }
            if(dayUsed>days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0;
        int high = 0;
        for(int i=0;i<n;i++){
            low = max(low,weights[i]);
            high = high + weights[i];
        }
        int res = -1;
        while(low<=high){
            int guess = low + (high-low)/2;
            if(func(weights,n,days,guess)){
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