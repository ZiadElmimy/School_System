#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "Admin.h"
#include "User.h"
Admin _admin;
Student s;
List l;
LIST L;
int choose_mode;
int main(){

        printf("-----------------------------------------------------------\n");
		printf("               * Welcome To Our Project *                \n");
		printf("               * Student Record System  *                 \n");
        printf("-----------------------------------------------------------\n");
		printf("\n");
    create_list(&l);
    create_list(&L);
    add_admin(&L,&_admin);
    Start_Program();

    return 0;
}


void Start_Program(){
	do
	{

        printf("\n");
        printf("_________________________________________________\n");
        printf("\n");
		printf("Admin Mode            >>>                  Enter1\n");
		printf("Student Mode          >>>                  Enter2\n");

	     printf("_________________________________________________\n");

        printf("\nYour choice: ");
        scanf("%d",&choose_mode);
		printf("\n");

		switch(choose_mode)
		{
			case 1:
			 printf("_________________________________________________\n");
			 printf("\n");
			 printf("               * Welcome To Admin Mode *        \n");
			 printf("_________________________________________________\n");
		    Login();

			break;

			case 2:
            printf("_________________________________________________\n");
            printf("\n");
 			printf("                * Welcome To Student Mode *              \n");

            printf("_________________________________________________\n");
			Login();
			//Student_Mode();
			break;

			default:
			 printf("_________________________________________________\n");
			 printf("\n");
			printf("                    Invalid Choice                    \n");
			 printf("_________________________________________________\n");
		}

		printf("\n");
		printf("Press y to run again .... ");
	}while(getch() == 'y');


	printf("\n\n");
	printf("_________________________________________________\n");

	printf("                  End of The Program                     \n");
	printf("_________________________________________________\n");
}


void Login(void)
{
	int flag = 0;
	int password_state;


	//login for admin
	if(choose_mode == 1)
	{
		int Entered_ID;

		printf("Enter Your ID: ");
		scanf("%d",&Entered_ID);
         Get_Admin( Entered_ID,&_admin,&L);


		while(L.head!= NULL)
		{

			if(_admin.adminID == Entered_ID)
			{
				password_state = Check_Password(_admin.adminPassword);

				if(password_state == 1)
					Admin_Mode();

				flag = 1;
				break;
			}

		}

		if(flag == 0)
		{
			printf("\n");
			printf("                Entered ID doesn't exist!                \n");

		}
	}
	else if(choose_mode == 2)  //login for student
	{
	    Node *current=l.Head;
		int Entered_ID;

		printf("Enter Your ID: ");
		scanf("%d",&Entered_ID);

		while(current != NULL)
		{
			if(current->value.ID== Entered_ID)
			{
				password_state = Check_Password(current->value.password);

				if(password_state == 1)
					Student_Mode(Entered_ID);

				flag = 1;
				break;
			}
         current=current->next;
		}

		if(flag == 0)
		{
			printf("\n");

			printf("                Entered ID doesn't exist!                \n");

		}
	}

}


int Check_Password(char *password)
{
	int counter, pass_correct_or_not;
	static int num_attempts = 0;
	char Entered_Password[5];
    printf("\nNote: password is only 4 characters.\n");
	if(num_attempts < 3)
	{
		printf("Enter Your Password: ");
		for(counter = 0; counter < 4; counter++)
		{
			Entered_Password[counter] = getch();
			printf("*");
		}
		Entered_Password[counter] = '\0';
		if(strcmp(Entered_Password,password) == 0)
		{
			num_attempts = 0;
			pass_correct_or_not = 1;
		}
		else
		{
			printf("\n\n");

			printf("                   Wrong Password !!!                    \n");

			num_attempts++;
			pass_correct_or_not = Check_Password(password);
		}
	}
	else
	{
		pass_correct_or_not = 0;
		num_attempts = 0;

		printf("                You can't try again !!!                  \n");

		printf("\n");
	}

	return pass_correct_or_not;
}
