//版权所有 Copyright © 2017 LaoHeze. All rights reserved

//课程设计一：员工工资管理系统

//涉及多函数调用，结构体构建单向链表存储数据，双向链表实现上下翻页
//不足：功能函数模块化不高，项目开发前整体布局不清晰，代码风格不规范

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
