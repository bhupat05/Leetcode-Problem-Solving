// Last updated: 3/18/2026, 3:02:44 PM
class Solution {
public:
    int findPivot(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;  
            } else {
                r = mid;      
            }
        }
        return l; 
    }

    int bs(int l, int r, vector<int>& nums, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return bs(pivot, n - 1, nums, target);
        } else {
            return bs(0, pivot - 1, nums, target);
        }
    }
};
