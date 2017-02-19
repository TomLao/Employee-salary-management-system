#include"menu.h"
#include"global.h"

NODE *AddData(int postSelect, NODE *p2, int i)	//���������ģ��
{
	NODE *p1;
	if ((p1 = (NODE*)malloc(sizeof(NODE))) == NULL) {
		printf("���ܳɹ�����洢�飡\n");
		exit(0);
	}
	p1->next = NULL;
	if (postSelect == manager || postSelect == salemanager) {
		p1->post = postSelect;
		printf("���� �Ա� ���� ����\n");
		scanf("%s%s%s%d", p1->name, p1->sex, p1->BuMeng, &p1->age);
	}
	if (postSelect == technician) {
		p1->post = postSelect;
		printf("���� �Ա� ���� ���� ���¹���ʱ��\n");
		scanf("%s%s%s%d%d", &p1->name, &p1->sex, &p1->BuMeng, &p1->age, &p1->workTime);
	}
	if (postSelect == salesman) {
		p1->post = postSelect;
		printf("���� �Ա� ���� ���� �������۶�\n");
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

void ChangeData()	//�޸�����
{
	int num, nSelect = -1;
	NODE *p;
	printf("\n������Ҫ�޸���Ϣ��ְ����:");
	scanf("%d", &num);

	p = FindNode(num);	//���ҽ��λ��

	if (p == NULL) {
		printf("δ�ҵ���Ա����\n");
	}
	else {
		while (nSelect != 0) {
			printf("1.���� 2.�Ա� 3.���� 4.��λ 5.���� 6.���¹��� ");
			if (p->post == technician) printf("7.���¹���ʱ�� ");
			else if (p->post == salesman) printf("8.�������۶� ");
			printf("0.�˳�\n");
			printf("\n����Ҫ�޸ĵ�����\n");
			scanf("%d", &nSelect);

			switch (nSelect) {
			case 0:printf("\n�˳�\n"); break;
			case 1:scanf("%s", p->name); break;
			case 2:scanf("%s", p->sex); break;
			case 3:scanf("%s", p->BuMeng); break;
			case 4:scanf("%d", &p->post); break;
			case 5:scanf("%d", &p->age); break;
			case 6:scanf("%d", &p->salary); break;
			case 7:scanf("%d", &p->workTime); break;
			case 8:scanf("%d", &p->salenum); break;
			default:printf("����������������룡\n"); break;
			}
		}
	}
}

int total_salenum()//��������Ա�������ܶ�
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

int CountSalary()	//��������Ա�����¹���
{
	int sum=0;
	NODE *p = head;
	
	while (p != NULL) {
		sum += p->salary;
		p = p->next;
	}
	return sum;
}

NODE * FindNode(int num) {	//���ҽ��λ�ò�����
	NODE*p;

	p = head->next;
	while ((p->number != num) && (p->next != NULL))
		p = p->next;
	if (p->number != num)
		p = NULL;

	return p;//���ؽ��λ��
}

void DeleteNode()
{
	int num;
	NODE *p1, *p2;

	printf("\n-----------------------\n");
	printf("������Ҫɾ��Ա����ְ���ţ�");
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
		printf("δ�ҵ���Ա��\n");

	writeFile();//������д���ļ��洢
}