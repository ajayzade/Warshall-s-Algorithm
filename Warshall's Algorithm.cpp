#include<stdio.h>
int i,j,k,v;
int w[10][10],q[10][10];
int min(int a,int b){
	if(a > b){
		return b;
	}else{
		return a;
	}
}
void warshall(int temp[][10]){
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(w[i][j] == 0){
				q[i][j] = 10000;
			}
			else{
				q[i][j] = w[i][j];
			}
		}
	}
	for(k=0;k<v;k++){
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				q[i][j] = min(q[i][j],q[i][k] + q[k][j]);
			}
		}
	}
	printf("\n\n");
	printf("Matrix is\n\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d\t",q[i][j]);
		}
		printf("\n");
	}
}
int main(){
	printf("Enter the number of vertices\n");
	scanf("%d",&v);
	printf("Enter the matrix elements\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			scanf("%d",&w[i][j]);
		}
	}
	printf("The Adjajency matrix is\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d\t",w[i][j]);
		}
		printf("\n");
	}
	warshall(w);
	return 0;
}
