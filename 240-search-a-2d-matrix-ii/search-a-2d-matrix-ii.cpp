class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1;
        int column = 0;
        while(row>=0 && column<m){
            if(matrix[row][column]==target){
                return true;
            }
            else if(matrix[row][column]>target){
                row--;
            }
            else{
                column++;
            }
        }
        return false;
    }
};