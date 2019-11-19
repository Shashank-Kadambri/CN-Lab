#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
    }
}

int main(){
    char ipstr[15];
    printf("\nEnter the IP Address:");
    scanf("%s",ipstr);
    int ip = atoi(ipstr);
    /*for(int j=0;j<4;j++){
        ip_arr[j] =atoi(&ipstr[i]);
        while(ipstr[i]!='.' && ipstr[i]!='\0'){
            i++;
        }
        i++;
    }*/ 
    if(ip>=1 && ip<=126){
        printf("\nAddress belongs to class A");
    }
    else if(ip>=128 && ip<=191){
        printf("\nAddress belongs to class B");
    }
    else if(ip>=192 && ip <=223){
        printf("\nAddress belongs to class C");
    }
    else if(ip>=224 && ip <=239){
        printf("\nAddress belongs to class D");
    }
    else{
        printf("\nAddress belongs to class E");
    }


    
}