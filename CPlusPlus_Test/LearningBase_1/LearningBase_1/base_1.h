#pragma once

class Base_1
{
public:
	static int* array_int;
};



/*
�����ظ����ͬ���麯��ʱ�����hides overloaded virtual function���뾯�档

���ص��麯����������

�����Ƿ��������أ����������˸���ĺ�������α����ص����麯������ʱ��������صĸ�����麯�����ᱻ���ء�
*/

struct Base
{
	virtual void* get(const char* e);
	//virtual void * get(char* e, int index);
};

struct Derived: public Base
{
	using Base::get;
	virtual void* get(const char* e, int index);

//�ŵ�˽��λ�� �������Base��get
//private:
//	using Base::get;
};