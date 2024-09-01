#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    std::string encode(vector<string> strs) {
        // write your code here
        std::string encodedString("");
        for(const auto& str: strs)
        {
            encodedString+=str + "+";
        }
        return encodedString;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<std::string> decode(string &str) {
        // write your code here

        std::vector<std::string> decodedStringVector;
        for(int i=0; i<str.length(); i++)
        {
            std::string result("");
            if(str[i]=='+')
            {
                decodedStringVector.push_back(result);
                result="";
            }
        }

        return decodedStringVector;

    }
};

int main()
{
    std::cout<<" Hello World\n";
    std::cout<<" Testing\n\n";
    std::cout<<" Testing2\n\n";

    std::vector<std::string> encoded;
    std::string s1("lint"), s2("code"), s3("love"),s4("you");
    encoded.push_back(s1);
    encoded.push_back(s2);
    encoded.push_back(s3);
    encoded.push_back(s4);
    Solution sol;
    std::cout<<sol.encode(encoded);
    return 0;

}
