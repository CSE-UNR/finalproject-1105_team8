// Andres Cuevas III
// Erin Keith
// CS 135
// May 7, 2024
// Final Project

#include<stdio.h>
int menu();
int loadImage();
int editmenu();
int savemenu();
_Bool save();


int main(){
int menuchoice, editchoice, loadinput;


	do{menuchoice = menu();
	switch(menuchoice){
	case 1:
	loadinput=loadImage();
	
	
	
//open file here to check for null
	break;
	case 2:
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
int loadImage(){
	//char filename;
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



















