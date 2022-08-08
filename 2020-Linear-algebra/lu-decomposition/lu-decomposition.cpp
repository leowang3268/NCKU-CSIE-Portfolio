#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n, tmpM, tmpN, M[10], N[10], tmp[10], size;
	int i, j, k, l, m; 
	bool decomposable;
	ifstream inFile("input.txt", ios::in);
	ofstream outFile("output.txt", ios::out);
    inFile >> n;
    double matrix[10][10], p_matrix[10][10],
		lower[10][10], lower_t[10][10], upper[10][10];
	
		for(i=0; i<n; i++) {
			for(j=0; j<10; j++) {
				for(k=0; k<10; k++) {
					matrix[j][k] = 0; p_matrix[j][k] = 0;
					lower[j][k] = 0; lower_t[j][k] = 0; upper[j][k] = 0;
				}
			}
			inFile >> tmpM >> tmpN;
			M[i] = tmpM; N[i] = tmpN;
			decomposable = true;
			if(M[i]>N[i]) { size = M[i]; }
			else { size = N[i]; }
			for(j=0; j<M[i]; j++) {
			 	for(k=0; k<N[i]; k++) {
					int num;
					inFile >> num;
				    matrix[j][k] = num;									    
				}
				for(k=0; k<size; k++) {
					if(j==k) {
						lower[j][k] = 1;
						p_matrix[j][k] = 1;
//						p_matrix_t[j][k] = p_matrix[j][k];
					}
				}
            }
			
			for(j=1; j<M[i]; j++) {
				for(k=0; k<j; k++) {
 
						if(matrix[k][k]==0 && matrix[j][k]!=0) { //pivot = 0
							decomposable = false;
							for(l=0; l<N[i]; l++) {
								tmp[l] = matrix[j][l];
								matrix[j][l] = matrix[k][l];
								matrix[k][l] = tmp[l];
								tmp[l] = p_matrix[j][l];
								p_matrix[j][l] = p_matrix[k][l];
								p_matrix[k][l] = tmp[l]; 
							}
			 			}
			 			else if(matrix[k][k]==0 && matrix[j][k]==0) {
			 				for(l=1; l<N[i]-k; l++)	{
			 					if(matrix[j][k+l]!=0) {
			 						double eliminate = matrix[j][k+l] / matrix[k][k+l];
									for(m=0; m<N[i]-(k+l); m++)	{ 
						    			matrix[j][(k+l)+m] -= matrix[k][(k+l)+m] * eliminate;
										lower[j][l] = eliminate;
									}
									break;	
								}
							}
			 			}
			 			else {
							double eliminate = matrix[j][k] / matrix[k][k];
							for(l=0; l<N[i]-k; l++)	{ 
						    	matrix[j][k+l] -= matrix[k][k+l] * eliminate;
								lower[j][k] = eliminate;
							}
						}
				}
			}
					
/*			for(j=0; j<M[i]; j++)
				for(k=0; k<N[i]; k++)
					if(p_matrix[j][k]!=p_matrix_t[j][k]) {
						decomposible = false;
						break;
					}
*/						
			if(decomposable==false) {
				for(j=0; j<M[i]; j++) {
					for(k=0; k<N[i]; k++) {
						lower_t[j][k] = lower[j][k];
				        lower[j][k] = 0;
				    }
				} 
				for(j=0; j<M[i]; j++) {
					for(k=0; k<N[i]; k++){
						for(l=0; l<N[i]; l++)
						lower[j][k] += lower_t[j][l] * p_matrix[l][k]; 
					}
				} 	
				for(j=0; j<M[i]; j++) {
					for(k=0; k<N[i]; k++) {
						lower_t[j][k] = lower[j][k];
				        lower[j][k] = 0;
				    }
				}
				for(j=0; j<M[i]; j++) {
					for(k=0; k<N[i]; k++){
						for(l=0; l<N[i]; l++)
						lower[j][k] += p_matrix[j][l] * lower_t[l][k]; 
					}
				}	
			}
			for(j=0; j<M[i]; j++) {
				for(k=0; k<N[i]; k++) {
					upper[j][k] = matrix[j][k];	
				}
			}
	    	if(i==0) { outFile << n << "\n"; }

			decomposable==true? outFile << "True\n" : outFile << "False\n";         	//if no row exchange
			if(decomposable==false) {
				outFile << M[i] << " " << M[i] << "\n";
				for(j=0; j<M[i]; j++) {
					for(k=0; k<M[i]; k++) {
						if(k!=M[i]-1) 
							{ outFile << fixed << setprecision(2) << p_matrix[j][k] << " "; }
						else
							{ outFile << fixed << setprecision(2) << p_matrix[j][k] << "\n"; }
					}
				}
			}
 			outFile << M[i] << " " << M[i] << "\n";
			for(j=0; j<M[i]; j++) {
				for(k=0; k<M[i]; k++) {
					if(k!=M[i]-1)
						{ outFile << fixed << setprecision(2) << lower[j][k] << " "; }
					else
						{ outFile << fixed << setprecision(2) << lower[j][k] << "\n"; }
				}
			}
				
			outFile << M[i] << " " << N[i] << "\n";
			for(j=0; j<M[i]; j++) {
				for(k=0; k<N[i]; k++) {
					if(k!=N[i]-1)
						{ outFile << fixed << setprecision(2) << upper[j][k] << " "; }
					else
						{ outFile << fixed << setprecision(2) << upper[j][k] << "\n"; }
				}
			}		
	    }	
    
    return 0;
}

