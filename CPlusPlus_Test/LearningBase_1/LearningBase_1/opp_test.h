#pragma once

/*
Object Oriented Programming   OOP
Object Oriented Design	      OOD

�����֮��Ĺ�ϵ�����·�Ϊ����    
Inheritance �̳�
Composition ���
Delegation  ί��




### Composition ��� ��ʾ has-a

���õ����ģʽ��
Adapter

��: 
class Container {
public:
	Container();
	~Container();
protected:
	Component c1;
}

class Component {
public:
	Component();
	~Component();
}

<�������ڶ���>
Container�Ĺ��캯���ȵ���Component��default���캯����Ȼ����ִ���Լ�
Container::Container()  :  Component() {...};                            ʹ�ù��캯���ĳ�ֵ���﷨ʵ��
���� Component() Ϊ������Ĭ�ϵ��ã�Ĭ�ϲ���Ҫд
���Ը����Լ������ֶ�д�ϲ�ͬ��������캯��

<�����������>
Container��������������ִ���Լ���Ȼ��ŵ���Component����������
Container::~Container() { ...  ~Component() }		



### Delegation ί��   Composition by reference ��������ָ�����ೣ˵��reference��
��ָ�룬������������

���� �ۺ� 

��������ϣ���û����Ͻ��ܣ��������ڲ�һ������ϵ����岻�����򲿷�Ҳ�������ˣ��ۺϵ����岻���ڵ��ǲ�����Ȼ���ڣ�

���˼�룺  
pimpl  ==>  pointer to impl  ��Handle  /  Body��
ָ��ָ�����ʵ��(Body)   �����ṩ�ⲿ�ӿڣ�Handle��
�������ǽ�����壨Handle�����ñ���

���ü�����reference counting��   ��ʵ�ֹ����ַ���
a -->
b ->  n (reference counting) -> Hello   
c -->

�����ʱ�� ��Ҫ���� �Ķ���Ӱ������
����һ�����copy on write ������һ�ݳ��������޸ģ�




### Inheritance �̳� ��ʾ is-a
C++ �����ּ̳�

����
struct _List_node_base
{
	_List_node_base* _M_next;
	_List_node_base* _M_prev;
}

template<typename _Tp>
struct _List_node
	: public _List_node_base  // : private _List_node_base  // : protected _List_node_base
{
	_Tp _M_data;
}


Base   ���ļ�ͷ <1----   Derived

<�������ڶ���>
Derived�Ĺ��캯�����ȵ���Base��default�Ĺ��캯����Ȼ���ִ���Լ�
Derived::Derived() : Base() {};                                   ----->  :Base() �Ǳ�����Ĭ�ϻ���õ�  �������Ҫִ�и����������캯�� ����Ҫд����

<�����������>
Derived��������������ִ���Լ���Ȼ��ŵ���Base����������
Derived::~Derived() {... ~Base()};

@ע�⣺  Base class��dtor ������ virtual, �������� undefined behavior



*/