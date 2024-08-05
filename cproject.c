#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct patient
{
    char name[50];
    int age,room;
    char phone[20];
    char disease[100];
}x[100];

int sum,num;

void add();
void del();
void edit();
void view();
void search();
void read_data();
void store_data();

int main()
{
    read_data();
    fflush(stdin);
    printf("Welcome to our Hospital Management System!");
    char option[4]="yes";
    while(strcmpi(option,"yes")==0)
    {
        fflush(stdin);
        printf("\nPlease choose any one of the following options: \n 1.View the records\n 2.Add a new record\n 3.Delete a record\n 4.Edit a record\n 5.Search for a record\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            system("cls");
            view();
        }
        else if(choice==2)
        {
            system("cls");
            add();
        }
        else if(choice==3)
        {  
            system("cls");
            del();
        }
        else if(choice==4)
        {
            system("cls");
            edit();
        }
        else if(choice==5)
        {
            system("cls");
            search();
        }
        else
        printf("\nWrong entry!");
        fflush(stdin);
        printf("\nWould you like to choose any other options? Please enter yes or no.\n");
        fflush(stdin);
        gets(option);
    }
    store_data();
    printf("\nThanks for checking our Hospital Management system. Hope you have a good day.\n");
    return 0;
}



void add()
{
    fflush(stdin);
    printf("Already existing number of records in the database: %d",num);
    fflush(stdin);
    printf("How many records would you like to add?\n");
    int n,p;
    scanf("%d",&n);
    sum=n+num;
    if(n>0)
    {
        for(int i=num;i<sum;i++)
        {
            fflush(stdin);
            printf("\nEnter the patient's name: ");
            gets(x[i].name);
            fflush(stdin);
            printf("\nEnter the patient's disease: ");
            gets(x[i].disease);
            fflush(stdin);
            printf("\nEnter the patient's age: ");
            scanf("%d",&x[i].age);
            fflush(stdin);
            printf("\nEnter the patient's room number: ");
            scanf("%d",&x[i].room);
            fflush(stdin);
            printf("\nEnter the patient's phone number: ");
            gets(x[i].phone);
            p=strlen(x[i].phone);
            while(p!=10)
            {
                printf("Invalid Phone Number");
                printf("\nEnter the patient's phone number: ");
                fflush(stdin);
                gets(x[i].phone);
                p=strlen(x[i].phone);
            }
            num++;
        }
        printf("\nThe required changes have been made. Thank you!\n");
    }
    else 
    printf("Wrong entry.");
}



void del()
{
    fflush(stdin);
    printf("Enter the serial number of the patient whose record has to be deleted:\n");
    int no;
    scanf("%d",&no);
    if(no<=num)
    {
        while(no<=num)
        {
            strcpy(x[no-1].name,x[no].name);
            strcpy(x[no-1].disease,x[no].disease);
            x[no-1].age=x[no].age;
            x[no-1].room=x[no].room;
            strcpy(x[no-1].phone,x[no].phone);
            no++;
        }
        num--;
        printf("We have deleted the required record. Thank you!\n");
    }
    else if(no>num)
    printf("Invalid Entry.\n");
}



void view()
{
    if(num==0)
    {
    printf("No records currently.");
    }
    else
    {
        printf("Hospital records are:\n");
        for(int i=0;i<num;i++)
        {
            printf("\nSerial Number: %d",(i+1));
            printf("\nName= %s",x[i].name);
            printf("\nDisease= %s",x[i].disease);
            printf("\nAge= %d",x[i].age);
            printf("\nRoom Number= %d",x[i].room);
            printf("\nPhone Number= %s",x[i].phone);
            printf("\n\n");
        }
    }
}



void edit()
{
    int ch,p;
    fflush(stdin);
    printf("\nEnter the option you want to edit:\n1.Name\n2.Disease\n3.Age\n4.Room Number\n5.Phone Number\n");
    scanf("%d",&ch);
    if(ch>=1 && ch<=5)
    {
        fflush(stdin);
        printf("Enter the serial number of the patient:\n");
        int sno;
        scanf("%d",&sno);
        if(sno<num)
        {
            if(ch==1)
            {
                fflush(stdin);
                printf("Enter the change in name of the patient:\n");
                gets(x[sno-1].name);
            }
            else if(ch==2)
            {
                fflush(stdin);
                printf("Enter the change in disease of the patient:\n");
                gets(x[sno-1].disease);
            }
            else if(ch==3)
            {
                fflush(stdin);
                printf("Enter the change in age of the patient:\n");
                scanf("%d",&x[sno-1].age);
            }
            else if(ch==4)
            {
                fflush(stdin);
                printf("Enter the change in room number of the patient:\n");
                scanf("%d",&x[sno-1].room);
            }
            else if(ch==5)
            {
                fflush(stdin);
                printf("Enter the change in phone number of the patient:\n");
                gets(x[sno-1].phone);
                p=strlen(x[sno-1].phone);
                while(p!=10)
                {
                    printf("Invalid Phone Number");
                    printf("\nEnter the patient's phone number: ");
                    gets(x[sno-1].phone);
                    p=strlen(x[sno-1].phone);
                }
            }
            printf("\nThe required changes have been made. Thank you!\n");
        }
        else
        printf("Invalid serial number.\n");
    }
    else
    printf("Invalid option chosen.\n");
}



void search()
{
    fflush(stdin);
    printf("Choose the parameter you want to use to search for the required patient:\n 1.Serial Number\n 2.Name\n 3.Disease\n 4.Age\n 5.Room Number\n 6.Phone Number\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        fflush(stdin);
        printf("Enter the serial number:\n");
        int sno;
        scanf("%d",&sno);
        if(sno>0 && sno<=num)
        {
            fflush(stdin);
            printf("Serial Number: %d\n",sno);
            printf("Name: %s\n",x[sno-1].name);
            printf("Disease: %s\n",x[sno-1].disease);
            printf("Age: %d\n",x[sno-1].age);
            printf("Room Number: %d\n",x[sno-1].room);
            printf("Phone Number: %s\n\n",x[sno-1].phone);
        }
        else
        printf("Invalid Entry.");
    }
    else if(choice==2)
    {
        fflush(stdin);
        printf("Enter the name:\n");
        char name[50];
        int found=-1;
        gets(name);
        for(int i=0;i<num;i++)
        {
            if(strcmpi(name,x[i].name)==0)
            {
                fflush(stdin);
                printf("Serial Number: %d\n",(i+1));
                printf("Name: %s\n",x[i].name);
                printf("Disease: %s\n",x[i].disease);
                printf("Age: %d\n",x[i].age);
                printf("Room Number: %d\n",x[i].room);
                printf("Phone Number: %s\n\n",x[i].phone);
                found=1;
            }
        }
        if(found==-1)
        printf("Invalid Entry.");
    }
    else if(choice==3)
    {
        fflush(stdin);
        printf("Enter the disease:\n");
        char disease[100];
        int found=-1;
        gets(disease);
        for(int i=0;i<num;i++)
        {
            if(strcmpi(disease,x[i].disease)==0)
            {
                fflush(stdin);
                printf("Serial Number: %d\n",(i+1));
                printf("Name: %s\n",x[i].name);
                printf("Disease: %s\n",x[i].disease);
                printf("Age: %d\n",x[i].age);
                printf("Room Number: %d\n",x[i].room);
                printf("Phone Number: %s\n\n",x[i].phone);
                found=1;
            }
        }
        if(found==-1)
        printf("Invalid Entry.");
    }
    else if(choice==4)
    {
        fflush(stdin);
        printf("Enter the age:\n");
        int age,found=-1;
        scanf("%d",&age);
        for(int i=0;i<num;i++)
        {
            if(age==x[i].age)
            {
                fflush(stdin);
                printf("Serial Number: %d\n",(i+1));
                printf("Name: %s\n",x[i].name);
                printf("Disease: %s\n",x[i].disease);
                printf("Age: %d\n",x[i].age);
                printf("Room Number: %d\n",x[i].room);
                printf("Phone Number: %s\n\n",x[i].phone);
                found=1;
            }
        }
        if(found==-1)
        printf("Invalid Entry.");
    }
    else if(choice==5)
    {
        fflush(stdin);
        printf("Enter the room:\n");
        int room,found=-1;
        scanf("%d",&room);
        for(int i=0;i<num;i++)
        {
            if(room==x[i].room)
            {
                fflush(stdin);
                printf("Serial Number: %d\n",(i+1));
                printf("Name: %s\n",x[i].name);
                printf("Disease: %s\n",x[i].disease);
                printf("Age: %d\n",x[i].age);
                printf("Room Number: %d\n",x[i].room);
                printf("Phone Number: %s\n\n",x[i].phone);
                found=1;
            }
        }
        if(found==-1)
        printf("Invalid Entry.");
    }
    else if(choice==6)
    {
        fflush(stdin);
        printf("Enter the phone number:\n");
        int found=-1;
        char phone[20];
        gets(phone);
        for(int i=0;i<num;i++)
        {
            if(strcmpi(phone,x[i].phone)==0)
            {
                fflush(stdin);
                printf("Serial Number: %d\n",(i+1));
                printf("Name: %s\n",x[i].name);
                printf("Disease: %s\n",x[i].disease);
                printf("Age: %d\n",x[i].age);
                printf("Room Number: %d\n",x[i].room);
                printf("Phone Number: %s\n\n",x[i].phone);
                found=1;
            }
        }
        if(found==-1)
        printf("Invalid Entry.");
    }
    else
    printf("Invalid Entry.");
}



void read_data()
{
    FILE *fp=fopen("patientlist.txt","r");
    if(fp==NULL)
    {
        fp=fopen("patientlist.txt","w");
        fclose(fp);
        printf("Database currently empty, just been created.");
    }
    num = fread(x, sizeof(struct patient),100, fp);
    fclose(fp);
}



void store_data()
{
    FILE *fw=fopen("patientlist.txt","w");
    if(fw==NULL)
    {
        printf("Error");
        exit(0);
    }
    fwrite(x,sizeof(struct patient),num,fw);
    if(fwrite!=0)
    printf("Required changes have been made to the database.");
    else
    printf("Error in updating the database.");
    fclose(fw);
}