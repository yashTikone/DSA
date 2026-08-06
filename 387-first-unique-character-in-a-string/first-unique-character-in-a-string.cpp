class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char,int> f;
        //  store in hashmap and increase frequency of letters
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        // check if frequency of a particular letter is one or not
        for(int i=0;i<n;i++){
            if(f[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};