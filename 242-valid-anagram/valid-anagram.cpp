class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;

        for(int i=0;i<s.size();i++){
            freq1[s[i]]++;
        }

        for(int j=0;j<t.size();j++){
            freq2[t[j]]++;
        }

        if(freq1 == freq2){
            return true;
        }
        return false;


    }
};