#include <iostream>

#include <vector>
#include <iterator>

#include "clampp.hpp"

int main(const int argc, const char *argv[]) {

	ClamppClass Args;
	int a = Args.AddDefinition("hello", true);
	
	
	int err = Args.ScanArgs(argc - 1, argv + 1);
	
	std::cout << err << std::endl;
	
	//std::cout << a << ": " << Args.DefinedArgList[(size_t)a].flag_pri << std::endl;
	//std::cout << b << ": " << Args.DefinedArgList[(size_t)b].flag_pri << std::endl;
	//std::cout << c << ": " << Args.DefinedArgList[(size_t)c].flag_pri << std::endl;
	
	//for(auto it = Args.DefinedArgList.begin(); it != Args.DefinedArgList.end(); ++it) {
	//	std::cout << it->flag_pri << std::endl;
	//}
	
	
	return 0;
}
