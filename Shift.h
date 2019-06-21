#ifndef __Shift__
#define __Shift__


#include "Cipher.h"




class Shift : public Cipher
{



public:
	int shift;
	string cipherText;
	void InData(ifstream& ifst);
	void Out(ofstream& ofst);


	Shift() {}
};

class ShiftFactory : public CipherFactory {
public:

	ShiftFactory() :CipherFactory(1) { }


	Cipher* Create(int key) {
		if (key == mark)
			return new Shift;
		else
			return nullptr;
	}
};

#endif
