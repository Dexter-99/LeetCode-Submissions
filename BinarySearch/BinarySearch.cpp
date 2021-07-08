class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  l=0;
        int  h=nums.size()-1;
        int  val=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(target==nums[mid])
            {
                val=mid;
                break;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return val;
    }
};