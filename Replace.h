#ifndef __Replace__
#define __Replace__


#include "Cipher.h"


class Replace : public Cipher
{
	
	
public:

	int lenPair;
	pair<char, char>* pairArray;
	string cipherText;
	void InData(ifstream& ifst);  
	void Out(ofstream& ofst);     

	
	Replace() {}
};

class ReplaceFactory : public CipherFactory {
public:

	ReplaceFactory() :CipherFactory(2) { }


	Cipher* Create(int key) {
		if (key == mark)
			return new Replace;
		else
			return nullptr;
	}
};
#endif
