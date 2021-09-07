#include "functions.h"

struct emp
{
    int id;
    char name[100];
    char desgn[10];
    float sal;
    char jdate[8];
    char gender[10];
    char branch[50];
    char psaddr[200];
    char prtaddr[200];
    char phone[15];
    char mail[20];
};

//====Welcome Screen=====
void welcome()
{
    printf("\n\n\n\n\n\t\t[ [ [ WELCOME TO OUR EMPLOYEE MANAGEMENT SYSTEM ] ] ]\n\n\n\n\n\n\n\t");
    system("pause");
}
//----printing character ch at n times ------
void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

//-----Printing Head Line of the program -----
void printHead()
{ system("cls");
printf("\t");
printChar('=',65);
printf("\n\t");
printChar('=',16);
printf("[EMPLOYEE] [MANAGEMENT] [SYSTEM]");
printChar('=',16);
printf("\n\t");
printChar('=',65);

}
// ==========ADDING NEW RECORD==========================
void add(FILE * fp)
{
printHead();
printf("\n\t\t\t\\Add Employee\\");
char another='y';
Employee e;
fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{
    printf("\n\n\t\tEnter ID number: ");
    scanf("%d",&e.id);
    printf("\n\n\t\tEnter Full Name of Employee: ");
    fflush(stdin);
    fgets(e.name,100,stdin); //fgets takes an extra \n character as input
    e.name[strlen(e.name)-1]='\0';
    printf("\n\n\t\tEnter Country: ");
    fflush(stdin);
    fgets(e.desgn,10,stdin); //fgets takes an extra \n character as input
    e.desgn[strlen(e.desgn)-1]='\0';
    printf("\n\n\t\tEnter Gender: ");
    fflush(stdin);
    fgets(e.gender,10,stdin); //fgets takes an extra \n character as input
    e.gender[strlen(e.gender)-1]='\0';
    printf("\n\n\t\tEnter Branch: ");
    fflush(stdin);
    fgets(e.branch,50,stdin);
    e.branch[strlen(e.branch)-1]='\0';
    printf("\n\n\t\tEnter Salary: ");
    scanf("%f",&e.sal);
    printf("\n\n\t\tEnter Present Address: ");
    fflush(stdin);
    fgets(e.psaddr,200,stdin);
    e.psaddr[strlen(e.psaddr)-1]='\0';
    printf("\n\n\t\tEnter Permanant Address: ");
    fflush(stdin);
    fgets(e.prtaddr,200,stdin);
    e.prtaddr[strlen(e.prtaddr)-1]='\0';
    printf("\n\n\t\tEnter Phone: ");
    fflush(stdin);
    fgets(e.phone,50,stdin);
    e.phone[strlen(e.phone)-1]='\0';
    printf("\n\n\t\tEnter E-mail: ");
    fflush(stdin);
    fgets(e.mail,20,stdin);
    e.mail[strlen(e.mail)-1]='\0';
    fwrite(&e,sizeof(e),1,fp);
    printf("\n\n\t\tWant to enter another employee info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}
//===================DELETING A RECORD FROM LIST ============
FILE * del(FILE * fp)
{
 printHead();
printf("\n\t\t\t\\Delete Employee\\");
Employee e;
int flag=0,tempid,siz=sizeof(e);
FILE *ft;
if((ft=fopen("temp.txt","wb+"))==NULL)
{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}

printf("\n\n\tEnter ID number of Employee to Delete the Record");
printf("\n\n\t\t\tID No. : ");
scanf("%d",&tempid);
rewind(fp);
while((fread(&e,siz,1,fp))==1)
{
    if(e.id==tempid)
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",e.name,e.branch,e.id);
    continue;
    }
    fwrite(&e,siz,1,ft);
}
fclose(fp);
fclose(ft);
remove("employeeInfo.txt");
rename("temp.txt","employeeInfo.txt");
if((fp=fopen("employeeInfo.txt","rb+"))==NULL)
{
    printf("ERROR");
    return  NULL;
}
if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");
printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}
//===========MODIFY A RECORD ===========================
void modify(FILE * fp)
{
printHead();
printf("\n\t\t\t\\Modify Employee\\");
Employee e;
int i,flag=0,tempid,siz=sizeof(e);
float sal;
printf("\n\n\tEnter ID Number of Employee to Modify the Record : ");
scanf("%d",&tempid);
rewind(fp);
while((fread(&e,siz,1,fp))==1)
{
    if(e.id==tempid)
        {flag=1;
        break;
        }
}
if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRecord Found");
    printf("\n\n\t\tEnter New Data for the Record");
     printf("\n\n\t\tEnter ID number: ");
    scanf("%d",&e.id);
    printf("\n\n\t\tEnter Full Name of Employee: ");
    fflush(stdin);
    fgets(e.name,100,stdin); //fgets takes an extra \n character as input
    e.name[strlen(e.name)-1]='\0';
    printf("\n\n\t\tEnter Designation: ");
    fflush(stdin);
    fgets(e.desgn,10,stdin); //fgets takes an extra \n character as input
    e.desgn[strlen(e.desgn)-1]='\0';
    printf("\n\n\t\tEnter Gender: ");
    fflush(stdin);
    fgets(e.gender,10,stdin); //fgets takes an extra \n character as input
    e.gender[strlen(e.gender)-1]='\0';
    printf("\n\n\t\tEnter Branch: ");
    fflush(stdin);
    fgets(e.branch,50,stdin);
    e.branch[strlen(e.branch)-1]='\0';
    printf("\n\n\t\tEnter Salary: ");
    scanf("%f",&e.sal);
    printf("\n\n\t\tEnter Present Address: ");
    fflush(stdin);
    fgets(e.psaddr,200,stdin);
    e.psaddr[strlen(e.psaddr)-1]='\0';
    printf("\n\n\t\tEnter Permanant Address: ");
    fflush(stdin);
    fgets(e.prtaddr,200,stdin);
    e.prtaddr[strlen(e.prtaddr)-1]='\0';
    printf("\n\n\t\tEnter Phone: ");
    fflush(stdin);
    fgets(e.phone,50,stdin);
    e.phone[strlen(e.phone)-1]='\0';
    printf("\n\n\t\tEnter E-mail: ");
    fflush(stdin);
    fgets(e.mail,20,stdin);
    e.mail[strlen(e.mail)-1]='\0';
    fwrite(&e,sizeof(e),1,fp);
}
else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");
printf("\n\n\t");
system("pause");
}

//====================DISPLAY THE LIST =================
void displayList(FILE * fp)
{   printHead();
printf("\n\t\t\t\\List  of Employees\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tGENDER : %s",e.gender);
        printf("\n\n\t\tBRANCH : %s",e.branch);
        printf("\n\n\t\tSALARY : %.2f",e.sal);
        printf("\n\n\t\tPRESENT ADDRESS : %s",e.psaddr);
        printf("\n\n\t\tPERMANANT ADDRESS : %s",e.prtaddr);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}
//================SEARCH EMPLOYEE==
void searchRecord(FILE *fp)
{printHead();
printf("\n\t\t\t\\Search Employee\\");
int tempid,flag,siz,i;
Employee e;
char another='y';
siz=sizeof(e);
while(another=='y'||another=='Y')
{
printf("\n\n\tEnter ID Number of Employee to search the record : ");
scanf("%d",&tempid);
rewind(fp);
while((fread(&e,siz,1,fp))==1)
{
    if(e.id==tempid)
        {flag=1;
        break;
        }
}
if(flag==1)
    {
    printf("\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tBRANCH : %s",e.branch);
        printf("\n\n\t\tSALARY: %.2f",e.sal);
        printf("\n\n\t\tPRESENT ADDRESS : %s",e.psaddr);
        printf("\n\n\t\tPERMANANT ADDRESS : %s",e.prtaddr);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s",e.mail);
        printChar('=',65);
}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}

//========================LIST OF MALE EMPLOYEE==
void maleemp(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\\List of Male Employee\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.gender,"Male")==0)||(strcmp(e.gender,"male")==0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printChar('-',65);
        }
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}
//========================LIST OF FEMALE EMPLOYEE==
void femaleemp(FILE * fp)
{
    printHead();
     printf("\n\t\t\t\\List of Female Employee\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.gender,"Female")==0)||(strcmp(e.gender,"female")==0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printChar('-',65);
        }
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF EMPLOYEE FROM DHAKA====
void frmindia(FILE * fp)
{
    printHead();
     printf("\n\t\t\t\\List the Employee Country\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        if((strstr(e.prtaddr,"India")==0)||(strstr(e.prtaddr,"india")==0)||(strstr(e.prtaddr,"India")==0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s",e.mail);
        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}
//==============DISPLAY BASIC INFO LIST==
void displaybasic(FILE * fp)
{   printHead();
printf("\n\t\t\t\\Display Basic Information\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tGENDER : %s",e.gender);
        printf("\n\n\t\tBRANCH : %s",e.branch);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//========BASIC CONTACT INFO LIST====
void basiccontact(FILE * fp)
{   printHead();
printf("\n\t\t\t\\Basic Contact Information\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}


//========================LIST OF EMPLOYEE OF MAIN BRANCH====
void mainbr(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\\List of Employee of Main Branch\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.branch,"Main")==0)||(strcmp(e.prtaddr,"main")==0)||(strcmp(e.prtaddr,"MAIN")==0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\t",e.mail);
        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF EMPLOYEE OF OTHRES BRANCH====
void otherbr(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\\List of Employee of Other Branch\\");
    Employee e;
    int i,siz=sizeof(e);
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.branch,"Main")!=0)&&(strcmp(e.prtaddr,"main")!=0)&&(strcmp(e.prtaddr,"MAIN")!=0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tCOUNTRY : %s",e.desgn);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t"); 
    system("pause");
}