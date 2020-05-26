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
		printf("ɾ������ϵ�˲�����\n");
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
		printf("���ļ�ʧ��");
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
		printf("�ļ���ʧ��");
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

			printf("������%s\n", pbook->array[i].name);
			printf("�绰��%s\n", pbook->array[i].tel);
			printf("��ַ��%s\n", pbook->array[i].address);
			printf("���䣺%d\n", pbook->array[i].age);

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