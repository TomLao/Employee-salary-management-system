#include"menu.h"
#include"global.h"

int printMainMenu() {
	int nSelect;

	printf("\n");//���������˵�
	printf("________________________________________\n");
	printf("1.�������\t2.�޸�����\t3.ɾ������\n");
	printf("4.��ѯ����\t5.��������\t6.ͳ������\n");
	printf("0.�˳�����\n");
	printf("----------------------------------------\n");
	printf("������Ҫ���еĲ˵���ţ�");
	scanf("%d", &nSelect);//����û�����
	fflush(stdin);

	switch (nSelect) {
	case 0:printf("�˳�\n");
		break;
	case 1:printf("�������\n");
		AddData_Menu();
		break;
	case 2:printf("�޸�����\n");
		ChangeData_Menu();
		break;
	case 3:printf("ɾ������\n");
		DeleteNode();
		break;
	case 4:printf("��ѯ����\n");
		FindData_Menu();
		break;
	case 5:printf("��������\n");
		SortSalary_Menu();
		break;
	case 6:printf("ͳ������\n");
		Statistic_Menu();
		break;
	}

	return nSelect;
}

void AddData_Menu()
{
	int postSelect, n, count=0;
	NODE *p2=NULL;

	printf("����ְ����������");
	scanf("%d", &n);

	for (int i = 1; i <= n;) {
		printf("\n��������Ҫ������ݵ���Աְλ��\n");
		printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
		printf("1.���� 2.����Ա 3.����Ա 4.���۾���\n");
		printf("----------------------------------------\n");
		scanf("%d", &postSelect);

		if (postSelect == 1 || postSelect == 2 || postSelect == 3 || postSelect == 4) {
			p2 = AddData(postSelect, p2, i);//�������
			i++;
		}
		else
			printf("�����������������\n");
	}

	calculate();//���㵱�¹���
	writeFile();//������д���ļ��洢
}

void ChangeData_Menu()	//�޸����ݲ˵�
{
	int nSelect;

	printf("\n1.�޸�Ա����Ϣ 2.��������Ա�����¹��� 3.�����ܶ�\n");
	printf("��ѡ��Ҫ�����޸ĵĲ�����");
	scanf("%d", &nSelect);
	switch (nSelect) {
	case 1:ChangeData();
		break;
	case 2:printf("%d",CountSalary());//���㲢�������Ա�����¹���
		break;
	case 3:printf("%d",total_salenum());//���㲢��������ܶ�
		break;
	}
}
		//����ɣ�����4
void FindData_Menu()
{
	int nSelect;

	printf("\n����������������������������������������������������\n");
	printf("1.��ҳ��ʾȫ��Ա����Ϣ  2.��������ʾ������ȫԱ����Ϣ\n\n");
	printf("3.�ֱ���ʾ4�ָ�λԱ����Ϣ  4.���ݹ��Ż�������ѯ��Ϣ\n");
	printf("����������������������������������������������������\n");
	scanf("%d", &nSelect);

	switch (nSelect) {
	case 1:All_printData();
		break;
	case 2:BuMeng_printData();//���㲢�������Ա�����¹���
		break;
	case 3:Post_printData();//���㲢��������ܶ�
		break;
	case 4:Number_Name_printData();
		break;
	}
}

void SortSalary_Menu()
{
	int nSelect, a;

	printf("\n������������������������������\n");
	printf("1.����Ա�������¹��ʴӸߵ�������\n\n");
	printf("2.����λԱ�����¹��ʴӸߵ�������\n");
	printf("��������������������������������\n");
	scanf("%d", &nSelect);

	switch (nSelect) {
	case 1:SortAllSalary();//����Ա�������¹��ʴӸߵ�������
		printLinkTable();
		break;
	case 2:
		SortPostSalary();
		break;
	}
}

void Statistic_Menu()
{
	int nSelect;

	printf("\n����������������������������������������������������\n");
	printf("1.ͳ�Ʋ���ʾĳ�����ŵ�ƽ�����ʡ���͹��ʡ���߹���\n");
	printf("2.ͳ�Ʋ���ʾĳ�����ų���ƽ�����ʵ�������Ա����Ϣ\n");
	printf("3.ͳ�Ʋ���ʾ����Ա���е���͹��ʺ���߹���Ա������Ϣ\n");
	printf("4.ͳ�Ʋ���ʾ����Ա������ƽ�����ʵ�������Ա����Ϣ\n");
	printf("����������������������������������������������������\n");
	scanf("%d", &nSelect);

	switch (nSelect) {
	case 1:BuMen_Ave_Low_High();
		break;
	case 2:BuMen_MoreThenAve();//���㲢�������Ա�����¹���
		break;
	case 3:All_Lowest_Highest();//���㲢��������ܶ�
		break;
	case 4:All_MoreThenAve();
		break;
	}
}