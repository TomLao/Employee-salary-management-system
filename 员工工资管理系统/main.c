#include"menu.h"
#include"global.h"

void printWelcome() {

	printf("┐┐┐┐┐┐┐┐┐┐┐┐┐┐┐┐┐┐\n");
	printf("■□■欢迎进入员工工资管理系统□■□\n");
	printf("└└└└└└└└└└└└└└└└└└\n");

}
void main()
{
	printWelcome();				//输出欢迎界面
	int nSelect = -1;

	readFILe();//打开文件并读入至链表

	while (nSelect != 0) {
		nSelect = printMainMenu();

	}
}
