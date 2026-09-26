class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0; 
        int high = (n*m)-1;
        while(low<=high){
            int guess = (low+high)/2;
            int row =  guess/m;
            int column = guess%m;
            if(matrix[row][column]==target){
                return true;
            }
            else if(matrix[row][column]<target){
                low = guess+1;
            }
            else{
                high = guess-1;
            }
        }
        return false;
    }
};