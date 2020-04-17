class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nz = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                int temp = nums[nz];
                nums[nz++] = nums[i];
                nums[i] = temp;
            }
        }
    }
};
