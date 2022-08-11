#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define MAX_LINE 1024
#define MAX_GROUP 256

char int2base64 (int n);

int main() {

	FILE *fin, *fout;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	/*getopt: support options*/
	char *optarg;
	char **argv;
	int argc, cmd_opt, optind, optopt, iflag = 0, oflag = 0;
	while ((cmd_opt = getopt(argc, argv, "i:o:")) != -1) {
		//printf("optind: %d\n", optind);
		switch (cmd_opt) {
			case 'i':
				printf("HAVE option: -i\n");
				iflag = 1;
				printf("The argument of -i is %s\n", optarg);
				break;
			case 'o':
				printf("HAVE option: -o\n");
				oflag = 1;
				printf("The argument of -o is %s\n", optarg);
				break;
			case '?':
				printf("Unknown option: %c\n", (char)optopt);
				break;
		}
	}
	
	char strLine[100][MAX_LINE];
	
	int n = 0; 
	while(!feof(fin)) { 
		fgets(strLine[n], MAX_LINE, fin);
	
		/* turn the input string into int  */
		int i, j, intLine[100][MAX_LINE];
		for(i=0; i<strlen(strLine[n]); i++) {
			if(strLine[n][i]=='\n') {
				strLine[n][i]='\0'; 
			}
			else if(strLine[n][i]=='A' || strLine[n][i]=='B' ||
				strLine[n][i]=='C' || strLine[n][i]=='D' ||
				strLine[n][i]=='E' || strLine[n][i]=='F')
				intLine[n][i] = strLine[n][i] - 55; //ASCII alphabet to hex number
			else 
				intLine[n][i] = strLine[n][i] - '0';			
		}
		
		/* do the hex2base64 convertion */
		int arr[100][MAX_GROUP];
		char output[100][MAX_GROUP];	
		int group = strlen(strLine[n])/3;
		int remain = strlen(strLine[n])%3;
		for(i=0; i<group*3; i+=3) {
			arr[n][i*2/3] = intLine[n][i]*4 + intLine[n][i+1]/4;
			arr[n][i*2/3+1] = intLine[n][i+1]%4*16 + intLine[n][i+2];		
		}
			
		for(j=0; j<group*2; j++) {
			output[n][j] =int2base64(arr[n][j]);
			fprintf(fout, "%c", output[n][j]);
		} 
			
		if(remain==1) {
			arr[n][group*2] = intLine[n][group*3]*4;
			output[n][group*2] = int2base64(arr[n][group*2]);
			output[n][group*2+1] = '=';
			fprintf(fout, "%c%c", output[n][group*2], output[n][group*2+1]);
		} 
		else if(remain==2) {
			arr[n][group*2] = intLine[n][group*3]*4 + intLine[n][group*3+1]/4; 
			arr[n][group*2+1] = intLine[n][group*3+1]%4*16;
			output[n][group*2] = int2base64(arr[n][group*2]);
			output[n][group*2+1] = int2base64(arr[n][group*2+1]);
			output[n][group*2+2] = '=';
			output[n][group*2+3] = '=';
			fprintf(fout, "%c%c%c%c",output[n][group*2], output[n][group*2+1], output[n][group*2+2], output[n][group*2+3]);
		}
		fprintf(fout, "\n");
		n++;
	}
	
	
	
	
	fclose(fin);
	fclose(fout);
	return 0;
}

char int2base64 (int n)
{
	char a; 
	if(n>=0&&n<26)
		a = 'A' + n;
	else if(n>=26&&n<52)
		a = 'a' + (n-26);
	else if(n>=52&&n<62)
		a = '0' + (n-52);
	else if(n==63)
		a = '+';
	else 
		a = '=';
	return a;	
}
