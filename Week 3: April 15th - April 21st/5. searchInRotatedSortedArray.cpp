class Solution {
public:
    int search(vector<int>& v, int x) {
        if(v.size() == 0) return -1;
        
        int s = 0, e = v.size() - 1;
        while(s < e){
            int m = (s + e) / 2;
            if(v[m] > v[e]) s = m + 1;
            else e = m;
        }
        
        int start = s;
        s = 0;
        e = v.size() - 1;
        
        if(x >= v[start] && x <= v[e]) s = start;
        else e = start;
        
        while(s <= e){
            int m = (s + e) / 2;
            if(v[m] == x) return m;
            else if(v[m] < x) s = m + 1;
            else e = m - 1;
        }
        return -1;
    }
};
