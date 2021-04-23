package com.tm.designpatterns.oop;


public class Base1 {

    //�����ೣ��д��
    public final class Constants{
        private Constants() {
            //restrict instantiation
        }
        public static final int TRUE = 1;
        public static final int FALSE = 0;
    }

    //�̳�
    /*
    * ���಻��̳��κθ���Ĺ��췽��������Ĭ�ϵĹ��췽���Ǳ������Զ����ɵģ����Ǽ̳е�
    *
    * ���๹�캯����  ʹ��super() ���ߴ���ָ������ ���� ���캯��
    *
    * ��ֹ�̳�
    * ��������£�ֻҪĳ��classû��final���η�����ô�κ��඼���ԴӸ�class�̳С�
    *
    * ��Java 15��ʼ������ʹ��sealed����class����ͨ��permits��ȷд���ܹ��Ӹ�class�̳е��������ơ�
    * ����
    * public sealed class Shape permits Rect, Circle, Triangle {
      }

      //����ɹ�
      public final class Rect extends Shape {...}

      //����ʧ��
      public final class Ellipse extends Shape {...}
      *
      * 2021 Ӧ�ò���Ԥ��״̬��
      //sealed����Java 15��Ŀǰ��Ԥ��״̬��Ҫ������������ʹ�ò���--enable-preview��--source 15��
      *
      *
      *
    *
    * ����ת�ͣ�upcasting��
    * ��һ���������Ͱ�ȫ�ر�Ϊ�������͵ĸ�ֵ
    *
    * ����ת�� (downcasting)
    *   Person p1 = new Student(); // upcasting, ok
        Person p2 = new Person();
        Student s1 = (Student) p1; // ok
        Student s2 = (Student) p2; // runtime error! ClassCastException!
        *
        *
        *
      ����ת�� �������ж�����
      instanceof �ж�ʵ���ǲ���ĳ������
      ��Java 14��ʼ���ж�instanceof�󣬿���ֱ��ת��Ϊָ�������������ٴ�ǿ��ת�͡����磬�������´��룺
      Object obj = "hello";
        if (obj instanceof String s) {
            // ����ֱ��ʹ�ñ���s:
            System.out.println(s.toUpperCase());
        }
    * */


    //��̬ Polymorphic
    /*
    * Java��ʵ�����������ǻ�������ʱ��ʵ�����͵Ķ�̬���ã����Ǳ������������͡�
    * ��̬�����Ծ��ǣ������ڲ��ܶ�̬�������õ����෽������ĳ�����͵���ĳ��������ִ�е�ʵ�ʷ���������ĳ������ĸ�д������
    *
    *
    *
    *
    *  Override  Object ���� ����
    *
       toString()����instance���ΪString��
       equals()���ж�����instance�Ƿ��߼���ȣ�
       hashCode()������һ��instance�Ĺ�ϣֵ��
       *
       *

       *
       Super  ������ø��෽��
       *
       *

       *
       *

*  final �ؼ���
        final���η����Ƿ���Ȩ�ޣ�����������class��field��method��

        ��final����class������ֹ���̳У�
        ��final����method������ֹ�����าд��
        ��final����field������ֹ�����¸�ֵ��
        ��final���ξֲ�����������ֹ�����¸�ֵ��

        final  ���෽�����final ���ܱ�����Override
        final  �������final  ���ܱ��̳�
        final  �ֶ����final  ���ܱ��޸�  ���ǿ����ڹ��캯���г�ʼ��
       *
       *

    * */

    //final  �ֶ����final  ���ܱ��޸�  ���ǿ����ڹ��캯���г�ʼ��
    class Person {
        public final String name = "Unamed";
    }
    Person p = new Person();
    //p.name = "New Name"; // compile error!

    class Person1 {
        public final String name;
        public Person1(String name) {
            this.name = name;
        }
    }

    //��final���ξֲ�����������ֹ�����¸�ֵ��
    protected void Test(final int i) {
        //i = 1; // compile error !
    }
}
