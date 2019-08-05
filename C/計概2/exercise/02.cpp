#include<stdio.h>
#include<string.h>



int main(){
	char str[100];
	
	int ans=1,i=0,j;
	
	gets(str);
	
	for(i;i<strlen(str);i++){
		if(str[i]>=0 && str[i] <=40){
			ans++;
		}
		else if(str[i]>=91 && str[i] <=96){
			ans++;
		}
		else if(str[i]>=123 && str[i] <=126){
			ans++;
		}
		
		if(str[i+1]>=0 && str[i+1] <=40 && str[i]>=0 && str[i] <=40){
			ans--;
		}
		else if(str[i+1]>=91 && str[i+1] <=96 && str[i]>=0 && str[i] <=40){
			ans--;
		}
		else if(str[i+1]>=123 && str[i+1] <=126 && str[i]>=0 && str[i] <=40){
			ans--;
		}
	}
	
	
	printf("%d",ans);
	return 0;
} 
