#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *dPtr,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << dPtr[i];
        if((i + 1)%(M)== 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *dPtr,int N,int M){
    for(int i = 0; i < N*M; i++){
        dPtr[i] = (rand()%101)/100.00;
    }
}

void findRowSum(const double *dPtr,double *sum1,int N,int M){
 int count = 0;
 double sum = 0;
 for (int i  = 0; i < M*N; i++){
  sum += dPtr[i];
  if((i+1)%M == 0){
      sum1[count] = sum;
      sum = 0;
      count++;
        }
 }
}

void findColSum(const double *dPtr,double *sum1,int N,int M){
    for (int j = 0; j < M ; j++) sum1[j] = 0;
 for (int i  = 0; i < M*N; i++){
  sum1[(i)%M] += dPtr[i];
 }
}