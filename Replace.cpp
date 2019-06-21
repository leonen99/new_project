
#include "Replace.h"
#include <utility>

void Replace::InData(ifstream& ifst) {
	ifst >> text;
	string tmp;
	ifst >> tmp;
	lenPair = tmp.length()/2;
	pairArray = new pair<char, char>[lenPair];
	int i = 0;
	for (int index = 0; index < 2*lenPair; index=index+2)
	{
		
		pairArray[i] = make_pair(tmp[index], tmp[index+1]);
		
		i++;
	}
	
	cipherText = text;
	for (int i = 0; i < text.length(); i++)
	{
		for (int j = 0; j < lenPair; j++)
		{
			if (text[i] == pairArray[j].first)
			{
				
				cipherText[i] = pairArray[j].second;
				break;
			}
		}

	}
	
}

void Replace::Out(ofstream& ofst) {
	ofst << "It is a text ciphered with replace" << endl;
	
	for (int i = 0; i < lenPair; i++)
	{
		ofst << pairArray[i].first << " - " << pairArray[i].second << endl;
	}
	
	
	
	ofst << "Cipher text: " << cipherText << endl;
	ofst <<"Unencrypted text: "<< text << endl;
	
}

namespace {
	ReplaceFactory bf;
}