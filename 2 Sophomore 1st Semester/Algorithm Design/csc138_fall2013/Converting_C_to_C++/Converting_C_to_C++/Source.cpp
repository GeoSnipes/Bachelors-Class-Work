#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;

//Structures
int ic=0, ec=0;

struct inventory
{
   int quant, price;
   char id[5], name[30];    
};
struct inventory inv[32];

struct employees
{
       char fname[20], lname[20], cnumber[12], address[40], eaddress[30];
};
struct employees emp[32];

//Functions
void mode();
void pass ();
void passprogram();
void man_menu();
void invent_menu();
void employ_menu();
void view_inventory();
void view_employees();
void update_inventory();
void update_employees();
void added();
void eadded();
void idelete();
void edelete();
void cash_menu();
void cview_inventory();
void cash();
void csearch();
void msearch();

void main()
{
	system ("color 3A"); // Change window colour to a greenish colour
	mode();
	cout<<"So far so good.";
}

//Actual Program

void mode()//Main Menu
{
    char ent;
    
    system("cls");
    fflush(stdin);
    cout<<"\t\t\t\t   C Hong Meat Store\n"; 
    cout<<"\t\t\t 20 Mitchell Street, Kingston 20 P.O.\n";
    cout<<"\t\t\t\tPhone: 878-3421, 908-7626";
    cout<<"\n\n\t\t    *******************************************\n";
    cout<<"\t\t    **Welcome to my Inventory/Cashier Program**\n"; 
    cout<<"\t\t    *******************************************\n\n";   
    cout<<"To: \n\tM- Enter Manager Mode \n\tC- Enter Cashier Mode \n\tE- Exit Program \n\n";
    cout<<"Option: ";
    cin>>ent;
    fflush(stdin);
    switch (ent)
    {
           case 'M': case 'm':
              system("cls");
              pass();
              break;
           case 'C': case 'c':
                system("cls");
                //cash_menu();
                break;
           case 'E': case 'e':
                exit(0);
                break;
           default:
				cout<<"\n\nCommand entered not recognised! Press a key to continue.\n";
				_getch();
				mode();
				break;         
    }
}

void pass ()//To check if username and password already exist
{
    ifstream rPassword;
    ofstream wPassword;
    
    char username[16] , password[16], password1[16];
      
    rPassword.open("Pass.dat");
    if (rPassword == "")
    {
     wPassword.open("Pass.dat");
     cout<<"\t\t\tThis is the first time you have used this program\n";
     cout<<"Enter your new Username:\n";
     cin>>username;
     cout<<"\nEnter a new password:\n";
     cin>>password1;
     cout<<"\nConfirm password by entering it again:\n";
     cin>>password;
     while (strcmp(password1,password)!= 0)
           {
			 system("cls");
                cout<<"Passwords do not match! \n\n";
                cout<<"Enter your new Username:\n";
                cin>>username;
                cout<<"\nEnter your new password:\n";
                cin>>password1;
                cout<<"\nConfirm password by entering it again:\n";
                cin>>password;
           }    
     wPassword<<username<<"\t"<<password;
     cout<<"\n\nNew Username and Password successfully created. Press a key to continue.\n"; 
     rPassword.close();
	wPassword.close();
     _getch();
     passprogram();
    }
    else
    {
        rPassword.close();
        passprogram();
    }
}

void passprogram()
{
    ifstream rPassword;
    
    char UserName[16], Password[16], usern[16], pword[16], pchoice;
    int x;//To keep count of incorrect attempts
    
    fflush(stdin);
    rPassword.open("Pass.dat");
    if (rPassword.fail())
    {
        cout<<"No username or password created. Do you want to create it now or exit the program?\nTo create a username and password now type 'Y' or 'N' to exit.\n\n\n\n\n";
        cin>>pchoice;
        switch (pchoice)
        {
               case 'Y': case 'y':
                    rPassword.close();
                    pass();
                    break;
               case 'N': case 'n':
                    rPassword.close();
                    exit(0);
                    break;
               default:
                       cout<<"Option not recognised. Press a key to continue.";
                       rPassword.close();
                       _getch();
                       passprogram();
                       break;
        }
    }
    else
    {
        for (x=0;x<3;x++)
        {
            system ("cls");
            cout<<"\t\tWelcome To Snipe's Meat Shop Manager Mode\n\n\n\n\n\n\n";
            cout<<"\t\t\tEnter Username...:";
            cin>>usern;
            cout<<"\t\t\tEnter Password...:";
            cin>>pword;
            rPassword>>UserName>>Password;
            if (strcmp(UserName,usern)==0 && strcmp(Password,pword)==0)
            {
                  rPassword.close();
                  man_menu();
            }
            else 
            {   
                cout<<"\nEntries do not match. Press a key to continue.";
                _getch();
            }
        }
        rPassword.close();
        cout<<"\nI'm sorry but you have entered 3 times the wrong Username and/or Password.\nThe Program will now close. Press a key to continue.";
        _getch();
        }
}

void man_menu()
{
       int option;         
       
	  fflush(stdin);
       system("cls");
       cout<<"Select your option:\n\n";
       cout<<"1. Inventory Menu\n";
       cout<<"2. Employee Menu\n";
       cout<<"3. Search\n";
       cout<<"4. Go to Mode Select\n";
       cout<<"5. Exit program\n\n";
       cout<<"Option: ";
       cin>>option;
       switch(option)
       {
          case 1:
			invent_menu();  
               break;
          case 2:
               employ_menu();
               break;
          case 3:
               //msearch();
               break;
          case 4:
               mode();
               break;
          case 5:
               exit(0);
               break;
          default:
               cout<<"Option not recognised.";
			_getch();
               man_menu();
               break;
       }
}

void invent_menu()
{
       int ioption;         
          
       fflush(stdin);
       system("cls");
       cout<<"Select your option:\n\n";
       cout<<"1. View Inventory\n";
       cout<<"2. Update Inventory\n";
       cout<<"3. Go to Main Menu\n";
       cout<<"4. Exit Program\n\n";
       cout<<"Option: ";
       cin>>ioption;
       switch(ioption)
       {
          case 1:
                        view_inventory();  
                        break;
          case 2:
                        update_inventory();
                        break;
          case 3:
                        man_menu();
                        break;
          case 4:
                        exit(0);
                        break;
          default:
                        cout<<"Option not recognised.";
                        _getch();
                        invent_menu();
                        break;
       }
}  
       
void employ_menu()
{
	int eoption;

	fflush(stdin);
	system("cls");
	cout << "Select your option:\n\n";
	cout << "1. View Employee Records\n";
	cout << "2. Update Employee Records\n";
	cout << "3. Go to Main Menu\n";
	cout << "4. Exit Program\n\n";
	cout << "Option: ";
	cin >> eoption;
	switch (eoption)
	{
	case 1:
		view_employees();
		break;
	case 2:
		update_employees();
		break;
	case 3:
		man_menu();
		break;
	case 4:
		exit(0);
		break;
	default:
		cout << "Option not recognised. ";
		_getch();
		employ_menu();
		break;
	}
}
                        

/*    
int invent_menu()
{
       int ioption;         
          
       fflush(stdin);
       system("cls");
       printf("Select your option:\n\n");
       printf("1. View Inventory\n");
       printf("2. Update Inventory\n");
       printf("3. Go to Main Menu\n");
       printf("4. Exit Program\n\n");
       printf("Option: ");
       scanf("%d", &ioption);
       switch(ioption)
       {
          case 1:
                        view_inventory();  
                        break;
          case 2:
                        update_inventory();
                        break;
          case 3:
                        man_menu();
                        break;
          case 4:
                        exit(0);
                        break;
          default:
                        printf("Option not recognised.");
                        getch();
                        invent_menu();
                        break;
       }
}  
       
int employ_menu()
{
       int eoption;         
          
       fflush(stdin);
       system("cls");
       printf("Select your option:\n\n");
       printf("1. View Employee Records\n");
       printf("2. Update Employee Records\n");
       printf("3. Go to Main Menu\n");
       printf("4. Exit Program\n\n");
       printf("Option: ");
       scanf("%d", &eoption);
       switch(eoption)
       {
           case 1:
                       view_employees();  
                       break;
           case 2:
                       update_employees();
                       break;
           case 3:
                       man_menu();
                       break;
           case 4:
                       exit(0);
                       break;
           default:
                       printf("Option not recognised. ");
                       getch();
                       employ_menu();
                       break;
          }
       }   
                        
int view_inventory()
{
    FILE *rInventory;
    FILE *restock;
    
    system ("cls");
    if ((rInventory = fopen("Inventory.txt","r"))==NULL)
    {
        printf("There are no records in your inventory!!!!\n\n");
        printf("Press a key to continue");
    }
    else
    {
      
        ic=ic+1;
        restock=fopen("Restock.txt", "w");//To check which goods need to be restocked
        printf("\t\t\t\t**INVENTORY**\n\n");
        printf("\t\t\t\tLbs\t\tPrice\n");
        printf("Id:\tName:\t\t\tin stock:\tper Lb:\n");
        fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(rInventory))
        {
            printf("%s\t%s\t\t\t%d\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
            if (inv[ic].quant <20)//20lbs is set to trigger to restock notifier
            {
                              fprintf(restock, "%s\t\t%s\t\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant);//Goods that need to be restocked are saved in this file
            }
            fscanf(rInventory,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        
        fclose(rInventory);
        fclose(restock);
        restock=fopen("Restock.txt", "r");
        fscanf(restock, "%s%s%d", inv[ic].id, inv[ic].name, &inv[ic].quant);
        while ( !feof(restock))
        {
            printf("\n\nItem ID %s, %s, needs to be restocked as %d lbs are left.", inv[ic].id, inv[ic].name, inv[ic].quant);
            fscanf(restock,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        printf("\n\n\nPress a key to continue");
    }
    getch();
    invent_menu();
}

int view_employees()
{
    FILE *rEmployee;

    system ("cls");
    if ((rEmployee = fopen("Employee.txt","r"))==NULL)
    {
        printf("There are no employee records stored!\n\n");
        printf("Press a key to continue");
    }
    else
    {
        ec=ec+1;
        fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        while ( !feof(rEmployee))
        {
            printf("Name: %s %s\nCell Number: %s\nAddress: %s\nEmail: %s\n\n", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
            fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        }
        printf("\nPress a key to continue");
        fclose(rEmployee);
    }
    getch();
    employ_menu();
}

int update_inventory()
{
    int iad_choice;      
    
    system("cls");
    printf("\t\t\t\t**UPDATE INVENTORY**\n\n\n");
    printf("Would you like to \n\t1 - Add new stock item\n\t2 - Delete an item\n\t3 - Go back to inventory menu\n\n");
    printf("Option: ");
    scanf("%d", &iad_choice);
    switch (iad_choice)
    {
           case 1:
                added();
                break;
           case 2:
                idelete();
                break;
           case 3:
                invent_menu();
                break;
           default:
                  printf("Option not recognised!\n\n\n");
                  getch();
                  update_inventory();
                  break;
    }
}

int update_employees()
{
    int ead_choice;      
    
    system("cls");
    printf("\t\t\t\t**UPDATE Employee Records**\n\n\n");
    printf("Would you like to \n\t1 - Add an employee\n\t2 - Delete an employee\n\t3 - Go to employee menu\n\n");
    printf("Option: ");
    scanf("%d", &ead_choice);
    switch (ead_choice)
    {
           case 1:
                eadded();
                break;
           case 2:
                edelete();
                break;              
           case 3:
                employ_menu();
                break;
           default:
                  printf("Option not recognised!\n\n\n");
                  getch();
                  update_employees();
                  break;
    }
}

int added()
{
    FILE *wInventory;
    
    char choice= 'y';
    ic=ic+1;
    while ((choice=='y')||(choice=='Y'))
    {
          system("cls");
          printf("\t\t\t\t***ADD STOCK***\n\n\n");
          wInventory = fopen ("Inventory.txt", "a");
          printf("NB. \tDO NOT USE SPACE IN ANY OF THE FOLLOWING AREAS.\n\tUSE A UNDERSCORE TO SEPARATE WORDS.\n\n");
          printf("Enter the item's ID #, no longer than 4 charaters:\n");
          scanf("%s", inv[ic].id);
          printf("\nEnter the item's name: \n");
          scanf("%s", inv[ic].name);
          printf("\nEnter the # of lbs in stock:\n");
          scanf("%d", &inv[ic].quant);
          printf("\nEnter the price per lb:\n");
          scanf("%d", &inv[ic].price);
          fprintf(wInventory, "%s\t%s\t\t%d\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
          fclose(wInventory);
          fflush(stdin);
          printf("\t\t\tRecord successfully added!\n\n\n");
          printf("Enter 'Y' for yes or or any other character for no.\nDo you want to add a next record?  ");
          scanf("%c", &choice);
    }
    if ((choice != 'Y')||(choice!='y'))
    {
          invent_menu();
    }                                  
}

int eadded()
{
    FILE *wEmployee;
   
    char choice= 'y';
    
    while ((choice=='y')||(choice=='Y'))
    {
          ec=ec+1;
          system("cls");
          printf("\t\t\t\t***ADD EMPLOYEE***\n\n\n");
          wEmployee = fopen ("Employee.txt", "a");
          printf("NB. \tDO NOT USE SPACE IN ANY OF THE FOLLOWING AREAS.\n\tUSE A UNDERSCORE TO SEPARATE WORDS.\n\n");
          printf("Enter the employee's first name:\n");
          scanf("%s", emp[ec].fname);
          printf("\nEnter the employee's last name: \n");
          scanf("%s", emp[ec].lname);
          printf("\nEnter his or her cell number:\n");
          scanf("%s", emp[ec].cnumber);
          printf("\nEnter his or her address:\n");
          scanf("%s", emp[ec].address);
          printf("\nEnter his or her email address:\n");
          scanf("%s", emp[ec].eaddress);
          fprintf(wEmployee, "%s\t%s\t%s\t%s\t%s\n", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
          fclose(wEmployee);
          fflush(stdin);
          printf("\n\t\t\tRecord successfully added!\n\n\n");
          printf("Do you want to add a next record? \nEnter 'Y' for yes or any other character for no.\n");
          printf("Option: ");
          scanf("%c", &choice);
    }
    
    if ((choice != 'Y')||(choice != 'y'))
    {
                  employ_menu();
    }                                   
}

int idelete()
{
    FILE *rInventory;
    FILE *nInventory;
    
    int count=0, icount=0;
    char iddelete[5], dent;
    
    fflush(stdin);
    system ("cls");
    rInventory = fopen("Inventory.txt", "r");
    if (rInventory == NULL)
    {
        printf("There are no records in your inventory to delete!!!!\n\n");
        printf("Press a key to continue");
        getch();
        invent_menu();
    }
    else
    {
        ic=ic+1;
        printf("\t\t\t\t**INVENTORY**\n\n");
        printf("\t\t\t\t\tLbs\n");
        printf("Id:\t\t\tName:\t\tin stock:\tPrice Per Lb:\n");
        fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(rInventory))
        {
            printf("%s\t\t\t%s\t\t%d\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
            ic=ic+1;
            fscanf(rInventory,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        fclose(rInventory);
        printf("\n\nThese are your records. Remember the ID number of the item you want to delete.\n\n");
        rInventory = fopen ("Inventory.txt","r");
        nInventory = fopen ("Inventory2.txt", "w");
        ic=1;
        printf("What stock would you like to delete?\n");
        scanf("%s", iddelete);
        fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while (!feof(rInventory))
        {
            if (strcmp(iddelete,inv[ic].id)!=0)
                {
                     fprintf(nInventory, "%s\t%s\t%d\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
                }
                else
                {
                    count=1;
                }
            ic=ic+1;
            fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        if (count ==1)
        {
           printf("\nRecord %s deleted.", iddelete);
        }
        else
        {
            printf("\nNo such record exists!\n");
        }
        fclose(nInventory);
        fclose(rInventory);
        rename("Inventory.txt","Inventory3.txt");
        rename("Inventory2.txt","Inventory.txt");
        remove("Inventory3.txt");
        fflush(stdin);
        rInventory= fopen("Inventory.txt","r");
        fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(rInventory))
        {
             icount= icount+1;
             fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        if (icount== 0)
        {
            fclose(rInventory);
            remove("Inventory.txt");
        }
        fclose(rInventory);
        printf("\n\nTo delete another record press 'Y' or press any other character to exit\n");
        scanf("%c", &dent);
        if ((dent== 'Y')||(dent=='y'))
        {
                  idelete();
        }
        else
        {
            invent_menu();
        }
    }
}

int edelete()
{
    FILE *rEmployee;
    FILE *nEmployee;
    
    int count=0, ecount=0;
    char edelete[5], dent;
    
    fflush(stdin);
    system ("cls");
    rEmployee = fopen("Employee.txt", "r");
    if (rEmployee==NULL)
    {
        printf("There are no records in your employee file to delete!!!!\n\n");
        printf("Press a key to continue");
        fclose(rEmployee);
        getch();
        employ_menu();
    }
    else
    {
        ec=ec+1;
        fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        while ( !feof(rEmployee))
        {
            printf("Name: %s %s\nCell Number: %s\nAddress: %s\nEmail: %s\n\n", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
            fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        }
        fclose(rEmployee);
        ec=1;
        printf("\nThese are your records. Remember the last name of the person you want to delete.\n\n\n");
        rEmployee = fopen ("Employee.txt","r");
        nEmployee = fopen ("Employee2.txt", "w");
        printf("Enter the last name of the employee you would like to delete: ");
        scanf("%s", edelete);
        fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        while (!feof(rEmployee))
        {
            if (strcmp(edelete,emp[ec].lname)!=0)
                {
                     fprintf(nEmployee, "%s\t%s\t%s\t%s\t%s\n", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
                }
                else
                {
                    count=1; //If the record exist
                }
            ec=ec+1;
            fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        }
        if (count == 1)
        {
           printf("\nRecord %s deleted.", edelete);
        }
        else
        {
            printf("\nNo such record exists!\n");
        }
        fclose(nEmployee);
        fclose(rEmployee);
        rename("Employee.txt","Employee3.txt");
        rename("Employee2.txt","Employee.txt");
        remove("Employee3.txt");
        fflush(stdin);
        rEmployee= fopen("Employee.txt","r");
        fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        while ( !feof(rEmployee))
        {
             ecount= ecount+1;
             fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        }
        if (ecount== 0)
        {
            fclose(rEmployee);
            remove("Employee.txt");
        }
        fclose(rEmployee);
        printf("\n\nTo delete another record press 'Y' or press any character to exit\n");
        scanf("%c", &dent);
        if ((dent == 'Y')||(dent=='y'))
        {
                int edelete();
        }
        else
        {
            employ_menu();
        }
    }
}

int msearch()
{
    FILE *rInventory;
    FILE *rEmployee;
    
    char search[15], soption;
    int found=0;
    
    system("cls");
    fflush(stdin);
    printf("Enter either the item # or name of the good or employee's first\nor last name of what or whom you are searching for: ");
    scanf("%s", search);
    rInventory=fopen("Inventory.txt", "r");
    rEmployee=fopen("Employee.txt", "r");
    if ((rInventory==NULL)&&(rEmployee==NULL))
    {
        printf("\n\nThere are no inventory or employee records to search!\n\n");
        printf("You will be directed back to the manager menu. Press a key to continue.");
        getch();
        man_menu();
    }
    else
    {
        fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(rInventory))
        {
            if ((strcmp(search,inv[ic].id)==0)||(strcmp(search,inv[ic].name)==0))
            {
                                            printf("\n\n\t\t\t\t**INVENTORY**\n\n");
                                            printf("\t\t\t\t\tLbs\n");
                                            printf("Id:\t\tName:\t\t\tin stock:\tPrice Per Lb:\n");
                                            printf("%s\t\t%s\t\t\t%d\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
                                            found=1;
            }
            fscanf(rInventory,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
        while ( !feof(rEmployee))
        {
            if ((strcmp(search,emp[ec].fname)==0)||(strcmp(search,emp[ec].lname)==0))
            {
                   printf("\n\nName: %s %s\nCell Number: %s\nAddress: %s\nEmail: %s\n\n", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);
                   found=1;
            }
            fscanf(rEmployee, "%s%s%s%s%s", emp[ec].fname, emp[ec].lname, emp[ec].cnumber, emp[ec].address, emp[ec].eaddress);

        }
        fclose(rInventory);
        fclose(rEmployee);
        if (found==0)
        {
                     printf("\n\nNo item was found matching your enquiry.");
        }
        fflush(stdin);
        printf("\n\n\n\n\nDo you want to:\nS- Search for another item\nC- Go back to manager menu\n\nOption: ");
        scanf("%c", &soption);
        switch(soption)
        {
                      case 'S': case 's':
                           msearch();
                           break;
                      case 'C': case 'c':
                           man_menu();
                           break;
                      default:
                           printf("Option not recognised. You will be directed back to the manager menu.\n\n\n");
                           getch();
                           man_menu();
                           break;
        }
        getch();
    }
}
    

int csearch()
{
    FILE *rInventory;
    
    char search[15], soption;
    int found=0;
    
    system("cls");
    fflush(stdin);
    printf("Enter either the item # or name of what you are searching for: ");
    scanf("%s", search);
    rInventory=fopen("Inventory.txt", "r");
    if (rInventory==NULL)
    {
        printf("There are no records in your inventory to search. Contact the manager!\n\n");
        printf("You will be directed back to mode select. Press a key to continue.");
        getch();
        cash_menu();
    }
    else
    {
        fscanf(rInventory, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(rInventory))
        {
            if((strcmp(search,inv[ic].id)==0)||(strcmp(search,inv[ic].name)==0))
            {
                                            printf("\t\t\t\t**INVENTORY**\n\n");
                                            printf("\t\t\t\t\tLbs\n");
                                            printf("Id:\t\tName:\t\t\tin stock:\tPrice Per Lb:\n");
                                            printf("%s\t\t%s\t\t\t%d\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
                                            found=1;
            }
            fscanf(rInventory,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        fclose(rInventory);
        if (found==0)
        {
                     printf("\n\nNo item was found matching your enquiry.");
        }
        fflush(stdin);
        printf("\n\n\n\n\nDo you want to:\nS- Search for another item\nC- Go back to cashier menu\n\nOption: ");
        scanf("%c", &soption);
        switch(soption)
        {
                      case 'S': case 's':
                           csearch();
                           break;
                      case 'C': case 'c':
                           cash_menu();
                           break;
                      default:
                           printf("Option not recognised. You will be directed back to cashier menu.\n\n\n");
                           getch();
                           cash_menu();
                           break;
        }
        getch();
    }
}
    
int cash_menu()
{ 
    char cashoption;
    
    fflush(stdin);
    system("cls");
    printf("Do you want to:\nV- View Inventory\nM- Make A Bill\nS- Search\nG- Go To Mode Select\n\nOption: ");
    scanf("%c", &cashoption);
    switch(cashoption)
    {
                      case 'V': case 'v':
                           cview_inventory();
                           break;
                      case 'M': case 'm':
                           cash();
                           break;
                      case 'S': case 's':
                           csearch();
                           break;
                      case 'G': case 'g':
                           mode();
                           break;
                      default:
                              printf("Option not recognised!\n\n\n");
                              getch();
                              cash_menu();
                              break;
    }
}

int cview_inventory()
{
    FILE *pRead;
    FILE *restock;
    
    char coption;

    fflush(stdin);
    ic=ic+1;
    system ("cls");
    pRead=fopen("Inventory.txt", "r");
    restock=fopen("Restock.txt", "w");//To check which goods need to be restocked
    if (pRead==NULL)
    {
        printf("There are no records in your inventory!!!!\n\n");
        printf("You will be directed back to mode select. Press a key to continue.");
        getch();
        mode();
    }
    else
    {
        printf("\t\t\t\t**INVENTORY**\n\n");
        printf("\t\t\t\t\tLbs\n");
        printf("Id:\t\tName:\t\t\tin stock:\tPrice Per Lb:\n");
        fscanf(pRead, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(pRead))
        {
            printf("%s\t\t%s\t\t\t%d\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
            if (inv[ic].quant <20)
            {
                              fprintf(restock, "%s\t\t%s\t\t\t%d\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
            }
            ic=ic+1;
            fscanf(pRead,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);

        }
        fclose(pRead);
        fclose(restock);
        restock=fopen("Restock.txt", "r");
        fscanf(restock, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(restock))
        {
            printf("\n\nItem ID %s, %s, needs to be restocked as %d lbs are left.\nNotify the manager.", inv[ic].id, inv[ic].name, inv[ic].quant);
            fscanf(restock,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        printf("\n\nDo you want to:\nM- Make a bill\nG- Go to mode select\n");
        printf("\nOption: ");
        scanf("%c", &coption);
        switch(coption)
        {
                   case 'M': case 'm':
                        cash();
                        break;
                   case 'G': case 'g':
                        mode();
                        break;
                   default:
                           printf("Option not recognised. You will be directed to mode select.");
                           getch();
                           mode();
                           break;
        }             
    }
    
}

int cash()                          
{
    FILE *wCash;
    FILE *readCash;
    FILE *newInvent;
    FILE *readInvent;
    
    int bquant, itotal=0, btotal=0, change, collect, ncollect;
    char eid[5], ient;
    
    system ("cls");
    readInvent = fopen("Inventory.dat", "r");
    if (readInvent==NULL)
    {
        printf("There are no records in your inventory to cash!!!!\nContact the manager.\n\n");
        printf("You will be directed back to mode select. Press a key to continue.");
        getch();
        mode();
    }
    else
    {
        ic=ic+1;
        printf("\t\t\t\t**INVENTORY**\n\n");
        printf("\t\t\t\t\tLbs\t\tPrice\n");
        printf("Id:\t\t\tName:\t\tin stock:\tper lb:\n");
        fscanf(readInvent, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        while ( !feof(readInvent))
        {
            printf("%s\t\t\t%s\t\t%d\t\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
            ic=ic+1;
            fscanf(readInvent,"%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
        }
        fclose(readInvent);
        ic=1;
        wCash = fopen ("Cash.dat", "w");
        printf("\n\n\nEnter the ID number of the item being purchased and the quantity needed.\nWhen finished enter 'End' for ID and '0' for quantity.\n");
        printf("\n\tId: ");
        scanf("%s", eid); 
        printf("\tQuantity: ");
        scanf("%d",  &bquant);
        while (((strcmp("End", eid)!=0)||(strcmp("end", eid)!=0)) && (bquant != 0))
        {
              readInvent = fopen ("Inventory.dat","r");
              newInvent= fopen ("Inventory2.dat", "a");
              fscanf(readInvent, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
              while (!feof(readInvent))
              {
                    if (strcmp(eid,inv[ic].id)==0)
                    {
                        if (bquant<=inv[ic].quant)
                        {
                               itotal= bquant*inv[ic].price;
                               btotal= btotal+itotal;
                               inv[ic].quant= inv[ic].quant-bquant;
                               fprintf(wCash, "%s\t%d\t%d\t%d\n", inv[ic].name, bquant, inv[ic].price, itotal);
                               fprintf(newInvent, "%s\t%s\t%d\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);              
                        }
                        else
                        {
                           printf("You cannot order more %s than what is in stock. Order again.\n", inv[ic].name);
                           fprintf(newInvent, "%s\t%s\t%d\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
                        }
                    }
                    else
                    {
                           fprintf(newInvent, "%s\t%s\t%d\t%d\n", inv[ic].id, inv[ic].name, inv[ic].quant, inv[ic].price);
                    }
                    ic=ic+1;
                    fscanf(readInvent, "%s%s%d%d", inv[ic].id, inv[ic].name, &inv[ic].quant, &inv[ic].price);
                    
              }
              fclose(readInvent);
              fclose(newInvent);
              rename("Inventory.dat","Inventory3.dat");
              rename("Inventory2.dat","Inventory.dat");
              remove("Inventory3.dat");
              printf("\nEnter the next item ID and quantity being purchased.\n");
              printf("\n\tId: ");
              scanf("%s", eid); 
              printf("\tQuantity: ");
              scanf("%d",  &bquant);
        }
        fclose(wCash);
        if (((strcmp("End", eid)==0)||(strcmp("end",eid)==0)) && (bquant == 0))
        {
              printf("\nEnter money collected: $");
              scanf("%d", &collect);
              change= collect-btotal;
        }
        wCash = fopen("Cash.dat", "r");
        if (wCash==NULL)
        {
                        printf("Cashing file does not exist");
        }
        else
        {
            if (change<0)
            {
                         ncollect= 0-change;
                         printf("\n\nYou have collected less than the total bill. Collect $%d more.\n", ncollect);
                         printf("Enter how much more money is collected: $");
                         scanf("%d", &ncollect);
                         collect=ncollect+collect;
                         change=collect-btotal;
            }
            system("cls");
            printf("\t\t\t      C Hong Wholesale Store\n"); 
            printf("\t\t\t20 Mitchell Street, Kingston 20 P.O.\n");
            printf("\t\t\t    Phone #: 878-3421, 908-7626\n");
            printf("\t\t\t     ******Invoice Bill******\n\n\n");
            printf("\t\t\tLbs\n");
            printf("Name\t\t\tPurchased\tPrice\tTotal\n");
            ic=1;
            fscanf(wCash, "%s%d%d%d", inv[ic].name, &bquant, &inv[ic].price, &itotal);
            while (!feof(wCash))
            {
                  printf("%s\t\t\t%d\t\t$%d\t$%d\n", inv[ic].name, bquant, inv[ic].price, itotal);
                  ic=ic+1;
                  fscanf(wCash, "%s%d%d%d", inv[ic].name, &bquant, &inv[ic].price, &itotal);
            }
            printf("\n\t Total Bill: $%d\n\t Money Collected: $%d\n\t Change: $%d", btotal, collect, change);
            fclose(wCash);
        }
        remove("Cash.dat");
        fflush(stdin);
        printf("\n\nTo make another invoice press 'Y' or press any character to exit and \ngo to cashing main view.\n");
        printf("Option: ");
        scanf("%c", &ient);
        if ((ient== 'Y')||(ient=='y'))
        {
                  cash();
        }
        else
        {
            cash_menu();
        }
      }
}

*/