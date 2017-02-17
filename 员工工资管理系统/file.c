#include"menu.h"
#include"global.h"

//д�����ݵ��ļ�
void writeFile() {
	NODE*p1, *p2;
	FILE*fp;

	if ((fp = fopen("salary.txt", "wb")) == NULL) {
		printf("\n���ܴ��ļ���\n");
		exit(0);
	}

	p1 = head;
	while (p1 != NULL) {
		fwrite(p1, sizeof(NODE), 1, fp);
		//fprintf(fp, "%d%s%s%s%d%d%d%d%d%d", p1->number, p1->name, p1->sex, p1->BuMeng, p1->post,
			//p1->age, p1->salary, p1->workTime, p1->salenum, p1->next);
		p1 = p1->next;
	}
	fclose(fp);
}

//���ļ���ȡ����
void readFILe()
{
	int i;
	NODE*p1 = NULL, *p2 = NULL;

	FILE*fp;

	if ((fp = fopen("salary.txt", "r")) == NULL) {
		printf("\n���ܴ��ļ���\n");
		exit(0);
	}

	while (!feof(fp)) {		//�ļ�����ĩβ
		if ((p1 = (NODE*)malloc(sizeof(NODE))) == NULL) {
			printf("\n�ڴ��������\n");
			fclose(fp);
			exit(0);
		}
		if (fread(p1, sizeof(NODE), 1, fp) != 1) {	//����ĩβ���߳�������ѭ��
			free(p1);
			break;
		}
		if (head == NULL)
			head = p2 = p1;
		else {
			p2->next = p1;
			p2 = p1;
		}
	}
	fclose(fp);

	/*p1 = head;
	while (p1 != NULL) {
		printf("\n");
		printf("%d %s %s %s %d %d %d %d %d %d\n", p1->number, p1->name, p1->sex, p1->BuMeng, p1->post,
			p1->age, p1->salary, p1->workTime, p1->salenum, p1->next);
		p1 = p1->next;
	}*/
}