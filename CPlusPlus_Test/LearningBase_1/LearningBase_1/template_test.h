#pragma once

class Account {
public:
	static double m_rate;                             //���� ������û�л���ڴ棬ֻ����class���룩   
													  //��̬����ĳ�ʼ���淶 �� ��Ҫ��class�ⲿ��gcc / clang���Ҳ�����ͷ�ļ��У����ж����ʼֵ ����һ����Ҫ���ʼֵ����
	static void set_rate(const double& x) { m_rate = x; }
};

/*
<<static  ��̬>>

complex����ɽṹ
---
data members
static data members
---
member functions
static member functions
---

��ȷ this pointer����

����
complex c1,c2,c3;
cout << c1.real();
cout << c2.real();

===>  to C

complex c1,c2,c3;
cout << complex::real(&c1);
cout << complex::real(&c2);

//�Ǿ�̬��������ͬ�ĺ��������벻ͬ�Ķ���ĵ�ַ ��this��
//��̬���� ��̬���� ֻ����һ��  û��this pointer  ���Բ��ܴ���Ǿ�̬�������ݣ�
*/

/*
��̬��������

1. ͨ��object����
	Account a;
	a.set_rate(xxx);                //ע�� this������� ����ʹ��  .  ���� ->

2. ͨ��class name ����
	Account::set_rate(yyy);

*/

//ctor�ŵ�private��

/*
����
���ӣ�
*/
class SingletonA {

public:
	static SingletonA& getInstance() { return a; }
	void setup();
private:
	SingletonA();
	SingletonA(const SingletonA& rhs);
	static SingletonA a;
};

//SingletonA::getInstance().setup();

//�Ż�  ����
class SingletonAA {
public :
	static SingletonAA& getInstance();
	void setup();

private:
	SingletonAA();
	SingletonAA(const SingletonAA& rhs);
};

SingletonAA& SingletonAA::getInstance()
{
	static SingletonAA a; //��c�����Ĺ淶�� ֻ�е��õ��������   static a�Ŵ���
	return a;
}


//��չ��ģ����
/*
//ģ������ T
template<typename T>                           ------------------->  typename
class complex
{
public:
	complex(T r = 0, T i = 0)
		: re(r), im(i)
	{}
	complex& operator += (const complex&);
	T real() const { return re; }
	T imag() const { return im; }

private:
	T re, im;

	friend complex& __doapl(complex*, const complex&);
};

//ģ��ʹ��
{
	complex<double> c1(2.5, 1.5);
	complex<int> c2(2, 6);
}
*/


//��չ��ģ�巽����ģ�庯��
/*

class stone
{
public:
	stone(int w, int h, int we)
		:_w(w), _h(h), _weight(we)
	{}
	bool operator < (const stone& rhs) const
	{
		return _weight < rhs._weight;
	}

	template <class T>
	inline const T& min(const T& a, const T& b)
	{
		return b < a ? b : a;
	}

private:
	int _w, _h, _weight;
};


ģ�巽�� ʹ�������
stone r1(2, 3), r2(3, 3), r3;
r3 = min(r1, r2);

��ģ���಻ͬ������Ҫ��������<����>
��������ʵ���Ƶ�

�������Ƶ����̣�
���� operator < ������  ʵ��b�ϣ� ��������ѯ b��Ӧ������stone Ȼ����֤stone�Ƿ��ж��� operator< ���������������ط��������Ե���

�������Ƶ������
TΪStone  ���ǵ���stone::operator<

���䣺��Ϊoperator< ����ʵ���� Stone����  ����ʵ���˾�����÷���min �� ����ʵ�ַ���operator< �ķ���
*/



//namespace
/*
ʹ�ã�

using namespace std;

cout>>...;
cin<<...;


using std::cout;

std::cin>>...;
cout <<...;

*/