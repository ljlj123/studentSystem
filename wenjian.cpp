//����strtokʵ��split
#include <iostream>
#include <string>
 using namespace std;
void main()
{
	string s="2--5--1";
	cout<<s<<endl;
	int n,len=0;
	n=s.find("--");
	while(len<=s.size())
	{	//cout<<n<<endl;
		cout<<s.substr(len, n)<<endl; //��ȡs�д�pos��ʼ������0����n���ַ����Ӵ���������
		n=s.find("--",n);
		len+=n;
		len+=2;
	}
}
