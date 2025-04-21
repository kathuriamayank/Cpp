#include <iostream>
#include <string>

class Report
{
public:
    std::string m_name;
    std::string m_content;

    Report(const std::string &name, const std::string &content): m_name{name},m_content{content}
    {
        //
    }

};


class ReportPrinter
{
public:
    void print(Report& report)
    {
        std::cout<<"Printing the report!!!\n";
        std::cout<<report.m_name<<":"<<report.m_content<<std::endl;
    }
};

class ReportSaver
{
public:
    void save(Report& report)
    {
        std::cout<<"Saving the report named:"<<report.m_name<<std::endl;
    }
};

int main()
{
    Report report("Mayank","Report on Mayank.Following is the content.....");

    ReportPrinter printer;
    ReportSaver saveData;

    printer.print(report);
    saveData.save(report);
    
    return 0;
}
