class Solution {
public:
    void solve(int open , int close,int n, string current,vector<string>& ans){
        // if we use all opening and closing brackets 
        if(open==n && close==n){
            ans.push_back(current);
            return;
        }
        // add '(' if we still have opnening brackets available
        if(open<n){
            solve(open+1,close,n,current +'(',ans);
        }
        //add ')'  only if it wont make parenthesis invalid
        if(close<open){
            solve(open,close+1,n,current + ')',ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};