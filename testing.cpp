#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>

int a[6][6]={{0,7,9,100,100,14},{7,0,10,15,100,100},{9,10,0,11,100,2},{100,15,11,0,6,100},{100,100,100,6,0,9},{14,100,2,100,9,0}};
int distance[6]={0,100,100,100,100,100};
int prevvertex[6]={0};
int vertex=0,previvertex=0,min=100;
int visitvertex[6]={1,0,0,0,0,0};
int flag[6]={0};
enum {A,B,C,D,E,F};                      //source=A
void minimum(int [6][6],int);
void printArray(int [],int);
void resetFlag();
void destination(int n);
char Destination(int n);
int n=0;
char str[]="";
int source=A;


int main(){
	printf("Delays between every nodes are:\n");
	int i=0,j=0;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	while(!(visitvertex[0]==1 && visitvertex[1]==1 && visitvertex[2]==1 && visitvertex[3]==1 && visitvertex[4]==1 && visitvertex[5]==1))
	{
		minimum(a,vertex);	
	}
	printf("\n ROUTING TABLE: \n");
	printf("Destination:-   A   B   C   D    E    F\n");
	printf("Delay:-         ");
	printArray(distance,6);
	printf("Prevvertex:-    ");
	printArray(prevvertex,6);
	
	printf("ENTER DESTINATION: ");
	scanf("%d",&n);
	if(n==A){
		printf("You are at destination only\n");
		goto label;
	}
		
		
	printf("The path traced is:");
	
	
	//destination(n);
	do{
		destination(n);
		n=prevvertex[n];
	}while(n!=0); 
	//printArray(visitvertex,6);
	
	label: destination(source);
	
} 


void resetFlag(){
	int j=0;
	for(j=0;j<6;j++){
		flag[j]=0;
	}
}
// CHECK MINIMUM FOR NOT VISITED VERTEX AND NOT FOR 0 VALUE
void minimum(int arr[6][6],int rowu){
	min = 100;
	int j=0;
	for(j=0;j<6;j++){
		if(min > arr[rowu][j] && arr[rowu][j]!=0 && visitvertex[j]!=1){
			min = (arr[rowu][j]);
			if(distance[j]>min + distance[rowu]){
				distance[j]=min + distance[rowu];
				prevvertex[j]=rowu;
			}
			if(arr[0][j]<distance[j]){
				distance[j]=arr[0][j];
				prevvertex[j]=0;
			}
			flag[j]=1;
		}
	}
	//check direct distance from center vs dist from prev vertex	
	int localmin =90;
	for(j=0;j<6;j++){
		if(flag[j]==1 && j!=0){        //vertex cannot be source
			if(distance[j]<localmin){
				vertex=j;
				localmin = distance[j];
			}
		}
	}
	resetFlag();                       //flag reset
	
	for(j=0;j<6;j++){
		if(vertex==j){
			visitvertex[j]=1;
		}
	}
}

void printArray(int a[],int size){
	int i=0,j=0;
	//printf("\n");
		for(j=0;j<size;j++){
			printf("%d:  ",a[j]);
		}
	printf("\n");
}

void destination(int n){
	if(n==0)
		printf("A");
	else if(n==1)
		printf("B");
	else if(n==2)
		printf("C");
	else if(n==3)
		printf("D");	
	else if(n==4)
		printf("E");
	else if(n==5)
		printf("F");	
}

char Destination(int n){
	if(n==0)
		return('A');
	else if(n==1)
		return('B');
	else if(n==2)
		return('C');
	else if(n==3)
		return('D');	
	else if(n==4)
		return('E');
	else if(n==5)
		return('F');	
}


