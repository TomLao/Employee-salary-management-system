#include"menu.h"
#include"global.h"

void SortAllSalary()//���������������ˣ���������
{
	NODE *p, *s, *pt;
	p = head;
	s = p->next;
	while (p->next != NULL) {
		while (s->next != NULL) {
			if (p->next->salary > s->next->salary) {
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
}

void SortPostSalary()//����λ��������post		//δ��ɣ�������������������������
{
	NODE *p=head;
	while (p != NULL) {
		if (p->post == manager) {
			SortAllSalary();
		}
		p = p->next;
	}
	printf("����������:\n");
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
	printf("����Ա��������:\n");
	printLinkTable();

	while (p != NULL) {
		if (p->post == salesman) {
			SortAllSalary();
		}
		p = p->next;
	}
	printf("����Ա��������:\n");
	printLinkTable();

	while (p != NULL) {
		if (p->post == salemanager) {
			SortAllSalary();
		}
		p = p->next;
	}
	printf("���۾���������:\n");
	printLinkTable();
}

void printLinkTable()//�������������
{
	NODE *p1;
	p1 = head->next;
	while (p1 != NULL) {
		printf("%d %s %s %s %d %d %d %d %d %d\n", p1->number, p1->name, p1->sex, p1->BuMeng, p1->post,
			p1->age, p1->salary, p1->workTime, p1->salenum, p1->next);
		//printf("%d %s\n", p->number, p->name);
		p1 = p1->next;
	}
}