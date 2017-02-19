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

void SortPostSalary()
{
	SortAllSalary();
	NODE *p1, *p2, *p3, *p4;
	p1 = p2 = p3 = p4 = head;

	printf("\n�������������������������������򩥩�������������������������\n");
	printf("ְ���� ���� �Ա� ���� ��λ ���� ���¹��� ���¹���ʱ�� �������۶�");
	while (p1 != NULL) {
		if (p1->post == manager) {
			PrintData(p1);
		}
		p1 = p1->next;
	}

	printf("\n\n��������������������������Ա�������򩥩�����������������������\n");
	printf("ְ���� ���� �Ա� ���� ��λ ���� ���¹��� ���¹���ʱ�� �������۶�");
	while (p2 != NULL) {
		if (p2->post == technician) {
			PrintData(p2);
		}
		p2 = p2->next;
	}

	printf("\n\n��������������������������Ա�������򩥩�����������������������\n");
	printf("ְ���� ���� �Ա� ���� ��λ ���� ���¹��� ���¹���ʱ�� �������۶�");
	while (p3 != NULL) {
		if (p3->post == salesman) {
			PrintData(p3);
		}
		p3 = p3->next;
	}

	printf("\n\n�����������������������۾��������򩥩�����������������������\n");
	printf("ְ���� ���� �Ա� ���� ��λ ���� ���¹��� ���¹���ʱ�� �������۶�");
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

	while (p1 != NULL) {	//����ģ��
		PrintData(p1);//�����������ģ��
		p1 = p1->next;
	}
}