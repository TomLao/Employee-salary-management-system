#include"menu.h"
#include"global.h"
#include<string.h>
void BuMen_Ave_Low_High()	//1.统计并显示某个部门的平均工资、最低工资、最高工资
{
	NODE *p1 = head, *pH, *pL;
	char Find_Bumen[20];
	int ave;
	pH = pL = head;

	printf("\n请输入要查询的部门");
	scanf("%s", Find_Bumen);
	ave = BM_Average(Find_Bumen);

	if (ave == 0)
		printf("未找到该部门\n");
	else {
		printf("%s 部门的平均工资为%d\n", Find_Bumen, ave);

		while (p1 != NULL) {
			if ((strcmp(p1->BuMeng, Find_Bumen) == 0) && (p1->salary > pH->salary))
				pH = p1;
			if ((strcmp(p1->BuMeng, Find_Bumen) == 0) && (p1->salary < pL->salary))
				pL = p1;
			p1 = p1->next;
		}
		printf("%s 部门的最低工资为%d\n", Find_Bumen, pL->salary);
		printf("%s 部门的最高工资为%d\n", Find_Bumen, pH->salary);
	}
}

void BuMen_MoreThenAve()	//2.统计并显示某个部门超出平均工资的人数与员工信息
{
	NODE *p = head;
	char Find_Bumen[20];
	int ave,count=0;

	printf("\n请输入要查询的部门");
	scanf("%s", Find_Bumen);
	ave = BM_Average(Find_Bumen);

	if (ave == 0)
		printf("未找到该部门\n");
	else {
		Print_Form();

		while (p != NULL) {
			if ((strcmp(p->BuMeng, Find_Bumen) == 0) && (p->salary >= ave)) {
				PrintData(p);
				count++;
			}
			p = p->next;
		}
		printf("\n%s 部门共有以上 %d 名员工高于平均工资\n", Find_Bumen, count);
	}
}
void All_Lowest_Highest()	//3.统计并显示所有员工中的最低工资和最高工资员工的信息
{
	NODE *p,*pH, *pL;
	p=pH = pL = head;

	while (p != NULL) {
		if (p->salary > pH->salary)
			pH = p;
		if (p->salary < pL->salary)
			pL = p;
		p = p->next;
	}

	Print_Form();
	printf("\n最高工资员工信息：");
	PrintData(pH);	//输出最高工资员工信息

	printf("\n最低工资员工信息：");
	PrintData(pL);	//输出最低工资员工信息
}

void All_MoreThenAve()	//4.统计并显示所有员工超出平均工资的人数与员工信息
{
	NODE *p = head;
	int ave, count=0;
	ave = Average(p);

	Print_Form();

	while (p != NULL) {
		if (p->salary >= ave) {
			PrintData(p);
		}
		p = p->next;
		count++;
	}

	printf("共有以上 %d 名员工高于平均工资\n", count);
}

int Average(NODE *p)
{
	//NODE *p = head;
	int count, sum;
	count = sum = 0;

	while (p != NULL) {
		sum += p->salary;
		count++;
		p = p->next;
	}
	return sum / count;
	//printf("%d", sum / count);
}

int BM_Average(char BM[20])
{
	NODE *p = head;
	int count, sum;
	count = sum = 0;

	while (p != NULL) {
		if (strcmp(p->BuMeng, BM) == 0) {
			sum += p->salary;
			count++;
		}
		p = p->next;
	}
	return sum / count;
}