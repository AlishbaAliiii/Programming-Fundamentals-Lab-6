//Pf theory BQ1
//hotel management
#include<stdio.h>
int main(){
	int season,roomtype,rate,duration;
	float discount,price;
	printf("Enter Season Choice, 1.Peak season 2.Off season : ");
	scanf("%d",&season);
	switch(season){
		case 1:
			printf("Enter Room Category 1.Standard 2.Deluxe 3.Suite : ");
			scanf("%d",&roomtype);
			switch(roomtype){
				case 1:
					rate=5000;
					
					break;
				case 2:
					rate=8000;
					break;
					
				case 3:
					rate=12000;
					break;
			}
			break;
			
		
		case 2:
			printf("Enter Room Category 1.Standard 2.Deluxe 3.Suite : ");
			scanf("%d",&roomtype);
						switch(roomtype){
				case 1:
					rate=3000;
					break;
				case 2:
					rate=5000;
					break;
					
				case 3:
					rate=8000;
					break;
			}
			break;
		
	}
	printf("Enter stay duration : ");
	scanf("%d",&duration);
	if (duration>7){
	
		discount=(rate*duration)*0.15;
		price=(rate*duration)-discount;
	}else{
		price=(rate*duration)-discount;
	}
	printf("%.2f",price);

	
	
}
