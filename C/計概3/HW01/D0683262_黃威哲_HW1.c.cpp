#include<stdio.h>
#include<math.h>
float ar(float x1,float y1,float  x2,float y2,float x3,float y3){
	float xab,xac,yab,yac;
	xab = x2-x1;
	xac = x3-x1;
	yab = y2-y1;
	yac = y3-y1;
	return  fabs((xab*yac-yab*xac)/2);
}
struct  coordinate{
	float x;
	float y;	
};
struct triangle{
	struct coordinate coor[3];
	float area;
};
int main (){
	int i,j;
	float step;
	struct triangle tri[3];
	struct coordinate sp;
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			scanf("%f",& tri[j].coor[i].x );
			scanf("%f",& tri[j].coor[i].y );
		}
	}
	for(j=0;j<3;j++){
		tri[j].area=ar(tri[j].coor[0].x,tri[j].coor[0].y,tri[j].coor[1].x,tri[j].coor[1].y,tri[j].coor[2].x,tri[j].coor[2].y);
	}
	printf("排序前:\n");
	for(j=0;j<3;j++){
		printf("第%d組 area = %.2f",j+1,tri[j].area);
		for(i=0;i<3;i++){
			printf(" (%.2f,%.2f) ",tri[j].coor[i].x,tri[j].coor[i].y);
		}
		printf("\n");
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if( tri[i].area > tri[j].area){
				step=tri[j].area;
				tri[j].area=tri[i].area;
				tri[i].area=step;
		
				sp=tri[j].coor[0];
				tri[j].coor[0]=tri[i].coor[0];
				tri[i].coor[0]=sp;
				
				sp=tri[j].coor[1];
				tri[j].coor[1]=tri[i].coor[1];
				tri[i].coor[1]=sp;
				
				sp=tri[j].coor[2];
				tri[j].coor[2]=tri[i].coor[2];
				tri[i].coor[2]=sp;
			}
		}
	}	
	printf("排序後:\n");
	for(j=0;j<3;j++){
		printf("第%d組 area = %.2f",j+1,tri[j].area);
		for(i=0;i<3;i++){
			printf(" (%.2f,%.2f) ",tri[j].coor[i].x,tri[j].coor[i].y);
		}
		printf("\n");
	}		
	return 0;
} 









