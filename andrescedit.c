// Andres Cuevas III
// Erin Keith
// CS 135
// May 7, 2024
// Final Project
#define MAXLENG 100
#include<stdio.h>
int menu();
int loadImage(FILE *fp1, char userfilename[MAXLENG], char imag[][MAXLENG], int *rows, int *columns);
int editmenu();
int savemenu();
_Bool save();
void dimImage(FILE *fp1, char userfilename[MAXLENG], char image[][MAXLENG], int *rows, int *columns);
void displayImage(FILE *fp1, char userfilename[MAXLENG], char imag[][MAXLENG], int *rows, int *columns);
void brightenImage(FILE *fp1, char userfilename[MAXLENG], char image[][MAXLENG], int *rows, int *columns);


int main(){
int menuchoice, editchoice, loadimage, rows, columns;
char userfilename[MAXLENG];
char imag[MAXLENG][MAXLENG];
char usersavefilename[MAXLENG];
	int cmax;
	int rmax;
	cmax=columns;
	rmax=rows;

FILE *fp1;
	
	//int lol = 48;
	//lol = lol + 1;
	//fp1 = fopen("bru.txt", "w");
	//fprintf(fp1, "%c", lol);
	
	
	//fclose(fp1);
	


	do{menuchoice = menu();
	switch(menuchoice){
	case 1:
	loadImage(fp1, userfilename, imag, &rows, &columns);
	
	int left;
	int right;
	int top;
	int bottom;
	left=3;
	right=5;
	top=2;
	bottom=4;
	cmax=columns;
	rmax=rows;
	
		for(int i=0; i<rmax; i++){
		if(i>=top && i<=bottom){

			for(int j=0; j<cmax; j++){
				if(j>=left && j<=right){
					if(imag[i][j]==48){
						printf(" ");
					}
					else if(imag[i][j]==49){
						printf(".");
					}
					else if(imag[i][j]==50){
						printf("o");
					}
					else if(imag[i][j]==51){
						printf("O");
					}
					else if(imag[i][j]>=52){
					printf("0");
					}
					if(j==right){
					printf("\n");
					}
					
				}
				//printf("\n");
			} //printf("\n");
		}//printf("\n");
		}
	
	
	//displayImage= displayImage(FILE *fp1, char userfilename[MAXLENG], int image[][MAXLENG], int *rows, int *columns)
//	printf("What is the name of the image file?");
//	scanf("%s", userfilename);
//	printf("%d", columns);
	
	
	
	

	
	
	
//open file here to check for null
	break;
	case 2:
	displayImage(fp1, userfilename, imag, &rows, &columns);
	

//open file here to check for null
	break;
	case 3:
//open file here to check for null
		editchoice = editmenu();
		switch(editchoice){
		case 1:
		break;
		case 2:
			//open file ('w')
		dimImage(fp1, userfilename, imag, &rows, &columns);
		if(savemenu()==1){
		printf("What would you like to name your file? ");
		scanf("%s", usersavefilename);
			printf("\nImage saved!!\n\n");
//PRINTING TO FILE(SAVING) DIM
	//int lol = 48;
	//lol = lol + 1;
	//fp1 = fopen("bru.txt", "w");
	//fprintf(fp1, "%c", lol);
	
	int cmax;
	int rmax;
	cmax=columns;
	rmax=rows;
	//fclose(fp1);
	int fileprint;
	fp1 = fopen(usersavefilename, "w");
	for(int i=0; i<rmax; i++){
	
			for(int j=0; j<cmax; j++){
				if(imag[i][j]==48){
					fileprint= imag[i][j];
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]==49){
					fileprint= imag[i][j]-1;
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]==50){
					fileprint= imag[i][j]-1;
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]==51){
					fileprint= imag[i][j]-1;
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]>=52){
					fileprint= imag[i][j]-1;
					fprintf(fp1,"%c", fileprint);
				}
			} fprintf(fp1,"\n");
		}
		fclose(fp1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		}
			//for
	//	for
	//		fprint...
	//fclose()
		break;
		case 3:
		brightenImage(fp1, userfilename, imag, &rows, &columns);
		if(savemenu()==1){
			printf("What would you like to name your file? ");
			scanf("%s", usersavefilename);
			printf("\nImage saved!!\n\n");
//PRINTING TO FILE(SAVING) DIM
	//int lol = 48;
	//lol = lol + 1;
	//fp1 = fopen("bru.txt", "w");
	//fprintf(fp1, "%c", lol);
	
	int cmax;
	int rmax;
	cmax=columns;
	rmax=rows;
	//fclose(fp1);
	int fileprint;
	fp1 = fopen(usersavefilename, "w");
	for(int i=0; i<rmax; i++){
	
			for(int j=0; j<cmax; j++){
				if(imag[i][j]==48){
					fileprint= imag[i][j]+1;
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]==49){
					fileprint= imag[i][j]+1;
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]==50){
					fileprint= imag[i][j]+1;
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]==51){
					fileprint= imag[i][j]+1;
					fprintf(fp1,"%c", fileprint);
				}
				else if(imag[i][j]>=52){
					fileprint= imag[i][j];
					fprintf(fp1,"%c", fileprint);
				}
			} fprintf(fp1,"\n");
		}
		fclose(fp1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		}
		break;
//rotate	case 4:
	//	break;
		case 0:
		break;
		default:
		printf("Invalid option, returning to main menu.\n");
		break;
		}
	break;
	case 0:
	break;
	default:
	printf("Invalid option, please try again.\n");
	break;
	}

	
	
	
	
	
	
	
	
	
	}while(menuchoice != 0);
	printf("Goodbye!\n");




//save();










return 0;
}

int menu(){
int decision;
	printf("***ERINSTAGRAM***\n");
	printf("1. Load Image\n");
	printf("2. Display Image\n");
	printf("3. Edit Image\n");
	printf("0. Exit\n");
	printf("Choose from one of the options above: ");
	scanf(" %d", &decision);
	
	return decision;
}
int loadImage(FILE *fp1, char userfilename[MAXLENG], char image1[][MAXLENG],  int *rows, int *columns){
//	char userfilename[MAXLENG];
//	int image[MAXLENG][MAXLENG];
//	FILE *fp1;
//	scanf("%s", userfilename);
	int r;
	int c;
	int maxc;
	r=0;
	c=0;
	int v;
	printf("What is the name of the image file? ");
	scanf("%s", userfilename);
//	fp1=fopen(userfilename,"w");
//	000044000000000440000
//	000400400000004004000
//	000411400000004114000
//	000044000000000440000
//	000000000000000000000,
//	000000000044000000000,
//	000000000000000000000,
//	000011000000000110000,
//	000001200000002100000,
//	000000230000023000000,
//	000000034404430000000,
//	000000000444000000000,
//	fprintf(fp1, "000044000000000440000\n");
//	fprintf(fp1, "000400400000004004000\n");
//	fprintf(fp1, "000411400000004114000\n");
//	fprintf(fp1, "000044000000000440000\n");
//	fprintf(fp1, "000000000000000000000\n");
//	fprintf(fp1, "000000000044000000000\n");
//	fprintf(fp1, "000000000000000000000\n");
//	fprintf(fp1, "000011000000000110000\n");
//	fprintf(fp1, "000001200000002100000\n");
//	fprintf(fp1, "000000230000023000000\n");
//	fprintf(fp1, "000000034404430000000\n");
//	fprintf(fp1, "000000000444000000000\n");
//	fclose(fp1);
	fp1=fopen(userfilename,"r");
			if(fp1==NULL){
				printf("Could not open file\n");	
			}
			else{
				printf("\nImage successfully loaded!\n\n");
				while(fscanf(fp1,"%c",&image1[r][c])==1){
					if(image1[r][c]=='\n'){
					r++;
					maxc=c;
					c=0;
					}
				else{
					c++;
				
				}
			}
			//	printf("%d\n", r);
			//	printf("%d\n", c);
			//	printf("%d\n", maxc);
				*rows=r;
				*columns=maxc;
			//	printf("Image successfully loaded!\n");
				fclose(fp1);
			}
	//Actual scan
	//fp1=fopen(userfilename,"r");
		//	if(fp1==NULL){
		//		printf("Could not open file\n");	
		//	}
		//	else{
			
				//printf("Image successfully loaded!\n");
			//	for(int i=0; i<r; i++){
			//		for(int j=0; j<maxc; j++){
						//fscanf(fp1,"%d",&v);
			//			printf("%c", image1[i][j]);
			//		}
			//		printf("\n");
			//	}
				
			//fclose(fp1);
			//}
			//for(int i=0; i<r; i++){
			//		for(int j=0; j<maxc; j++){
			//			printf("%d",image[i][j]);
			//		}
			//		
			//	}
			//	while(fscanf(fp1,"%d",&image[r][c])==1){
			///		if(image[r][c]=='\n'){
			//		r++;
			//		maxc=c;
			//		c=0;
			//		}
			//	else{
			//		c++;
			//	
			//	}
			//}
			//	printf("%d\n", r);
			//	printf("%d\n", c);
			//	printf("%d\n", maxc);
			//	*rows=r;
			//	*columns=maxc;
			//	printf("Image successfully loaded!\n");
			//	fclose(fp1);
			//}
			
			
	//scanf("%d", userfilename);
	//FILE *fp;
	//printf("What is the name of the image file?");
	//scanf(" %s", &filename);
	//fp=fopen(filename, "r");
	//		if(fp==NULL){
	//			printf("Could not open file");	
			
//doesn't load
//	printf("Could not find an image with that filename.");
//loads
//	printf("Image successfully loaded!");




}
void displayImage(FILE *fp1, char userfilename[MAXLENG], char image[][MAXLENG], int *rows, int *columns){
	int i;
	int j;
	int r;
	int c;
	int rmax;
	int cmax;
	rmax=*rows;
	cmax=*columns;
	//printf("%d", rmax);
	fp1=fopen(userfilename,"r");
	if(fp1==NULL){
		printf("Could not open file\n");	
	}
	else{
		for(i=0; i<rmax; i++){

			for(j=0; j<cmax; j++){
				if(image[i][j]==48){
					printf(" ");
				}
				else if(image[i][j]==49){
					printf(".");
				}
				else if(image[i][j]==50){
					printf("o");
				}
				else if(image[i][j]==51){
					printf("O");
				}
				else if(image[i][j]>=52){
				printf("0");
				}
			} printf("\n");
		}
		fclose(fp1);
	}

}
int editmenu(){
	int decision;
	printf("\nWhat Edit Would You Like to Make? \n\n");
	printf("1. Crop Image \n");
	printf("2. Dim Image \n");
	printf("3. Brighten Image \n");
//	printf("4. Rotate Image");
	printf("0. Exit\n");
	printf("\nChoose from one of the options above: ");
	scanf(" %d", &decision);

	return decision;
}
int cropmenu(){
//display image
//show image with a number indicating the first row and first column
//this image is a 12 x 12 image


}
void dimImage(FILE *fp1, char userfilename[MAXLENG], char image[][MAXLENG], int *rows, int *columns){
	int rmax, cmax;
	rmax=*rows;
	cmax=*columns;
	fp1=fopen(userfilename,"r");
		if(fp1==NULL){
			printf("Could not open file\n");	
		}
		else{
			for(int i=0; i<rmax; i++){

				for(i=0; i<rmax; i++){

			for(int j=0; j<cmax; j++){
				if(image[i][j]==48){
					printf(" ");
					
				}
				else if(image[i][j]==49){
					printf(" ");
				}
				else if(image[i][j]==50){
					printf(".");
				}
				else if(image[i][j]==51){
					printf("o");
				}
				else if(image[i][j]==52){
					printf("O");
				}
			}printf("\n");
		}
		}
		
	
	fclose(fp1);
	}






}
void brightenImage(FILE *fp1, char userfilename[MAXLENG], char image[][MAXLENG], int *rows, int *columns){
	int rmax, cmax;
	rmax=*rows;
	cmax=*columns;
	fp1=fopen(userfilename,"r");
		if(fp1==NULL){
			printf("Could not open file\n");	
		}
		else{
			for(int i=0; i<rmax; i++){

				for(int j=0; j<cmax; j++){
					if(image[i][j]<=48){
						printf(".");
					}
					else if(image[i][j]==49){
						printf("o");
					}
					else if(image[i][j]==50){
						printf("O");
					}
					else if(image[i][j]==51){
						printf("0");
					}
					else if(image[i][j]>=52){
					printf("0");
					}
			} printf("\n");
		}
	fclose(fp1);
	}






}


int savemenu(){
	int decision;
	printf("Would You Like to Save? \n");
	printf("1. Yes \n");
	printf("2. No \n");
	scanf(" %d", &decision);
	
	return decision;
}


	//_Bool save(){
	//_Bool check;

	//char arr[10];
	//arr[0] = 'A';
	//arr[1] = 'n';
	//arr[2] = '.';
	//arr[3] = 't';
	//arr[4] = 'x';
	//arr[5] = 't';


	//printf("%s\n", arr);


	//fopen(arr, "w");//


	//return check;
	//}



















