#include"menu.h"
#include"global.h"
#include<string.h>

void All_printData()//分页显示全部员工信息
{
	NODE *p1 = head;
	DNODE *dp, *dp_First, *dp_Last, *dhead;
	int n;
	dhead = Creat_DoubleLink();
	dp_First = dp_Last = dp = dhead;	//dp_First固定首个
									//dp_Last固定尾个，dp机动

	while (dp_Last->next != NULL)	//将dp_Last置于尾个
		dp_Last = dp_Last->next;

	do {
		printf("\n━━━━━━━输入要进行的操作━━━━━━━\n");
		printf("1.首页 2.上一页 3.下一页 4.最后一页 0.退出\n");
		scanf("%d", &n);

		switch (n) {
		case 1:Print_10_Data(dp_First->point); break;
		case 2: {
			if (dp->front == NULL)
				printf("已是首页！");
			else {
				Print_10_Data(dp->front->point);
				dp = dp->front;
			}
		}break;
		case 3: {
			if (dp->next == NULL)
				printf("已是尾页！");
			else {
				Print_10_Data(dp->next->point);
				dp = dp->next;
			}
		}break;
		case 4:Print_10_Data(dp_Last->point);
		}
	} while (n != 0);
}

void BuMeng_printData()//按部门显示本部门全部员工信息
{
	NODE *p1 = head;
	char Find_BuMeng[20];
	printf("请输入要查询的部门：");
	scanf("%s", Find_BuMeng);

	Print_Form();

	while (p1 != NULL) {
		if (strcmp(p1->BuMeng, Find_BuMeng) == 0) {
			PrintData(p1);//调用数据输出模块
		}
		p1 = p1->next;
	}
}

void Post_printData()//分别显示4种岗位的员工信息
{
	NODE *p1 = head;
	int Find_post;

	printf("\n请输入要查询的岗位(1:经理，2:技术员，3:销售员，4:销售经理)");
	scanf("%d", &Find_post);

	Print_Form();

	while (p1 != NULL) {
		if (Find_post == p1->post) {
			PrintData(p1);//调用数据输出模块
		}
		p1 = p1->next;
	}
}

void Number_Name_printData()//根据工号或者姓名查询员工信息
{
	NODE *p1 = head;
	int Find_number, index;
	char Find_name[10];
	printf("请输入要查询的员工信息的方式(1:工号，2:姓名)：");
	scanf("%d", &index);

	if (index == 1) {
		printf("请输入要查询员工的工号：");
		scanf("%d", &Find_number);
	}
	else {
		printf("请输入要查询员工的姓名：");
		scanf("%s", Find_name);
	}

	Print_Form();

	while (p1 != NULL) {	//搜索模块
		if ((Find_number == p1->number) || (strcmp(Find_name, p1->name) == 0)) {
			PrintData(p1);//调用数据输出模块
		}
		p1 = p1->next;
	}
}

int Print_10_Data(NODE *p1)
{
	Print_Form();

	for (int i = 1; i <= 10 && p1 != NULL; i++) {
		PrintData(p1);//调用数据输出模块
		p1 = p1->next;
	}
	
	return p1;
}

int PrintData(NODE *p1)
{
	if (p1->post == manager || p1->post == salemanager)
		printf("\n%d       %s    %s    %s    %d    %d    %d\n", p1->number, p1->name, p1->sex, p1->BuMeng, p1->post, p1->age, p1->salary);
	else if (p1->post == technician)
		printf("\n%d       %s    %s    %s    %d    %d    %d     %d\n", p1->number, p1->name, p1->sex, p1->BuMeng, p1->post, p1->age, p1->salary, p1->workTime);
	else
		printf("\n%d       %s    %s    %s    %d    %d    %d                      %d\n", p1->number, p1->name, p1->sex, p1->BuMeng, p1->post, p1->age, p1->salary, p1->salenum);
}

void Print_Form()
{
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("职工号 姓名 性别 部门 岗位 年龄 当月工资 当月工作时间 当月销售额");
}

//一下为双向链表实验
DNODE *Creat_DoubleLink()	//添加链表结点模块
{
	NODE *p = head;
	DNODE *dhead = NULL, *dp1, *dp2;
	int count = 1;

	while (p != NULL) {
		if (count % 10 == 1) {
			if ((dp1 = (DNODE*)malloc(sizeof(DNODE))) == NULL) {
				printf("不能成功分配存储块！\n");
				exit(0);
			}
			dp1->point = p;
			dp1->next = NULL;

			if (count == 1) {
				dp1->front = NULL;
				dhead = dp1;
			}
			else {
				dp2->next = dp1;
				dp1->front = dp2;
			}
			dp2 = dp1;
		}
		count++;
		p = p->next;
	}
	return dhead;
}