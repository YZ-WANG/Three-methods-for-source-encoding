//
//  main.cpp
//  Arithmetic
//
//

#include <iostream>
#include "Arithmetic.h"
#include <string>
#include <time.h>
using namespace std;

int main()
{
	Arithmetic test;   //ʵ����
	clock_t start, end;  
	start = clock();
	test.open("C:/Users/Administrator/Desktop/news.txt");  //���ļ�
	test.Press();   //ѹ���ļ�
	end = clock();
	cout << endl<<endl<<"ѹ����ʱ��";
	cout << double (end - start) << "/ms" << endl << endl;   //��ʾѹ����ʱ
	start = clock();
	test.Decode("C:/Users/Administrator/Desktop/news.txt.ari", "C:/Users/Administrator/Desktop/nextnews.txt");  //��ѹ�ļ�
	cout << "��ѹ��ʱ��" ;   
	cout << double (start - end)  << "/ms" << endl << endl;    //��ʾ��ѹ��ʱ
	getchar();
	return 0;
}


