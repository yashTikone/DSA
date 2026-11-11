class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0 , sumB = 0;
        
        for(int x: aliceSizes){
            sumA += x;
        }

        for(int x: bobSizes){
            sumB += x;
        }
        int diff = (sumA - sumB)/2;

        unordered_set<int> st(bobSizes.begin(),bobSizes.end());
        for(int x:aliceSizes){
            int y = x-diff;

            if(st.find(y) != st.end()){
                return{x,y};
            }
        }
        return{};

    }
};