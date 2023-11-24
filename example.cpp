/*******************************************************************************
* Example of how to use clampp - Command Line Argument Mananger - Plus Plus
* This file is part of clampp, and is under the GPLv2 License.
*
* In this example, There are 2 Defined Arguments, and no support for Undefined
* Args. This is an example of how to call this program:
* ./example test substr hello!
*
* ADBeta (c)    24 Nov 2023    v1.0.0
*******************************************************************************/
#include <iostream>

#include "clampp.hpp"

int main(const int argc, const char *argv[]) {
	//Define a Clampp object
	ClamppClass Args;
	
	//Error Codes:
	//CLAMPP_ENONE      (0)    No Error occured.
	//CLAMPP_ENOARGS   (-1)    No Arguments were passed to the program
	//CLAMPP_ENOMATCH  (-2)    No Match/Defined argument was found. (See config)
	//CLAMPP_ENOSUBSTR (-3)    An Argument with a substring was not given one
	
	//Configuration Flags:
	//allow_undefined_args controls what happens during a ScanArgs.
	//If false, ScanArgs returns CLAMPP_ENOMATCH when an Undefined Arg is found
	//If true, an Undefined Argument will be pushed onto UndefinedArgList
	ClamppConfig::allow_undefined_args = false;
	
	
	//Define Arguments. Keep the return index, as it makes looking for them
	//much faster, althrough it can be done by string
	//NOTE: The Bool value is if the string has a substring.
	int test = Args.AddDefinition   ("test", false);
	int substr = Args.AddDefinition ("substr", true);
	
	//Scan the input Arguments. Value is nudged to skip argv[0], but this is 
	//not required, it just skips the executable name
	int scan_ret = Args.ScanArgs(argc - 1, argv + 1);
	
	//Check the return value and print a message based on them
	if(scan_ret != CLAMPP_ENONE) {
		switch(scan_ret) {
			//NOTE: Remove this to allow no Arguments being passed
			case CLAMPP_ENOARGS:
				std::cerr << "No Arguments were passed" << std::endl;
				break;
			//NOTE: Remove this and set config flag to enable Undefined Args
			case CLAMPP_ENOMATCH:
				std::cerr << "An Undefined Argument was passed" << std::endl;
				break;
			case CLAMPP_ENOSUBSTR:
				std::cerr << "A Required Substring was not given" << std::endl;
				break;
		}
		
		exit(EXIT_FAILURE);
	}
	
	//Print the Defined Argument Data for debugging
	std::cout << "Arg: test\nDetected: " << Args.GetDetectedStatus(test) 
	          << std::endl << std::endl;
	
	std::cout << "Arg: substr\nDetected: " << Args.GetDetectedStatus(substr)
	          << std::endl << "Substring: " << Args.GetSubstring(substr) 
	          << std::endl;
	
	//NOTE: You can also get the Detected and Substring variables by passing 
	//the flag string
	std::cout << "Substring by flag: " << Args.GetSubstring("substr") 
	          << std::endl;
		
	return 0;
}
