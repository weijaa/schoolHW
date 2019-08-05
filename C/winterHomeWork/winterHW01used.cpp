#include<stdio.h>
#include<string.h>

int  main(){
	
	char id[15] ;
	int ans,n,time=1;
	
	 
	scanf("%d",&n);
	
	while(time<=n){
	
		scanf("%s", id);
		
		
		if(id[0] == 'A'){
			ans = 1+0*9;
		}
		else if(id[0] == 'B'){
			ans = 1+1*9;
		}
		else if(id[0] == 'C'){
			ans = 1+2*9;
		}	
		else if(id[0] == 'D'){
			ans = 1+3*9;
		}	
		else if(id[0] == 'E'){
			ans = 1+4*9;
		}
		else if(id[0] == 'F'){
			ans = 1+5*9;
		}	
		else if(id[0] == 'G'){
			ans = 1+6*9;
		}
		else if(id[0] == 'H'){
			ans = 1+7*9;
		}
		else if(id[0] == 'J'){
			ans = 1+8*9;
		}	
		else if(id[0] == 'K'){
			ans = 1+9*9;
		}
		else if(id[0] == 'L'){
			ans = 2+0*9;
		}
		else if(id[0] == 'M'){
			ans = 2+1*9;
		}	
		else if(id[0] == 'N'){
			ans = 2+2*9;
		}
		else if(id[0] == 'P'){
			ans = 2+3*9;
		}	
		else if(id[0] == 'Q'){
			ans = 2+4*9;
		}
		else if(id[0] == 'R'){
			ans = 2+5*9;
		}	
		else if(id[0] == 'S'){
			ans = 2+6*9;
		}
		else if(id[0] == 'T'){
			ans = 2+7*9;
		}
		else if(id[0] == 'U'){
			ans = 2+8*9;
		}	
		else if(id[0] == 'V'){
			ans = 2+9*9;
		}
		else if(id[0] == 'X'){
			ans = 3+0*9;
		}
		else if(id[0] == 'Y'){
			ans = 3+1*9;
		}	
		else if(id[0] == 'W'){
			ans = 3+2*9;
		}
		else if(id[0] == 'Z'){
			ans = 3+3*9;
		}	
		else if(id[0] == 'I'){
			ans = 3+4*9;
		}
		else if(id[0] == 'O'){
			ans = 3+5*9;
		}	
		
		ans = ans + 8*(id[1]-48) + 7*(id[2]-48) + 6*(id[3]-48) + 5*(id[4]-48) + 4*(id[5]-48) + 3*(id[6]-48) + 2*(id[7]-48) +1*(id[8]-48) +(id[9]-48) ;
	//	printf("%d",ans);
		if(ans%10 == 0){
			printf("real\n");
		}
		else{
			printf("fake\n");
		}
		time++;
	}
	
	return 0;
}







