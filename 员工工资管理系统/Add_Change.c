#include"menu.h"
#include"global.h"

NODE *AddData(int postSelect, NODE *p2, int i)	//添加链表结点模块
{
	NODE *p1;
	if ((p1 = (NODE*)malloc(sizeof(NODE))) == NULL) {
		printf("不能成功分配存储块！\n");
		exit(0);
	}
	p1->next = NULL;
	if (postSelect == manager || postSelect == salemanager) {
		p1->post = postSelect;
		printf("姓名 性别 部门 年龄\n");
		scanf("%s%s%s%d", p1->name, p1->sex, p1->BuMeng, &p1->age);
	}
	if (postSelect == technician) {
		p1->post = postSelect;
		printf("姓名 性别 部门 年龄 当月工作时间\n");
		scanf("%s%s%s%d%d", &p1->name, &p1->sex, &p1->BuMeng, &p1->age, &p1->workTime);
	}
	if (postSelect == salesman) {
		p1->post = postSelect;
		printf("姓名 性别 部门 年龄 当月销售额\n");
		scanf("%s%s%s%d%d", &p1->name, &p1->sex, &p1->BuMeng, &p1->age, &p1->salenum);
	}
	p1->number = i;

	if (i == 1)
		head = p1;
	else
		p2->next = p1;
	p2 = p1;

	return p2;
}

void calculate()
{
	int sum;
	NODE *p = head;
	
	while (p != NULL) {
		if (p->post == manager)
			p->salary = 8000;
		else if (p->post == technician)
			p->salary = p->workTime * 100;
		else if (p->post == salesman)
			p->salary = p->salenum*0.04;
		else if (p->post == salemanager)
			p->salary = 5000 + (total_salenum()*0.005);

		p = p->next;
	}
}

void ChangeData()	//修改数据
{
	int num, nSelect = -1;
	NODE *p;
	printf("\n请输入要修改信息的职工号:");
	scanf("%d", &num);

	p = FindNode(num);	//查找结点位置

	if (p == NULL) {
		printf("未找到该员工！\n");
	}
	else {
		while (nSelect != 0) {
			printf("1.姓名 2.性别 3.部门 4.岗位 5.年龄 6.当月工资 ");
			if (p->post == technician) printf("7.当月工作时间 ");
			else if (p->post == salesman) printf("8.当月销售额 ");
			printf("0.退出\n");
			printf("\n输入要修改的数据\n");
			scanf("%d", &nSelect);

			switch (nSelect) {
			case 0:printf("\n退出\n"); break;
			case 1:scanf("%s", p->name); break;
			case 2:scanf("%s", p->sex); break;
			case 3:scanf("%s", p->BuMeng); break;
			case 4:scanf("%d", &p->post); break;
			case 5:scanf("%d", &p->age); break;
			case 6:scanf("%d", &p->salary); break;
			case 7:scanf("%d", &p->workTime); break;
			case 8:scanf("%d", &p->salenum); break;
			default:printf("输入错误，请重新输入！\n"); break;
			}
		}
	}
}

int total_salenum()//计算销售员的销售总额
{
	int sum=0;
	NODE *p = head;

	while (p != NULL) {
		if (p->post == salesman) {
			sum = sum + p->salenum;
		}
		p = p->next;
	}
	return sum;
}

int CountSalary()	//计算所有员工当月工资
{
	int sum=0;
	NODE *p = head;
	
	while (p != NULL) {
		sum += p->salary;
		p = p->next;
	}
	return sum;
}

NODE * FindNode(int num) {	//查找结点位置并返回
	NODE*p;

	p = head->next;
	while ((p->number != num) && (p->next != NULL))
		p = p->next;
	if (p->number != num)
		p = NULL;

	return p;//返回结点位置
}

void DeleteNode()
{
	int num;
	NODE *p1, *p2;

	printf("\n-----------------------\n");
	printf("请输入要删除员工的职工号：");
	scanf("%d", &num);

	p1 = p2 = head;
	while ((p1->number != num) && (p1->next != NULL)) {
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->number == num) {
		if (head == p1)
			head = p1->next;
		else
			p2->next = p1->next;
		free(p1);
	}
	else
		printf("未找到该员工\n");

	writeFile();//将数据写入文件存储
}