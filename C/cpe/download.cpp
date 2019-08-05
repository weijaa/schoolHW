#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

int main(){
	fstream file;
	char input[100],txtin[100],txtout[100],newfile[100],http[200],delfile[100];
	int num;


	system("dir /b /o:n UVA*-* >temp.txt");

	file.open("temp.txt",ios::in);
	while(1){
		file.getline(input,sizeof(input));
		if(file.eof())break;
		sscanf(input,"%*c%*c%*c%d",&num);
		sprintf(newfile,"md uva%d",num);
		sprintf(txtin,"copy %s\\ans\\in.stdin.txt uva%d\\input.txt",input,num);
		sprintf(txtout,"copy %s\\ans\\out.stdout.txt uva%d\\output.txt",input,num);
		sprintf(http,"wget -t 1 -T 1 -O uva%d\\uva_%d.pdf https://uva.onlinejudge.org/external/%d/%d.pdf",num,num,num/100,num);
		sprintf(delfile,"rd /s /q %s",input);

		system(newfile);
		system(txtin);
		system(txtout);
		system(http);
		system(delfile);

	}
	file.close();
	system("del /q temp.txt");

	system("dir /b /o:n ide-* >temp.txt");
	file.open("temp.txt",ios::in);
	while(1){
    file.getline(input,sizeof(input));
		if(file.eof())break;
		sprintf(delfile,"rd /s /q %s",input);
		system(delfile);
	}
	file.close();
	system("del /q temp.txt");

	return 0;
}

