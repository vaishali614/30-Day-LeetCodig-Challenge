class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, int> :: iterator it;
        m[0] = -1;
        int sum = 0, ml = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] == 1 ? 1 : -1;
            
            if(m.find(sum) == m.end())
                m[sum] = i;
            else{
                it = m.find(sum);
                ml = max(ml, i - it->second);
            }
        }
        return ml;
    }
};
