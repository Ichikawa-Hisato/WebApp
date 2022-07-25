#include <iostream>
using namespace std;
 
int main(int argc, char *argv[])
{
        std::cout << "[Info] Sample App Lambda Expressions" << std::endl;
        auto plus = [](int a, int b) { return a + b; };
        int result = plus(2, 3); // result == 5
        std::cout << "[Info] result = " << result << std::endl;
        return 0;
}
