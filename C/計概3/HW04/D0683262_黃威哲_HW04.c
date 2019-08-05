#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	int num;
	char name[10];
	char sex;
	int math;
	int english;
	int chinese;
	double average;
	//char *next;	
}stu;

int main(){
	
	FILE *input=NULL,*GRADE,*NUMBER;
	int i=0,j=0,k=0,itmp,n;
	double ftmp;
	char a[100][10],ctmp[10],tmp;
	
	stu studentData[9];
	
	input = fopen("input.txt","rb");
	GRADE = fopen("grade.txt","wb");
	NUMBER = fopen("number.txt","wb");

	while(feof(input)==0)
	{
		fread(a,sizeof(char),1,input);
		printf("%s",a);
		i++;	
	}
	i=6;
	for(k=0;k<9;k++){
		j=0;
		while(j<6){
			if(j==0){
				if(a[i][1] <= '9' && a[i][1] >= '0'){
					studentData[k].num = (a[i][0]-48)*10+(a[i][1]-48);
				}
				else{
					studentData[k].num = (a[i][0]-48);
				}
			}
			else if(j==1){
				strcpy(studentData[k].name,a[i]);
			}
			else if(j==2){
				studentData[k].sex=a[i][0];
			} 
			else if(j==3){
				studentData[k].math = (a[i][0]-48)*10+(a[i][1]-48);
			}
			else if(j==4){
				studentData[k].english = (a[i][0]-48)*10+(a[i][1]-48);
			}
			else if(j==5){
				studentData[k].chinese = (a[i][0]-48)*10+(a[i][1]-48);
			}
			i++;
			j++;
		}
		studentData[k].average = (studentData[k].chinese+studentData[k].english+studentData[k].math)/3.0;
	}
	
	for(i=0;i<9;i++){
		for(j=i;j<9;j++){
			if(studentData[i].num > studentData[j].num){
				itmp = studentData[i].num;
				studentData[i].num = studentData[j].num;
				studentData[j].num = itmp;
				
				strcpy(ctmp,studentData[i].name);
				strcpy(studentData[i].name,studentData[j].name);
				strcpy(studentData[j].name,ctmp);
				
				tmp = studentData[i].sex;
				studentData[i].sex = studentData[j].sex;
				studentData[j].sex = tmp;
				
				ftmp = studentData[i].average;
				studentData[i].average = studentData[j].average;
				studentData[j].average = ftmp;
				
				itmp = studentData[i].chinese;
				studentData[i].chinese = studentData[j].chinese;
				studentData[j].chinese = itmp;
				
				itmp = studentData[i].english;
				studentData[i].english = studentData[j].english;
				studentData[j].english = itmp;
				
				itmp = studentData[i].math;
				studentData[i].math = studentData[j].math;
				studentData[j].math = itmp;
			}
		}
	}
	fprintf(NUMBER,"NO.	Name	Sex	English	Chinese	Math	Avarage\n");
	for(k=0;k<9;k++){
		fprintf(NUMBER,"%d	%s	%c	%d	%d	%d	%.2lf\n",studentData[k].num,studentData[k].name,studentData[k].sex
		,studentData[k].math,studentData[k].english,studentData[k].chinese,studentData[k].average);
	}
	
	for(i=0;i<9;i++){
		for(j=i;j<9;j++){
			if(studentData[i].average < studentData[j].average){
				itmp = studentData[i].num;
				studentData[i].num = studentData[j].num;
				studentData[j].num = itmp;
				
				strcpy(ctmp,studentData[i].name);
				strcpy(studentData[i].name,studentData[j].name);
				strcpy(studentData[j].name,ctmp);
				
				tmp = studentData[i].sex;
				studentData[i].sex = studentData[j].sex;
				studentData[j].sex = tmp;
				
				ftmp = studentData[i].average;
				studentData[i].average = studentData[j].average;
				studentData[j].average = ftmp;
				
				itmp = studentData[i].chinese;
				studentData[i].chinese = studentData[j].chinese;
				studentData[j].chinese = itmp;
				
				itmp = studentData[i].english;
				studentData[i].english = studentData[j].english;
				studentData[j].english = itmp;
				
				itmp = studentData[i].math;
				studentData[i].math = studentData[j].math;
				studentData[j].math = itmp;
			}
		}
	}
	fprintf(GRADE,"NO.	Name	Sex	English	Chinese	Math	Avarage\n");
	for(k=0;k<9;k++){
		fprintf(GRADE,"%d	%s	%c	%d	%d	%d	%.2lf\n",studentData[k].num,studentData[k].name,studentData[k].sex
		,studentData[k].math,studentData[k].english,studentData[k].chinese,studentData[k].average);
	}
	printf("Data output finish\n");
	while(1){
		
		printf("Search student:");
		scanf("%d",&n);
		if(n==0){
			break;
		}
		for(i=0;i<9;i++){
			if(studentData[i].num ==n){
				printf("%d %s %c %d %d %d %.2lf\n",studentData[i].num,studentData[i].name,studentData[i].sex,
				studentData[i].math,studentData[i].english,studentData[i].chinese,studentData[i].average);
				break;
			}
			if(i==8){
				printf("Error Number!\n");
				break;
			}
		}
		
	}
	fclose(GRADE);
	fclose(NUMBER);
	fclose(input);
	return 0;
} 
