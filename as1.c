/* CONTACT KEEPER
 * ==============
 * 
 * So far, you've been learning the C programing language about two weeks.
 * Now is the right time to think about your assignment.
 * This semester, your task is to write a C program, namely Contact Keeper,
 * to manage your contacts easily and effectively.
 * 
 * One contact should have the following features:
 *		1. First Name
 *		2. Last Name
 *		3. Company
 *		3. Phone Number
 *		4. Email
 *		5. Working Address
 *		6. Home Address
 *		7. Birthday
 *
 * Data validation should be implemented, for example:
 *		1. Phone Number should be a integer number of 9 or 10 digits
 *		2. Bithday should be in the DD/MM/YYYY format 
 *
 * Your program should have at least six functions:
 *		1. Add new contact
 *		2. Edit contact
 *		3. Delete contact (by name or phone number)
 *		4. Search contact (by name or phone number)
 *		5. List all contacts with birthdays in a given month (sort by date)
 *		6. List all contacts in the table format (sort by name)
 *
 * The contact information should be permanently stored in a text file
 * so that when the program starts all contacts could be loaded automatically.
 *
 * Form a group of three members and enjoy this task!
 */


#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>

#define MAX 10000

void print_menu();
void add_contact();
void edit_contact();
void delete_contact();
// các hàm thêm
void search_contact();
void list_month();
void list_all();
//

// t khai baos 1 struct kieu ngay sinh
typedef struct born
{
	int date;
	int month;
	int year;
}bd;

// day la kieu khai bao 1 struct kieu con nguoi, la tat ca cac thong tin de contact
typedef struct ng
{

	char first_name[10];
	char last_name[25];
	char company[40];
	char phone_number[10];
	char email[50];
	char working_address[100];
	char home_address[100];
	bd birday;
	
}person;


//bien toan cuc
person *man;
int soluong;
// t can số lượng để có thể sử dụng in list contact

int main()
{	
	char choice;
	soluong = 0; // số lượng hiện tại là 0, sau khi ô Phúc sử dụng hàm add thì t sẽ lấy giá trị của ô Phúc
	do
	{
		system("cls"); 
		print_menu();
		scanf("%c%*c", &choice);

		system("cls"); 

		printf("CONTACT KEEPER\n");
		printf("==============\n\n");

		switch(choice)
		{
			case '1':
				add_contact();
				break;
			case '2':
				edit_contact();
				break;
			case '3':
				delete_contact();
				break;
			case '4':
				search_contact();
				break;
			case '5':
				list_all(man, soluong);
				break;
			case '6':
				list_month(man, soluong);
				break;
		}
		
		if (choice != 'q')
		{
			printf("\n\n---\n");
			printf("Press any key to back to main menu.");
			getchar();
			getchar();
		}
	}
	while (choice != 'q');

	return 0;
}


void print_menu()
{
	printf("CONTACT KEEPER\n");
	printf("==============\n\n");
	printf("1. Add Contact\n");
	printf("2. Edit Contact\n");
	printf("3. Delete Contact\n");
	printf("4. Search Contact\n");
	printf("5. Show list Contact\n");
	printf("6. show list Contact with birday by given month\n");
	printf("q. Quit\n\n");
	printf("Enter your choice (1/2/3/4/5/6/q): ");
}


void add_contact()
{
	printf("Write your code here to add new contact.");
}


void edit_contact()
{
	printf("Write your code here to edit contact.");
}


void delete_contact()
{
	printf("Write your code here to delete contact.");
}

//ham them
void search_contact()
{
	printf("Write your code here to delete contact.");
}

void list_month(person man[], int soluong)
{
	int m;
	printf("Enter the month you want to find: ");
	scanf("%d", &m);
	getchar();
	if(soluong==0)
	printf("The Contact table is empty! Please add some.");
	else
	{
	for(int i = 0; i < soluong-1;i++)
	{
		for(int j = 0; j < soluong; j++)
		{
			if(man[i].birday.date > man[j].birday.date && man[i].birday.month == m && man[j].birday.month == m)
			{
				person temp = man[i];
				man[i] = man[j];
				man[j] = temp;
			}
		}
	}
	for(int i = 0; i < soluong;i++)
	{
		if(man[i].birday.month == m)
		{
			printf("%s %s works in %s - address: %s\
			\nEmail: %s - Phone: %s - Birthday:%d/%d/%d\
			\nHome address: %s",man[i].first_name, man[i].last_name, man[i].company,man[i].working_address,
			man[i].email, man[i].phone_number,man[i].birday.date,man[i].birday.month,man[i].birday.year,
			man[i].home_address);
		}
		printf("\n");
	}
	}
}


void list_all(person man[], int soluong)
{
	if(soluong==0)
	printf("The Contact table is empty! Please add some.");
	else
	{
	for(int i = 1; i < soluong ; i++)
	{
		for(int j = 1; j < soluong; j++)
		{
			if(strcmp(man[j-1].first_name, man[j].first_name) > 0)
			{
				person temp = man[j-1];
				man[j-1] = man[j];
				man[j] = temp;				
			}
		}
	} 
	for(int i = 0; i < soluong;i++)
	{
		printf("\n%s %s works in %s - address: %s\
			\nEmail: %s - Phone: %s - Birthday:%d/%d/%d\
			\nHome address: %s",man[i].first_name, man[i].last_name, man[i].company,man[i].working_address,
			man[i].email, man[i].phone_number,man[i].birday.date,man[i].birday.month,man[i].birday.year,
			man[i].home_address);
	}
	}
}