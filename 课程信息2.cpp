#include <iostream>
#include <fstream>  
#define M 100 
#define N 10 
#define NU 20 
#include<string>
using namespace std;
typedef struct  sub 
{ 	 string num;				//�γ̱��
	 string book;			//�γ���
	 string start;				//����ѧ��
}sub; 
 typedef struct  subject 
 {
	 sub data[M];  
	 int len;
 }subject; 

 /*���ļ��е���Ϣд��������*/
subject readFile(subject L){
	ifstream cla("class.txt");
	cla.seekg(ios::beg);
	string s;
	getline(cla,s);
	while ( getline(cla,s) ){
		L.len++;
		int n,l=0;
		n=s.find("------");
		int flag=1;
		while(l<=s.size()){	
			string sh=s.substr(l,n);
			if(flag==1) L.data[L.len].num=sh;
			else if(flag==2) L.data[L.len].book=sh;
			else if(flag==3) L.data[L.len].start=sh;
			n=s.find("------",n);
			l+=n;
			l+=6;
			flag++;
		}
	}
	return L;
}
/*������д���ļ���*/
void writeFile(subject L){
	 ofstream clas("class.txt");
     //	clas.seekg(ios::beg);
	 int a;
	 clas<<"�γ̱��------�γ���------����ѧ��"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 clas<<L.data[a].num<<"------"<<L.data[a].book<<"------"<<L.data[a].start<<endl;
	 }
	// cla.close();
}
 /*6.0 �γ���Ϣ����Ŀ¼*/
  void sub_menu(){
	cout<<"�γ���Ϣ����"<<endl;
	cout<<"1.��ӿγ���Ϣ"<<endl;
    cout<<"2.ɾ���γ���Ϣ"<<endl;
	cout<<"3.�޸Ŀγ���Ϣ"<<endl;
	cout<<"4.���ҿγ���Ϣ"<<endl;
	cout<<"5.����γ���Ϣ"<<endl;
	cout<<"6.�˳�"<<endl;
 }
 /*6.4.1��ѯ�γ̱��*/
 int searchBynum(subject L,string num){
	int i,s=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].num==num)
		{s=i;break;}
	}
	return s;
 }
 /*6.4.2��ѯ�γ�����*/
 int searchByBook(subject L,string book){
	int i,b=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].book==book)
		{b=i;break;}
	}
	return b;
 }
/*6.1.����*/
subject insert(subject L){
	L.len++;
	int s=0,b=0;
	int n=L.len;
	cout<<"������γ̱��:";  
	cin>>L.data[n].num;
	s=searchBynum(L,L.data[n].num);
	while(s!=n)  
    {  
       cout<<"�ñ���Ѵ��ڣ�������������ţ�";  
       cin>>L.data[n].num;  
	   s=searchBynum(L,L.data[n].num);
    }  
	cout<<"������γ���:";  
	cin>>L.data[n].book;
	b=searchByBook(L,L.data[n].book);
	while(b!=n)  
    {  
       cout<<"�ÿγ����Ѵ��ڣ������������γ�����";  
       cin>>L.data[n].book;     
	   b=searchByBook(L,L.data[n].book);
    }  
	cout<<"�����뿪��ѧ��:";  
	cin>>L.data[n].start;
	return L;
}
/*6.2.ɾ��Ŀ¼*/
void delecla_menu(){
	cout<<"����***ɾ���γ���Ϣ����"<<endl;
	cout<<"1.�γ̱��"<<endl;
    cout<<"2.�γ���"<<endl;
	cout<<"3.����ѧ��"<<endl;
	cout<<"4.�˳�"<<endl;
 }
/*6.6.0ɾ����󲿷�ǰ*/
subject dele(subject L,int s){
	int j;
	for(j=s+1;j<=L.len;j++){
		L.data[j-1]=L.data[j];
	}
	L.len--;
	cout<<"ɾ���ɹ�;"<<endl;
	return L;
}
/*6.2.1���γ̱��ɾ��*/
subject deleByNum(subject L,string i){
	int s;
	if(L.len==0) {cout<<"��գ�����ɾ��"<<endl;}
	else{
		s=searchBynum(L,i);
		cout<<s;
		if(s<1||s>L.len) {cout<<"�Ҳ����˿γ�"<<endl;}
		else{
			L=dele(L,s);
		}
	}
	return L;
}

/*6.2.2���γ���ɾ��*/
subject deleByName(subject L,string book){
	int b=0;
	b=searchByBook(L,book);
	if(b==0){cout<<"�����ڴ˿γ�!!"<<endl;}
	else{
		L=dele(L,b);
	}
	return L;
}
/*6.2.3��ѧ��ɾ��*/
subject deleByStart(subject L,string start){
	int i;
	for(i=1;i<=L.len;i++){
		if(L.data[i].start==start){
			L=dele(L,i);
		}
	}
	return L;
}
/*6.3.0��*/
void updatecla_menu(){
	cout<<"�޸Ŀγ�***��Ϣ����"<<endl;
	cout<<"1.�γ���"<<endl;
    cout<<"2.����ѧ��"<<endl;
	cout<<"3.�˳�"<<endl;
}
/*6.3.1�޸Ŀγ�*/
subject updateName(subject L){
	string num;
	string book;
	cout<<"������Ҫ�޸ĵı��:";
	cin>>num;
	cout<<"������Ҫ�޸ĵĿγ�:";
	cin>>book;			
	int b=searchByBook(L,book);
	if(b==0) {L.data[b].book=book;cout<<"�޸ĳɹ�"<<endl;}
	else cout<<"�ÿγ̺��Ѿ����ڣ����Ϊ"<<L.data[b].num<<endl;
	return L;
}
/*6.3.2 �޸Ŀ���ѧ��*/
subject updateStart(subject L){
	string num,start;
	cout<<"������Ҫ�޸ĵı��:";
	cin>>num;
	cout<<"������Ҫ�޸ĵĿ���ѧ��:";
	cin>>start;
	int n=searchBynum(L,num);
	L.data[n].start=start;
	cout<<"�޸ĳɹ�"<<endl;
	return L;
}
/*6.4��ѯ*/
void searchcla_menu(){
	cout<<"����**��Ϣ��ѯ�γ̹���"<<endl;
	cout<<"1.�γ̱��"<<endl;
	cout<<"2.�γ���"<<endl;
    cout<<"3.����ѧ��"<<endl;
	cout<<"4.�˳�"<<endl;
}
/*6.4.0 ���ݱ����*/
void out_one(subject L,int num){
	cout<<"�γ̱��------�γ���------����ѧ��"<<endl; 
	cout<<L.data[num].num<<"------";
	cout<<L.data[num].book<<"------";
	cout<<L.data[num].start<<endl;
}
/*6.4.1 ���ݱ�Ų�*/
subject search_num(subject L){
	string num;
	int n;
	cout<<"�������ѯ�ı��:";
	cin>>num;
	n=searchBynum(L,num);
	cout<<n;
	if(n==0) cout<<"�����ڸñ��;"<<endl; 
	else out_one(L,n);	
	return L;
}
/*6.4.2 ���ݿγ�����*/
subject search_name(subject L){
	string book;
	int b;
	cout<<"�������ѯ�Ŀγ���:";
	cin>>book;
	b=searchByBook(L,book);
	if(b==0) cout<<"�����ڸÿγ���;"<<endl;
	else out_one(L,b);
	return L;
}
/*6.4.3 ���ݿ���ѧ�ڲ�*/
subject search_start(subject L){
	string start;
	cout<<"�������ѯ�Ŀ���ѧ��:";
	cin>>start;
	int flag=0;
	for(int i=1;i<=L.len;i++){
		if(L.data[i].start==start)
			{out_one(L,i);flag=1;}	
	}
	if(flag==0) cout<<"�����ڸ�ѧ�ڵĿγ�"<<endl;
	return L;
}
/*6.5��*/
void out(subject L) {
	 int a;   
	 cout<<"�γ̱��------�γ���------����ѧ��"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 cout<<L.data[a].num<<"------";
		 cout<<L.data[a].book<<"------";
		 cout<<L.data[a].start<<endl;
	 }
 }

void main(){
   	subject L;  
   	string num;
	int x;
	L.len=0;
	sub_menu();
	L=readFile(L);
	while(1){
		cout<<endl;
		cout<<"������Ҫʵ�ֵĹ��ܣ�";
		cin>>x;
		switch(x){
		case 1:{L=insert(L);break;
			   }
			case 2:{	delecla_menu();
						int y;
						char con='y';
						string book;
						string start;
						while(con=='y'){
							cout<<"�������й�ɾ���Ĺ���:";
							cin>>y;
							//1����ţ�2���� 3.��ѧ��
							if(y==1) {cout<<"������Ҫɾ���γ̵ı��:";cin>>num;L=deleByNum(L,num);}
							else if(y==2) {cout<<"������Ҫɾ���Ŀγ���:";cin>>book;L=deleByName(L,book);}
							else if(y==3) {cout<<"������Ҫɾ����ѧ�ڿγ̣�";cin>>start;L=deleByStart(L,start);}
							else if(y==4) exit(0);	
							cout<<endl;
							cout<<"�Ƿ����ɾ����y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 3:{	updatecla_menu();
						int y;
						char con='y';
						while(con=='y'){
							cout<<"�������й��޸ĵĹ���:";
							cin>>y;
							//1���� 2.��ѧ��
							if(y==1)	L=updateName(L);
							else if(y==2) L=updateStart(L);
							else if(y==3) exit(0);	
							cout<<endl;
							cout<<"�Ƿ�����޸ģ�y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 4:{	searchcla_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"�������йز�ѯ�Ĺ���:";
							cin>>y;
							//1.���  2.�γ���  3.����ѧ��
							if(y==1) L=search_num(L);
							else if(y==2) L=search_name(L);
							else if(y==3) L=search_start(L);
							else if(y==4) exit(0);
							cout<<endl;
							cout<<"�Ƿ�����޸ģ�y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
				   }
			case 5:out(L);break;
			default:{writeFile(L);exit(0);}
		}		
	}
}

