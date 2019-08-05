#include<stdio.h>
#include<string.h>


int main(){
	char pl[200][10],step[10];
	int player[200];
	int i,j,n,st,len;
	int group[30][10];
	
	
	
	scanf(" %d ",&n);
	for(i=0;i<n;i++){
		scanf(" %d ",&player[i]);
		gets(pl[i]);
	}

	len = n/8;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(pl[i][0] < pl[j][0]){
				st = player[i];
				player[i]=player[j];
				player[j] =st;
				
				strcpy(step,pl[i]);
				strcpy(pl[i],pl[j]);
				strcpy(pl[j],step);
			}
			else if(pl[i][0]==pl[j][0]){
				
				if(pl[i][1] < pl[j][1]){
					st = player[i];
					player[i]=player[j];
					player[j] =st;
				
					strcpy(step,pl[i]);
					strcpy(pl[i],pl[j]);
					strcpy(pl[j],step);
				}
				else if(pl[i][1] == pl[j][1]){
					
					if(pl[i][3] < pl[j][3]){
						st = player[i];
						player[i]=player[j];
						player[j] =st;
				
						strcpy(step,pl[i]);
						strcpy(pl[i],pl[j]);
						strcpy(pl[j],step);
					}
					else if(pl[i][3] == pl[j][3]){
						
						if(pl[i][3] < pl[j][3]){
							st = player[i];
							player[i]=player[j];
							player[j] =st;
				
							strcpy(step,pl[i]);
							strcpy(pl[i],pl[j]);
							strcpy(pl[j],step);
						}
					}
				}
			}	 
		}
	}
	j=0;
	
	for(i=1;i<=len;i++){
		group[i][3] = player[j];
		j++;
	}
	for(i=len;i>=1;i--){
		group[i][4] = player[j];
		j++;
	}
	for(i=1;i<=len;i++){
		group[i][2] = player[j];
		j++;
	}
	for(i=len;i>=1;i--){
		group[i][5] = player[j];
		j++;
	}
	for(i=1;i<=len;i++){
		group[i][1] = player[j];
		j++;
	}
	for(i=len;i>=1;i--){
		group[i][6] = player[j];
		j++;
	}
	for(i=1;i<=len;i++){
		group[i][0] = player[j];
		j++;
	}
	for(i=len;i>=1;i--){
		group[i][7] = player[j];
		j++;
	}
	for(i=1;i<=len;i++){
		printf("%d ",i);
		for(j=0;j<8;j++){
			printf("%2d ",group[i][j]);
		}
		printf("\n");
	}

	
	
	return 0;
} 
