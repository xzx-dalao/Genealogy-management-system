#include "stdlib.h"      
#include"iostream"
#include"fstream"
#pragma warning(disable:4996)
using namespace std;
typedef struct {
	char name[50];//姓名
	char sex[50];//性别
	int brithday;//出生
	int deaday;//死亡
	char work[50];//工作
	char school[50];//学历
	int  beifen;//辈分

}StructNode;
typedef struct Node {
	StructNode data;
	struct Node* lc;//左指针
	struct Node* rc;//右指针
}TreeNode;
int man;//男
int woman;//女
int num;//总人数
int sum;//年龄总和
int now;//在世数
int go;//去世数
int y = 2020;//今年
TreeNode* root;//根指针
TreeNode* findLocation(TreeNode* b, char cname[]) //查询位置
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
TreeNode* creatFirst()//创建你的祖宗
{
	TreeNode* p;
	p = new Node;//创建新的节点
	cout << "输入祖宗名字:" << endl;
	cin >> p->data.name;
	cout << "请输入祖宗的性别：(男/m，女/n)" << endl;
	cin >> p->data.sex;
	cout << "输入祖宗的诞生时间：" << endl;
	cin >> p->data.brithday;
	cout << "输入祖宗的仙游时间：(没死的输入0)" << endl;
	cin >> p->data.deaday;
	cout << "输入祖宗的学历：" << endl;
	cin >> p->data.school;
	cout << "输入祖宗的职业：" << endl;
	cin >> p->data.work;
	p->lc = p->rc = NULL;//左右子树清空
	p->data.beifen = 1;//当前辈分为1
	cout << "祖宗创建成功" << endl;
	return p;

}
TreeNode* creatNode()//创建一个新的节点
{
	int flag = 0;
	TreeNode* m = NULL;//指针初始化
	TreeNode* p;
	p = new Node;//创建新的节点
	cout << "输入名字:" << endl;
	cin >> p->data.name;
	m = findLocation(root, p->data.name);//查找当前名字返回的变量
	if (m != NULL)
	{
		cout << "出现重名!!!\n";
		p = NULL;
		return p;
	}
	else {
		cout << "请输入性别：(男/m，女/n)" << endl;
		cin >> p->data.sex;
		cout << "输入诞生时间：" << endl;
		cin >> p->data.brithday;
		cout << "输入仙游时间：(没死的输入0)" << endl;
		cin >> p->data.deaday;
		cout << "输入学历：" << endl;
		cin >> p->data.school;
		cout << "输入职业：" << endl;
		cin >> p->data.work;
		return p;
	}
}
TreeNode* changeNode()//创建要修改的新的节点
{
	int flag = 0;
	TreeNode* m = NULL;//指针初始化
	TreeNode* p;
	p = new Node;//创建新的节点
	cout << "输入名字:" << endl;
	cin >> p->data.name;
	cout << "请输入性别：(男/m，女/n)" << endl;
	cin >> p->data.sex;
	cout << "输入诞生时间：" << endl;
	cin >> p->data.brithday;
	cout << "输入仙游时间：(没死的输入0)" << endl;
	cin >> p->data.deaday;
	cout << "输入学历：" << endl;
	cin >> p->data.school;
	cout << "输入职业：" << endl;
	cin >> p->data.work;
	return p;
	
}
void cunru(TreeNode* p, char name[], int dai, char sex[], int brithday, int deaday, char school[], char work[])//存入结构体
{
	//赋值给结构体
	p->data.beifen = dai;
	strcpy_s(p->data.name,name);
	strcpy_s(p->data.sex, sex);
	p->data.brithday = brithday;
	p->data.deaday = deaday;
	strcpy_s(p->data.school, school);
	strcpy_s(p->data.work, work);
    //显示文件的东西
	cout << "辈分:" << p->data.beifen << "  ";
	cout << "名字:" << p->data.name << "  ";
	cout << "性别:" << p->data.sex << "  ";
	cout << "出生:" << p->data.brithday << "  ";
	cout << "逝世:" << p->data.deaday << "  ";
	cout << "学历:" << p->data.school << "  ";
	cout << "职业:" << p->data.work << "  " << endl;
}
void find_Function(TreeNode* p, char name[]) //查找功能
{
	p = findLocation(p, name);
	if (p == NULL) {
		cout << "当前为空节点" << endl;
	}
	else {
		cout << "辈分:" << p->data.beifen << "  ";
		cout << "姓名:" << p->data.name << "  ";
		cout << "性别:" << p->data.sex << "  ";
		cout << "出生:" << p->data.brithday << "  ";
		cout << "逝世:" << p->data.deaday << "  ";
		cout << "学历:" << p->data.school << "  ";
		cout << "职业:" << p->data.work << "  " << endl;
		cout << p->data.name << "的子女:";
		if (p->lc == NULL)
		{
			cout<<"无左孩子!";
		}
		else {
			cout << "辈分:" << p->lc->data.beifen <<"  ";
			cout << "名字:" << p->lc->data.name << endl;
		}
		if (p->rc == NULL)
		{
			cout<<"无右孩子!";
		}
		else {
			cout << "辈分:" << p->rc->data.beifen <<"  ";
			cout << "名字:" << p->rc->data.name << endl;
		}


	}

}
void add_Function(TreeNode* t)//添加功能
{
	TreeNode* p, * q;
	char name[20];
	cout << "你要当谁的儿子：" << endl;
	cin >> name;
	q = findLocation(t, name);//查找当前名字返回的变量，为父亲节点
	if (q == NULL) { cout << "双亲不存在" << endl; }
	else {
		p = creatNode();//如果有这个父亲，就创建一个新的节点
		if (p) {
			p->data.beifen = q->data.beifen + 1; // 这是其父亲的辈分加 1
			p->lc = p->rc = NULL;
			if (q->lc == NULL) {
				q->lc = p;
				cout << "插入左子树成功！" << endl;
			}
			else {
				q = q->lc;
				//使用兄弟链表法
				while (q->rc != NULL) {
					q = q->rc;
				}
				q->rc = p;
				cout << "插入右子树成功！" << endl;

			}
		}
	}
}
void bianli(TreeNode* p, char father[])//写入祖宗
{
	ofstream w("D://dzy.txt", ios::app);//追加
	if (!w) {
		cerr << "file could not be open." << endl;
		exit(0);
	}
	TreeNode* q;
	if (p)//左子树的不为空
	{	
		w << father << "\t" << p->data.beifen << "\t" << p->data.name << "\t" 
			<< p->data.sex << "\t"<< p->data.brithday << "\t" << p->data.deaday 
			<< "\t" << p->data.school << "\t" << p->data.work << "\t"<< endl;
		bianli(p->lc, p->data.name); //遍历左子树 
		q = p->rc;
		while (q)   //遍历右子树          
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
void save_File(TreeNode* p) //保存文件功能
{
	ofstream ofile;
	ofile.open("D://dzy.txt", ios::out);//清空文件
	if (!ofile) {
		cerr << "file could not be open." << endl;
		exit(0);

	}	
	if (p) {
		ofile << "\t" << p->data.beifen << "\t" << p->data.name << "\t" 
			<< p->data.sex << "\t" << p->data.brithday << "\t" << p->data.deaday 
			<< "\t" << p->data.school << "\t" << p->data.work << "\t" << endl;
		if (p->lc) {
                    bianli(p->lc, p->data.name);//兄弟链表，左子树开始遍历
		}
	}
	
	ofile.close();}
void tree(char father[], char son[], int dai, char sex[], int brithday, int deaday, char school[], char work[])//生成树
{
	TreeNode* t;
	TreeNode* p;
	p = findLocation(root, father);//爸爸
	if (p == NULL) { return; }
	t = findLocation(root, son);//儿子，找空的位置
	if (t != NULL) { return; }
	if (p->lc == NULL)//添加孩子
	{
		p->lc = new Node;
		p->lc->rc = p->lc->lc = NULL;
		cunru(p->lc, son, dai, sex, brithday, deaday, school, work);
		cout << "插入左子树成功！" << endl;
	}
	else//添加前一个孩子的兄弟
	{
		p = p->lc;
		while (p->rc != NULL)
			p = p->rc;
		p->rc = new Node;
		p->rc->rc = p->rc->lc = NULL;
		cunru(p->rc, son, dai, sex, brithday, deaday, school, work);
		cout << "插入右子树成功！" << endl;
	}
}
void read_File() {
	int dai, brithday,deaday;
	char son[10], father[10],sex[10], school[10], work[10];
	root = new Node;//创建一个根节点
	root->lc = root->rc = NULL;
	ifstream read("D://dzy.txt");//文件不存在会返回错误
	if (!read) {
		cerr << "file could not be open." << endl;
		exit(0);
	}
	read >> dai >> father >> sex >> brithday >> deaday >> school >> work;//读入祖宗
	cunru(root, father, dai, sex, brithday, deaday, school, work);//存入结构体
	while (!read.eof())//如果不为空
	{
		read >> father >> dai >> son >> sex >> brithday >> deaday >> school >> work;//读取儿子
		tree(father, son, dai, sex, brithday, deaday, school, work);//存入结构体
	}
	read.close();

}
void change_Function(TreeNode* t, char name[])//修改功能
{
	TreeNode* node, * newnode;
	node = findLocation(t, name);
	if (node == NULL) { cout << "双亲不存在" << endl; }
	else {
		cout << ">>重新输入要修改的信息>>>"<<endl;
		newnode = changeNode();//创建新的节点
		if (newnode) {//赋值
			strcpy_s(node->data.name, newnode->data.name);
			strcpy_s(node->data.sex, newnode->data.sex);
		    node->data.brithday=newnode->data.brithday;
			node->data.deaday= newnode->data.deaday;
			strcpy_s(node->data.school, newnode->data.school);
			strcpy_s(node->data.work, newnode->data.work);
		}
	}

}
void delete_Function(TreeNode*& p, char name[])//删除功能
{
	//地址指针
	if (p != NULL) {
		if (strcmp(p->data.name, name) == 0)
		{

			p = NULL;//当前节点值为空
			delete p;//删除当前节点
			cout << "删除成功!!!" << endl;
			return;
		}
		else { cout << "查无此人" << endl; }

		if (p->lc != NULL) { delete_Function(p->lc, name); }//找不到就遍历左边；
		if (p->rc != NULL) { delete_Function(p->rc, name); }//找不到就遍历右边；

	}

}
void look(TreeNode* p)   // 前序遍历
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
		cout << "辈分:" << p->data.beifen << "  ";
		cout << "姓名:" << p->data.name << "  ";
		cout << "性别:" << p->data.sex << "  ";
		cout << "出生:" << p->data.brithday << "  ";
		cout << "逝世:" << p->data.deaday << "  ";
		cout << "学历:" << p->data.school << "  ";
		cout << "职业:" << p->data.work << "  " << endl;
		if (p->lc != NULL) { printAll(p->lc); }//遍历孩子
		if (p->rc != NULL) { printAll(p->rc); }//遍历兄弟
	}
}
void bili(TreeNode* p) //男女比例和年龄统计
{
	int a = 0;
	num++;//当前族谱人数
	if (p != NULL) {
		cout << "姓名:" << p->data.name << "  ";
		cout << "性别:" << p->data.sex << "  ";
		cout << "出生:" << p->data.brithday << "  ";
		cout << "逝世:" << p->data.deaday << "  "<<endl;
		if (p->data.deaday == 0) {//还没死的
			a=y - p->data.brithday;	//当前年减去出生年
			sum += a;//累加
			now++;//没死的加1
		}
		if(p->data.deaday - p->data.brithday>=0){//死了的
			a=p->data.deaday - p->data.brithday;	//享年
			sum += a;//累加
			go++;//死了的加1
		}
		if (strcmp(p->data.sex, "男") == 0 || (strcmp(p->data.sex, "m") == 0))//计算男的
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
	cout << ">>>                  1 --- 添加祖宗                  <<<" << endl; 
	cout << ">>>                  2 --- 添加儿子                  <<<" << endl;
	cout << ">>>                  3 --- 删除名字                  <<<" << endl; 
	cout << ">>>                  4 --- 修改                      <<<" << endl;
	cout << ">>>                  5 --- 查找名字                  <<<" << endl; 
	cout << ">>>                  6 --- 括号法前序遍历            <<<" << endl; 
	cout << ">>>                  7 --- 遍历全部信息              <<<" << endl;
	cout << ">>>                  8 --- 统计 扩展1                <<<" << endl;
	cout << ">>>                  9 --- 手动保存 扩展2            <<<" << endl;
	cout << ">>>                 10 --- 手动读取 扩展3            <<<" << endl;
	cout << ">>>                 11 --- 清屏                      <<<" << endl;
	cout << "--------------------------------------------------------" << endl;
}

int main()
{

	int m;
	char name[20];
	while (1) {
		menu();
		cout << ">>请输入选项>>>:";
		cin >> m;
		switch (m) {
		case 1:
			if (root != NULL) { cout << "已经存在祖宗！" << endl; }
			else { root = creatFirst(); }   break;
		case 2:
			if (root == NULL) { cout << "请创建祖宗先"<<endl; break; }
			add_Function(root); break;
		case 3:
			if (root == NULL) { cout << "请创建祖宗先" << endl; break; }
			cout << "输入删除的姓名" << endl; cin >> name; delete_Function(root, name); break;
		case 4:
			if (root == NULL) { cout << "请创建祖宗先" << endl; break; }
			cout << "输入修改的姓名" << endl;
			cin >> name; change_Function(root, name); break;
		case 5:	
			if (root == NULL) { cout << "请创建祖宗先" << endl; break; }
			cout << "输入查找的姓名" << endl;
			cin >> name;
			find_Function(root, name); break;
		case 6:
			if (root == NULL) { cout << "请创建祖宗先" << endl; break; }
			look(root); break;
		case 7:
			if (root == NULL) { cout << "请创建祖宗先" << endl; break; }
			printAll(root); break;
		case 8:
			if (root == NULL) { cout << "请创建祖宗先" << endl; break; }
		    num = man = woman = go=now=sum=0;
		    bili(root);	
		    cout << "-----------------------------------------"<<endl;
		    cout << "族谱目前人数:" << num << " "<<"在世的人数:"<<now << " " << "仙游的人数:" << go << " " <<endl;
		    cout << "年龄总和:" << sum << " "; cout << "平均年龄:" << sum / num << " "<<endl; 
		    cout << "男: " << man << ":" << "女: " << woman << endl; 	
		    cout << "-----------------------------------------" << endl;break;
		case 9: 
			if (root == NULL) { cout << "请创建祖宗"; break; }
			save_File(root); cout << "保存成功!!!" << endl; break;
		case 10:
			read_File(); break;
		case 11:
			system("cls"); break;
		default:
			cout << "输入错误!!!" << endl; break;
		}
	}
	system("pause");
	return 0;
}