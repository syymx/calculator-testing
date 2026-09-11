#include <iostream>
#include "calculator.hpp"


int main()
{
    try
    {
        std::cout << calculator::eval("10 / 0") << std::endl;
    }
    catch (const calculator::error& e)
    {
        std::cerr << "Calculator Error: "
                  << e.what()
                  << std::endl;
    }

    return 0;
}