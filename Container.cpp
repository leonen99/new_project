#include "Container.h"

Container::Container()
{
	length = 0;
	Top = NULL;
	Bot = NULL;
}


void Container::Input(ifstream& ifst)
{

	

	while (!ifst.eof())
	{
		length++;  
		Cipher* temp;       
		temp = CipherFactory::In(ifst);
		                              
		temp->next = Top;                                    
		                                          

		if (Top != NULL)                                       
		{
			Bot->next = temp;                                    
			Bot = temp;                                          
		}
		else Top = Bot = temp;                                
	}

}

void Container::	Output(ofstream& ofst)
{
	ofst << "Contain " << length << " elemenst" << endl;
	Cipher* temp = Top;                              
	int tempLenght = length;                                       
	int index = 0;
	while (tempLenght != 0)                                    
	{
		ofst << index << ": ";
		temp->Out(ofst);                     
		temp = temp->next;                        
		tempLenght--;    
		index++;
	}
	
}

void Container::Delete()
{
	while (length != 0)                        
	{
		Cipher* temp = Top->next;
		delete Top;                           
		Top = temp;                           
		length--;                                
	}
}

