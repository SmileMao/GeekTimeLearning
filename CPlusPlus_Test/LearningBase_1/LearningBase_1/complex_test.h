//ͷ�ļ�����ʽ����

//��ʽ1. �ɱ������ṩ��֤  ͬһ�ļ����ᱻ�������
#pragma once  

//��ʽ2. ����ʽ  ����ʽ  ����  guard
#ifndef __COMPLEX__
#define __COMPLEX__

/*
�������ļ��

1. ���ݶ�����private
2. ��������ͨ��reference����  ����������Ƿ���Ҫ��const �����ȿ��Ǵ������ã�
3. ����ֵ����ͨ��reference����							�����ȿ��Ǵ������ã�
4. �����еĺ�������Ա������ �ܼ�const�ľ�����			 ������ı亯���ڲ��������ݣ�ʱ ���const		
5. ���캯������ʹ�ó�ʼ��





*/




/*******************************************************************    ǰ������    ***************************************************************/

#include <cmath>

class ostream;
class complex;

complex&
	__doapl(complex* ths, const complex& r);




/*****************************************************************      ������      *************************************************************/
class complex										//class head
{													//class body start

//access level���ʼ���  ���Խ���д ��һ����Ҫд��������
public:
	//ctor :  ��������Я��Ĭ��ֵ Ĭ��ʵ��
	complex(double r = 0, double i = 0)
		: re(r), im(i)							   //��ʼ�У���ֵ��(initialization list)  Ч�ʸ��� �ڹ��캯���ڲ����и�ֵ���� ������ʼֵ assignments��
												   //������ֵ�������׶Σ���ʼ���� ��ֵ
	{}

	//complex() : re(0), im(0) {}				   //������캯���������Ĭ��ֵ�� �޷�ͬʱ����  �����Ϻ�������

	complex& operator += (const complex&);		   //����-���ô��� (������ to const ���ᱻ���շ��޸�Ӱ������) 
												   //����ֵ���ݣ����ô���

	//�������������ܿ��ܻᱻ�����������inline
	double real() const { return re; }			   //const  λ����() �� {} ֮��
	double imag() const { return im; }			   //����  ����������ı��������� ���const ��ȡ�����в��� ��������Ҫȡ�� ����Ҫ�ı�
												   //�κβ���ı����ݳ�Ա�ĳ�Ա���� ��������const  
												   //��������޸������ݳ�Ա ���ߵ����˷�const ��Ա���� �������ᱨ�� ���ӳ���׳��

	//����
	void real(double r) { re = r; }


	//test friend func
	//int func(const complex& param) { return param.re + param.im; } // ͬһ��class�ĸ���object �˴˻�Ϊ��Ԫ 	c2.func(c1);

//���ݾ�������private
private:
	double re, im;

protected:
	double test;

	friend complex& __doapl(complex*, const complex&); //��Ԫ ���Լӵ�������   ���������������ȡ�� friend �� private�ĳ�Ա
														//Ҳ����ͨ���������������ݣ� ��û��ֱ���ÿ죬 ����friend�����˷�װ������

};


//��չ������������inline�� ִ��Ч�ʸ� 
//���壺������class body�ڶ�����ɣ����Զ���Ϊinline��ѡ�������������ѡ��
//����̫���� ���ܾ��޷�������������Ϊinline
//������class body �ⶨ��ģ������ڲ�ʵ�ּ򵥣�����������inline �����ѡ
/*
inline double imag(const complex& x)
{
	return x.imag();
}*/


//��չ�����캯��
//���涼�Ǵ�������ķ�ʽ
/*
complex c1(2, 1);
complex c2;
complex* p = new complex(4);
*/

//����ѹ��캯������private�� �������ǵ���ģʽ Singleton
/*
class A {
public:
	static A& getInstance();
	setup() {...}

private:
	A();
	A(const A& rhs);
	...
};

A& A::getInstance()
{
	static A a;
	return a;
}

����
A::getInstance().setup();

*/

//��չ����������(overloading) ���������캯��
//������ʵ�����Ʋ�һ��
//�������س������ڹ��캯��
//���������������Ĭ��ֵ��Ҫע���û�в����ĺ����ܲ��ܹ�������


//��չ��const ����
/*
	const complex c1(2, 1); //����һ��const ����
	cout << c1.real();      //real() ��Ҫconst ����
	cout << c1.imag();	    //imag() ��Ҫconst ����
*/


//��չ�� ��������
//pass by value vs. pass by reference(to const)
//���þ���ͨ��ָ��ʵ�ֵ�
//�������þ��Ǵ���ָ�� Ч�ʿ�
//c++ ���� ����ȫ����������������
//���� ����������� ��������˵Ĳ�ȷ���޸� ��Ӱ�촫�ݷ�  ����ѡ�� ���� reference (to const)
//ϸ���� �������ֻ��һ�����ֽڣ���ָ�����ĸ��ֽڣ��ǿ��Դ���ֵ�ķ�ʽ

//��չ�� ����ֵ����
//return by value vs. return by reference(to const)
//����ֵ�Ĵ���Ҳ������������


//ʲô����¿��Դ�ֵ ʲô����¿��Դ�����
/*
����������������У���Ҫ������ʱ���������ݣ���������ʱ����ʱ����Ӧ�ñ����ݵ��ⲿ�����ã���������²��ܴ�������
�����Ĳ��� ���һ�����ᱻ�Ķ� �ڶ��������ᱻ�Ķ� ��Ҫ���ڶ��������ӵ���һ������ʱ ���Դ�������


//���������ݲ������������
//���1����������������ݴ�ŵ�ĳ��������
inline complex&
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
//���2�����������¿ռ��Ų����������
//������ c3�����������ں�������ʱ�Ѿ����� ��local���� ���ܰ����ô���ȥ
inline complex&
__doapl(complex* ths, const complex& r)
{
	complex c3;
	c3.real(r.re);
	return c3;
}
*/


//��չ: ��Ԫ
//ͬһ��class�ĸ���object �˴˻�Ϊ��Ԫ
//����int func(const complex& param) { return param.re + param.im; }  ֱ���ó�Ա
//    c2.func(c1);


//��չ������������  (operator overloading)   //��ͬ����λ�ã���Ա����
//������ʵ����һ������
/* ���� c2 += c1
��Ԫ������ ������������������������
�������Ὣ += ������������
��������� += �����壨���أ� ����������ִ�ж�Ӧ�Ĳ���������
*/

/*
1. ��Ա����

���г�Ա������������صĲ��� this pointer��  ���������������д��������� ���Ǻ����ڿ����õ��� ͬʱ��ͬ������ ���this��λ��Ҳ��һ����ͬ
����__doapl  ==>  do assignment plus
inline complex&
complex::operator += (const complex& r)
{
	return __doapl(this, r);
}

inline complex&
complex::operator += (   this,    const complex& r)
{
	return __doapl(this, r);
}

c2 += c1;
��thisָ��c2�ĵ�ַ 


return by reference �﷨����
����������֪������������reference��ʽ���յ�
inline complex&                                       //����
__doapl(complex* ths, const complex& r)				  //complex* ����ָ��
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;									  //ָ����ָ��Ķ��� value / object		��Ϊths��ָ�� *ths��Ϊָ��ָ��Ķ���
}
### ������ʵ���Դ��� ��ָ�롷 ���ǻ����ӽ����ߵĲ����Ѷ� ��Ҫ����ָ��


���ڴ�����������
c3 += c2 += c1  �ȵ���c2 += c1������ֵt21, Ȼ�����c3 += t21
���������+=���ز������������ܷ���value ��Ȼ�޷�ʵ����������

*/



/***************************************************************     �ඨ��     **************************************************************/

inline complex&
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
	return __doapl(this, r);
}

/*
class body ��ĸ��ֶ��� ��definitions��

2. ȫ�֣�ȫ�򣩺���
����class���Ƶĺ���
���֣�

��Ա����
inline complex&
complex::operator += (   this,    const complex& r)
{
	return __doapl(this, r);
}

ȫ�ֺ���
inline double
imag(const complex& x)
{
	return x.imag();
}
*/

//��չ������������  (operator overloading)   //��ͬ����λ�ã��ǳ�Ա���� 
/*
ȫ�ֺ��� ����Я������this
Ϊ���������󣬿�����Ҫ���ض��

����
���� + ����
inline complex
operator + (const complex& x, const complex& y)
{
	return complex (real(x) + real(y), imag(x) + imag(y));
}

ʵ�� + ����
inline complex
operator + (const complex& x, double y)
{
	return complex (real(x) + y, imag(x));
}
inline complex
operator + (double x, const complex& y)
{
	return complex ( x + real (y), imag(y));
}

�ȵȡ�����

������������ֵ �ض��� local object  �������� return by reference  ���� return by value
��ͬ��ԭ�ȵ����� ����һ�����ӵ���һ���Ѿ����ڵ�����
������������������ ���һ���µ���ֵ����Ҫ����������
������Ƿ������ã��ں�������ʱ���������������������ھͽ����ˣ��������ȥ���ã���ô���ö�������ǿ�ֵ

��һ�������ܷ񷵻����ã�����������Ƿ���Ҫ���ڲ�������ʱ���ݲ���Ҫ�����ⲿ��


��չ����ʱ����temp object   û������
 ���﷨��typename();
 ����
 inline complex
operator + (double x, const complex& y)
{
	return complex ( x + real (y), imag(y));
}

������ʱ���������̷���
complex ( x + real (y), imag(y));

���𴴽�����
complex c1(2, 1);
complex c2;

������ʱ����
complex();
complex(4, 5);
complex(2);
ע�⣺ִ�е���һ�� ��������ʱ��������������Ѿ�����



��չ������������
��������ȡ�� ȡ��������
inline complex
operator + (const complex& x)
{
	return x;
}

// �޸�Ϊ�������� Ӧ��Ҳ���� ��Ϊ���صľ���ԭ����ֵ
inline complex&
operator + (const complex& x)
{
	return x;
}

inline complex
operator - (const complex& x)
{
	return complex(-real(x), -imag(x));
}

// complex c1(2, 1);
// complex c2;
// cout << -c1;
// cout << +c1;

����
//�������ʵ����ȣ��鲿�����෴
inline complex
conj (const complex&)
{
	return complex(real(x), -imag(x));
}


��չ��������������� - ȫ�ֺ���
�������ò�����
����
#include <iostream.h>
ostream& 
operator << (ostream& os, const complex& x)
{
	return os << '(' << real(x) << ',' 
			  << imag(x) << ')';
}

C++û����������ֵ�ϵĲ�����

����
complex c1(2, 1);
cout << conj(c1);
// << ������ ����cout��   cout�Ǳ�׼��Ķ��� ����ѯ��׼�� �������� ostream��  ����ʶ �¶���� conj(c1) ���Բ��ܰ� << �����غ���д�ɳ�Ա����
//ע�⣺���ܰ����ô��ڵĲ����� �����غ��� д�ɳ�Ա���� ֻ��д��ȫ�ֺ��� ��
// ����<<�ĺ����еĲ��� ���� ostream& ָ�� cout  const complex& ָ�� conj(c1)

// ����д   ostream& 
			operator << const (ostream& os, const complex& x) 
			{...} ��
// ����д const ��ԭ���� �����ڲ� �� cout / os ����(<<) ��Ҫ��ӡ������ʱ �Ѿ�����os��

// ����������ʵ������ void ���ǿ��ǵ�ʹ���߻��������
// ����д   void
			operator << (ostream& os, const complex& x)
			{...} ��
����
cout << c1 << conj(c1);
// �����c1 �õ��Ľ���ٽ��� conj(c1)  �Ƿ��ص���Ҫ�� cout  �����Ƿ���return by value ���� by reference ��Ϊ os�ں����ڲ�����local����  ��д�� ostream&
// ��������ǰ���ܼ� const  ������ ���c1 �� ����Ҫ�ı�cout ��� conj(c1)
// ����д   const ostream& 
			operator << (ostream& os, const complex& x) 
			{...} ��
//�����������ֵ���� by value �Ǽ�const û�м�ֵ
��:
double real() const { return re;}
д�� const double real() const {return re;}




//���Ҫʵ��Υ�������д�� ����Ȼ�ǲ��Ƽ�������
����
complex c1(1, 2);
c1 << cout;

����ʵҲ������complex�����ز����� <<   
ֻ����������ֵ�� ���Կ�����Ϊ��Ա���� ����this
�ڲ�ʵ�� ������
void
complex::operator << (ostream& os)
{
	os << real() << imag();
}


*/


#endif