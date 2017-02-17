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

void SortPostSalary()//按岗位工资排序post		//未完成！！！！！！！！！！！！
{
	NODE *p=head;
	while (p != NULL) {
		if (p->post == manager) {
			SortAllSalary();
		}
		p = p->next;
	}
	printf("经理工资排序:\n");
	while (p->post == manager) {
		printLinkTable();
		p = p->next;
	}

	while (p != NULL) {
		if (p->post == technician) {
			SortAllSalary();
		}
		p = p->next;
	}
	printf("技术员工资排序:\n");
	printLinkTable();

	while (p != NULL) {
		if (p->post == salesman) {
			SortAllSalary();
		}
		p = p->next;
	}
	printf("销售员工资排序:\n");
	printLinkTable();

	while (p != NULL) {
		if (p->post == salemanager) {
			SortAllSalary();
		}
		p = p->next;
	}
	printf("销售经理工资排序:\n");
	printLinkTable();
}

/*void printLinkTable()//输出排序猴的链表
{
	NODE *p1;
	p1 = head->next;
	while (p1 != NULL) {
		printf("%d %s %s %s %d %d %d %d %d %d\n", p1->number, p1->name, p1->sex, p1->BuMeng, p1->post,
			p1->age, p1->salary, p1->workTime, p1->salenum, p1->next);
		//printf("%d %s\n", p->number, p->name);
		p1 = p1->next;
	}
}*/

void printLinkTable()
{
	NODE *p1 = head;
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("职工号 姓名 性别 部门 岗位 年龄 当月工资 当月工作时间 当月销售额");
	while (p1 != NULL) {	//搜索模块
		PrintData(p1);//调用数据输出模块
		p1 = p1->next;
	}

	return p1;
}