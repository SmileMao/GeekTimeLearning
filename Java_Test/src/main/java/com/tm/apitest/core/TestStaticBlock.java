package com.tm.apitest.core;

/*
* ���� static��͹��캯���ĵ����Ⱥ�˳��
*
* �����
*
*   [TestStaticBlock] - static block
    [TestStaticBlock] - ctor block
* */
public class TestStaticBlock {
    public TestStaticBlock() {
        System.out.println("[TestStaticBlock] - ctor block");
    }

    static
    {
        System.out.println("[TestStaticBlock] - static block");
    }
}
