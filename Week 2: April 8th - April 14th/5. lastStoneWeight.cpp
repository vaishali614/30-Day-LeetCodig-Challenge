class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        
        while(stones.size() > 1){
            int n = stones.size();
            int max1 = stones[n-1];
            int max2 = stones[n-2];
            
            if(max1 == max2){
                stones.pop_back();
                stones.pop_back();
            } else {
                stones.pop_back();
                stones.pop_back();
                stones.push_back(max1 - max2);
            }
            sort(stones.begin(), stones.end());
        }
        
        if(stones.size() == 1)
            return stones.at(0);
        else
            return 0;
    }
};
