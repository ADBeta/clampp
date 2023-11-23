#include <iostream>

#include <vector>
#include <iterator>

#include "clampp.hpp"

int main(const int argc, const char *argv[]) {

	ClamppClass Args;
	//ClamppConfig::allow_undefined_args = true;
	
	int a = Args.AddDefinition("hello", true);
	int b = Args.AddDefinition("bye", true);
	int c = Args.AddDefinition("test", false);
	
	int err = Args.ScanArgs(argc - 1, argv + 1);
	
	std::cout << "Err: " << err << std::endl;
	
	std::cout << "find: " << Args.FindDefinedByFlag("hello") << std::endl;
	std::cout << "find: " << Args.FindDefinedByFlag("ho") << std::endl;
	std::cout << "find: " << Args.FindDefinedByFlag("bye") << std::endl;
	std::cout << "find: " << Args.FindDefinedByFlag("test") << std::endl;
	
	std::cout << "Substr: " << Args.GetSubstring(a) << std::endl;
	std::cout << "Substr: " << Args.GetSubstring(b) << std::endl;
	std::cout << "Substr: " << Args.GetSubstring("bye") << std::endl;
	
	
	std::cout << "test detected: " << Args.GetDetectedStatus(c) << std::endl;
	std::cout << "Substr: " << Args.GetSubstring(c) << std::endl;
	
	//std::cout << a << ": " << Args.DefinedArgList[(size_t)a].flag_pri << std::endl;
	//std::cout << b << ": " << Args.DefinedArgList[(size_t)b].flag_pri << std::endl;
	//std::cout << c << ": " << Args.DefinedArgList[(size_t)c].flag_pri << std::endl;
	
	//for(auto it = Args.DefinedArgList.begin(); it != Args.DefinedArgList.end(); ++it) {
	//	std::cout << it->flag_pri << std::endl;
	//}
	
	
	return 0;
}
