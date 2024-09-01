#include <iostream>
#include <string>   
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;

        while(j>=i)
        {
            while(i<s.length() && !isAlphaNum(s[i]))
            {
                i++;
            }

            while(j>=0 && !isAlphaNum(s[j]))
            {
                j--;
            }
            if(i>=j)
            {
                return true;
            }
            if(to_lower(s[i])!=to_lower(s[j]))
            {
               return false;
            }
            i++,j--;

        }
        return true;
    }

    bool isAlphaNum(char ch)
    {
        if(ch>='a'  && ch<='z' )
            return true;
        if(ch>='A' && ch<='Z')
            return true;
        if(ch>='0' && ch<='9')
            return true;
        return false;
    }

    char to_lower(char ch)
    {
        return ch-'A' +'a';
    }


};

int main()
{
    char chLowerA='a';
    char chUpperA='A';

    int lowerA=chLowerA;
    int upperA=chUpperA;

    std::cout<<"Lower a Ascii:"<<lowerA<<"Upper A Ascii:"<<upperA<<std::endl;    


    char chUpperCase='B';
    char convertedLowerCase=chUpperCase - 'A' + 'a';
    std::cout<<"converted lower case:"<<convertedLowerCase<<std::endl;

    char convertedUpperCase=convertedLowerCase - 'a' + 'A';
    std::cout<<"converted upper case:"<<convertedUpperCase<<std::endl;


    Solution s;
    s.isPalindrome(std::string("A man, a plan, a canal: Panama"));
    return 0;

}

