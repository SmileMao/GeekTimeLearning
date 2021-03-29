package com.tm;

import com.tm.apitest.core.TestJavaBean;
import com.tm.apitest.core.TestStaticBlock;
import com.tm.apitest.core.TestString;

import java.beans.IntrospectionException;
import java.util.Scanner;

public class Main {

    //args �����в���
    // ʹ�ã�
    // $ javac Main.java
    // $ java Main -version
    public static void main(String[] args){
	// write your code here
        //System.out.println("hello world");

        //System.out.println(TestJson.serializeRes());

        //TestReflection.test();

        /*
        double df2 = 1.2 + 24 / 5; // 5.2       24/5 ~= 4
        char a = 'A';     //��ʾASCII�ַ�
        char zh = '��';   //���Ա�ʾ Unicode�ַ�
        int a1 = a;
        int zh1 = zh;
        char a2 = '\u0041';
        char zh2 = '\u4e2d';
        System.out.println(a2);
        System.out.println(zh2);
         */

        //com.tm.apitest.base.base3.cal_pi_value();

        for (String arg : args) {
            if ("-version".equals(arg)) {
                System.out.println("v 1.0");
                break;
            }
        }

        //TestString ts = new TestString();
        //ts.test1();

        try {
            TestJavaBean.test1();
        }catch (IntrospectionException e) {}

        //���� static��͹��캯���ĵ����Ⱥ�˳��
        TestStaticBlock staticBlock = new TestStaticBlock();
    }
}
