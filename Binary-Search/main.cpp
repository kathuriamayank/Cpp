#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int pivot=binarySearchMinPos(nums);
        int start=0,end=0;
        const int N=nums.size();
        if(target>=nums[pivot] and target<=nums[N-1])
        {
            start=pivot,end=N-1;
        }
        else
        {
            start=0,end=pivot-1;
        }

        return binarySearch(start,end,target,nums);
    }

    int binarySearch(int start,int end, int target,std::vector<int> &nums)
    {
        while(start<=end)
        {
            int mid=start+ ((end-start)/2);
            if(target==nums[mid])
                return mid;
            
            if(target<nums[mid])
                end=mid-1;
            else
                end=mid+1;
        }
        return -1;
    }

    int binarySearchMinPos(std::vector<int> &nums)
    {
        int start=0,end=nums.size()-1;
        const int N=nums.size();
        
        while(start<=end)
        {
            int mid=start+ ((end-start)/2);
            int next=(mid+1)%N;
            int prev=(mid+ N-1)%N;

            if(nums[mid]<nums[prev] && nums[mid]<nums[next])
            {
                return mid;
            }

            if(nums[mid]<nums[end])
                end=mid-1;
            else
                start=mid+1;
        }

        return -1;
    }
};


int main()
{
    Solution s;
    std::vector<int> v{1,3};
    int ans=s.search(v,2);
    
    return 0;
}