#include <map>
#include <vector>
#include <iostream>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return 1;

        std::map<int,int> numsMap;
        int maxLen=1,curMaxLen=1;

        for(const auto& it:nums)
        {
            numsMap[it]=1;
        }


        const auto firstIter=numsMap.begin();
        int prev=firstIter->first;

        auto it=numsMap.begin();
        ++it;
        
        while(it!=numsMap.end())
        {
            int curr=it->first;
            if(curr==prev+1)
            {
                curMaxLen++;
                if(curMaxLen>maxLen)
                    maxLen=curMaxLen;
            }
            else
            {
                curMaxLen=1;
            }

            prev=curr;
            it++;
        }

        return maxLen;
    }
};


int main()
{
    Solution s;
    std::vector<int> vec{100,4,200,1,3,2};
    auto result=s.longestConsecutive(vec);
    return 0;
}
