#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int i(1);
    int j(0);

    if (argc >= 2)
    {
        while (argc-- != 1)
        {
            while (argv[i][j])
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    argv[i][j] -= 32;
                j++;
            }
            std::cout << argv[i];
            j = 0;
            i++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}