//PFTHEORY A1
//BQ3 Class Result Processing

#include<stdio.h>
int main(){
	int marks,sum,flag,index;
	float avg;
	index=1;
	sum=0,flag=0;
	while (index<=5){
		printf("Enter Marks per subject one by one ");
		scanf("%d",&marks);
		if (marks<33){
			flag=1;
		}
		sum+=marks;
		index+=1;
		
	}
	avg=sum/5;
	if (flag==1){
		printf("Fail -- Subject Deficiency");
		
	}else{
		if (avg>=80){
			printf("Distinction");
		
		}else if(avg<80 && avg>=60){
			printf("Pass");
		
		}else{
			printf("Fail");
		}
	}
	
	
}
