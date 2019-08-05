#include<stdio.h>
#include<string.h>


int main(){
	char text[100][100];
	int n,i,j,k,ans[26]={0},max;
	
	scanf("%d ",&n);
	for(i=0;i<n;i++){
		gets(text[i]);
	}
	
	for(i=0;i<n;i++){
		
		for(j=0;j<50;j++){
			if(text[i][j]=='\n'){
				break;
			}
			else if (text[i][j]=='a'||text[i][j]=='A'){
				ans[0]++;
			}
			else if (text[i][j]=='b'||text[i][j]=='B'){
				ans[1]++;
			}
			else if (text[i][j]=='c'||text[i][j]=='C'){
				ans[2]++;
			}
			else if (text[i][j]=='d'||text[i][j]=='D'){
				ans[3]++;
			}
			else if (text[i][j]=='e'||text[i][j]=='E'){
				ans[4]++;
			}
			else if (text[i][j]=='f'||text[i][j]=='F'){
				ans[5]++;
			}
			else if (text[i][j]=='g'||text[i][j]=='G'){
				ans[6]++;
			}
			else if (text[i][j]=='h'||text[i][j]=='H'){
				ans[7]++;
			}
			else if (text[i][j]=='i'||text[i][j]=='I'){
				ans[8]++;
			}
			else if (text[i][j]=='j'||text[i][j]=='J'){
				ans[9]++;
			}
			else if (text[i][j]=='k'||text[i][j]=='K'){
				ans[10]++;
			}
			else if (text[i][j]=='l'||text[i][j]=='L'){
				ans[11]++;
			}
			else if (text[i][j]=='m'||text[i][j]=='M'){
				ans[12]++;
			}
			else if (text[i][j]=='n'||text[i][j]=='N'){
				ans[13]++;
			}
			else if (text[i][j]=='o'||text[i][j]=='O'){
				ans[14]++;
			}
			else if (text[i][j]=='p'||text[i][j]=='P'){
				ans[15]++;
			}
			else if (text[i][j]=='q'||text[i][j]=='Q'){
				ans[16]++;
			}
			else if (text[i][j]=='r'||text[i][j]=='R'){
				ans[17]++;
			}
			else if (text[i][j]=='s'||text[i][j]=='S'){
				ans[18]++;
			}
			else if (text[i][j]=='t'||text[i][j]=='T'){
				ans[19]++;
			}
			else if (text[i][j]=='u'||text[i][j]=='U'){
				ans[20]++;
			}
			else if (text[i][j]=='v'||text[i][j]=='V'){
				ans[21]++;
			}
			else if (text[i][j]=='w'||text[i][j]=='W'){
				ans[22]++;
			}
			else if (text[i][j]=='x'||text[i][j]=='X'){
				ans[23]++;
			}
			else if (text[i][j]=='y'||text[i][j]=='Y'){
				ans[24]++;
			}
			else if (text[i][j]=='z'||text[i][j]=='Z'){
				ans[25]++;
			}
		}
	}
	for(i=100;i>0;i--)
		for(k=0;k<26;k++){
			if(ans[k]==i){
			
				printf("%c %d\n",'A'+k,ans[k]);	
			}
		}
	return 0;
} 
