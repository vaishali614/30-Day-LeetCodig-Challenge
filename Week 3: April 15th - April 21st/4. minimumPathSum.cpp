class Solution {
public:
    int minPathSum(vector<vector<int>>& input) {
        int m = input.size(), n = input[0].size();
        int **storage=new int*[m];
        for(int i=0; i < m; i++)
            storage[i]=new int[n];

        storage[m-1][n-1]=input[m-1][n-1];
        for(int i=m-2; i >= 0; i--)
            storage[i][n-1] = storage[i+1][n-1] + input[i][n-1];

        for(int j=n-2; j >= 0; j--)
            storage[m-1][j] = storage[m-1][j+1] + input[m-1][j];

        for(int i=m-2; i >= 0; i--){
            for(int j=n-2; j >= 0; j--){
                storage[i][j] = input[i][j] + min(storage[i+1][j],storage[i][j+1]);
            }
        }
        int ans=storage[0][0];
        for(int i=0; i < m; i++)
            delete [] storage[i];

        delete [] storage;
        
        return ans;
    }
};
