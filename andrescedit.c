// Andres Cuevas III
// Erin Keith
// CS 135
// May 7, 2024
// Final Project

#include<stdio.h>
void menu
void editmenu

int main(){











return 0;
}

int menu(){
int decision;
	printf("What would you like to do?\n");
	printf("1. Load a New Image \n");
	printf("2. Display Current Image \n");
	printf("3. Edit the Current Image \n");
	printf("4. Exit the Program");
	scanf(" %d", &decision);
	
	return decision;
}
int editmenu(){
	int decision;
	printf("What Edit Would You Like to Make? \n");
	printf("1. Crop Image \n");
	printf("2. Dim Image \n");
	printf("3. Brighten Image \n");
//	printf("4. Rotate Image");
	scanf(" %d", &decision);

	return decision;
}
int savemenu(){
	int decision;
	printf("Would You Like to Save? \n");
	printf("1. Yes \n");
	printf("2. No \n");
	scanf(" %d", &decision);
	
	return decision;
}
















