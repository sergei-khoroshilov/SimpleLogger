
#include <iostream>
#include <cstdlib>

#include "SimpleLogger.h"

int main ()
{
	std::cout << "Hello, world" << std::endl;

	SimpleLogger::GetInstance().SetEnabled(false);
	SimpleLogger::GetInstance() << "Hello" << std::endl << "world";

	SimpleLogger::GetInstance().SetEnabled(true);
	SimpleLogger::GetInstance() << "String after enabling logger" << std::endl;

	SH_DEBUG << "Debug using SH_DEBUG macros" << std::endl;

	std::cin.get();
	return EXIT_SUCCESS;
}
