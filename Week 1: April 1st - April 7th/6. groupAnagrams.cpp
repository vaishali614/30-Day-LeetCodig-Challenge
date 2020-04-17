class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        if(strs.size() == 0){
            return ans;
        }
        
        map<string, vector<string>> dict;
        
        for(string s: strs){
            string str = s;
            sort(str.begin(), str.end());
            dict[str].push_back(s);
        }
        
        auto itr = dict.begin();
        while(itr != dict.end()){
            ans.push_back(itr->second);
            itr++;
        }
        
        return ans;
    }
};
