#include <iostream>
#include <string>
using namespace std;

#include "PrintLog.h"

/////////////////////////////////////////////
////        class PrintLog               ////
/////////////////////////////////////////////

string PrintLog::union_string_append(string msg1, string msg2)
{
    return msg1.append(msg2);
}

void PrintLog::print_string_cout(string msg1)
{
    std::cout << "[INFO] " << msg1 << std::endl;
}

void PrintLog::print_string_cout(string msg1, string msg2)
{
    print_string_cout(union_string_append(msg1, msg2));
}

void PrintLog::print_string_cout(string msg1, string msg2, string msg3)
{
    print_string_cout(union_string_append(msg1, msg2), msg3);
}
