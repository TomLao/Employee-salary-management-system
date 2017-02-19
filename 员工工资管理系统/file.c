#include"menu.h"
#include"global.h"

//写入数据到文件
void writeFile() {
	NODE*p1, *p2;
	FILE*fp;

	if ((fp = fopen("salary.txt", "w")) == NULL) {
		printf("\n不能打开文件！\n");
		exit(0);
	}

	p1 = head;
	while (p1 != NULL) {
		fwrite(p1, sizeof(NODE), 1, fp);
		p1 = p1->next;
	}
	fclose(fp);
}

//从文件读取数据
void readFILe()
{
	int i;
	NODE*p1 = NULL, *p2 = NULL;

	FILE*fp;

	if ((fp = fopen("salary.txt", "r")) == NULL) {
		printf("\n不能打开文件！\n");
		exit(0);
	}

	while (!feof(fp)) {		//文件不到末尾
		if ((p1 = (NODE*)malloc(sizeof(NODE))) == NULL) {
			printf("\n内存申请出错\n");
			fclose(fp);
			exit(0);
		}
		if (fread(p1, sizeof(NODE), 1, fp) != 1) {	//读到末尾或者出错，跳出循环
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