#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file2.h"
#define tru 1
#define fulse 0
#define admin 0
#define client 1
/**************************************/
#define the_curnt_open_system  admin
/**************************************/
#define main_windo  2
#define create_New_Account 1
#define open_existing_accoun 2
#define Exit_the_System 3
#define name_age 21
#define Make_Transaction 1
#define Change_Account_Status 2
#define Change_Account_password 2
#define Get_Cash 3
#define Deposit_in_Account 4
#define Return_to_main_menu 5
#define number_of_operation 4
#define number_of_operation2 6
#define yes 1
#define no  2
// function definition

void client_system(void);
void banck_system(void);
void New_account(void);
void open_Existing_Accoun(void);
void make_Transaction(void);
void change_Account_Status(void);
void get_Cash(void);
void deposit_in_Accoun(void);
void change_Account_password(void);

u8 flag_for_enter_in_accunet=fulse ;

typedef struct
{
	u8 name[100];
	u8 address[100];
	u8 stat[100];
	u16 age ;
	u16 password ;
	u64 balance ;
	u64 national_id ;
	u64 bank_account_id ;
	u64 Guardian_National_id ;

}acount;
// varibal

acount new_acount1 = {0} ;
acount new_acount2 = {"Mohamed Salah Hamed Mahrous","Hussien Wassef From El-Dokki st Giza","Active",25,1234,75000,29805070100179,1000000000};
acount new_acount3 ={"mahmoud ahmed abde twab","Hussien Wassef From El-Dokki st Giza","Active",26,1231,50000,29805070100178,1000000001};




// main functio

int main(int argc, char *argv[]) {
	#if the_curnt_open_system==admin
    banck_system();

	#elif the_curnt_open_system==client
     client_system();

	#endif

	return 0;
}




void banck_system(void)
{
	u16 The_type_of_operation;
	u16 flag1 = fulse ;
while(flag1 != tru)
{

	printf("plase entre The type of operation\n");
	printf("press (1) to create New Account\n");
	printf("press (2) to open Existing Account\n");
	printf("press (3) to exit the System\n");

	printf("the is operation : ");
	scanf("%d",&The_type_of_operation);
	if(The_type_of_operation < number_of_operation)
	 flag1 = tru ;
	else
	printf("\n\n wrong opration umber plase tray agine\n\n");
}

switch (The_type_of_operation)
    {
    	case create_New_Account :
        New_account();
		break ;


		case open_existing_accoun :
		open_Existing_Accoun();
		break;

		case Exit_the_System :
		printf("\n\n\n ************************************ system is Exit ***************************************\n\n\n ");
		break;

	}
}

void client_system(void)
{
    u16 flag1=fulse ;
	u16 flag2=fulse ;
	u16 flag3=fulse ;
	u16 password ;
	u16 typr_of_opreting2 ;
	u64 ID ;
if(flag_for_enter_in_accunet == fulse)
{
	while(flag1 != tru)
	{
			printf("plase enter your correct ID : ");
			scanf(" %d",&ID);
			if(new_acount2.bank_account_id == ID)
                flag1=tru ;
			else
			printf("\n\n your ID is wrong pleas try agine\n\n");
	}
		while(flag2 != tru)
	{
			printf("\nplase enter your correct password : ");
			scanf(" %d",&password);
			if(new_acount2.password == password)
                flag2=tru ;
			else
			printf("\n\n your password is wrong pleas try agine\n\n");
	}
	flag_for_enter_in_accunet=tru;
}
	while(flag3 != tru)
{


	printf("\n\nplase entre The type of operation\n");
	printf("press (1) to Make Transaction\n");
	printf("press (2) to Change Account password\n");
	printf("press (3) to Get Cash\n");
	printf("press (4) to Deposit in Account\n");
	printf("press (5) to Return to main menu\n");
    printf("pleas enter the is operation : ");
	scanf("%d",&typr_of_opreting2);
	if(typr_of_opreting2 < number_of_operation2)
	flag3 = tru ;
	else
	printf("\n\n worng umber operation \n\n");
}
	switch(typr_of_opreting2)
	{
		case Make_Transaction :
			make_Transaction();
			break;

		case Change_Account_password :
			change_Account_password();
			break;

		case Get_Cash :
			get_Cash();
			break;

		case Deposit_in_Account :
		deposit_in_Accoun();
		break;

		case Return_to_main_menu :
		flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system ***************************************\n\n\n ");
		client_system();
		break;
	}
}

void New_account(void)
{

	printf("\n\nhellow new we will take all of data to create new account\n\n\n");
	fflush(stdin);
	printf("plase enter yor full name : ");
	scanf("%[^\n]%*c",new_acount1.name);

    fflush(stdin);
	printf("\n\nplase enter your adderss :");
	scanf("%[^\n]%*c",new_acount1.address);

	fflush(stdin);
	printf("\n\nplase enter your age :");
	scanf("%d",&new_acount1.age);
	fflush(stdin);

    printf("\n\nplase enter national_id : ");
    scanf("%d",&new_acount1.national_id);
    if(new_acount1.age < name_age)
    {
        fflush(stdin);
    	printf("\n\nplase enter your Guardian_National_id : ");
    	scanf("%d",&new_acount1.Guardian_National_id);
	}
	printf("\n\nwe will creat  password and banck_id automatic\n\n\n");
    printf("\n\n\n ************************************ thank you for using my bank system ***************************************\n\n\n");
    banck_system();
}

void open_Existing_Accoun(void)
{
	u16 flag1=fulse ;
	u16 flag2=fulse ;
	u16 typr_of_opreting2 ;
	u64 ID ;

if(flag_for_enter_in_accunet == fulse)
{
	while(flag1 != tru)
	{
			printf("plase enter your correct ID : ");
			scanf(" %d",&ID);
			if(new_acount2.bank_account_id == ID)
			flag1=tru ;
			else
			printf("\n\n your ID is wrong pleas try agine\n\n");
	}
	flag_for_enter_in_accunet=tru;
}
while(flag2 != tru)
{
	fflush(stdin);
	printf("\n\nplase entre The type of operation\n");
	printf("press (1) to Make Transaction\n");
	printf("press (2) to Change Account Status\n");
	printf("press (3) to Get Cash\n");
	printf("press (4) to Deposit in Account\n");
	printf("press (5) to Return to main menu\n");

	printf("pleas enter the is operation : ");
	scanf("%d",&typr_of_opreting2);

	if(typr_of_opreting2 < number_of_operation2)
	flag2 = tru ;
	else
	printf("\n\n worng umber operation \n\n");
}
	switch(typr_of_opreting2)
	{
		case Make_Transaction :
			make_Transaction();
			break;

		case Change_Account_Status :
			change_Account_Status();
			break;

		case Get_Cash :
			get_Cash();
			break;

		case Deposit_in_Account :
		deposit_in_Accoun();
		break;

		case Return_to_main_menu :
        flag_for_enter_in_accunet = fulse ;
        printf("/n/n/n ************************************ thank you for using my bank system *************************************** ");
		banck_system();
		break;
	}

}





void make_Transaction(void)
{
    u8 flag = fulse;
    u8 flag1 = fulse;
    u8 operation;
    u64 mony ;
    u64 Bank_Account_ID ;
    while(flag!=tru)
    {
        printf("\n\nplase enter Bank Account ID of : ");
        scanf("%d",&Bank_Account_ID);
        if(Bank_Account_ID == new_acount3.bank_account_id)
        {
            if((strcmp(new_acount2.stat,"Active") == fulse) && (strcmp(new_acount3.stat,"Active") == fulse))
                flag = tru ;
            else
                printf("\none of your Account not Active pleas enter active Account\n");
        }
        else
            printf("\npleas enter correct Bank ID\n");
    }
    while(flag1!=tru)
    {
    printf("\npleas enter mony you went to transction: ");
    scanf("%d",&mony);
    if(mony<new_acount2.balance)
       flag1 = tru ;
    else
        printf("you enter mony more than you have pleas tray agin");
    }
    new_acount3.balance+=mony;
    new_acount2.balance-=mony;
#if the_curnt_open_system==admin
    printf("\n do you went to do any operation(1 for yes || 2 for return to main windo):");
    scanf("%d",&operation);
    switch(operation)
    {
    case yes :
        open_Existing_Accoun();
        break;
    case main_windo :
        flag_for_enter_in_accunet = fulse ;
        printf("/n/n/n ************************************ thank you for using my bank system *************************************** ");
        banck_system();
        break;
    }
#elif the_curnt_open_system==client
    printf("\n do you went to do any operation(1 for yes || 2 for no ):");
    scanf("%d",&operation);
    switch(operation)
    {
    case yes :
        client_system();
        break;
    case no :
        flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system ***************************************\n\n\n ");
        client_system();
        break;
    }
#endif


}


void change_Account_Status(void)
{
     u8 operation;
    fflush(stdin);
    printf("\n\nthe stats of this account is :%s",new_acount2.stat);
	printf("\n\nplase enter r the Bank Account Status, you want for this account:{Active State OR  Restricted State OR  Closed }");
	scanf("%[^\n]%*c",new_acount2.stat);

    printf("\n do you went to do any operation(1 for yes || 2 for return to main windo):");
    scanf("%d",&operation);
    switch(operation)
    {
    case yes :
        open_Existing_Accoun();
        break;
    case main_windo :
        flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system ***************************************\n\n\n ");
        banck_system();
        break;

    }

}


void get_Cash(void)
{
     u8 operation;
u64 monye ;
u8 flag1 = fulse ;

while(flag1 != tru)
{
printf("plase enter amount of mony you wented : ");
scanf("%d",&monye);

if(monye < new_acount2.balance)
{
	new_acount2.balance -= monye ;

    printf("your cearnt balance : %d",new_acount2.balance);

    flag1= tru ;
}
else
    printf("\n\n you dont have this amont  of many in you acount pleas tray agine");
}

#if the_curnt_open_system==admin
    printf("\n do you went to do any operation(1 for yes || 2 for return to main windo):");
    scanf("%d",&operation);
    switch(operation)
    {
    case yes :
        open_Existing_Accoun();
        break;
    case main_windo :
        flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system *************************************** \n\n\n ");
        banck_system();
        break;

    }
#elif the_curnt_open_system==client
    printf("\n do you went to do any operation(1 for yes || 2 for no):");
    scanf("%d",&operation);
    switch(operation)
    {
    case yes :
        client_system();
        break;
    case no :
        flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system ***************************************\n\n\n ");
        client_system();
        break;
    }

#endif
}


void deposit_in_Accoun(void)
{
    u8 operation;
	u64 monye;

printf("how amount of money do you went to add : ");
scanf("%d",&monye);
new_acount2.balance += monye ;
printf("\n\n\n new your have : %d",new_acount2.balance);
#if the_curnt_open_system==admin
    printf("\n do you went to do any operation(1 for yes || 2 for return to main windo):");
    scanf("%d",&operation);

    switch(operation)
    {
    case yes :
        open_Existing_Accoun();
        break;
    case main_windo :
        flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system *************************************** \n\n\n ");
        banck_system();
        break;

    }
#elif the_curnt_open_system==client
    printf("\n do you went to do any operation(1 for yes || 2 for no):");
    scanf("%d",&operation);
    switch(operation)
    {
    case yes :
        client_system();
        break;
    case no :
        flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system ***************************************\n\n\n ");
        client_system();
        break;
    }

#endif

}

void change_Account_password(void)
{
u8 flag_password = fulse ;
u16 password ;
u8 operation ;
		while(flag_password != tru)
	{
			printf("\nplase enter your correct password : ");
			scanf(" %d",&password);
			if(new_acount2.password == password)
                flag_password=tru ;
			else
			printf("\n\n your password is wrong pleas try agine\n\n");
	}
	printf("\n\npleas enter new password : ");
	scanf("%d",&new_acount2.password);
    printf("\n do you went to do any operation(1 for yes || 2 for no):");
    scanf("%d",&operation);
    switch(operation)
    {
    case yes :
        client_system();
        break;
    case no :
        flag_for_enter_in_accunet = fulse ;
        printf("\n\n\n ************************************ thank you for using my bank system ***************************************\n\n\n ");
        client_system();
        break;
    }

}































