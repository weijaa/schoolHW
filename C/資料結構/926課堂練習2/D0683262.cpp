#include<stdio.h>
#include<memory.h>
#include<string.h>
#define MAX 100

struct grade{
	int chinese;
	int math;
	int english;
}; 
struct info{
	char stuid[10];
	char name[10];
	struct grade gra ;
	
};

struct classes{
	struct info terms[MAX];
	int size;
	void AddStuInfo(char[],char[],int,int,int);
	void Show();
	void ShowStuInfo(char[]);
	void Average();
	void StuAverage(char[]);
};
int main(){
	FILE *input;
	struct classes classInfo;
	int i=0;
	memset(&classInfo,NULL,sizeof(classes));
	
	input = fopen( "C.txt","r");
	
	while(feof(input) ==0){
		if(classInfo.terms[i].name[0] == NULL){
			fscanf(input,"%s %s ", classInfo.terms[i].stuid, classInfo.terms[i].name);
			fscanf(input,"%d %d %d",&classInfo.terms[i].gra.chinese, &classInfo.terms[i].gra.english,&classInfo.terms[i].gra.math);
	} 		
	else i++;
	}
	classInfo.size = i+1;
	fclose(input);
	printf("1.新增學生資料\n");
	printf("2.印出全班資料\n");
	printf("3.印出學生資料\n");
	printf("4.印出各科平均\n");
	printf("5.印出學生分數平均\n"); 
	char ans,id[10],na[10];
	int chi,eng,ma;
	scanf("%c",&ans);
	switch(ans){
		case '1':
			printf("輸入學號:");
			scanf("%s",id );
			printf("輸入姓名:");
			scanf("%s",na );
			printf("輸入國文成績:");
			scanf("%d",&chi );
			printf("輸入英文成績:");
			scanf("%d",&eng );
			printf("輸入數學成績:");
			scanf("%d",&ma );
			classInfo.AddStuInfo(id,na,chi,eng,ma);
			break;
		case '2':
			classInfo.Show();
			break;
		case '3':
			printf("輸入學號:");
			scanf("%s",id);
			classInfo.ShowStuInfo(id);
			break;
		case '4':
			classInfo.Average();
			break;
		case '5':
			printf("輸入學號:");	
			scanf("%s",id);
			classInfo.StuAverage(id);
			break;	
	}
	return 0;
} 
void classes::AddStuInfo(char id[10],char name[10],int chi,int eng,int ma){
	FILE *output;
	size++;
	output = fopen("C.txt", "a");
	fprintf(output,"%s %s %d %d %d\n",id, name, chi, eng, ma); 
	fclose(output);
	size++;
}
void classes::Show(){
	int i=0;
	while(terms[i].name[0] != NULL){
		printf("%s %s %d %d %d\n",terms[i].stuid, terms[i].name, terms[i].gra.chinese, terms[i].gra.english, terms[i].gra.math);
		i++;
	}
}
void classes::ShowStuInfo(char id[10]){
	int i;
	for(i=0;i<size;i++){
		if(strcmp(terms[i].stuid , id) == 0){
			printf("%s %s %d %d %d\n", terms[i].stuid, terms[i].name, terms[i].gra.chinese, terms[i].gra.english, terms[i].gra.math);
			break;
		}
		else{
			printf("no this student\n");
		}
	}
}
void classes::Average(){
	int i;
	float C=0,E=0,M=0;
	for(i=0;i<size;i++){
		C = C + terms[i].gra.chinese;
		E = E + terms[i].gra.english;
		M = M + terms[i].gra.math;
	}
	C = C/size;
	E = E/size;
	M = M/size;
	printf("Chinese average = %.1f\n",C);
	printf("English average = %.1f\n",E);
	printf("Math average = %.1f\n",M);
}
void classes::StuAverage(char id[10]){
	int i;
	float ave;
	for(i=0;i<size;i++){
		if(strcmp(terms[i].stuid , id) == 0){
			ave = (terms[i].gra.chinese+ terms[i].gra.english+terms[i].gra.math)/3;
			printf("%.1f\n", ave);
			break;
		}
		else{
			printf("no this student\n");
		}
	}
}
