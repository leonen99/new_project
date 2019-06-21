
#include "Shift.h"


void Shift::InData(ifstream& ifst) {
	ifst >> text;
	ifst >> shift;
	cipherText = text;
	for (int i = 0; i < text.length();i++)
	{
		cipherText[i] = cipherText[i] + shift;
	}
	
	
}

void Shift::Out(ofstream& ofst) {
	
	ofst  << "It is a text ciphered with shift" << endl;
	ofst << "Shift = " << shift << endl;
	ofst << "Cipher text: " << cipherText << endl;
	ofst << "Unencrypted text: " << text << endl;
}
namespace {
	ShiftFactory sf;
}