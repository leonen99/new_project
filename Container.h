#ifndef __Container__
#define __Container__

#include "Cipher.h"



class Container
{

	

public:
	int length;
	Container();

	Cipher* Top;
	Cipher* Bot;

	void Input(ifstream& ifst);
	void Output(ofstream& ofst);
	void Delete();
};

#endif
