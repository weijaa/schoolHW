#include "StudyClub.h"


void StudyClub(char id[]){
	system("cls");
	size_t write_num;
    FILE *fp;
    int a,Case,i,j,time[100],day[100],place[100],sort_,tmp_day,tmp_time,tmp_place;
    a=1;
    if(access("study_club.dat", 0 )==-1)
    {
        for(i=0; i<100; i++)
        {
            place[i]=0;
            day[i]=0;
            time[i]=0;
        }
    }
    while(a!=0)
    {
        fp = fopen( "study_club.dat","a+" );
        printf("1.Build a study club\n");
        printf("2.Check study club\n");
        printf("0.Back to main menu\n");
        printf("Please choose function : ");
        scanf("%d",&Case);
        switch(Case)
        {
        case 1:
            for(i=0; i<100; i++)
            {
                fread(time,sizeof(int),100,fp);
                fread(day,sizeof(int),100,fp);
                fread(place,sizeof(int),100,fp);
                if(time[i]==0)
                {
                    while(1)
                    {
                        printf("Choose time (please input as 24-hour clock Ex:1630 is 16:30) : ");
                        scanf("%d",&time[i]);
                        if(time[i]<0||time[i]>2400)
                        {
                            printf("input wrong time!\n");
                        }
                        else
                            break;
                    }
                    while(1)
                    {
                        printf("Choose day (please input as example Ex:22 is 22th) : ");
                        scanf("%d",&day[i]);
                        if(day[i]<0||day[i]>31)
                            printf("input wrong day!\n");
                        else
                            break;
                    }
                    while(1)
                    {
                        printf("Choose place 1.人言大樓 2.資電館 3.圖書館 (please input as example Ex:1 is 人言大樓) : ");
                        scanf("%d",&place[i]);
                        if(place[i]<0||place[i]>3)
                            printf("input wrong day!\n");
                        else
                            break;
                    }
                    write_num=fwrite(time,sizeof(int),100,fp);
                    write_num=fwrite(day,sizeof(int),100,fp);
                    write_num=fwrite(place,sizeof(int),100,fp);
                    fclose(fp);
                    break;
                }
            }
            break;
        case 2:
            while(1)
            {
                for(i=0; i<100; i++)
                {
                    fread(time,sizeof(int),100,fp);
                    fread(day,sizeof(int),100,fp);
                    fread(place,sizeof(int),100,fp);
                }
            for(i=99; i>0; i--)
                {
                    for(j=0; j<i; j++)
                    {
                        if(time[j]>time[j+1])
                        {
                            tmp_day=day[j];
                            day[j]=day[j+1];
                            day[j+1]=tmp_day;
                            tmp_time=time[j];
                            time[j]=time[j+1];
                            time[j+1]=tmp_time;
                            tmp_place=place[j];
                            place[j]=place[j+1];
                            place[j+1]=tmp_place;
                        }
                    }

                }
                printf("Choose resort type 1.time 2.place : ");
                scanf("%d",&sort_);
                if(sort_<0||sort_>2)
                {
                    printf("input wrong time!\n");
                }
                else
                    break;
            }
            if(sort_==1)
            {
                for(i=99; i>0; i--)
                {
                    for(j=0; j<i; j++)
                    {
                        if(day[j]>day[j+1])
                        {
                            tmp_day=day[j];
                            day[j]=day[j+1];
                            day[j+1]=tmp_day;
                            tmp_time=time[j];
                            time[j]=time[j+1];
                            time[j+1]=tmp_time;
                            tmp_place=place[j];
                            place[j]=place[j+1];
                            place[j+1]=tmp_place;
                        }
                    }

                }
                for(i=0; i<100; i++)
                {
                    if(day[i]<=0)
                        continue;
                    else
                    {
                        switch(place[i])
                        {
                        case 1:
                        {
                            printf("人言大樓");
                            break;
                        }
                        case 2:
                        {
                            printf("資電學院");
                            break;
                        }
                        case 3:
                        {
                            printf("圖書館");
                            break;
                        }
                        }
                        printf(" %dth",day[i]);
                        printf(" %d\n",time[i]);
                    }
                }
                fclose(fp);
            }
            if(sort_==2)
            {
                for(i=99; i>0; i--)
                {
                    for(j=0; j<i; j++)
                    {
                        if(place[j]>place[j+1])
                        {
                            tmp_day=day[j];
                            day[j]=day[j+1];
                            day[j+1]=tmp_day;
                            tmp_time=time[j];
                            time[j]=time[j+1];
                            time[j+1]=tmp_time;
                            tmp_place=place[j];
                            place[j]=place[j+1];
                            place[j+1]=tmp_place;
                        }
                    }

                }
                for(i=0; i<100; i++)
                {
                    if(day[i]<=0)
                        continue;
                    else
                    {
                        switch(place[i])
                        {
                        	case 1:
                      		{
                       	    	printf("人言大樓");
                            	break;
	                        }
	                        case 2:
	                        {
	                            printf("資電學院");
	                            break;
	                        }
	                        case 3:
	                        {
	                            printf("圖書館");
	                            break;
	                        }
                        }
                        printf(" %dth",day[i]);
                        printf(" %d\n",time[i]);
                    }
                }
                fclose(fp);
            }
            printf("\n");
            break;
        case 0:
            fclose(fp);
            a=0;
            break;
        default :
            printf("input number wrong!\n");
            break;
        }
    }
	
	
	
}
