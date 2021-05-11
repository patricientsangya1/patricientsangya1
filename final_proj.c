
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//int n = 0;

/*
struct category{

    int price;
    int period;
    int cat; //Category should be: 1, 2, 3
}pa;*/

struct citizen_details{
        int id;
        char name[20];
        int n_of_f_m;
        int cat;
        //float total_amount;

}ct;

//cust s;

void record_citizen(){
    FILE *fp;
    fp = fopen("citizens.txt","a");
    printf("Enter citizen's ID: ");
    scanf("%d",&ct.id);
    printf("Enter citizen's name: ");
    scanf("%s",ct.name);
    printf("Enter number of familly members: ");
    scanf("%d",&ct.n_of_f_m);
    printf("Enter citizen's category: ");
    scanf("%d",&ct.cat);

    //store data
    fprintf(fp,"\n%d\t%s\t %d\t%d\n",ct.id,ct.name,ct.n_of_f_m,ct.cat);
    fclose(fp);
    printf("\Citizen recoreded successfully!\n");
}

void display(){
    FILE *fp;
    fp = fopen("citizens.txt","r");
    printf("\nID\tNAME\t  # OF F_MEMBERS\tCATEGORY\n--------------------------------------------\n");
    while(!feof(fp)){
        fscanf(fp,"\n%d\t%s\t%d\t%d\n",&ct.id,ct.name,&ct.n_of_f_m,&ct.cat);
        printf("\n%d\t%s\t\t%d\t\t%d\n",ct.id,ct.name,ct.n_of_f_m,ct.cat);
    }printf("\n");

    fclose(fp);

}

void search(){
    int id, flag = 0;
    FILE *fp;
    fp = fopen("citizens.txt","r");
    printf("Enter number of category to be searched: ");
    scanf("%d",&id);
    printf("\nID\tNAME\t  # OF F_MEMBERS\tCATEGORY\n--------------------------------------------\n");
    while(!feof(fp)){
        fscanf(fp,"\n%d\t%s\t%d\t%d\n",&ct.id,ct.name,&ct.n_of_f_m,&ct.cat);
        if(id==ct.cat){
            flag=1;
            printf("\n%d\t%s\t\t%d\t\t%d\n",ct.id,ct.name,ct.n_of_f_m,ct.cat);
        }
    }printf("\n");
    if(!flag){
        printf("Data not found!\n");
    }
}
//
void sort(){
    int c=0, oc=0;
    FILE *fp;
    fp = fopen("citizens.txt","r");
    while(!feof(fp)){
        fscanf(fp,"\n%d\t%s\t%d\t%d\n",&ct.id,ct.name,&ct.n_of_f_m,&ct.cat);
        c++;
    }
    fclose(fp);
    struct citizen_details temp, st2[c];
    fp = fopen("citizens.txt","r");
    while(!feof(fp)){
        if(oc==0){
            fscanf(fp,"\n");
        }
        else{
            fscanf(fp,"\n%d\t%s\t%d\t%d\n",&st2[oc-1].id,st2[oc-1].name,&st2[oc-1].n_of_f_m,&st2[oc-1].cat);
        }
        oc++;
    }
    int i, j;
    for(i=0;i<c-1;i++){
        for(j=0;j<c-i-1;j++){
            if(st2[j].id > st2[j+1].cat){
                temp = st2[j];
                st2[j] = st2[j+1];
                st2[j+1] = temp;
            }
        }
    }
    for(int i=0; i<c; i++){
        printf("\n%d\t%s\t%d\t%d\n",st2[i].id,st2[i].name,st2[i].n_of_f_m,st2[i].cat);
    }
}


void main()
{
    printf("\n----------MUYISA TSANGYA PATRICIEN'S WORK----------\n");
    printf("\n");

    int choice;
    do{
        printf("\n\t1.New record\n\t2.Display\n\t3.Search\n\t4.Sort\n\t0.exit\n");
        printf("\tPlease make a choice: \n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            record_citizen();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        default:
            if(choice!=0)
                printf("\nInvalid input");

                }
    }while(choice != 0);


}
