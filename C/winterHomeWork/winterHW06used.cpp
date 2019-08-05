#include<stdio.h>
#include<string.h>



int main(){
	char quistion[10],ans[10],a=0,b=0;
	
	scanf("%s",&quistion);
	
	while(1){
		
		scanf("%s",&ans);
		
		if(quistion[0] ==ans[0]){
			a++;
		}
		if(quistion[1]==ans[1]){
			a++;
		}
		if(quistion[2]==ans[2]){
			a++;
		}
		if(quistion[3]==ans[3]){
			a++;
		}
		
		if(ans[0]==quistion[1] || ans[0]==quistion[2] || ans[0]==quistion[3]){
			b++;
		}
		if(ans[1]==quistion[0] || ans[1]==quistion[2] || ans[1]==quistion[3]){
			b++;
		}
		if(ans[2]==quistion[0] || ans[2]==quistion[1] || ans[2]==quistion[3]){
			b++;
		}
		if(ans[3]==quistion[0] || ans[3]==quistion[2] || ans[3]==quistion[1]){
			b++;
		}
		printf("%dA%dB\n",a,b);
		a=0;
		b=0;
		if(quistion[1] == ans[1] && quistion[0] == ans[0] && quistion[2] == ans[2] && quistion[3] == ans[3]){
			break;
		}
	}
	
	
	
	return 0;
} 
