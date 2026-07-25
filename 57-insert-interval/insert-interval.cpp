class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = intervals.size();
        bool insert = false;
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            if(insert==false and start>=newInterval[0]){
                ans.push_back(newInterval);
                insert = true;
            }
            ans.push_back(intervals[i]);
            
            
        }
        if(insert==false){
            ans.push_back(newInterval);
        }
        vector<vector<int>> result;
        sort(ans.begin(),ans.end());
        int start1 = ans[0][0];
        int end1 = ans[0][1];
        for(int i=1;i<ans.size();i++){
            int start2 = ans[i][0];
            int end2 = ans[i][1];
            if(end1>=start2){
                start1=start1;
                end1 = max(end1,end2);
                continue;
            }
            result.push_back({start1,end1});
            start1 = start2;
            end1= end2;
        }
        result.push_back({start1,end1});
        return result;

        
    
    }
};