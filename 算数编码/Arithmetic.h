//
//  Arithmetic.h
//  Arithmetic
//
//

#ifndef Arithmetic_h
#define Arithmetic_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <wchar.h>
using namespace std;

class Arithmetic
{
public:
	string FileAddress; //���������ļ���ַ
	int TotalNumber = 0;  //��¼�ܵ�bit��
	int NumList[2] = {0};   //�洢0��1���ֵĴ���
	long double ProbaList[2] = {0.0};   //�洢0��1���ֵĸ���
	long double P[2] = {0.0};     //�洢0��1�������������
	Arithmetic();   //���캯��
	void open(string input);
	void Press();   //ѹ���ļ�
	void Decode(string sourcefile, string dstfile); //��ѹ�ļ�

};




#endif /* Arithmetic.h */
#pragma once
#pragma once
