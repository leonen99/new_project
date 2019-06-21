#ifndef __Cipher__
#define __Cipher__

#include <fstream>
using namespace std;


class Cipher {

public:
	int type;
	string text;
	Cipher* next = NULL;//pointer for next element
	static  Cipher* In(ifstream& ifst);

	virtual void InData(ifstream& ifst) = 0;
	virtual void Out(ofstream& ofst) = 0;

	//    Cipher() {};	
};


class CipherFactory
{
protected:
public:
	CipherFactory(int m);
	static Cipher* Make(int key);
	static Cipher* In(ifstream& ifst);
	virtual Cipher* Create(int key) = 0;
	int mark;
	static CipherFactory* top;
	CipherFactory* next;
};
#endif
