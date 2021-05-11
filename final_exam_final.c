/*
#include<stdio.h>
#include<string.h>

struct citizen{
    int id;
    char name[30];
    int n_of_f_m;
    int cat;
    float amount;
}ct;

*/


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
//#define n  0
//#define id 0001
int n = 0;


struct pack{

    int price;
    int period;
    int cat;
}pa;

typedef struct citizen
{
        int id;
        int national_id;
        char name[30];
        int n_of_f_m;
        int cat;
        float amount;
        char last_name[15];
        float total_amount; // This should contain the down-payment + total_monthly_payments
        float down_payment;
        float monthly_payment


}cust;

cust s;

void newrecords();
void display();
void editrecords();
void balance();
void deleterecords();
void searchrecords();
void payment();

void main()
{

    printf("\n-----------MUYISA TSANGYA PATRICIEN'S WORK-----------\n");
    printf("\n");

    int c;
    do{
        printf("\n\t1.New record\n\t2.Display\n\t3.Balance\n\t4.Search\n\t5.Payment\n\t6.Admin Pannel\n\t0.exit\n");
        printf("\tPlease make a chose from one of the above options: \n");
        printf("\n\t>>> ");
        scanf("%d",&c);

        switch(c){
        case 1:
            newrecords();
            break;
        case 2:
            display();
            break;
        case 3:
            balance();
            break;
        case 4:
            searchrecords();
            break;
        case 5:
            payment();
            break;
        case 6:
            admin();
            break;
        default:
            if(c!=0)
                printf("\nInvalid input");

                }
    }while(c != 0);


}

void newrecords(){
int c,y;
FILE *fp, *rp, *sp;


printf("\n\tEnter details for new record\n");
do{

printf("\n\tEnter 1 to for new record\tEnter 0 to exit\n");
//Commenting this out for the moment-----

scanf("%d",&c);
if(c != 1)
return;
sp = fopen("ids.txt", "r");

    printf("\n\tEnter national ID \n\t> ");
    scanf("%d",&s.national_id);
    printf("\n\tEnter the  first name and last name \n\t> ");
    scanf("%s",s.last_name);
    scanf("%s",s.first_name);
    printf("\n\tEnter the Cuctomer's address : Town District StreetNo \n\t> ");
    scanf("%s",s.ad.city);
    scanf("%s",s.ad.district);
    scanf("%s",s.ad.streetNo);
    printf("Enter phone number \n\t>");
    scanf("%s",s.phone_no);

    fscanf(sp,"\n%d",&y);

fclose(sp);
sp = fopen("ids.txt","w");
fp = fopen("data.txt","a");
    fprintf(fp,"%d\t%s\t%s\t%d\t%s\t%s\n",y,s.first_name,s.last_name,s.national_id,s.phone_no,s.ad.city);

    printf("\nSuccesfully entered! your C_ID is %d", y);
        y++;
        fprintf(sp,"\n%d",y);

fclose(fp);
fclose(sp);
}while(c !=0);

}
void display() // , total_amount, down_payment, monthly_payment, current_balance, created_date, created_date, address
{
int i,y;//y is the unique id
printf("\nCust_ID\tF_Name\tL_Name\tNational_ID\tMobileNo\tCity\n======\t======\t=======\t==========\t========\t=======\n");//This code deals with the header

FILE *fp;

fp = fopen("data.txt","r");

while(!feof(fp)){
fscanf(fp,"%d\t%s\t%s\t%d\t%s\t%s\n",&y,s.first_name,s.last_name,&s.national_id,s.phone_no,s.ad.city);
printf("%d\t%s\t%s\t%d\t\t%s\t%s\n",y,s.first_name,s.last_name,s.national_id,s.phone_no,s.ad.city);
}

}
void balance(){}
void searchrecords(){}
void admin(){
int c;
    printf(" \t ________________________________________________________\n");
    printf("\t|                                                        |\n");
    printf("\t|        ADMIN MENU                                       \n");
    printf("\n\t|                                                        |\n");
    printf("\t ________________________________________________________\n");
    printf("\t|    DEVELOPED BY:                                       |\n");
    printf("\t|\n\t\t\tMUYISA TSANGYA PATRICIEN\n\t\t\tANDY BADERHA & \n\t\t\tMURENZI INNOCENT\n");
    printf(" \t|________________________________________________________|\n");
    printf("\n");
do{
printf("\n1.insert new items in the stock\n0.Exit");
scanf("%d",&c);
switch(c){
    case 1:
        insrt();
        break;
        default:
        if(c!=0)
        printf("\nInvalid output");
}
}while(c!=0);
}


insrt(){
FILE *po, *sp;
int d,y;
printf("Enter new Item");
int c;
do{
po = fopen("Packs.txt","a");
printf("\n1 to edit \t 0 to exit\n\t>");
scanf("%d",&c);
if(c == 0)
return;
sp = fopen("packid.txt","r");
fscanf(sp,"\n%d",&y);
printf("Enter price\n\t>");
scanf("%d",&pa.price);
printf("Enter period\n\t>");
scanf("%d",&pa.period);
printf("select packName 1.basic\t2.medium\t3.higher\n\t>");
scanf("%d",&d);
if(d == 1){
fprintf(po,"%d\t%d\t%d\t%s\n",y,pa.price,pa.period,"Basic");;
}else if(d == 2){
 fprintf(po,"%d\t%d\t%d\t%s\n",y,pa.price,pa.period,"Medium");
} else if(d == 3){
 fprintf(po,"%d\t%d\t%d\t%s\n",y,pa.price,pa.period,"Higher");
}
fclose(sp);
sp = fopen("packid.txt","w");

y++;
fprintf(sp,"\n%d",y);
fclose(sp);
fclose(po);
}while(c!=0);

}
void payment(){
    printf(" \t ________________________________________________________\n");
    printf("\t|                                                        |\n");
    printf("\t|        CHECK THE MENU\n");

    printf("\t\n\t\t\t BASIC ----------2lights, phone charger\n");
    printf("\t\n\t\t\t MEDIUM----------4lights, phone charger and radio\n");
    printf("\t\n\t\t\t HIGHER----------4lights, phone charger, radio and TV\n");
    printf("\n");
    //Patricien------------------------
    printf("\t\n\t\t\t BASIC\t\tMEDIUM\t\tHIGHER\t\n\t\t\t ========\t========\t========\n\t\n\t\t\t * 2 lights\t* 2 lights\t* 4 lights\n\t\n\t\t * phone charger\t* phone charger\t* phone charger\n    \t\n\t\t\t \t\t* radio\t\t* radio\n      \t\t      \t\n\t\t\t \t\n\t\t\t \t\t* TV\n");//This code deals with the header


    //--------------------------------
    int c,d,y,pc,cid,a;//switchs choice
    FILE *p, *j, *lp;
    lp = fopen("data.txt","r");
        printf("Enter Your ID: ");
        scanf("%d",&cid);
    while(!feof(lp)){
fscanf(lp,"%d\t%s\t%s\t%d\t%s\t%s\n",&a,s.first_name,s.last_name,&s.national_id,s.phone_no,s.ad.city);
    if(cid == a){
    do{
    printf("\nSelect Desired package\t\n1 for basic\t2 for medium\t3 for higher\n\t>");
    scanf("%d",&c);
    switch(c){
    case 1:
    printf("______________________________________________\n");
    printf("-------------------BASIC-----------------------\n");
    printf("______________________________________________\n");

        printf("\n1 .Check Available items\t 2. Buy");
        scanf("%d",&d);
        if(d == 1){
        p = fopen("packs.txt","r");
        printf("\nID\tPrice\tPeriod(year)\tPackage");

        while(!feof(p)){
        fscanf(p,"%d\t%d\t%d\t%s\n",&y,&pa.price,&pa.period,pa.packn);
        if(strcmp(pa.packn,"Basic") == 0)
        printf("%d\t%d\t%d\t%s\n",y,pa.price,pa.period,pa.packn);

        }
        fclose(p);
        }else if(d == 2){
        p = fopen("packs.txt","r");
        printf("\nEnter ID of the package that you wish to buy");
        scanf("%d",&pc);
        while(!feof(p)){
        fscanf(p,"%d\t%d\t%d\t%s\n",&y,&pa.price,&pa.period,pa.packn);
        if(y == pc){
        j = fopen("client_purchase.txt","w");
        fprintf(j,"%d\t%s\t%d\t%s\t%s",y,pa.packn,s.first_name,s.last_name);
        printf("\npurchased succesfully!!");
        fclose(j);
        }
        }
        fclose(p);
        }else{
        return;
        }
    }
    }while(c!=0);
    }else{
    printf("\nThis user does not exist");

    }
    }


}
