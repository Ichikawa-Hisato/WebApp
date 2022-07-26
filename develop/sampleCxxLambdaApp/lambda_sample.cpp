#include <iostream>
#include <string>
using namespace std;

auto union_string = [](string msg1, string msg2){
    return msg1.append(msg2);
};

auto print_cout = [](string msg) {
    std::cout << "[INFO] " << msg << std::endl;
};

int main(int argc, char *argv[])
{
    auto plus = [](int a, int b) { return a + b; };

    print_cout("Sample App Lambda Expressions");

    int result1 = plus(2, 3); // result == 5
    auto s = union_string("result1 = ", to_string(result1));
    print_cout(s);

    int result2 = plus(5, 3); // result == 8
    std::cout << "[Info] result2 = " << result2 << std::endl;

    return 0;
}
