#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef struct contact
{
	char name[20];
	char tel[15];
	char address[20];
	int age;
}contact;

typedef struct contactbook
{
	contact* array;
	size_t  size;//联系人个数
	size_t capacity;//容量
}contactbook;

void contactbookint(contactbook* pbook);
void contactbookadd(contactbook* pbook, contact* pcon);
contact* contactbookfind(contactbook* pbook, const char* name);
void contactbookdelete(contactbook* pbook, const char* name);
void contactbooksave(contactbook* pbook);
void contactbookload(contact* pbook);
void contactbookprint(contactbook* pbook);
void contactbookdestory(contactbook* pbook);