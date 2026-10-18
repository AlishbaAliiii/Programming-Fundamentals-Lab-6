//PF THEORY A1
//Q4 Online shopping bill calculator
#include<stdio.h>
int main(){
	int q; //assuming all products have same price according to question, q quantity
	float p,s,a,fb,t; //p price,s subtotal,a discounted amount,fb final bill,t tax.
	float d; //discount
	
	printf("Please enter the quantity of products purchased:  ");
	//since the question is free of iterations,we will skip asking for price per item
	scanf("%d",&q);
	printf("Enter the price for your product:  "); //asking price once.
	scanf("%f",&p);
	
	s=q*p;
	printf("Enter the discount percentage (if 10 percent write 0\.10):   ");
	scanf("%f",&d);
	if (d==0.0 || d==0){ //if 0% discount
		d=1;
	}
	a=s-((s*d)/100);
	
	//assuming the store must have tax policy of some sort
	
	printf("Enter tax according to store policy (if 18 percent write 0\.18):  ");
	if (t>0.0 && t<=0.30){        //maximum in store gst is 30% rounded
		scanf("%d",&t);
		a=s-((s*d)/100); //discounted bill
		fb= a+((a*t)/100);  //bill after tax, final bill
		
		
		//bill report 
		printf("================================================ \n\n");
		printf(" Total Bill: Rs %.2f\t\n ",s);
		printf("Payable Bill After Tax and Discounts: Rs%.2f\n\n ",fb);
		printf("================================================ \n\n");
		
	}else{
		printf("Invalid tax input");
	}
}
