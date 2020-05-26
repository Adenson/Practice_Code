#include"contact.h"
void menu()
{
	printf("****************************************\n");
	printf("***1.增加联系人          2.删除联系人***\n");
	printf("***3.查找联系人          4.保存到文件***\n");
	printf("***5.从文件加载          6.打印联系人***\n");
	printf("***         0.退出该程序             ***\n");
	printf("*****************************************\n");
}
int main()
{
	contactbook book;
	contact con;
	contactbookint(&book);
	char name[22];
	int input = 0;
	do
	{	
		menu();
		printf("请选择需要操作对应的数字：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请依次输入联系人：姓名，电话，地址，年龄\n");
			scanf("%s",con.name);
			scanf("%s", con.tel);
			scanf("%s", con.address);
			scanf("%d", &con.age);
			contactbookadd(&book,&con);
			break;
		case 2:
			printf("请输入你所要删除联系人的姓名：\n");
			scanf("%s",name);
			contactbookdelete(&book,name);
		case 3:
			printf("请输入你所要查找联系人的姓名：\n");
			scanf("%s",name);
			contact* ret=contactbookfind(&book,name);
			if (ret == NULL)
			{
				printf("该联系人不存在\n");
			}
			else
			{
				printf("姓名:%s,电话:%s,家庭住址:%s,年龄:%d\n", ret->name, ret->tel, ret->address, ret->age);
			}
			break;
		case 4:
			contactbooksave(&book);
			break;
		case 5:
			contactbookload(&book);
			break;
		case 6:
			contactbookprint(&book);
			break;
		case 0:
			break;
		}
	} while (input);
	contactbookdestory(&book);
	system("pause");
	return 0;
}