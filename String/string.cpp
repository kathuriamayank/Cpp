#include <iostream>
#include <cstring>

template<typename T>
void disp(T val)
{
    std::cout<<val<<std::endl;
}


int main()
{

    // C style array string
    char str_arr[100]{"Hello World"};
    std::cout<<str_arr<<std::endl;

    int len=std::strlen(str_arr);
    std::cout<<"len:"<<len<<std::endl;

    //C-Style const pointer string
    const char *str="Hey";

    std::strcat(str_arr,str);
    std::cout<<"Concatinated String is:"<<str_arr<<std::endl;

    const char*str2="Hey";
    if(std::strcmp(str,str2)==0)
    {
        std::cout<<"Equal Strings\n";
    }

    str_arr[1]='g';
    /*
        NOTE: std::cout<< will always print char * until it encounters the \0.
    */
    std::cout<<str_arr<<std::endl;


    // std::string class
    std::string s1("Hello");
    /*
    ***Capacity:
        size(), length()----> both are same
        empty()
        capacity()
        reserve()
        max_size()
        resize(n)
    */

    int size=s1.size();
    int capacity=s1.capacity();
    auto max_size=s1.max_size();
    
    std::cout<<"size:"<<size<<"capacity:"<<capacity<<"max_size:"<<max_size<<std::endl;

    /*
    *** Iterators:
        begin()
        end()
        cbegin()
        end()
        rbegin()
        rend()
        crbein()
        crend()
    */

    for(auto it=s1.crbegin(); it!=s1.crend(); it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";


    /*
    *** Access:
        []
        at()
        data()
        c_str() 
        *** data() and c_str both return the C Style null terminated strings
    */


   char *ptr=s1.data();
   std::cout<<ptr<<std::endl;


   /*
    ***Modifiers:
    *push_back()----> appends a char to a string
    *append(std::str)---> appends a string to the string
    *pop_back()---> removes last char from the string
    *insert(pos,string)-----> the position is not an iterator
    *erase(pos,len)---? from that pos till the specified length.
    *replace(pos,len,string)---> replace the char of length l, starting from pos.
   */
    s1.append("abc");
    std::cout<<s1<<std::endl;

    s1.pop_back();
    std::cout<<s1<<std::endl;

    s1.insert(s1.size()-1,std::string("Mayank"));
    disp(s1);

    s1.erase(5,1);
    disp(s1);

    s1.replace(5,4,"John");
    disp(s1);

    s1.erase(9,2);
    disp(s1);



    /*
        String functions:
        *find(str,pos):Searches the string for the first occurrence of the sequence specified by its arguments.

        When pos is specified, the search only includes characters at or after position pos, 
        ignoring any possible occurrences that include characters before pos.

        *rfind(string,pos): will return the last of the sequence matched.

        *substr(pos,len): will generate the subsrting starting from the pos till the length(or end of string,
        if lenght is not specified.)

        *find_first_of(str,pos): searches the string for the first character that matches with 
        any of the chars specified in the arg.
        
        When pos is specified, the search only includes characters at or after position pos, 
        ignoring any possible occurrences that include characters before pos


        *find_first_not_of(str,pos): finds the first position, which does not match with any of the
        chars of the sequence.

        *find_last_not_of(str,pos): finds the last position, which does not match with any of the
        chars of the sequence.


        *compare(str)
        *compare(str,pos,len)
        
        Return Value is:
        0	They compare equal
        <0	Either the value of the first character that does not match is lower 
        in the compared string, or all compared characters match 
        but the compared string is shorter.
        >0	Either the value of the first character that does not match is greater 
        in the compared string, or all compared characters match 
        but the compared string is longer.

        *******
        
        ****Also some arguments are in form of
        pos,len: which is starting from that position pos and of length len
        
        
        *****Note: In find we search for the entire sequence, where as in other finds 
        we search char wise in the sequence



        *******

    */


   // find()
    std::string str3 ("There are two needles in this haystack with needles.");
    std::string str4 ("needle");

    std::size_t found=str3.find(str4);
    if(found!=std::string::npos)
    {
        std::cout<<str4<<"is found at pos:"<<found<<std::endl;
    }

    found=str3.find(str4,found+1);
    if(found!=std::string::npos)
    {
        std::cout<<str4<<"is found at pos:"<<found<<std::endl;
    }

    found=str3.find(str4);
    while(found!=std::string::npos)
    {
        found=str3.find(str4,found+1);
        if(found!=std::string::npos)
        {
            std::cout<<str4<<"is found at pos:"<<found<<std::endl;
        }
    }

    std::cout<<str3.substr(14,6)<<std::endl;
    

    //rfind()
    std::string str5="HelloMayankHelloHello";
    found =str5.rfind("Hello");
    if(found!=std::string::npos)
    {
        std::cout<<"Found:"<<found<<std::endl;
    }




    //substr()
    std::cout<<str5.substr(5,6)<<std::endl;  //Mayank
    std::cout<<str5.substr(5)<<std::endl;   // MayankHelloHello


    //find_first_of and find_last_of
    std::cout<<str5.find_first_of("dM")<<std::endl; //5 because M is first char which matches with given seq of chars.

    std::cout<<str5.find_last_of("H")<<std::endl;// 16 is the last pos in the string which matches with "H".

    std::string str6("this is a -alpha numeric- string");
    std::cout<<str6.find_first_not_of("abcdefghijklmnopqrstuvwxyz ")<<std::endl; //10 is the first pos
    // which is char "-", that does not match with any of the chars.

    std::cout<<str6.find_last_not_of("abcdefghijklmnopqrstuvwxyz ")<<std::endl; //24 is the lat pos
    // which is char "-", that does not match with any of the chars.



    //compare
    std::string str7("Red Apple");
    std::string str8("Green Apple");

    if(str7.compare(str8)!=0)
    {
        std::cout<<"Unequal String\n";
    }

    if(str7.compare(3,5,"Apple"))
    {
        std::cout<<"Yes they are apples\n";
    }


    std::wstring strW("abc");
    std::wcout<<strW<<std::endl;
    return 0;
}