class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long ans=0;
        
        for(int i=0; i<n; i++){
            int max_v = nums[i];
            int min_v = nums[i];
            for(int j=i; j<n; j++){
                max_v = max(max_v , nums[j]);
                min_v = min(min_v, nums[j]);
                ans += max_v - min_v; 
            }
        }
        return ans;
    }
};