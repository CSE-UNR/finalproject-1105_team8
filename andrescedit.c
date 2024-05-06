// Andres Cuevas III
// Erin Keith
// CS 135
// May 7, 2024
// Final Project
#define MAXLENG 100
#include<stdio.h>
int menu();
int loadImage(FILE *fp1, char userfilename[MAXLENG], int image[][MAXLENG], int *rows, int *columns);
int editmenu();
int savemenu();
_Bool save();
void displayImage(FILE *fp1, char userfilename[MAXLENG], int image[][MAXLENG], int *rows, int *columns);


int main(){
int menuchoice, editchoice, loadimage, rows, columns;
char userfilename[MAXLENG];
int image[MAXLENG][MAXLENG];

FILE *fp1;


	do{menuchoice = menu();
	switch(menuchoice){
	case 1:
	loadImage(fp1, userfilename, image, &rows, &columns);
	//displayImage= displayImage(FILE *fp1, char userfilename[MAXLENG], int image[][MAXLENG], int *rows, int *columns)
//	printf("What is the name of the image file?");
//	scanf("%s", userfilename);
	
	
	
	

	
	
	
//open file here to check for null
	break;
	case 2:
	displayImage(fp1, userfilename, image, &rows, &columns);
//open file here to check for null
	break;
	case 3:
//open file here to check for null
		editchoice = editmenu();
		switch(editchoice){
		case 1:
		break;
		case 2:
		break;
		case 3:
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
int loadImage(FILE *fp1, char userfilename[MAXLENG], int image[][MAXLENG], int *rows, int *columns){
//	char userfilename[MAXLENG];
//	int image[MAXLENG][MAXLENG];
//	FILE *fp1;
//	scanf("%s", userfilename);
	int r;
	int c;
	*rows=0;
	*columns=0;
	printf("What is the name of the image file? ");
	scanf("%s", userfilename);
	fp1=fopen(userfilename,"r");
			if(fp1==NULL){
				printf("Could not open file\n");	
			}
			else{
		//		printf("Image successfully loaded!\n");
				while(fscanf(fp1,"%d",&image[r][c])==1){
				if(image[r][c]=='\n'){
				*rows++;
				}
				else if(image[r][c]!='\n'){
				*columns++;
				}
				}
				printf("Image successfully loaded!\n");
	//			fclose(fp1);
			}
			
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
void displayImage(FILE *fp1, char userfilename[MAXLENG], int image[][MAXLENG], int *rows, int *columns){
	int i;
	int j;
	int r;
	int c;
	int rmax;
	int cmax;
	rmax=*rows;
	cmax=*columns;
	for(i=0; i<rmax; i++){
		for(j=0; j<rmax; j++){
			if(image[i][j]==0){
				printf(" ");
			}
			else if(image[i][j]==1){
				printf(".");
			}
			else if(image[i][j]==2){
				printf("o");
			}
			else if(image[i][j]==3){
				printf("O");
			}
			else if(image[i][j]>=4){
			printf("0");
			}
		}
	}
	

}
int editmenu(){
	int decision;
	printf("What Edit Would You Like to Make? \n");
	printf("1. Crop Image \n");
	printf("2. Dim Image \n");
	printf("3. Brighten Image \n");
//	printf("4. Rotate Image");
	printf("0. Exit\n");
	printf("Choose from one of the options above: ");
	scanf(" %d", &decision);

	return decision;
}
int cropmenu(){
//display image
//show image with a number indicating the first row and first column
//this image is a 12 x 12 image


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



















