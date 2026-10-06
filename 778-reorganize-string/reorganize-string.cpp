class Solution {
public:
    struct cmp{
        bool operator() (pair<int,char>&a , pair<int,char>&b ){
            return a.first<b.first;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char,int> f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        priority_queue<pair<int,char> , vector<pair<int,char>>, cmp> pq;

        for(auto i:f){
            pq.push({i.second,i.first});
        }
        string res = "";
        int seat = 0;

        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();

            if(seat==0 || res[seat-1] != p.second){
                res.push_back(p.second);
                seat++;
                p.first--;

                if(p.first>0){
                    pq.push(p);
                }

            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char> q = pq.top();
                pq.pop();
                res.push_back(q.second);
                seat++;
                q.first--;
                if(q.first>0){
                    pq.push(q);
                }
                pq.push(p);

            }

        }
        return res;

    }
};