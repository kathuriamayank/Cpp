#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string,std::vector<std::string>> mapAnagrams;
        std::vector<std::vector<std::string>> results;

        for(int i=0; i<strs.size(); i++)
        {
            std::string key=this->getKey(strs[i]);
            mapAnagrams[key].push_back(strs[i]);
        }

        for(const auto &it:mapAnagrams)
        {
            results.push_back(it.second);
        }

        return results;
    }

    std::string getKey(std::string str)
    {
        std::vector<int> keyVector(26,0);
        std::string key("");

        for(int i=0; i<str.size(); i++)
        {
            keyVector[str[i]-'a']++;
        }

        for(const auto &it:keyVector)
        {
            key=key+ std::to_string(it)+"#";
        }

        return key;
    }
};


int main()
{
    std::cout<<"Hello World\n";

    Solution s;
    std::vector<std::string> strs{"bdddddddddd","bbbbbbbbbbc"};
    
    auto result=s.groupAnagrams(strs);

    return 0;
}

