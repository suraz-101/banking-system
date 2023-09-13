#include <stdio.h>
#include <string.h>
#include<time.h>
struct date {
    int day;
    int month;
    int year;
};

struct transaction{
    char time[256];
    int account_no;
    float amount;
    float balance;
    struct date dat;
    char type;
};
void calcTime(char *str) {
      time_t ts;
      ts = time(NULL);
      strcpy(str, ctime(&ts));
      str[strlen(str) - 1] = '\0';
      return;
}
struct usr
{
    char time[256];
    int  t_count;
    int id;
    int account_no;
    char name[20];
    char username[20];
    char password[20];
    char Address[50];
    long int phone;
    char gender[20];
    char accounttype[20];
    struct transaction t[100];
    float balance;
    
};
//typedef struct usr aac[100];
void mainmenu(struct usr aac_list[],int count,int account_no);
void adminregister(struct usr aac_list[],int count);
void customerregister(struct usr aac_list[],int count);
void adminlogin( struct usr aac_list[],int count,int account_no );
void customerlogin(struct usr aac_list[],int count,int account_no);
void adminmenu(struct usr aac_list[],int count,int account_no);
void customermenu(struct usr aac_list[],int count,int account_no);
void deposit(struct usr aac_list[],int count,int account_no);
void withdraw(struct usr aac_list[],int count,int account_no);
void viewtransaction(struct usr aac_list[],int count,int account_no);
void customerlist(struct usr aac_list[],int count);
void deletcustomeraccount(struct usr aac_list[],int count);
void updatepersonalinformation(struct usr aac_list[],int count, int account_no);
void checkbalance(struct usr aac_list[], int count,int account_no);
void  viewcustomerlist(struct usr [],int );
void writetransactiontofile(struct transaction t,struct usr aac_list[] );
void viewcustomertransaction(struct usr aac_list[],int count, int account_no);
void writecustomerstofile(struct usr [], int);
void viewpersonalinformation(struct usr aac_list[],int count, int account_no);
void viewaccountdetails(struct usr aac_list[],int count, int account_no);
int transferac_file (struct usr aac_list[]);

int main()
{
 
    int ac_count;
    int account_no = 0;
    struct transaction t;
    struct usr aac_list[100];
    ac_count = transferac_file(aac_list);
    mainmenu(aac_list,ac_count,account_no);
}

void mainmenu(struct usr aac_list[],int count,int account_no)
{
    int i;
    do{
        int choice = 0;
        printf("\n\t\t======================MAIN MENU=====================\n");
        printf("\n1.admin resister \n");
        printf("\n2.customer resister \n");
        printf("\n3.admin login\n");
        printf("\n4.customer login\n");
        printf("\n5.exit\n");
        printf("\nEnter your chocie ",choice);
        scanf("%d",&choice );
        switch(choice)
        {
            case 1:adminregister(aac_list,count);break;
            case 2:customerregister(aac_list,count);break;
            case 3:adminlogin( aac_list, count,account_no);break;
            case 4:customerlogin(aac_list,count,account_no);break;
            case 5:printf("\n=========================BYE=BYE======================\n");break;
  
            default: printf("\nEnter valid number[1-5]");break;
                
        }
        printf("\n DO YOU WANT TO REPEAT THIS PROCESS AGAIN? IF YES PRESS 1 ELSE PRESS ANY OTHER NUMBER\n");
        scanf("%d",&i);
    }while (i==1);
}

void adminregister(struct usr aac_list[],int count)
{
    char name[20],username[20],password[20],address[50], gender[20];
    int id;
    long int phone;
    printf("\n\t\t\t=====================ADMIN REGISTER=======================\t\n\n");
    FILE *fp;
    fp=fopen("admin.txt","a");
    if (fp==NULL)
    {
       printf("\nfile could not be opened\n");return;
    }
    else
    {
        printf("\nEnter your identity number:\n"); scanf("%d",&id); fflush(stdin);
        printf("\nEnter your name:\n"); scanf("%s",name); fflush(stdin);
        printf("\nEnter your username:\n"); scanf("%s",username); fflush(stdin);
        printf("\nEnter your password:\n"); scanf("%s",password); fflush(stdin);
        printf("\nEnter your address:\n"); scanf("%s",address); fflush(stdin);
        printf("\n\Enter your phone number:\n"); scanf("%ld",&phone); fflush(stdin);
        printf("\nEnter your gender:\n"); scanf("%s",gender); fflush(stdin);
             
        fprintf(fp,"%d %s %s %s %s %ld %s\n",id,name, username , password,address,phone,gender);
        fclose(fp);
        printf("\n data are stored in the file \n");
    }
}
void customerregister(struct usr aac_list[],int count)
{
    char name[20],username[20],password[20],Address[50], gender[20],accounttype[20];
    int account_no;
    long int phone;
    float balance;
    printf("\n\t\t\t================customer register======================\n\n");
    FILE *fp;
    fp=fopen("customer.txt","a");
    if (fp==NULL)
    {
        printf("\nfile could not be opened\n");return;
    }
    else
    {
        int i;
        printf("\nEnter your account number:\n"); scanf("%d",&account_no); fflush(stdin);
        printf("\nEnter your name:\n"); scanf("%s",name); fflush(stdin);
        printf("\nEnter your username:\n"); scanf("%s",username); fflush(stdin);
        for (i=0; i<count; i++)
        {
              if (strcmp(username, aac_list[i].username)==0)
                  {
                      printf("\n please enter another usrname\n");customerregister(aac_list, count);
                  }
        }
      
        printf("\nEnter your password:\n"); scanf("%s",password); fflush(stdin);
        printf("\nEnter your address:\n"); scanf("%s",Address); fflush(stdin);
        printf("\n\Enter your phone number:\n"); scanf("%ld",&phone); fflush(stdin);
        printf("\nEnter your gender:\n"); scanf("%s",gender); fflush(stdin);
        printf("\n Enter your account type(saving/current)\n"); scanf("%s",&accounttype); fflush(stdin);
        int c;
        while((c= getchar()) != '\n' && c != EOF);
        printf("\nEnter the balance:"); scanf("%f",&balance);fflush(stdin);
             
        fprintf(fp,"%d %s %s %s %s %ld %s %s %f\n",account_no,name, username , password,Address,phone,accounttype,gender,balance);
        fclose(fp);
        printf("\n data are stored in the file \n");
        mainmenu(aac_list, count, account_no);
    }
}
void adminlogin( struct usr aac_list[],int count, int account_no)
{
    char un[20];
    char pw[20];
    char name[20],username[20],password[20],Address[50], gender[20];
    long int phone;
    int id;
    printf("\t\t\t===================ADMIN LOGIN======================\T\N");
    FILE *fp;
    fp =fopen ("admin.txt","r");
    if(fp == NULL)
    {
        printf("\nfile could not be opened\n");
         
    }
    printf("\nEnter username :",un);scanf("%s",un);fflush(stdin);
    printf("\nEnter password:",pw);scanf("%s",pw);fflush(stdin);
    while (fscanf(fp,"%d %s %s %s %s %ld %s \n",&id,name, username ,password,Address,&phone,gender)==7)
    {
       if  (strcmp(un,username)==0 && strcmp(pw,password)==0 )
        {
            adminmenu (aac_list,count,account_no); getchar(); break;
        }
       
    }
     fclose(fp);
    printf("please enter correct information");
    mainmenu(aac_list,count,account_no);

}
void customerlogin( struct usr aac_list[],int count,int account_no)
{
    int i;
    char usn[20];
    char psw[20];
    struct usr tmp;
    printf("\n\n\t\t\t-=================custome login=====================\t\n\n");
    FILE *fp;
    fp =fopen ("customer.txt","r");
    
    
    if(fp == NULL)
     {
         printf("\nfile could not be opened\n");
     }
     printf("\nEnter username :");scanf("%s",usn);fflush(stdin);
     printf("\nEnter password:");scanf("%s",psw);fflush(stdin);
     //printf("\nEnter Account number:");scanf("%d",&account_no);fflush(stdin);
     
     //while(fscanf(fp,"%d %s %s %s %s %ld %s %s\n",&account_no,name, username , password,Address,&phone,gender,&accounttype)==8)
     //{
    i=0;
    
    while(i<count)
    {
        
        tmp = aac_list[i];
       if (strcmp(usn,tmp.username)==0 && strcmp(psw, tmp.password)==0)
            {
                getchar();
                customermenu(aac_list,count,tmp.account_no); getchar(); break;
          }
    
        i++;
    }
    printf("\nplease enter correct inforamtion\n"); fclose(fp);
    mainmenu(aac_list,count,account_no);
     //}
}
void adminmenu(struct usr aac_list[],int count,int account_no)
{
    int choice ;
    printf("\n\n\n\t\t=======================ADMINMENU=========================\t\t\n");
    printf("\n1.View Customer list\n");
    printf("\n2.Delet Costomer Account\n");
    printf("\n3.View Customer Transaction\n");
    printf("\n4.logout\n");

    printf("\nEnter your choice\n");
    scanf ("%d",&choice );
    switch(choice)
    {
        case 1:viewcustomerlist( aac_list,count);break;
        case 2:deletcustomeraccount(aac_list,count);break;
        case 3:viewcustomertransaction(aac_list, count,  account_no);break;
        case 4:mainmenu(aac_list,count,account_no);break;
        default: printf("\nlease enter valid numnber[1-4]\n");break;
            
    }adminmenu( aac_list, count, account_no);
}
void customermenu(struct usr aac_list[],int count,int account_no)
{
    int choice = 0;
     printf("\n\n\n\t\t\t-----------------customer menu-----------------\n\n\n");
     printf("\n1.Deposit\n");
     printf("\n2.Withdraw\n");
     printf("\n3.View Transaction\n");
    printf("\n4.Update Personal Information\n");
    printf("\n5.view perosnal information\n");
    printf("\n6.view account details\n");
     printf("\n7.Check Balance\n");
    printf("\n8.Logout\n");
     printf("\Which operation do you want to perform?",choice);
     scanf("%d",&choice);
           switch(choice)
           {
               case 1:deposit(aac_list,count,account_no);break;
               case 2:withdraw(aac_list,count,account_no);break;
               case 3:viewtransaction( aac_list,count,account_no);break;
               case 4:updatepersonalinformation(aac_list,count,account_no);break;
               case 5:viewpersonalinformation( aac_list, count, account_no);
                case 6:viewaccountdetails(aac_list, count,account_no);
               case 7:checkbalance(aac_list, count,account_no);break;
               case 8:mainmenu(aac_list,count,account_no);break;
               default : printf("\nplease enter valid number\n");break;
              
           }
           customermenu(aac_list,count,account_no);
   
}

void deposit(struct usr aac_list[],int count,int account_no)
{
    float d_amount;int i;
     struct transaction t;
    printf("\t\t\t=======================DEPOSIT=======================\n\n");
    
    printf("\nEnter the amount you want to deposit:\t");
    scanf("%f",&d_amount);
    fflush(stdin);
    for (i=0;i<count;i++)
    {
        if (account_no==aac_list[i].account_no)
            
        {
           printf("\nname:\t%s\n",aac_list[i].name);
                       aac_list[i].balance=aac_list[i].balance+d_amount;
            printf("\n Now your balance in aacount number %d is %f:\t",account_no,aac_list[i].balance);
            
            t.account_no = aac_list[i].account_no;
            t.amount = d_amount;
            t.type = 'd';
            t.balance=aac_list[i].balance;
            
            writetransactiontofile(t,aac_list);
            writecustomerstofile(aac_list,count);
            
             break;
        }
    }
}


void withdraw(struct usr aac_list[],int count,int account_no)
{
    int i;
   
    float w_amount;
    struct transaction t;
    time_t;
    time(&t);
    printf("\t\t\t\n=======================WITHDRAW===================\n");
   
    printf("\nEnter the amount you want to withdraw\n");
    scanf("%f",&w_amount);
    fflush(stdin);
    
    for (i=0;i<count;i++)
    {
        if(account_no==aac_list[i].account_no)
        {
           
            if (aac_list[i].balance >= w_amount)
            {
                printf("\nname:\t%s\n",aac_list[i].name);
                

                aac_list[i].balance = aac_list[i].balance - w_amount;
                printf("\n Now your balance in aacount number %d is %f:\t",account_no,aac_list[i].balance);

                t.account_no = aac_list[i].account_no;
                t.amount = w_amount;
                t.type = 'w';
                t.balance=aac_list[i].balance;
                writetransactiontofile(t,aac_list);
                writecustomerstofile(aac_list,count);
                
                
                break;
            }
          
        }
    }        printf("\nYou didn't have enough money\n");

}


void writecustomerstofile(struct usr list[], int count)
{
    int i;
    FILE *fp;
    struct usr u;
    fp=fopen("customer.txt", "w");
    for(i=0;i<count;i++)
    {
        u=list[i];
        fprintf(fp,"%d %s %s %s %s %ld %s %s %f\n",u.account_no,u.name, u.username , u.password,u.Address,u.phone,u.gender,u.accounttype,u.balance);
    }
    fclose(fp);
}



void writetransactiontofile(struct transaction t,struct usr aac_list[])
{
    time_t;
    time(&t);
    FILE *fp;
    fp =fopen ("Transaction.txt","a");

    if(fp==NULL)
    {
        printf("\nFIle could not be opened!\n"); getchar(); return ;
    }
    fprintf(fp,"%d %f %s %c %f\n",  t.account_no, t.amount,ctime(&t), t.type,t.balance);
    fclose(fp);
    printf("\n\nTransaction written successfully to file!\n\n");
}

void viewtransaction(struct usr aac_list[],int count, int account_no)
{
     int i=0;
    struct transaction t;
    struct usr tmp;
    time_t;
    time(&t);
    printf("\t\t\t\t========================================================\n\t\t\t\t===================view transaction:=====================\n\t\t\t\t========================================================\n");
    printf("\nA/C No.\tdeposit \t\twithdraw \t\tbalance\n");
    FILE *fp;
    fp =fopen ("Transaction.txt","r");
    
   // while( fscanf(fp, "%d %f %s %c %f\n",  &t.account_no, &t.amount,ctime(&t), &t.type,&t.balance)==5)
   
    while (i<count)
    {
      
        if (account_no==account_no)
        {
                    printf(fp, "%d %f  %c %f\n",t.account_no,t.amount,t.amount,t.balance);

        }
        i++;
    }
    fclose(fp);
}

void deletcustomeraccount(struct usr aac_list[],int count)
{
    int i;
    int account_no;
    struct usr tmp;
    printf("\n\t\t\t=====================DELET CUSTOMER LIST==========================\n\n");
    printf("\nEnter the account number you want to delet:\n");
    scanf("%d",&account_no);fflush(stdin);
    for (i=0;i<count;i++)
    {
        tmp=aac_list[i];
        if (account_no==tmp.account_no)
        {
            for (i=i+1; i<count; i++)
            {
                aac_list[i-1]=aac_list[i];
            }
        }
    }
    count--;
    writecustomerstofile(aac_list, count);
    printf("\naccount is successfully cleared");
    adminmenu(aac_list, count, account_no);
    
    
}

void updatepersonalinformation(struct usr aac_list[],int count, int account_no)
{
    int i;
    char Name[20];
    char oldpassword[20];
    char newpassword[20];
    long int newphonenumber;
    struct usr tmp;
    do
    {
        int choice;
        int j;
        printf("\n======================update personal information =============================\n");
        printf("\n1.name\n");
        printf("\n2.password\n");
        printf("\n3.phone\n");
        printf("\n which option do you want to perform:\n");
        scanf("%d",&choice);fflush(stdin);
        switch (choice)
        {
            case 1:
              printf("\nEnter new name:\n");
                scanf("%s",Name);fflush(stdin);
                
                for (j=0;j<count;j++)
                {
                    tmp=aac_list[j];
                    if (tmp.account_no==account_no)
                    {
                        strcpy(tmp.name, Name);
                        aac_list[j]=tmp;
                        break;
                    }
                    aac_list[j]=tmp;
                }
                //printf("count %d j %",count ,j);
                 writecustomerstofile(aac_list,count);
                printf("\n information updated successfully\n\n");getchar();
                break;
            case 2:
                printf("\n Enter old password:\n" );
                scanf("%s",&oldpassword);fflush(stdin);
                j=0;
                for (j=0; j<count; j++)
                {
                    tmp=aac_list[j];
                    if (tmp.account_no==account_no)
                    {printf("account no:%d",tmp.account_no);
                        printf("\n\npassword:%s",tmp.password);
                      if (strcmp(oldpassword,tmp.password)==0)
                        {
                           
                            printf("\npassword matched\n");
                            printf("\nEnter a new password:\n");
                            scanf("%s",newpassword);
                            fflush(stdin);
                            strcpy(tmp.password, newpassword) ;
                         }
                      else{
                          printf("\nplease enter correct password\n");
                          updatepersonalinformation(aac_list, count, account_no);
                          }
                    }
                     aac_list[j]=tmp;
                    
                }
                writecustomerstofile(aac_list,count);
                printf("\n information updated successfully\n\n");break;
               
            case 3:
                printf("\nplease enter your new phone number:\n");
                scanf("%ld",&newphonenumber);fflush(stdin);
                for (j=0; j<count; j++)
                {
                    tmp=aac_list[j];
                    if (tmp.account_no==account_no)
                    {
                        (tmp.phone=newphonenumber);
                        aac_list[j]=tmp;
                        break;
                    }
                    aac_list[j]=tmp;
                }
                 writecustomerstofile(aac_list,count);
                printf("\n information updated successfully\n\n");getchar();break;
                
            default: printf("\nplease enter valid number [1-3]\n");getchar();
                customermenu(aac_list, count, account_no);
                
                
              
        }
        printf("\n DO YOU WANT TO REPEAT THIS PROCESS AGAIN? IF YES PRESS 1 ELSE PRESS ANY OTHER NUMBER\N");
        scanf("%d",&i);fflush(stdin);
    }while (i==1);
    
    
}
void viewcustomerlist(struct usr aac_list[],int count)
{
    struct transaction t;
    int i;
    printf("\t\t\t\t========================================================\n\t\t\t\t======================USER LIST:========================\n\t\t\t\t========================================================\n");
    printf("\n\nA/NO \tname\t\tusername\t\tpassword\t\taddress\t\tphone\t\t\t gender\t\ttype\t\tbalance \n\n");
    for(i=0;i<count; i++)
    {
        printf("%d\t\t%s\t\t%s\t\t\t%s\t\t\t%s\t\t%ld\t\t\t%s\t\t%s\t\t%f\n", aac_list[i].account_no, aac_list[i].name,
        aac_list[i].username,aac_list[i].password,aac_list[i].Address,aac_list[i].phone,aac_list[i].gender,aac_list[i].accounttype,aac_list[i].balance);

       
        
    }
}
void checkbalance(struct usr aac_list[],int count,int account_no)
{
    int i;
    printf("\n\n\t\t\t=====================BALANCE ENQUIRY=======================\n\n");
    for(i=0;i<count;i++)
    {
        if (account_no==aac_list[i].account_no)
        {
            printf("\nYour balance is:%f",aac_list[i].balance);
            
        }
    }i++;

}
void viewcustomertransaction(struct usr aac_list[],int count, int account_no)
{
    float amount;
    float balance;
    char type;
    int i;
    struct transaction t;
    FILE *fp;
    fp = fopen("Transaction.txt","r");
    while( fscanf(fp, "%d %f %s %c %f\n",  &t.account_no, &t.amount,ctime(&t), &t.type,&t.balance)==5)
    {
         printf("\n account number:%d\t\n",t.account_no);
         printf("\namount:%f\t\n",t.amount);
         printf("\ntransaction type:%c\t\n",t.type);
         printf("\nbalance:%f\t\n",t.balance);
    }
    fclose(fp);
    adminmenu(aac_list, count, account_no);
}
void viewpersonalinformation(struct usr aac_list[],int count, int account_no)
{
    int i;
    FILE *fp;
    fp=fopen("customer.txt","r");
  
       for (i=0; i<count; i++)
        {
         if (aac_list[i].account_no==account_no)
                
                   {
                       printf("\naccount number:%d\n",aac_list[i].account_no);
                       printf("\nname:%s\n",aac_list[i].name);
                       printf("\naddress:%s\n",aac_list[i].Address);
                       printf("\nphone number:%ld\n",aac_list[i].phone);
                       printf("\ngender:%s\n",aac_list[i].gender);
                       printf("\naccount type:%s\n",aac_list[i].accounttype);
                   }
     
       
    }getchar();
    customermenu(aac_list, count, account_no);
    
}
void viewaccountdetails(struct usr aac_list[],int count, int account_no)
{
    char name[20],username[20],password[20],Address[50], gender[20],accounttype[20];
       long int phone;
       float balance;
       int i=0 ;
       FILE *fp;
       fp=fopen("customer.txt","r");
       //while (fscanf(fp, "%d %s %s %s %s %ld %s %s %f\n",&account_no,name,username , password,Address,&phone,gender,accounttype,&balance)==9)
     //  {
          for (i=0; i<count; i++)
           {
            if (aac_list[i].account_no==account_no)
                   
                      {
                          printf("\naccount number:%d\n",aac_list[i].account_no);
                          printf("\nname:%s\n",aac_list[i].name);
                          printf("\nusername:%s\n",aac_list[i].username);
                          printf("\npassword:%s\n",aac_list[i].password);
                          printf("\naddress:%s\n",aac_list[i].Address);
                          printf("\nphone number:%ld\n",aac_list[i].phone);
                          printf("\ngender:%s\n",aac_list[i].gender);
                          printf("\naccount type:%s\n",aac_list[i].accounttype);
                          printf("\nbalance:%f\n",aac_list[i].balance);

                          
                      }
         //  }
          
       }getchar();
       customermenu(aac_list, count, account_no);
       
}
int transferac_file(struct usr aac_list[])
{
    struct usr tmp;
    int k=0;
    FILE *fp;
    fp = fopen("customer.txt","r");
    for(k=0;fscanf(fp,"%d %s %s %s %s %ld %s %s %f\n",&tmp.account_no,tmp.name, tmp.username ,tmp.password,tmp.Address,&tmp.phone,&tmp.accounttype,tmp.gender,&tmp.balance)==9; k++)
        {
           
            aac_list[k]=tmp;
        }return k;
    fclose(fp);
   
}
