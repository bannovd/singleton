#include <iostream>
#include "singleton.h"


int main()
{
    std::cout << "singleton\n" << std::endl;
    patterns::singleton::get_instance();

    patterns::single<int>();
    return 0;
}
