#include "RPN.hpp"
#include <iostream>

void autoTest(const char *tests)
{
    try
    {
        std::cout << " (" << tests << ")" << std::endl;
        RPN rpn(tests);
        rpn.calcRPN();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void runAutomaticTests()
{
    std::cout << "===== " << "Basic" << " =====" << std::endl;
    autoTest("8 9 * 9 - 9 - 9 - 4 - 1 +");
    autoTest("7 7 * 7 -");
    autoTest("1 2 * 2 / 2 * 2 4 - +");
    autoTest("3 4 +");
    autoTest("9 9 *");
    autoTest("5 1 2 + 4 * + 3 -");
    std::cout << std::endl;

    std::cout << "===== " << "Error" << " =====" << std::endl;
    autoTest("(1 2 +)");
    autoTest("1 a +");
    autoTest("1 +");
    autoTest("+ 1 2");
    autoTest("1 2 3 +");
    autoTest("");
    autoTest("    ");
    autoTest("10 2 +");
    autoTest("5 0 /");
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "--test")
    {
        runAutomaticTests();
        return 0;
    }

    try
    {
        RPN rpn(argv[1]);
        rpn.calcRPN();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}