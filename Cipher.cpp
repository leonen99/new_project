
#include "Cipher.h"

// Первоначальный список зарегистрированных фабрик пуст.
// Поэтому указатель обнулен.
CipherFactory* CipherFactory::top = nullptr;

// Конструктор, обеспечивающий начальную расстановку элементов в стеке и их ранжирование
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

	// Обход фабрик в стеке до той, у которой ключ совпадает с искомым
	while (tmp) {
		f = tmp->Create(key);
		// При создании обход завершается
		if (f) return f;
		tmp = tmp->next;
	}
	return nullptr;
}

// иденитфикация, порождение и ввод 
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
