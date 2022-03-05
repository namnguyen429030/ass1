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
void delete_number();
void delete_name();
// các hàm thêm
void search_number();
void search_name();
void list_month();
void list_all();
void inputPhone();
void inputBirth();
int valid_date();
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

	char first_name[20];
	char last_name[50];
	char company[100];
	char phone_number[100];
	char email[100];
	char working_address[400];
	char home_address[400];
	bd birday;
	
}person;


//bien toan cuc
person man[1000];

// t can số lượng để có thể sử dụng in list contact

int main()
{	
	int soluong = 0;
	char choice;
	// số lượng hiện tại là 0, sau khi ô Phúc sử dụng hàm add thì t sẽ lấy giá trị của ô Phúc
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
				add_contact(man, &soluong);
				//printf("%d", soluong);
				break;
			case '2':
				edit_contact();
				break;
			case '3':
                		char del;
                		printf("Enter 1 to delete by number/Enter 2 to delete by name: ");
                		scanf("%d",&del);
                		switch(del)
                		{
                    			case '1':
                        			char number[100];
                        			printf("Enter number you want to delete: ");
                        			scanf("%c",&number);
                        			delete_number(man,soluong,number);
                        		//o day dien ham hien thi lai cai contact keeper
                    			case '2':
                        			char fn[20],ln[50];   
                        			printf("Enter first name you want to delete: ");
                        			scanf("%c",&fn);
                        			printf("Enter last name you want to delete: ");
                        			scanf("%c",%ln);
                        			delete_name(man,soluong,fn,ln);
                        		//o day dien ham hien thi lai cai contact keeper
                		}
				break;
			case '4':
                		char search;
                		printf("Enter 1 to search by number/Enter 2 to search by name: ");
				scanf("%d",&search);
                		switch(del)
                		{
                    			case '1':
                        			char number[100];
                       				printf("Enter number you want to search: ");
                        			scanf("%c",&number);
                        			search_number(man,soluong,number);
                    			case '2':
                       				char fn[20],ln[50];   
                        			printf("Enter first name you want to search: ");
                        			scanf("%c",&fn);
                        			printf("Enter last name you want to search: ");
                        			scanf("%c",%ln);
                        			search_name(man,soluong,fn,ln);
                		}
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
			fflush(stdin);
		}
	}
	while (choice != 'q');

	return 0;
}

void inputPhone(char* phone){
	while(1)
	{
	printf("Phone number : ");	
	scanf("%s",phone);
	fflush(stdin);
	if(strlen(phone) < 9 || strlen(phone) > 10){
		printf("Phone number must have 9-10 digits!\n");
		continue;
	}
	int i = 0;
	int check = 1;
	for(i = 0;i < strlen(phone);i++){
		if(!isdigit(phone[i])){
			printf("Phone number must be included only number!\n");
			check = 0;
			break;
		}
	}
	if(check){
		return;
	}	
	}
}

void inputBirth(person man[], int *soluong)
{
	char a, b; 
	while(1)
	{
		printf("Enter Birthday in DD/MM/YYYY format: ");
		scanf("%d%c%d%c%d",&man[(*soluong)].birday.date, &a, &man[(*soluong)].birday.month, &b, &man[(*soluong)].birday.year);
		if(a != '/' || b != '/')
		{
			printf("Wrong format!\n");
			continue;
		}
		if(valid_date(man[(*soluong)].birday.date,man[(*soluong)].birday.month,man[(*soluong)].birday.year) == 0)
		{
			printf("Not valid number!\n");
			continue;
		}
		return;
	}
	
}

int valid_date(int dd, int mm, int yy) {
    if (mm < 1 || mm > 12) {
        return 0;
    }
    if (dd < 1) {
        return 0;
    }

    int days = 31;
    if (mm == 2) {
        days = 28;
        if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
            days = 29;
        }
    } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        days = 30;
    }

    if (dd > days) {
        return 0;
    }
    return 1;
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


void add_contact(person man[], int *soluong)
{	
	printf("Add one person!\n");
	printf("First name: ");
	scanf("%[^\n]", &man[(*soluong)].first_name);
	fflush(stdin);
	printf("Last name: ");
	scanf("%[^\n]", &man[(*soluong)].last_name);
	fflush(stdin);
	printf("Company: ");
	scanf("%[^\n]", &man[(*soluong)].company);
	fflush(stdin);
	printf("Working address: ");
	scanf("%[^\n]", &man[(*soluong)].working_address);
	fflush(stdin);
	printf("Email: ");
	scanf("%[^\n]", &man[(*soluong)].email);
	fflush(stdin);
	inputPhone(man[(*soluong)].phone_number);
	inputBirth(man, soluong);
	//printf("Phone number : ");
	//scanf("%[^\n]", &man[(*soluong)].phone_number);
	fflush(stdin);
	printf("Home address: ");
	scanf("%[^\n]", &man[(*soluong)].home_address);
	fflush(stdin);
	//nhap lieu ngay sinh
	(*soluong)++;
	
}


void edit_contact()
{
	printf("Write your code here to edit contact.");
}


void delete_number(person man[],int &n,char number[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(man[i].phone_number,number)==0)
                man[i]=man[j];
        }
        n-=1;
        return;
    }
}
void delete_name(person man[],int &n,char fn[],char ln[] )
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(man[i].first_name,fn)==0 && strcmp(man[i].last_name,ln)==0 )
                man[i]=man[j];
        }
        n-=1;
        return;
    }
}

void search_number(person man[],int &n,char number[])
{
	for(int i=0;i<n;i++)
        if(strcmp(man[i].phone_number,number)==0)
            printf("%10s %-20s - works in: %-20s - address: %s\n     Email: %-25s - Phone: %s - Birthday:%d/%d/%d\n     Home address: %s\n"
 			,man[i].first_name, man[i].last_name, man[i].company,man[i].working_address,man[i].email, man[i].phone_number,man[i].birday.date,man[i].birday.month,man[i].birday.year,man[i].home_address);
        else
            printf("Not found");
}

void search_name(person man[],int &n,char fn[],char ln[] )
{
    for(int i=0;i<n;i++)
        if(strcmp(man[i].first_name,fn)==0 && strcmp(man[i].last_name,ln)==0)
            printf("%10s %-20s - works in: %-20s - address: %s\n     Email: %-25s - Phone: %s - Birthday:%d/%d/%d\n     Home address: %s\n"
 			,man[i].first_name, man[i].last_name, man[i].company,man[i].working_address,man[i].email, man[i].phone_number,man[i].birday.date,man[i].birday.month,man[i].birday.year,man[i].home_address);
        else
            printf("Not found");
}

void list_month(person man[], int soluong)
{
	int m;
	if(soluong==0)
	printf("The Contact table is empty! Please add some.");
	else
	{
	printf("Enter the month you want to find: ");
	scanf("%d", &m);
	getchar();
	for(int i = 0; i <= soluong;i++)
	{
		if(m == man[i].birday.month)
		break;
		if(i == soluong)
		{
			printf("Your wanted imformation about month can not be found!");
			return;
		}
	}
	printf("----------------------------------------------------\n");
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
			printf("%10s %-20s - works in: %-20s - address: %s\n     Email: %-25s - Phone: %s - Birthday:%d/%d/%d\n     Home address: %s\n"
			,man[i].first_name, man[i].last_name, man[i].company,man[i].working_address,man[i].email, man[i].phone_number,man[i].birday.date,man[i].birday.month,man[i].birday.year,man[i].home_address);
		printf("----------------------------------------------------\n");
		}
	}
	}
}


void list_all(person man[], int soluong)
{
	if(soluong==0)
	printf("The Contact table is empty! Please add some.");
	else
	printf("CONTACT KEEPER TABLE\n");
	printf("----------------------------------------------------\n");

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
		printf("%10s %-20s - works in: %-20s - address: %s\n     Email: %-25s - Phone: %s - Birthday:%d/%d/%d\n     Home address: %s\n"
			,man[i].first_name, man[i].last_name, man[i].company,man[i].working_address,man[i].email, man[i].phone_number,man[i].birday.date,man[i].birday.month,man[i].birday.year,man[i].home_address);
		printf("----------------------------------------------------\n");
	}
	}
}

