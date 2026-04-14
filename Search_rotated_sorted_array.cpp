// /*
// Problem: Search in Rotated Sorted Array
// Platform: LeetCode
// Approach: Binary Search
// Time Complexity: O(log n)
// */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Search(vector<int>& nums, int si, int ei, int target){
        if(si > ei){
            return -1;
        }

        int mid = si + (ei - si) / 2;

        if(nums[mid] == target){
            return mid;
        }

        if(nums[si] <= nums[mid]){  // left sorted
            if(nums[si] <= target && target < nums[mid]){
                return Search(nums, si, mid - 1, target);
            } else {
                return Search(nums, mid + 1, ei, target);
            }
        } else {  // right sorted
            if(nums[mid] < target && target <= nums[ei]){
                return Search(nums, mid + 1, ei, target);
            } else {
                return Search(nums, si, mid - 1, target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return Search(nums, 0, nums.size() - 1, target);
    }
};