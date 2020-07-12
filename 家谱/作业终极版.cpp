#include "stdlib.h"      
#include"iostream"
#include"fstream"
#pragma warning(disable:4996)
using namespace std;
typedef struct {
	char name[50];//����
	char sex[50];//�Ա�
	int brithday;//����
	int deaday;//����
	char work[50];//����
	char school[50];//ѧ��
	int  beifen;//����

}StructNode;
typedef struct Node {
	StructNode data;
	struct Node* lc;//��ָ��
	struct Node* rc;//��ָ��
}TreeNode;
int man;//��
int woman;//Ů
int num;//������
int sum;//�����ܺ�
int now;//������
int go;//ȥ����
int y = 2020;//����
TreeNode* root;//��ָ��
TreeNode* findLocation(TreeNode* b, char cname[]) //��ѯλ��
{
	TreeNode* p;
	if (b == NULL)   return NULL;
	if (strcmp(b->data.name, cname) == 0)
		return b;
	if (b->lc) {
		p = findLocation(b->lc, cname);
		if (p)return p;
	}
	if (b->rc) {
		p = findLocation(b->rc, cname);
		if (p)return p;
	}
	
	return NULL;
}
TreeNode* creatFirst()//�����������
{
	TreeNode* p;
	p = new Node;//�����µĽڵ�
	cout << "������������:" << endl;
	cin >> p->data.name;
	cout << "���������ڵ��Ա�(��/m��Ů/n)" << endl;
	cin >> p->data.sex;
	cout << "�������ڵĵ���ʱ�䣺" << endl;
	cin >> p->data.brithday;
	cout << "�������ڵ�����ʱ�䣺(û��������0)" << endl;
	cin >> p->data.deaday;
	cout << "�������ڵ�ѧ����" << endl;
	cin >> p->data.school;
	cout << "�������ڵ�ְҵ��" << endl;
	cin >> p->data.work;
	p->lc = p->rc = NULL;//�����������
	p->data.beifen = 1;//��ǰ����Ϊ1
	cout << "���ڴ����ɹ�" << endl;
	return p;

}
TreeNode* creatNode()//����һ���µĽڵ�
{
	int flag = 0;
	TreeNode* m = NULL;//ָ���ʼ��
	TreeNode* p;
	p = new Node;//�����µĽڵ�
	cout << "��������:" << endl;
	cin >> p->data.name;
	m = findLocation(root, p->data.name);//���ҵ�ǰ���ַ��صı���
	if (m != NULL)
	{
		cout << "��������!!!\n";
		p = NULL;
		return p;
	}
	else {
		cout << "�������Ա�(��/m��Ů/n)" << endl;
		cin >> p->data.sex;
		cout << "���뵮��ʱ�䣺" << endl;
		cin >> p->data.brithday;
		cout << "��������ʱ�䣺(û��������0)" << endl;
		cin >> p->data.deaday;
		cout << "����ѧ����" << endl;
		cin >> p->data.school;
		cout << "����ְҵ��" << endl;
		cin >> p->data.work;
		return p;
	}
}
TreeNode* changeNode()//����Ҫ�޸ĵ��µĽڵ�
{
	int flag = 0;
	TreeNode* m = NULL;//ָ���ʼ��
	TreeNode* p;
	p = new Node;//�����µĽڵ�
	cout << "��������:" << endl;
	cin >> p->data.name;
	cout << "�������Ա�(��/m��Ů/n)" << endl;
	cin >> p->data.sex;
	cout << "���뵮��ʱ�䣺" << endl;
	cin >> p->data.brithday;
	cout << "��������ʱ�䣺(û��������0)" << endl;
	cin >> p->data.deaday;
	cout << "����ѧ����" << endl;
	cin >> p->data.school;
	cout << "����ְҵ��" << endl;
	cin >> p->data.work;
	return p;
	
}
void cunru(TreeNode* p, char name[], int dai, char sex[], int brithday, int deaday, char school[], char work[])//����ṹ��
{
	//��ֵ���ṹ��
	p->data.beifen = dai;
	strcpy_s(p->data.name,name);
	strcpy_s(p->data.sex, sex);
	p->data.brithday = brithday;
	p->data.deaday = deaday;
	strcpy_s(p->data.school, school);
	strcpy_s(p->data.work, work);
    //��ʾ�ļ��Ķ���
	cout << "����:" << p->data.beifen << "  ";
	cout << "����:" << p->data.name << "  ";
	cout << "�Ա�:" << p->data.sex << "  ";
	cout << "����:" << p->data.brithday << "  ";
	cout << "����:" << p->data.deaday << "  ";
	cout << "ѧ��:" << p->data.school << "  ";
	cout << "ְҵ:" << p->data.work << "  " << endl;
}
void find_Function(TreeNode* p, char name[]) //���ҹ���
{
	p = findLocation(p, name);
	if (p == NULL) {
		cout << "��ǰΪ�սڵ�" << endl;
	}
	else {
		cout << "����:" << p->data.beifen << "  ";
		cout << "����:" << p->data.name << "  ";
		cout << "�Ա�:" << p->data.sex << "  ";
		cout << "����:" << p->data.brithday << "  ";
		cout << "����:" << p->data.deaday << "  ";
		cout << "ѧ��:" << p->data.school << "  ";
		cout << "ְҵ:" << p->data.work << "  " << endl;
		cout << p->data.name << "����Ů:";
		if (p->lc == NULL)
		{
			cout<<"������!";
		}
		else {
			cout << "����:" << p->lc->data.beifen <<"  ";
			cout << "����:" << p->lc->data.name << endl;
		}
		if (p->rc == NULL)
		{
			cout<<"���Һ���!";
		}
		else {
			cout << "����:" << p->rc->data.beifen <<"  ";
			cout << "����:" << p->rc->data.name << endl;
		}


	}

}
void add_Function(TreeNode* t)//��ӹ���
{
	TreeNode* p, * q;
	char name[20];
	cout << "��Ҫ��˭�Ķ��ӣ�" << endl;
	cin >> name;
	q = findLocation(t, name);//���ҵ�ǰ���ַ��صı�����Ϊ���׽ڵ�
	if (q == NULL) { cout << "˫�ײ�����" << endl; }
	else {
		p = creatNode();//�����������ף��ʹ���һ���µĽڵ�
		if (p) {
			p->data.beifen = q->data.beifen + 1; // �����丸�׵ı��ּ� 1
			p->lc = p->rc = NULL;
			if (q->lc == NULL) {
				q->lc = p;
				cout << "�����������ɹ���" << endl;
			}
			else {
				q = q->lc;
				//ʹ���ֵ�����
				while (q->rc != NULL) {
					q = q->rc;
				}
				q->rc = p;
				cout << "�����������ɹ���" << endl;

			}
		}
	}
}
void bianli(TreeNode* p, char father[])//д������
{
	ofstream w("D://dzy.txt", ios::app);//׷��
	if (!w) {
		cerr << "file could not be open." << endl;
		exit(0);
	}
	TreeNode* q;
	if (p)//�������Ĳ�Ϊ��
	{	
		w << father << "\t" << p->data.beifen << "\t" << p->data.name << "\t" 
			<< p->data.sex << "\t"<< p->data.brithday << "\t" << p->data.deaday 
			<< "\t" << p->data.school << "\t" << p->data.work << "\t"<< endl;
		bianli(p->lc, p->data.name); //���������� 
		q = p->rc;
		while (q)   //����������          
		{
			w << father << "\t" << q->data.beifen << "\t" << q->data.name << "\t" 
				<< q->data.sex << "\t"<< q->data.brithday << "\t" << q->data.deaday 
				<< "\t" <<q->data.school << "\t" << q->data.work << "\t"<< endl;
			bianli(q->lc, q->data.name);
			q = q->rc;
		}

	}
	w.close();
}
void save_File(TreeNode* p) //�����ļ�����
{
	ofstream ofile;
	ofile.open("D://dzy.txt", ios::out);//����ļ�
	if (!ofile) {
		cerr << "file could not be open." << endl;
		exit(0);

	}	
	if (p) {
		ofile << "\t" << p->data.beifen << "\t" << p->data.name << "\t" 
			<< p->data.sex << "\t" << p->data.brithday << "\t" << p->data.deaday 
			<< "\t" << p->data.school << "\t" << p->data.work << "\t" << endl;
		if (p->lc) {
                    bianli(p->lc, p->data.name);//�ֵ�������������ʼ����
		}
	}
	
	ofile.close();}
void tree(char father[], char son[], int dai, char sex[], int brithday, int deaday, char school[], char work[])//������
{
	TreeNode* t;
	TreeNode* p;
	p = findLocation(root, father);//�ְ�
	if (p == NULL) { return; }
	t = findLocation(root, son);//���ӣ��ҿյ�λ��
	if (t != NULL) { return; }
	if (p->lc == NULL)//��Ӻ���
	{
		p->lc = new Node;
		p->lc->rc = p->lc->lc = NULL;
		cunru(p->lc, son, dai, sex, brithday, deaday, school, work);
		cout << "�����������ɹ���" << endl;
	}
	else//���ǰһ�����ӵ��ֵ�
	{
		p = p->lc;
		while (p->rc != NULL)
			p = p->rc;
		p->rc = new Node;
		p->rc->rc = p->rc->lc = NULL;
		cunru(p->rc, son, dai, sex, brithday, deaday, school, work);
		cout << "�����������ɹ���" << endl;
	}
}
void read_File() {
	int dai, brithday,deaday;
	char son[10], father[10],sex[10], school[10], work[10];
	root = new Node;//����һ�����ڵ�
	root->lc = root->rc = NULL;
	ifstream read("D://dzy.txt");//�ļ������ڻ᷵�ش���
	if (!read) {
		cerr << "file could not be open." << endl;
		exit(0);
	}
	read >> dai >> father >> sex >> brithday >> deaday >> school >> work;//��������
	cunru(root, father, dai, sex, brithday, deaday, school, work);//����ṹ��
	while (!read.eof())//�����Ϊ��
	{
		read >> father >> dai >> son >> sex >> brithday >> deaday >> school >> work;//��ȡ����
		tree(father, son, dai, sex, brithday, deaday, school, work);//����ṹ��
	}
	read.close();

}
void change_Function(TreeNode* t, char name[])//�޸Ĺ���
{
	TreeNode* node, * newnode;
	node = findLocation(t, name);
	if (node == NULL) { cout << "˫�ײ�����" << endl; }
	else {
		cout << ">>��������Ҫ�޸ĵ���Ϣ>>>"<<endl;
		newnode = changeNode();//�����µĽڵ�
		if (newnode) {//��ֵ
			strcpy_s(node->data.name, newnode->data.name);
			strcpy_s(node->data.sex, newnode->data.sex);
		    node->data.brithday=newnode->data.brithday;
			node->data.deaday= newnode->data.deaday;
			strcpy_s(node->data.school, newnode->data.school);
			strcpy_s(node->data.work, newnode->data.work);
		}
	}

}
void delete_Function(TreeNode*& p, char name[])//ɾ������
{
	//��ַָ��
	if (p != NULL) {
		if (strcmp(p->data.name, name) == 0)
		{

			p = NULL;//��ǰ�ڵ�ֵΪ��
			delete p;//ɾ����ǰ�ڵ�
			cout << "ɾ���ɹ�!!!" << endl;
			return;
		}
		else { cout << "���޴���" << endl; }

		if (p->lc != NULL) { delete_Function(p->lc, name); }//�Ҳ����ͱ�����ߣ�
		if (p->rc != NULL) { delete_Function(p->rc, name); }//�Ҳ����ͱ����ұߣ�

	}

}
void look(TreeNode* p)   // ǰ�����
{

	if (p == NULL)return ;
	else {
		putchar('(');
		cout << p->data.name;
		look(p->lc);
		look(p->rc);
		putchar(')');
	}
}
void printAll(TreeNode* p) {
	if (p != NULL) {
		cout << "����:" << p->data.beifen << "  ";
		cout << "����:" << p->data.name << "  ";
		cout << "�Ա�:" << p->data.sex << "  ";
		cout << "����:" << p->data.brithday << "  ";
		cout << "����:" << p->data.deaday << "  ";
		cout << "ѧ��:" << p->data.school << "  ";
		cout << "ְҵ:" << p->data.work << "  " << endl;
		if (p->lc != NULL) { printAll(p->lc); }//��������
		if (p->rc != NULL) { printAll(p->rc); }//�����ֵ�
	}
}
void bili(TreeNode* p) //��Ů����������ͳ��
{
	int a = 0;
	num++;//��ǰ��������
	if (p != NULL) {
		cout << "����:" << p->data.name << "  ";
		cout << "�Ա�:" << p->data.sex << "  ";
		cout << "����:" << p->data.brithday << "  ";
		cout << "����:" << p->data.deaday << "  "<<endl;
		if (p->data.deaday == 0) {//��û����
			a=y - p->data.brithday;	//��ǰ���ȥ������
			sum += a;//�ۼ�
			now++;//û���ļ�1
		}
		if(p->data.deaday - p->data.brithday>=0){//���˵�
			a=p->data.deaday - p->data.brithday;	//����
			sum += a;//�ۼ�
			go++;//���˵ļ�1
		}
		if (strcmp(p->data.sex, "��") == 0 || (strcmp(p->data.sex, "m") == 0))//�����е�
		{
			man++;
		}
		else {
			woman++;
		}
		if (p->lc != NULL) { bili(p->lc); }
		if (p->rc != NULL) { bili(p->rc); }

	}


}
void menu() {
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << ">>>                  1 --- �������                  <<<" << endl; 
	cout << ">>>                  2 --- ��Ӷ���                  <<<" << endl;
	cout << ">>>                  3 --- ɾ������                  <<<" << endl; 
	cout << ">>>                  4 --- �޸�                      <<<" << endl;
	cout << ">>>                  5 --- ��������                  <<<" << endl; 
	cout << ">>>                  6 --- ���ŷ�ǰ�����            <<<" << endl; 
	cout << ">>>                  7 --- ����ȫ����Ϣ              <<<" << endl;
	cout << ">>>                  8 --- ͳ�� ��չ1                <<<" << endl;
	cout << ">>>                  9 --- �ֶ����� ��չ2            <<<" << endl;
	cout << ">>>                 10 --- �ֶ���ȡ ��չ3            <<<" << endl;
	cout << ">>>                 11 --- ����                      <<<" << endl;
	cout << "--------------------------------------------------------" << endl;
}

int main()
{

	int m;
	char name[20];
	while (1) {
		menu();
		cout << ">>������ѡ��>>>:";
		cin >> m;
		switch (m) {
		case 1:
			if (root != NULL) { cout << "�Ѿ��������ڣ�" << endl; }
			else { root = creatFirst(); }   break;
		case 2:
			if (root == NULL) { cout << "�봴��������"<<endl; break; }
			add_Function(root); break;
		case 3:
			if (root == NULL) { cout << "�봴��������" << endl; break; }
			cout << "����ɾ��������" << endl; cin >> name; delete_Function(root, name); break;
		case 4:
			if (root == NULL) { cout << "�봴��������" << endl; break; }
			cout << "�����޸ĵ�����" << endl;
			cin >> name; change_Function(root, name); break;
		case 5:	
			if (root == NULL) { cout << "�봴��������" << endl; break; }
			cout << "������ҵ�����" << endl;
			cin >> name;
			find_Function(root, name); break;
		case 6:
			if (root == NULL) { cout << "�봴��������" << endl; break; }
			look(root); break;
		case 7:
			if (root == NULL) { cout << "�봴��������" << endl; break; }
			printAll(root); break;
		case 8:
			if (root == NULL) { cout << "�봴��������" << endl; break; }
		    num = man = woman = go=now=sum=0;
		    bili(root);	
		    cout << "-----------------------------------------"<<endl;
		    cout << "����Ŀǰ����:" << num << " "<<"����������:"<<now << " " << "���ε�����:" << go << " " <<endl;
		    cout << "�����ܺ�:" << sum << " "; cout << "ƽ������:" << sum / num << " "<<endl; 
		    cout << "��: " << man << ":" << "Ů: " << woman << endl; 	
		    cout << "-----------------------------------------" << endl;break;
		case 9: 
			if (root == NULL) { cout << "�봴������"; break; }
			save_File(root); cout << "����ɹ�!!!" << endl; break;
		case 10:
			read_File(); break;
		case 11:
			system("cls"); break;
		default:
			cout << "�������!!!" << endl; break;
		}
	}
	system("pause");
	return 0;
}