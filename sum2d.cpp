#include<omp.h>
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
int getRand(){
	return rand()%1000;
}
int main(){
	int m,n;
	cout<<"Enter rows and columns:";
	cin>>m>>n;
	srand (time(NULL));
	int a[m][n],b[m][n],c[m][n];
	#pragma omp parallel for schedule(dynamic,1) collapse(2)
	for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	printf ("id = %d, a[%d][%d]=%d \n", omp_get_thread_num(),i,j,a[i][j]=getRand());
	}
	}
	#pragma omp parallel for schedule(dynamic,1) collapse(2)
	for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	printf ("id = %d, b[%d][%d]=%d \n", omp_get_thread_num(),i,j,b[i][j]=getRand());
	}
	}

	#pragma omp parallel for schedule(dynamic,1) collapse(2)
	for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	printf ("id = %d, c[%d][%d]=%d \n", omp_get_thread_num(),i,j,c[i][j]=a[i][j]+b[i][j]);
	}
	}

	  cout<<"Array1"<<endl;
	  for(int i=0;i<m;i++){
	  for(int j=0;j<n;j++){
	  cout<<a[i][j]<<" ";
	  }
	  cout<<endl;
	  }
	  cout<<"Array2"<<endl;
	  for(int i=0;i<m;i++){
	  for(int j=0;j<n;j++){
	  cout<<b[i][j]<<" ";
	  }
	  cout<<endl;
	  }
	  cout<<"Array3"<<endl;
	  for(int i=0;i<m;i++){
	  for(int j=0;j<n;j++){
	  cout<<c[i][j]<<" ";
	  }
	  cout<<endl;
	  }
	return 0;
}
