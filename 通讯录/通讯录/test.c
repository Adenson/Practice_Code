#include"contact.h"
void menu()
{
	printf("****************************************\n");
	printf("***1.������ϵ��          2.ɾ����ϵ��***\n");
	printf("***3.������ϵ��          4.���浽�ļ�***\n");
	printf("***5.���ļ�����          6.��ӡ��ϵ��***\n");
	printf("***         0.�˳��ó���             ***\n");
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
		printf("��ѡ����Ҫ������Ӧ�����֣�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������������ϵ�ˣ��������绰����ַ������\n");
			scanf("%s",con.name);
			scanf("%s", con.tel);
			scanf("%s", con.address);
			scanf("%d", &con.age);
			contactbookadd(&book,&con);
			break;
		case 2:
			printf("����������Ҫɾ����ϵ�˵�������\n");
			scanf("%s",name);
			contactbookdelete(&book,name);
		case 3:
			printf("����������Ҫ������ϵ�˵�������\n");
			scanf("%s",name);
			contact* ret=contactbookfind(&book,name);
			if (ret == NULL)
			{
				printf("����ϵ�˲�����\n");
			}
			else
			{
				printf("����:%s,�绰:%s,��ͥסַ:%s,����:%d\n", ret->name, ret->tel, ret->address, ret->age);
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