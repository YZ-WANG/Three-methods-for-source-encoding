//
//  Arithmetic.cpp
//  Arithmetic
//

#include "Arithmetic.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include<math.h>
using namespace std;


Arithmetic::Arithmetic()
{

}


void Arithmetic::open(string input)   //����Ŀ���ļ���ַ
{
	FileAddress = input;
}


void Arithmetic::Press()  //����ѹ��
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);    // �������С���ľ���ΪС�����10λ

	ifstream read;
	read.open(FileAddress, ios::in | ios::binary);
	if (!read)
	{
		cout << "�ļ���ȡ����" << endl << endl;
		return;
	}

	ofstream write;
	write.open(FileAddress + ".ari", ios::out | ios::binary);
	if (!write)
	{
		cout << "����ļ����ܽ���(*.lz)" << endl;
		return;
	}

	char *InChar = new char;
	
	int len(0);
	int BitList[8];
	long int reg(0);
	long double C(0.0);
	long double B(0.0);
	long double A(1);

	read.read((char*)InChar, sizeof(unsigned char));    //����һ���ֽ�
	while (!read.eof())   //δ����ĩβ����ѭ��
	{
		TotalNumber += 8;   //ÿ����һ���ַ�����bit����8
		BitList[0] = (*InChar & 0x80) == 0x80 ? 1 : 0;
		BitList[1] = (*InChar & 0x40) == 0x40 ? 1 : 0;
		BitList[2] = (*InChar & 0x20) == 0x20 ? 1 : 0;
		BitList[3] = (*InChar & 0x10) == 0x10 ? 1 : 0;
		BitList[4] = (*InChar & 0x08) == 0x08 ? 1 : 0;
		BitList[5] = (*InChar & 0x04) == 0x04 ? 1 : 0;
		BitList[6] = (*InChar & 0x02) == 0x02 ? 1 : 0;
		BitList[7] = (*InChar & 0x01) == 0x01 ? 1 : 0;    //���ֽڷָ��bit��ʽ

		for (int i(0); i < 8; i++)       //�ж�bitΪ0����1
		{
			if (BitList[i] == 0)
			{
				NumList[0] ++;
			}
			if (BitList[i] == 1)
			{
				NumList[1] ++;
			}
		}

		read.read((char*)InChar, sizeof(unsigned char));   //�������ϸ��ֽڵ�����£�����һ���ֽ�
	}

	cout <<endl<< "ѹ������bit��Ϊ��" << TotalNumber << endl;
	cout << "  ����0�ĸ���Ϊ��" << NumList[0] << endl;
	cout << "  ����1�ĸ���Ϊ��" << NumList[1] << endl;
	ProbaList[0] = long double(NumList[0]) / TotalNumber;    //����0��1���ֵĸ���
	ProbaList[1] = long double(NumList[1]) / TotalNumber;
	
	P[0] = 0;    //����0��1�������������
	P[1] = ProbaList[0];   

	cout << endl << "bit0���ֵĸ���Ϊ��" << "	" << ProbaList[0];
	cout << endl << "bit1���ֵĸ���Ϊ��" << "	" << ProbaList[1];
	


	read.clear();    //��ָ������ļ�ͷ
	read.seekg(0);

	read.read((char*)InChar, sizeof(unsigned char)); //����һ���ֽ�
	while (!read.eof())
	{	
		for (int i(0); i < 1; i++)
		{
			BitList[0] = (*InChar & 0x80) == 0x80 ? 1 : 0;
			BitList[1] = (*InChar & 0x40) == 0x40 ? 1 : 0;
			BitList[2] = (*InChar & 0x20) == 0x20 ? 1 : 0;
			BitList[3] = (*InChar & 0x10) == 0x10 ? 1 : 0;
			BitList[4] = (*InChar & 0x08) == 0x08 ? 1 : 0;
			BitList[5] = (*InChar & 0x04) == 0x04 ? 1 : 0;
			BitList[6] = (*InChar & 0x02) == 0x02 ? 1 : 0;
			BitList[7] = (*InChar & 0x01) == 0x01 ? 1 : 0;
			
			for (int j(0); j < 8; j++)   //���ַ����е�һ���ֽڱ���
			{
				if (BitList[j] == 0)
				{
					C = C;
					A = A * ProbaList[0];
				}

				else
				{
					C = C + A * P[1];
					A = A * ProbaList[1];
				}
			}

			read.read((char*)InChar, sizeof(unsigned char)); //��һ���ֽ�
			if (read.eof())  break;
		}
		
		len = -log(A) / log(2) + 1;  //ȷ���������
		B = C * (pow(10, len));
		B += 0.5;
		C = B / (pow(10, len));

		write << setiosflags(ios::fixed) << setprecision(len) << C;  //��ѹ��������������ѹ���ļ���
		write << "	";
		C = 0;   //��C��A��λ
		A = 1;
		
	}

	read.close();
	write.close();
}





void Arithmetic::Decode(string sourcefile, string dstfile)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);

	ifstream readfile;
	ofstream putfile;
	readfile.open(sourcefile);
	if (!readfile)
	{
		cout << "��ѹ�ļ���ȡ����(*.ari)" << endl << endl;
		return;
	}

	putfile.open(dstfile);
	if (!putfile)
	{
		cout << "��ѹ�ļ���������" << endl;
	}

	long double temp(0);   //���Ա�����������
	int OutList[8];
	int count(0);
	int OutChar(0);

	count = TotalNumber;
	readfile >> temp;  //�����һ������

	while (!readfile.eof())
	{
		for (int i(0); i < 1; i++)
		{
			if (count == 0)		break;  //����Ѿ������ļ������˳�ѭ��

			for (int j(0); j < 8; j++)
			{
				if (temp >= P[1])
				{
					count -= 1;
					OutList[j] = 1;
					temp = (temp - P[1]) / ProbaList[1];				
				}

				else
				{
					count -= 1;
					OutList[j] = 0;
					temp = (temp - P[0]) / ProbaList[0];
				}
			}

			OutChar = OutList[7] + OutList[6] * 2 + OutList[5] * 4 + OutList[4] * 8 + OutList[3] * 16 + OutList[2] * 32 + OutList[1] * 64 - OutList[0];
			putfile << char(OutChar);   //���ֽ�Ϊ��λ���
		}

		
		readfile >> temp;   //����һ������
	}

	readfile.close();
	putfile.close();
}
