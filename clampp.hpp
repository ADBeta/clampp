/*******************************************************************************
* clampp - Command Line Argument Manager, Plus Plus
* A Simple, Efficient and Fast CLI Argument Handler Library.
*
* See the GitHub For more information: https://github.com/ADBeta/clampp
* See example.cpp for programatic demonstation of usage/syntax.
*
* ADBeta(c)    18 Nov 2023
*******************************************************************************/
#ifndef CLAMPP_H
#define CLAMPP_H

#include <vector>


typedef enum {
	CLAMPP_ENONE = 0, CLAMPP_ENOARGS = -1, CLAMPP_ENOMATCH = -2, 
	CLAMPP_ENOSUBSTR = -3
} ClamppError;

class ClamppClass {
	public:
	/*** API Functions ********************************************************/
	//NOTE Function overflow for both versions of a Defined Argument.
	//Returns an index of the argument in the list or -1 if an error occured
	//Add a Defined Argument with one one, primary flag string
	int AddDefinition(const char *pri, const bool has_substr);
	int AddDefinition(const char *pri, const char *sec, const bool has_substr);
	
	//Scan through the arguments using the standard argc/argv method
	//Returns a ClamppError value
	ClamppError ScanArgs(const int argc, const char *argv[]);
	
	
	
	
	//private:
	/*** Configuration Variables **********************************************/
	
	
	
	/** Argument Definition Struct ********************************************/
	typedef struct {
		const char *flag_pri = NULL;   //Primary flag string for argument (e.g -h)
		const char *flag_sec = NULL;   //(Optional) Secondary flag string (e.g --help)
		
		bool has_substr = false;       //Does argument have a substring (e.g -m hello)
		const char *substr = NULL;     //Argument string from the argv[] array
		
		bool was_detected = false;     //Was the argument detected during scan
	} ArgDef_t;

	//List of Defined Arguments 	
	std::vector<ArgDef_t> DefinedArgList;

};

#endif
