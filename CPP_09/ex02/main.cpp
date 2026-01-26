#include "PmergeMe.hpp"
#include <iostream>
#include <string>

void autoTest(const std::string& name, char **tests)
{
    std::cout << "===== " << name << " =====" << std::endl;
    try
    {
        PmergeMe p(tests);
        p.make();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void runAutomaticTests()
{
    static char progName[] = "PmergeMe";

    static char t1_1[] = "3";
    static char t1_2[] = "5";
    static char t1_3[] = "9";
    static char t1_4[] = "7";
    static char t1_5[] = "4";

    char *vals1[] = {
        progName,
        t1_1, t1_2, t1_3, t1_4, t1_5,
        NULL
    };
    autoTest("Test 1 : Basic", vals1);
    std::cout << std::endl;

    static char t2_1[] = "1";
    static char t2_2[] = "2";
    static char t2_3[] = "3";
    static char t2_4[] = "4";
    static char t2_5[] = "5";

    char *vals2[] = {
        progName,
        t2_1, t2_2, t2_3, t2_4, t2_5,
        NULL
    };
    autoTest("Test 2 : Already sorted", vals2);
    std::cout << std::endl;

    static char t3_1[] = "9";
    static char t3_2[] = "8";
    static char t3_3[] = "7";
    static char t3_4[] = "6";
    static char t3_5[] = "5";

    char *vals3[] = {
        progName,
        t3_1, t3_2, t3_3, t3_4, t3_5,
        NULL
    };
    autoTest("Test 3 : Reverse sorted", vals3);
    std::cout << std::endl;

    static char t4_1[] = "5";
    static char t4_2[] = "1";
    static char t4_3[] = "5";
    static char t4_4[] = "2";
    static char t4_5[] = "5";
    static char t4_6[] = "3";

    char *vals4[] = {
        progName,
        t4_1, t4_2, t4_3, t4_4, t4_5, t4_6,
        NULL
    };
    autoTest("Test 4 : Duplicates", vals4);
    std::cout << std::endl;

    static char t5_1[] = "42";

    char *vals5[] = {
        progName,
        t5_1,
        NULL
    };
    autoTest("Test 5 : Single number", vals5);
    std::cout << std::endl;

    static char t6_1[] = "10";
    static char t6_2[] = "3";
    static char t6_3[] = "7";

    char *vals6[] = {
        progName,
        t6_1, t6_2, t6_3,
        NULL
    };
    autoTest("Test 6 : Odd set", vals6);
    std::cout << std::endl;
}


int main(int argc, char **argv)
{
    if (argc < 2)
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
        PmergeMe p(argv);
        p.make();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
