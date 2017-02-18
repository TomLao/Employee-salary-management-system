#include"menu.h"
#include"global.h"
#include<string.h>
void All_printData()//分页显示全部员工信息
{
	NODE *p1 = head;
	while (p1 != NULL) {
		p1=Print_10_Data(p1);
		if (p1 == NULL)
			break;
		else {
			printf("按任意键显示下一页");
			getch();
		}
	}
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