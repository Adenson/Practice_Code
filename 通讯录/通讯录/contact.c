#include"contact.h"
void contactbookint(contactbook* pbook)
{
	assert(pbook);
	pbook->array = (contact*)malloc(sizeof(contact));
	if (pbook->array == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	pbook->size = 0;
	pbook->capacity = 8;
}
void contactbookadd(contactbook* pbook, contact* pcon)
{
	assert(pbook && pcon);
	if (pbook->size == pbook->capacity)
	{
		pbook->capacity *= 2;
		contact* newarray = (contact*)realloc(pbook->array, sizeof(pbook->capacity));
		if (newarray == NULL)
		{
			printf("realloc error");
			exit(-1);
		}
		pbook->array = newarray;
	}
	contact* array = pbook->array;
	size_t i = pbook->size;
	strcpy(array[i].name, pcon->name);
	strcpy(array[i].tel, pcon->tel);
	strcpy(array[i].address, pcon->address);
	array[i].age = pcon->age;
	pbook->size++;
}
contact* contactbookfind(contactbook* pbook, const char* name)
{
	assert(pbook && name);
	for (size_t i = 0; i < pbook->size; i++)
	{
		if (strcmp(pbook->array[i].name, name) == 0)
		{
			return &pbook->array[i];
		}
	}
	return NULL;
}
void contactbookdelete(contactbook* pbook, const char* name)
{
	assert(pbook && name);
	contact* p = contactbookfind(pbook, name);
	if (p == NULL)
	{
		printf("删除的联系人不存在\n");
	}
	while (p < pbook->array + (pbook->size - 1))
	{
		memcpy(p, p + 1, sizeof(contact));
		p++;
	}
	pbook->size--;
}
void contactbooksave(contactbook* pbook)
{
	FILE* p = fopen("contact.txt", "wb");
	if (p == NULL)
	{
		printf("打开文件失败");
	}
	for (size_t i = 0; i < pbook->size; ++i)
	{
		fwrite(&pbook->array[i], sizeof(contact), 1, p);
	}
	fclose(p);
	p = NULL;
}
void contactbookload(contactbook* pbook)
{
	FILE* p = fopen("contact.txt", "rb");
	if (p == NULL)
	{
		printf("文件打开失败");
	}
	contact con;
	while (fread(&con, sizeof(contact), 1, p) == 1)
	{
		contactbookadd(pbook, &con);
	}
	fclose(p);
	p = NULL;
}
void contactbookprint(contactbook* pbook)
{
		for (size_t i = 0; i < pbook->size; ++i)
		{
			printf("====================================\n");

			printf("姓名：%s\n", pbook->array[i].name);
			printf("电话：%s\n", pbook->array[i].tel);
			printf("地址：%s\n", pbook->array[i].address);
			printf("年龄：%d\n", pbook->array[i].age);

			printf("====================================\n");
		}
}
void contactbookdestory(contactbook* pbook)
{
	assert(pbook);
	free(pbook->array);
	pbook->array = NULL;
	pbook->size = pbook->capacity = 0;
}