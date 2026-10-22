class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n_xor = nums.size();
        for(int i=0; i<nums.size(); i++){
            n_xor = n_xor^i;
            n_xor = n_xor^nums[i];
        }
        return n_xor;
    }
};