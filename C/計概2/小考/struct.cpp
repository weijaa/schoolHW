#include<stdio.h>



struct student {
	char name[19];
	char id[16];
	int  english;
	int  math;
	int  chinese;
	float  average;
};

int main(){
	struct student paul ={"Paul", "d0683262", 80, 60, 48, 0 } , chrise;
		
	printf("id : ");
	gets(chrise.id);
	printf("english : ");
	scanf("%d",&chrise.english);
	printf("math : ");
	scanf("%d",&chrise.math);
 	printf("chinese : ");
	scanf("%d",&chrise.chinese);

	
	
	printf("name : %s\n",paul.name);
	printf("id : %s\n",paul.id);
	printf("english : %d\n",paul.english);
	printf("math : %d\n",paul.math);
	printf("chinese : %d\n",paul.chinese);
	printf("average : %d\n",(paul.math+paul.english+paul.chinese)/3);
	printf("=====================================\n");
	
	printf("name : %s\n",chrise.name);
	printf("id : %s\n",chrise.id);
	printf("english : %d\n",chrise.english);
	printf("math : %d\n",chrise.math);
	printf("chinese : %d\n",chrise.chinese);
	printf("average : %d\n",(chrise.math+chrise.english+chrise.chinese)/3);
	printf("=====================================\n");
	
	return 0;
}


