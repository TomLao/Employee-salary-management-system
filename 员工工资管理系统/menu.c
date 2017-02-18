#include"menu.h"
#include"global.h"

int printMainMenu() {
	int nSelect;

	printf("\n");//输出主界面菜单
	printf("________________________________________\n");
	printf("1.添加数据\t2.修改数据\t3.删除数据\n");
	printf("4.查询数据\t5.排序数据\t6.统计数据\n");
	printf("0.退出程序\n");
	printf("----------------------------------------\n");
	printf("请输入要进行的菜单序号：");
	scanf("%d", &nSelect);//获得用户输入
	fflush(stdin);

	switch (nSelect) {
	case 0:printf("退出\n");
		break;
	case 1:printf("添加数据\n");
		AddData_Menu();
		break;
	case 2:printf("修改数据\n");
		ChangeData_Menu();
		break;
	case 3:printf("删除数据\n");
		DeleteNode();
		break;
	case 4:printf("查询数据\n");
		FindData_Menu();
		break;
	case 5:printf("排序数据\n");
		SortSalary_Menu();
		break;
	case 6:printf("统计数据\n");
		Statistic_Menu();
		break;
	}

	return nSelect;
}

void AddData_Menu()
{
	int postSelect, n, count=0;
	NODE *p2=NULL;

	printf("输入职工总人数：");
	scanf("%d", &n);

	for (int i = 1; i <= n;) {
		printf("\n请输入所要添加数据的人员职位：\n");
		printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
		printf("1.经理 2.技术员 3.销售员 4.销售经理\n");
		printf("----------------------------------------\n");
		scanf("%d", &postSelect);

		if (postSelect == 1 || postSelect == 2 || postSelect == 3 || postSelect == 4) {
			p2 = AddData(postSelect, p2, i);//添加数据
			i++;
		}
		else
			printf("输入错误，请重新输入\n");
	}

	calculate();//计算当月工资
	writeFile();//将数据写入文件存储
}

void ChangeData_Menu()	//修改数据菜单
{
	int nSelect;

	printf("\n1.修改员工信息 2.计算所有员工当月工资 3.销售总额\n");
	printf("请选择要进行修改的操作：");
	scanf("%d", &nSelect);
	switch (nSelect) {
	case 1:ChangeData();
		break;
	case 2:printf("%d",CountSalary());//计算并输出所有员工当月工资
		break;
	case 3:printf("%d",total_salenum());//计算并输出销售总额
		break;
	}
}
		//待完成，功能4
void FindData_Menu()
{
	int nSelect;

	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("1.分页显示全部员工信息  2.按部门显示本部门全员工信息\n\n");
	printf("3.分别显示4种岗位员工信息  4.根据工号或姓名查询信息\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	scanf("%d", &nSelect);

	switch (nSelect) {
	case 1:All_printData();
		break;
	case 2:BuMeng_printData();//计算并输出所有员工当月工资
		break;
	case 3:Post_printData();//计算并输出销售总额
		break;
	case 4:Number_Name_printData();
		break;
	}
}

void SortSalary_Menu()
{
	int nSelect, a;

	printf("\n━━━━━━━━━━━━━━━\n");
	printf("1.所有员工按当月工资从高到低排序\n\n");
	printf("2.按岗位员工当月工资从高到低排序\n");
	printf("━━━━━━━━━━━━━━━━\n");
	scanf("%d", &nSelect);

	switch (nSelect) {
	case 1:SortAllSalary();//所有员工按当月工资从高到低排序
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

	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("1.统计并显示某个部门的平均工资、最低工资、最高工资\n");
	printf("2.统计并显示某个部门超出平均工资的人数与员工信息\n");
	printf("3.统计并显示所有员工中的最低工资和最高工资员工的信息\n");
	printf("4.统计并显示所有员工超出平均工资的人数与员工信息\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	scanf("%d", &nSelect);

	switch (nSelect) {
	case 1:BuMen_Ave_Low_High();
		break;
	case 2:BuMen_MoreThenAve();//计算并输出所有员工当月工资
		break;
	case 3:All_Lowest_Highest();//计算并输出销售总额
		break;
	case 4:All_MoreThenAve();
		break;
	}
}