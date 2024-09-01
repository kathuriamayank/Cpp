#include <queue>
#include <vector>
#include <string>

#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen=1;
        int i=0,j=0;

        std::unordered_map<char,int> freqMap;
        while(j<s.length())
        {
            int len=j-i+1;
            if(freqMap.find(s[j])==freqMap.end())
                freqMap[s[j]]=1;
            else
                freqMap[s[j]]++;
            
            // int max=*std::max_element(freqMap.begin(),freqMap.end(),[](std::pair<char,int> const &a,std::pair<char,int> const &b)
            // {
            //     return a.second<b.second;
            // });

            auto max=*std::max_element(freqMap.begin(), freqMap.end(), [](std::pair<char,int> const &x, std::pair<char,int> const &y) {
        return x.second < y.second;
    });

            if(len-max.second<=k)
            {
                maxLen=std::max(maxLen,len-max.second);
                j++;
            }
            else
            {
                freqMap[s[i]]--;
                i++;
                j++;
            }

        }

        return maxLen;
    }
};
int main()
{
    Solution sol;
    auto val=sol.characterReplacement(std::string("ABAB"),2);
    
    return 0;
}