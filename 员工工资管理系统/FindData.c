#include"menu.h"
#include"global.h"
#include<string.h>

void All_printData()//��ҳ��ʾȫ��Ա����Ϣ
{
	NODE *p1 = head;
	DNODE *dp, *dp_First, *dp_Last, *dhead;
	int n;
	dhead = Creat_DoubleLink();
	dp_First = dp_Last = dp = dhead;	//dp_First�̶��׸�
									//dp_Last�̶�β����dp����

	while (dp_Last->next != NULL)	//��dp_Last����β��
		dp_Last = dp_Last->next;

	do {
		printf("\n������������������Ҫ���еĲ�����������������\n");
		printf("1.��ҳ 2.��һҳ 3.��һҳ 4.���һҳ 0.�˳�\n");
		scanf("%d", &n);

		switch (n) {
		case 1:Print_10_Data(dp_First->point); break;
		case 2: {
			if (dp->front == NULL)
				printf("������ҳ��");
			else {
				Print_10_Data(dp->front->point);
				dp = dp->front;
			}
		}break;
		case 3: {
			if (dp->next == NULL)
				printf("����βҳ��");
			else {
				Print_10_Data(dp->next->point);
				dp = dp->next;
			}
		}break;
		case 4:Print_10_Data(dp_Last->point);
		}
	} while (n != 0);
}

void BuMeng_printData()//��������ʾ������ȫ��Ա����Ϣ
{
	NODE *p1 = head;
	char Find_BuMeng[20];
	printf("������Ҫ��ѯ�Ĳ��ţ�");
	scanf("%s", Find_BuMeng);

	Print_Form();

	while (p1 != NULL) {
		if (strcmp(p1->BuMeng, Find_BuMeng) == 0) {
			PrintData(p1);//�����������ģ��
		}
		p1 = p1->next;
	}
}

void Post_printData()//�ֱ���ʾ4�ָ�λ��Ա����Ϣ
{
	NODE *p1 = head;
	int Find_post;

	printf("\n������Ҫ��ѯ�ĸ�λ(1:����2:����Ա��3:����Ա��4:���۾���)");
	scanf("%d", &Find_post);

	Print_Form();

	while (p1 != NULL) {
		if (Find_post == p1->post) {
			PrintData(p1);//�����������ģ��
		}
		p1 = p1->next;
	}
}

void Number_Name_printData()//���ݹ��Ż���������ѯԱ����Ϣ
{
	NODE *p1 = head;
	int Find_number, index;
	char Find_name[10];
	printf("������Ҫ��ѯ��Ա����Ϣ�ķ�ʽ(1:���ţ�2:����)��");
	scanf("%d", &index);

	if (index == 1) {
		printf("������Ҫ��ѯԱ���Ĺ��ţ�");
		scanf("%d", &Find_number);
	}
	else {
		printf("������Ҫ��ѯԱ����������");
		scanf("%s", Find_name);
	}

	Print_Form();

	while (p1 != NULL) {	//����ģ��
		if ((Find_number == p1->number) || (strcmp(Find_name, p1->name) == 0)) {
			PrintData(p1);//�����������ģ��
		}
		p1 = p1->next;
	}
}

int Print_10_Data(NODE *p1)
{
	Print_Form();

	for (int i = 1; i <= 10 && p1 != NULL; i++) {
		PrintData(p1);//�����������ģ��
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
	printf("\n����������������������������������������������������������������\n");
	printf("ְ���� ���� �Ա� ���� ��λ ���� ���¹��� ���¹���ʱ�� �������۶�");
}

//һ��Ϊ˫������ʵ��
DNODE *Creat_DoubleLink()	//���������ģ��
{
	NODE *p = head;
	DNODE *dhead = NULL, *dp1, *dp2;
	int count = 1;

	while (p != NULL) {
		if (count % 10 == 1) {
			if ((dp1 = (DNODE*)malloc(sizeof(DNODE))) == NULL) {
				printf("���ܳɹ�����洢�飡\n");
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