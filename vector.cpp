#include<iostream>
#include<string> 
#include<vector>
#define M 100 
#define N 10 
#define NU 20 
using namespace std; 
typedef struct  Student
{  
    string no;  //ѧ��
    string name;//����
    string cla;   //�༶
	int sex;		//�Ա�  0��1 Ů
	string phone;//�ֻ�����
	vector<int> a;	//	ѡ�޿γ�
}Student; 
typedef struct stu{
	Student data[M];
	int len;
}stu;
void main(){
	stu S;
	S.data[0].a.push_back(5);
	S.data[0].a.push_back(4);
	S.data[0].a.pop_back();
	for(int i=0;i<S.data[0].a.size();i++){
		cout<<S.data[0].a[i]<<endl;
	}
	//cout<<S.data[0].a.size()<<endl;

}