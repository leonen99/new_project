
#include "Cipher.h"

// �������������� ������ ������������������ ������ ����.
// ������� ��������� �������.
CipherFactory* CipherFactory::top = nullptr;

// �����������, �������������� ��������� ����������� ��������� � ����� � �� ������������
CipherFactory::CipherFactory(int m) : mark(m)
{
	this->next = top;
	top = this;
}



//------------------------------------------------------------------------------
Cipher* CipherFactory::Make(int key)
{

	Cipher* f = nullptr;

	CipherFactory* tmp = top;

	// ����� ������ � ����� �� ���, � ������� ���� ��������� � �������
	while (tmp) {
		f = tmp->Create(key);
		// ��� �������� ����� �����������
		if (f) return f;
		tmp = tmp->next;
	}
	return nullptr;
}

// �������������, ���������� � ���� 
Cipher* CipherFactory::In(ifstream& ifst)
{
	Cipher* pf = nullptr;
	int k;
	ifst >> k;

	pf = Make(k);
	if (pf)
	{
		pf->type = k;
		pf->InData(ifst);

	}
	return pf;

}
