#include<omp.h>
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
int getRand(){
	return rand()%100;
}
int main(){
	int m,n,p;
	cout<<"Enter rows and columns of first array:";
	cin>>m>>n;
	cout<<"Enter columns of second array:";
	cin>>p;
	srand (time(NULL));
	int a[m][n],b[n][p],c[m][p];
	#pragma omp parallel for schedule(dynamic,1) collapse(2)
	for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	printf ("id = %d, a[%d][%d]=%d \n", omp_get_thread_num(),i,j,a[i][j]=getRand());
	}
	}
	#pragma omp parallel for schedule(dynamic,1) collapse(2)
	for(int i=0;i<n;i++){
	for(int j=0;j<p;j++){
	printf ("id = %d, b[%d][%d]=%d \n", omp_get_thread_num(),i,j,b[i][j]=getRand());
	}
	}
	#pragma omp parallel for schedule(dynamic,1) collapse(2)
	for(int i=0;i<m;i++){
	for(int j=0;j<p;j++){
	printf ("id = %d, c[%d][%d]=%d \n", omp_get_thread_num(),i,j,c[i][j]=0);
	}
	}

	#pragma omp parallel for schedule(dynamic,1) collapse(3)
	for(int i=0;i<m;i++){
	for(int j=0;j<p;j++){
	for(int k=0;k<n;k++){
	printf ("id = %d, c[%d][%d]+=a[%d][%d]*b[%d][%d] c[%d][%d]=%d \n", omp_get_thread_num(),i,j,i,k,k,j,i,j,c[i][j]+=(a[i][k]*b[k][j]));
	}
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
	  for(int i=0;i<n;i++){
	  for(int j=0;j<p;j++){
	  cout<<b[i][j]<<" ";
	  }
	  cout<<endl;
	  }
	  cout<<"Array3"<<endl;
	  for(int i=0;i<m;i++){
	  for(int j=0;j<p;j++){
	  cout<<c[i][j]<<" ";
	  }
	  cout<<endl;
	  }
	return 0;
}
