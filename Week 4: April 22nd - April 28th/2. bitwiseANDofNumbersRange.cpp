// Method 1:
// class Solution {
// public:
//     int rangeBitwiseAnd(int m, int n) {
//         int ans = 0;
//         for(int i = 30; i >= 0; i--){
//             if((m & (1 << i)) == (n & (1<<i))){
//                 ans |= (m & (1<<i));
//             } else {
//                 break;
//             }
//         }
//         return ans;
//     }
// };


// Method 2: (more efficient)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        while(m != n){
            m = m >> 1;
            n = n >> 1;
            ans++;
        }
        return n << ans;
    }
};
