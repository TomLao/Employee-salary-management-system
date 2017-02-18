#include"menu.h"
#include"global.h"
#include<string.h>
void BuMen_Ave_Low_High()	//1.ͳ�Ʋ���ʾĳ�����ŵ�ƽ�����ʡ���͹��ʡ���߹���
{
	NODE *p1 = head, *pH, *pL;
	char Find_Bumen[20];
	int ave;
	pH = pL = head;

	printf("\n������Ҫ��ѯ�Ĳ���");
	scanf("%s", Find_Bumen);
	ave = BM_Average(Find_Bumen);

	if (ave == 0)
		printf("δ�ҵ��ò���\n");
	else {
		printf("%s ���ŵ�ƽ������Ϊ%d\n", Find_Bumen, ave);

		while (p1 != NULL) {
			if ((strcmp(p1->BuMeng, Find_Bumen) == 0) && (p1->salary > pH->salary))
				pH = p1;
			if ((strcmp(p1->BuMeng, Find_Bumen) == 0) && (p1->salary < pL->salary))
				pL = p1;
			p1 = p1->next;
		}
		printf("%s ���ŵ���͹���Ϊ%d\n", Find_Bumen, pL->salary);
		printf("%s ���ŵ���߹���Ϊ%d\n", Find_Bumen, pH->salary);
	}
}

void BuMen_MoreThenAve()	//2.ͳ�Ʋ���ʾĳ�����ų���ƽ�����ʵ�������Ա����Ϣ
{
	NODE *p = head;
	char Find_Bumen[20];
	int ave,count=0;

	printf("\n������Ҫ��ѯ�Ĳ���");
	scanf("%s", Find_Bumen);
	ave = BM_Average(Find_Bumen);

	if (ave == 0)
		printf("δ�ҵ��ò���\n");
	else {
		Print_Form();

		while (p != NULL) {
			if ((strcmp(p->BuMeng, Find_Bumen) == 0) && (p->salary >= ave)) {
				PrintData(p);
				count++;
			}
			p = p->next;
		}
		printf("\n%s ���Ź������� %d ��Ա������ƽ������\n", Find_Bumen, count);
	}
}
void All_Lowest_Highest()	//3.ͳ�Ʋ���ʾ����Ա���е���͹��ʺ���߹���Ա������Ϣ
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
	printf("\n��߹���Ա����Ϣ��");
	PrintData(pH);	//�����߹���Ա����Ϣ

	printf("\n��͹���Ա����Ϣ��");
	PrintData(pL);	//�����͹���Ա����Ϣ
}

void All_MoreThenAve()	//4.ͳ�Ʋ���ʾ����Ա������ƽ�����ʵ�������Ա����Ϣ
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

	printf("�������� %d ��Ա������ƽ������\n", count);
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