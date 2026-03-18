// Last updated: 3/18/2026, 2:24:02 PM
class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        int count=0;
        int n=nums.size();
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(nums[j]>=i)
                {
                     count++;
                }
               
            }
            if(count==i)
            {
                return count;
            }
            count=0;
        }
       return -1; 
    }
};