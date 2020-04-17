class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size();
        // string f;
        for(int i = 0; i < shift.size(); i++){
            int d = shift[i][0];
            int a = shift[i][1];
            
            if(d == 0){
                s = s.substr(a, n-a) + s.substr(0, a);
            } else {
                s = s.substr(n-a, a) + s.substr(0, n-a);
            }
        }
        return s;
    }
};
