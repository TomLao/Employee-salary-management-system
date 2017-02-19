#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int number;
	char name[10];
	char sex[5];
	char BuMeng[20];
	enum {
		manager=1, technician, salesman, salemanager
	}post;
	int age;
	int salary;
	int workTime;
	int salenum;
	struct Node *next;
}NODE;

typedef struct DNode {
	struct Node *point;
	struct DNode *front;
	struct DNode *next;
}DNODE;



void printWelcome();
int printMainMenu();
void AddData_Menu();
NODE *AddData(int postSelect, NODE *p2, int i);

void writeFile();

void readFILe();

void ChangeData_Menu();
void ChangeData();//修改指定数据
NODE * FindNode(int num);//查找结点

int total_salenum();

int CountSalary();
void DeleteNode();

void FindData_Menu();

void SortSalary_Menu();
void SortAllSalary();
void SortPostSalary();
void printLinkTable();
void Print_Form();

void Statistic_Menu();
int Average(NODE *p);
void BuMen_Ave_Low_High();
void BuMen_MoreThenAve();
void All_Lowest_Highest();
int BM_Average(char BM[20]);


int PrintData(NODE *p1);


DNODE *Creat_DoubleLink();