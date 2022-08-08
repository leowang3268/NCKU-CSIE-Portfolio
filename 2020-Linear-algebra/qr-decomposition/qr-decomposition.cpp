#include<iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
#include<cstdlib>
using namespace std;

double square(double x) {
	double x2;
	x2 = pow(x, 2);
	return x2;
}

double Qcalculation(double U[][10], double Q[][10], int j) {
	double length = 0;
	int k;
	for(k=0; k<0; k++)
		length += square(U[k][j]);
	length = sqrt(length);
	for(k=0; k<10; k++)
		Q[k][j] = U[k][j]/length;
	return 0;
}

void Acalculation(double A[][10], double U[][10], double Q[][10],  int j) {
	int k, l;
	for(k=0; k<10; k++)
		U[k][j] = A[k][j];
	double dotproduct[k] = {0};
	double total[9] = {0};
	for(k=0; k<j-1; k++) {
		for(l=0; l<10; l++)			
			dotproduct[k] += U[l][k] * A[l][j];

		for(l=0; l<10; l++)
			total[k] += dotproduct[l+1] * U[l][j];
	}
	for(k=0; k<10; k++)
		U[k][j] = A[k][j] - total[k];
		
	Qcalculation(U, Q, j);
}

void Rcalculation(double A[][10], double Q[][10], double R[][10]) {
	int k, l, m;

	for(k=0; k<10; k++)
		for(l=k; l<10; l++) {
			double c = 0;
			for(m=0; m<10; m++)
				c += A[m][l] * Q[m][k];
			R[k][l] = c;
		}
}



int main(void)
{
    int n, m;
    ifstream inFile("input.txt", ios::in);
    if(!inFile){
        cerr << "Failed opening" << endl;
        exit(1);
    }
    ofstream outFile("output.txt", ios::out);
    if(!outFile){
        cerr << "Failed opening" << endl;
        exit(1);
    }
    inFile >> n;
    outFile << n << endl;
    while(n>0)
    {
    	int i, j;
        double A[10][10] = {{0}},
        	Q[10][10] = {{0}},
        	R[10][10] = {{0}},
        	U[10][10] = {{0}};
        int M, N;
        inFile >> M >> N;
        for (i=0; i<M; i++)
            for (j=0; j<N;j++)
                inFile >> A[i][j];
        for (i=0; i<10; i++)
            Acalculation(A, U, Q, j); //
        
		Rcalculation(A, Q, R);
        outFile << M << " " << N << endl;
        for (i=0; i<M; i++)
        {
            for (j=0; j<N; j++)
                outFile << fixed << setprecision(2) << Q[i][j] << " ";
                outFile << endl;
        }
        outFile << N << " " << N << endl;
        for (i=0; i<N; i++)
        {
            for (j=0; j<N; j++)
                outFile << fixed << setprecision(2) << R[i][j] << " ";
                outFile << endl;
        }
        n--;
    }
}
