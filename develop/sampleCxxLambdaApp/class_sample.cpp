#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////////////////
////        class Print                  ////
/////////////////////////////////////////////

class Print
{
public:
    // string union_string_append(string msg1, string msg2);
    // void print_string_cout(string msg1);
    // void print_string_cout(string msg1, string msg2);
    // void print_string_cout(string msg1, string msg2, string msg3);

    string union_string_append(string msg1, string msg2)
    {
        return msg1.append(msg2);
    }

    void print_string_cout(string msg1)
    {
        std::cout << "[INFO] " << msg1 << std::endl;
    }

    void print_string_cout(string msg1, string msg2)
    {
        print_string_cout(union_string_append(msg1, msg2));
    }

    void print_string_cout(string msg1, string msg2, string msg3)
    {
        print_string_cout(union_string_append(msg1, msg2), msg3);
    }
};



/////////////////////////////////////////////
////        main.cpp                     ////
/////////////////////////////////////////////

int main(int argc, char *argv[])
{
    auto plus = [](int a, int b) { return a + b; };
    Print print_log;

    print_log.print_string_cout("Sample App Lambda Expressions");

    int result1 = plus(2, 3); // result == 5
    print_log.print_string_cout("result1 = ", to_string(result1));

    int result2 = plus(5, 3); // result == 8
    std::cout << "[Info] result2 = " << result2 << std::endl;

    return 0;
}
