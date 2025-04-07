#include <iostream>
#include <string>
#include "Harl.hpp"

int main(void)
{
    Harl goat;
    
    goat.complain("DEBUG");
	goat.complain("ERROR");
	goat.complain("INFO");
	goat.complain("WARNING");
    return (0);
}