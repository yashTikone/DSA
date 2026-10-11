class Solution {
public:
    class Node{
        public:
        int value;
        int row;
        int col;
        Node(int v,int r, int c){
            value = v;
            row = r;
            col = c;
        }

    };
    struct cmp{
        bool operator() (const Node&a, const Node&b) const{
            return a.value > b.value;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue <Node, vector<Node>, cmp> pq;
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }
        vector<int> res;
        while(!pq.empty()){
            Node n = pq.top();
            pq.pop();
            int v = n.value;
            int row = n.row;
            int col = n.col;
            res.push_back(v);
            if(col<(m-1)){
                pq.push({matrix[row][col+1],row,col+1});
            }
        }
        return res[k-1];

        
    }
};