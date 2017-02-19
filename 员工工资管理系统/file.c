#include"menu.h"
#include"global.h"

//д�����ݵ��ļ�
void writeFile() {
	NODE*p1, *p2;
	FILE*fp;

	if ((fp = fopen("salary.txt", "w")) == NULL) {
		printf("\n���ܴ��ļ���\n");
		exit(0);
	}

	p1 = head;
	while (p1 != NULL) {
		fwrite(p1, sizeof(NODE), 1, fp);
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
}