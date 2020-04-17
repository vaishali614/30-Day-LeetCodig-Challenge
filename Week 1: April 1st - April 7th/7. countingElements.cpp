class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for(int i = 0; i < arr.size(); i++){
            freq[arr[i]]++;
        }
        
        for(int i = 0; i < arr.size(); i++){
            int x = arr[i] + 1;
            if(freq.count(x) > 0){
                count++;
            }
        }
        
        return count;
    }
};
