#include"menu.h"
#include"global.h"

void SortAllSalary()//���������������ˣ���������
{
	NODE *p, *pp, *s, *pt;

	
	if ((p = (NODE*)malloc(sizeof(NODE))) == NULL) {
		printf("���ܳɹ�����洢�飡\n");
		exit(0);
	}
	if ((pp = (NODE*)malloc(sizeof(NODE))) == NULL) {
		printf("���ܳɹ�����洢�飡\n");
		exit(0);
	}

	p->next = head;	//����Ҫ���ͷָ�벻�����������⣬��������λ��ͷָ��ǰ���½��2��
					//һ��(p)���ڶ�����һ��(pp)���ڴ���λ�ûָ�ͷָ��
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

	head = pp->next;	//�ָ�ͷָ��
}

void SortPostSalary()//����λ��������post		//δ��ɣ�����������������������
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

/*void printLinkTable()//�������������
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
	printf("\n����������������������������������������������������������������\n");
	printf("ְ���� ���� �Ա� ���� ��λ ���� ���¹��� ���¹���ʱ�� �������۶�");
	while (p1 != NULL) {	//����ģ��
		PrintData(p1);//�����������ģ��
		p1 = p1->next;
	}

	return p1;
}