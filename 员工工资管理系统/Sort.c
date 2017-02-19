#include"menu.h"
#include"global.h"

void SortAllSalary()//按工资排序所有人（链表排序）
{
	NODE *p, *pp, *s, *pt;

	
	if ((p = (NODE*)malloc(sizeof(NODE))) == NULL) {
		printf("不能成功分配存储块！\n");
		exit(0);
	}
	if ((pp = (NODE*)malloc(sizeof(NODE))) == NULL) {
		printf("不能成功分配存储块！\n");
		exit(0);
	}

	p->next = head;	//这里要解决头指针不参与排序问题，用再申请位于头指针前的新结点2个
					//一个(p)用于动排序，一个(pp)用于储存位置恢复头指针
	pp = p;
	s = p->next;
	//s = p;
	while (p->next != NULL) {
		while (s->next != NULL) {
			if (p->next->salary < s->next->salary) {
				pt = p->next;
				p->next = s->next;
				s->next = p->next->next;
				p->next->next = pt;
			}
			else s = s->next;
		}
		p = p->next;
		s = p->next;
	}

	head = pp->next;	//恢复头指针
}

void SortPostSalary()
{
	SortAllSalary();
	NODE *p1, *p2, *p3, *p4;
	p1 = p2 = p3 = p4 = head;

	printf("\n━━━━━━━━━━━经理工资排序━━━━━━━━━━━━━━\n");
	printf("职工号 姓名 性别 部门 岗位 年龄 当月工资 当月工作时间 当月销售额");
	while (p1 != NULL) {
		if (p1->post == manager) {
			PrintData(p1);
		}
		p1 = p1->next;
	}

	printf("\n\n━━━━━━━━━━━技术员工资排序━━━━━━━━━━━━━\n");
	printf("职工号 姓名 性别 部门 岗位 年龄 当月工资 当月工作时间 当月销售额");
	while (p2 != NULL) {
		if (p2->post == technician) {
			PrintData(p2);
		}
		p2 = p2->next;
	}

	printf("\n\n━━━━━━━━━━━销售员工资排序━━━━━━━━━━━━━\n");
	printf("职工号 姓名 性别 部门 岗位 年龄 当月工资 当月工作时间 当月销售额");
	while (p3 != NULL) {
		if (p3->post == salesman) {
			PrintData(p3);
		}
		p3 = p3->next;
	}

	printf("\n\n━━━━━━━━━━销售经理工资排序━━━━━━━━━━━━━\n");
	printf("职工号 姓名 性别 部门 岗位 年龄 当月工资 当月工作时间 当月销售额");
	while (p4 != NULL) {
		if (p4->post == salemanager) {
			PrintData(p4);
		}
		p4 = p4->next;
	}
}

void printLinkTable()
{
	NODE *p1 = head;

	Print_Form();

	while (p1 != NULL) {	//搜索模块
		PrintData(p1);//调用数据输出模块
		p1 = p1->next;
	}
}