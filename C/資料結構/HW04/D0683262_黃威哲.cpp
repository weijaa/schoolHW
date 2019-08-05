#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct {
	char str[MAX];
	int length();
	int find(char*);
	void insert(int,char*);
	void replace(char*,char*);
	void remove(char*);
	void reverse();
}MyString;
int main(){
	int n,i,num;
	MyString mystr;
	char words[MAX] = {0};
	char replaceWords[MAX] ={0};
	memset(mystr.str,0,MAX);
	while(1){
		printf("1.輸入字串\n2.印出字串\n3.印出字串長度\n");
		printf("4.插入字串\n5.取代字串\n6.刪除字串\n7.反轉字串\n");
		printf(" >");
		scanf("%d",&n);
		fflush(stdin);
		if(n == 1){
			memset(mystr.str,0,MAX);
			scanf("%s",mystr.str);
			fflush(stdin);
		}else if(n == 2){
			printf("%s\n",mystr.str);
		}else if(n == 3){
			printf("%d\n",mystr.length());
		}else if(n == 4){
			memset(words,0,MAX); 
			scanf("%d %s",&num,words);
			fflush(stdin);
			mystr.insert(num,words);
		}else if(n == 5){
			memset(words,0,MAX); 
			scanf("%s",words);
			fflush(stdin);
			memset(replaceWords,0,MAX); 
			scanf("%s",replaceWords);
			fflush(stdin);
			mystr.replace(words,replaceWords);
		}else if(n == 6){
			memset(words,0,MAX); 
			scanf("%s",words);
			fflush(stdin);
			mystr.remove(words);
		}else if(n == 7){
			mystr.reverse();
		}else{
			break;
		}
	}
	return 0;
}	
int MyString::length(){
	return strlen(str);
}
int MyString::find(char* tmp){
	char* x;
	x = strstr(str,tmp);
	int num;
	num = strlen(str) - strlen(x);
	return num;
}
void MyString::insert(int num,char* words){
	int i;
	char tmp[MAX]={0};
	for(i=0;i<num;i++){
		tmp[i] = str[i];
	}
	for(i=0;i<strlen(words);i++){
		tmp[num+i] = words[i];
	}
	for(i=num;i<strlen(str);i++){
		tmp[i+strlen(words)] = str[i];
	}
	for(i = 0;i<strlen(tmp);i++){
		str[i] = tmp[i];
	}
	str[i] = '\0';
}
void MyString::replace(char* words,char* replaceWords){
	int n,i;
	char tmp[MAX] = {0};
	n = find(words);
	for(i=0;i<n;i++){
		tmp[i] = str[i];
	}
	for(i=0;i<strlen(replaceWords);i++){
		tmp[n+i] = replaceWords[i];
	}
	for(i = n+strlen(words);i<strlen(str);i++){
		tmp[i+strlen(replaceWords)-strlen(words)] = str[i];
	}
	printf("%s\n",tmp);
	for(i = 0;i<strlen(tmp);i++){
		str[i] = tmp[i];
	}
	str[i] = '\0';
}
void MyString::remove(char* words){
	int n,i;
	char tmp[MAX] = {0};
	n = find(words);
	for(i=0;i<n;i++){
		tmp[i] = str[i];
	}
	for(i=n+strlen(words);i<strlen(str);i++){
		printf("%c",str[i]);
		tmp[i-strlen(words)] =str[i];
	}
	for(i = 0;i<strlen(tmp);i++){
		str[i] = tmp[i];
	}
	str[i] = '\0';

}
void MyString::reverse(){
	char tmp[MAX] = {0};
	int i,j;
	j=0;
	for(i=strlen(str)-1;i>=0;i--){
		tmp[j] = str[i];
		j++; 
	}
	printf("%s\n",tmp);
	for(i = 0;i<strlen(tmp);i++){
		str[i] = tmp[i];
	}
	str[i] = '\0';
}
