#include"menu.h"
#include"global.h"

void printWelcome() {

	printf("������������������������������������\n");
	printf("��������ӭ����Ա�����ʹ���ϵͳ������\n");
	printf("������������������������������������\n");

}
void main()
{
	printWelcome();				//�����ӭ����
	int nSelect = -1;

	readFILe();//���ļ�������������

	while (nSelect != 0) {
		nSelect = printMainMenu();

	}
}
