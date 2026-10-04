#include <stdio.h>
int main(){
	int Cargo,weight,n;
	int ClientCode,flag=0;
	
	printf("\n=========WELCOME TO COASTAL FREIGHT CONTAINER SCANNER=========\n");
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("Enter the number of containers for the day: \n");
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		printf("Enter Weight for Container %d    :",i);
		scanf("%d",&weight);
		printf("\n Enter Cargo Type: \n");
		printf("\n 1. General Goods 2. Hazardous Goods 3.Refrigerated Goods \n");
		scanf("%d",&Cargo);
		
		switch(Cargo){
			case(1):
				if (weight>20000){
					flag=1;
						
				}
				break;
			case(2):
				if (weight>15000){
					flag=1;
						
						
				}else{
					if (i % 2==1){
						flag=2;     //hazardous container loading 
					}
					else{
						flag=3;     //hazardous containder can't be loaded due to sequence r??
					}
				}	
				break;
			case(3):
				if (weight>18000){
					flag=1;	
						
				}
				break;
						
				
			}
			ClientCode=(weight%97);
			ClientCode=ClientCode%100;
			printf("Container Tracking Code is:    %02d\n",ClientCode);
		
		if (flag==1){
			printf("Overweight, Container Rejected \n");
		}else if(flag==2){
			printf("Hazardous Goods approved for load \n");
		}else if (flag==3){
			printf("Hazardous Goods on hold for load \n");
		}
		flag=0;
		
	}
	printf("------------Coast Clear!-------------");
}
