#include <unordered_map>
#include <iostream>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        bool isAnagram(true);
        if(s.size() !=t.size())
        {
            isAnagram=false;
        }
        
        else
        {
            std::unordered_map<char,int> count_map_s;
            std::unordered_map<char,int> count_map_t;

            // Filling the count map
            for(int i=0; i<s.size(); i++)
            {
                count_map_s[s[i]]+=1;
                count_map_t[t[i]]+=1;
            }

            //Comparing the maps
            for(int i=0; i<s.size(); i++)
            {
                if(count_map_s[s[i]] != count_map_t[s[i]])
                {
                    isAnagram=false;
                    break;                            
                }
            }            
        }

        return isAnagram;
    }
};


int main()
{
    Solution sol;
    std::string s("anagram"), t("nagaram");
    int result=sol.isAnagram(s,t);

    if(result)
    {
        std::cout<<"True\n";
    }

    else
        std::cout<<"False\n";

    return 0;
}