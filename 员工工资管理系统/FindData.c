#include"menu.h"
#include"global.h"
#include<string.h>
void All_printData()//��ҳ��ʾȫ��Ա����Ϣ
{
	NODE *p1 = head;
	while (p1 != NULL) {
		p1=Print_10_Data(p1);
		if (p1 == NULL)
			break;
		else {
			printf("���������ʾ��һҳ");
			getch();
		}
	}
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