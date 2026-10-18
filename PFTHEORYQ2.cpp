//PF THEORY A1
//BQ2 Elevator Simulation
#include<stdio.h>
int main(){
	int currentfloor,requestedfloor;
	currentfloor=0;
	//assuming the elevator is at ground floor according to the question
	printf("Please Enter The Floor Number: ");
	scanf("%d",&requestedfloor);
	if (requestedfloor> currentfloor){
		printf("Moving Up");
	}else if (requestedfloor>currentfloor){
		printf("Moving Down");
	}else{
		printf("Opening Doors");	
	}
	
	
}
