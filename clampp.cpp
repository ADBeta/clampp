/*******************************************************************************
* clampp - Command Line Argument Manager, Plus Plus
* A Simple, Efficient and Fast CLI Argument Handler Library.
*
* See the GitHub For more information: https://github.com/ADBeta/clampp
* See example.cpp for programatic demonstation of usage/syntax.
*
* ADBeta(c)    19 Nov 2023    Version 0.2.4
*******************************************************************************/
#include "clampp.hpp"

#include <iostream> //TODO

#include <iterator>
#include <cstring>

/*** Private Functions ********************************************************/


/*** API Functions ************************************************************/
//Add a Defined Argument with a single, primary flag string
int ClamppClass::AddDefinition(const char *pri, const bool has_substr) {
	
	ArgDef_t arg_temp;
	arg_temp.flag_pri = pri;
	arg_temp.flag_sec = NULL;
	arg_temp.has_substr = has_substr;

	try {
		DefinedArgList.push_back(arg_temp);
	} catch(const std::bad_alloc &) {
		return -1;
	}
	
	return (int)std::distance(DefinedArgList.begin(), DefinedArgList.end()) - 1;
}	
	
//Add a Defined Argument with two flag strings, one primary + one alias
int ClamppClass::AddDefinition(const char *pri, const char *sec, const bool has_substr) {

	ArgDef_t arg_temp;
	arg_temp.flag_pri = pri;
	arg_temp.flag_sec = sec;
	arg_temp.has_substr = has_substr;

	try {
		DefinedArgList.push_back(arg_temp);
	} catch(const std::bad_alloc &) {
		return -1;
	}
	
	return (int)std::distance(DefinedArgList.begin(), DefinedArgList.end()) - 1;
}

ClamppError ClamppClass::ScanArgs(const int argc, const char *argv[]) {
	if(argc <= 0) return CLAMPP_ENOARGS;
	
	//Go through all of the input argument strings
	for(int crnt_arg = 0; crnt_arg < argc; crnt_arg++) {
		const char *arg_str = argv[crnt_arg];
		
		std::cout << arg_str << std::endl; //TODO
		//Keep track of if the current argument has been matched to a definition
		bool found_match = false;
		
		//Go through each Defined Argument looking for a match
		for(auto def = this->DefinedArgList.begin(); def != this->DefinedArgList.end(); def++) {
			//See if the primary or secondary flag strings match
			int pri_cmp = strcmp(def->flag_pri, arg_str);
			//Preset the sec_cmp to failed, if it has been defined, compare
			int sec_cmp = -1;
			if(def->flag_sec != NULL) sec_cmp = strcmp(def->flag_sec, arg_str);
			
			//If either flag string matched, set the argument to detected
			if(pri_cmp == 0 || sec_cmp == 0) {
				found_match = true;
				def->was_detected = true;
				
				//If the string is marked as having a substring, look for one.
				//Return error if a subsequent string doesn't exist
				if(def->has_substr == true) {
					if(++crnt_arg == argc) return CLAMPP_ENOSUBSTR;
					def->substr = argv[crnt_arg];				
				}
			}
			
			
		}
		
		//If no match error, or put into array
		if(found_match == false) {
			std::cout << "No match found" << std::endl;
		}
				
	}
	
	
	
	
	return CLAMPP_ENONE;
}
