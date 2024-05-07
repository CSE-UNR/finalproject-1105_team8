#include <stdio.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500
#define FILE_NAME_LIMIT 100

int readPixelsFromFile(char pixels[MAX_HEIGHT][MAX_WIDTH], int *finalrows, int *finalcolumns);
void displayPixelsArray(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns);
void brightenImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns);
void dimImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns);
void saveImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns);     
void cropImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int *finalrows, int *finalcolumns);   
void rotateImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int *finalrows, int *finalcolumns);
int menu();
int editmenu();

int main() {
    int menuchoice, editchoice, imagecheck = -1, finalrows = 0, finalcolumns = 0;
    char pixels[MAX_HEIGHT][MAX_WIDTH];
    do {
        menuchoice = menu();
        switch(menuchoice){
            case 1:
                imagecheck = readPixelsFromFile(pixels, &finalrows, &finalcolumns);
                break;
            case 2:
                if (imagecheck == -1) {
                    printf("Sorry, no image to display\n");
                } else {
                    displayPixelsArray(pixels, finalrows, finalcolumns);
                }
                break;
            case 3:
                do {
                if (imagecheck == -1) {
                    printf("Sorry, no image to edit\n");
                    break;
                    }
                    editchoice = editmenu();
                    if (editchoice == 1) {
                    displayPixelsArray(pixels, finalrows, finalcolumns);
                        cropImage(pixels, &finalrows, &finalcolumns);
                        displayPixelsArray(pixels, finalrows, finalcolumns);
                        saveImage(pixels, finalrows, finalcolumns);
                    } else if (editchoice == 2) {
                        dimImage(pixels, finalrows, finalcolumns);
                        displayPixelsArray(pixels, finalrows, finalcolumns);
                        saveImage(pixels, finalrows, finalcolumns);
                        break;
                    } else if (editchoice == 3) {
                        brightenImage(pixels, finalrows, finalcolumns);
                        displayPixelsArray(pixels, finalrows, finalcolumns);
                        saveImage(pixels, finalrows, finalcolumns);
                        break;
                        }
                        else if (editchoice == 4) {
                        rotateImage(pixels, &finalrows, &finalcolumns);
                        displayPixelsArray(pixels, finalrows, finalcolumns);
                        saveImage(pixels, finalrows, finalcolumns);
                        break;
                    } else if (editchoice == 0) {
                        printf("Returning to menu\n");
                    } else {
                        printf("Invalid choice\n");
                    }
                } while (editchoice != 0);
                break;
            case 0:
                printf("Goodbye\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(menuchoice != 0);



    return 0;
}

int readPixelsFromFile(char pixels[MAX_HEIGHT][MAX_WIDTH], int *finalrows, int *finalcolumns) {
    int imagecheck = 0;
    char filename[FILE_NAME_LIMIT + 1];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        imagecheck = -1;
        return imagecheck;
    }

    int row = 0;
    int truecolumns, columns = 0, totalpixels = 0;

    while(fscanf(file, "%c", &pixels[row][columns]) == 1) {
        if (pixels[row][columns] >= '0' && pixels[row][columns] <= '4') {
            pixels[row][columns] = pixels[row][columns];
            columns++;
            totalpixels++;
        } else if (pixels[row][columns] == '\n') {
            row++;
            columns = 0;
        }
    }
    *finalrows = row;
 
    *finalcolumns = totalpixels / row;
    if (totalpixels % row != 0) {
        printf("File is an incomplete image, missing pixels. Returning to menu\n");
        imagecheck = -1;
    } else {
        printf("Image successfully uploaded!\n");
    }
   
    fclose(file);
    return imagecheck;
}

void displayPixelsArray(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns) {
    printf("Image:\n");
    for (int i = 0; i < finalrows; i++) {
        for (int j = 0; j < finalcolumns; j++) {
            switch (pixels[i][j]) {
                case '0':
                    printf(" ");
                    break;
                case '1':
                    printf(".");
                    break;
                case '2':
                    printf("o");
                    break;
                case '3':
                    printf("O");
                    break;
                case '4':
                    printf("0");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

void brightenImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns) {
    for (int i = 0; i < finalrows; i++) {
        for (int j = 0; j < finalcolumns; j++) {
            if (pixels[i][j] >= '0' && pixels[i][j] < '4') {
                pixels[i][j]++;
            }
        }
    }
}

void dimImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns) {
    for (int i = 0; i < finalrows; i++) {
        for (int j = 0; j < finalcolumns; j++) {
            if (pixels[i][j] > '0' && pixels[i][j] <= '4') {
                pixels[i][j]--;
            }
        }
    }
}

void saveImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int finalrows, int finalcolumns) {
    char decision;
    printf("Do you want to save the edited image? (y/n): ");
    scanf(" %c", &decision);

    if (decision == 'n' || decision == 'N') {
        printf("Image not saved. Returning to menu.\n");
        return;
    } else if (decision != 'y' && decision != 'Y') {
        printf("Invalid input. Image not saved. Returning to menu.\n");
        return;
    }

    char filename[FILE_NAME_LIMIT + 1];
    printf("Enter the file name to save the image (with .txt extension): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < finalrows; i++) {
        for (int j = 0; j < finalcolumns; j++) {
            fprintf(file, "%c", pixels[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Image saved successfully as %s\n", filename);
}

int menu() {
    int decision;
    printf("\n ***ERINSTAGRAM***\n");
    printf("1. Load Image\n");
    printf("2. Display Image\n");
    printf("3. Edit Image\n");
    printf("0. Exit\n");
    printf("Choose from one of the options above: \n");
    scanf("%d", &decision);

    return decision;
}

int editmenu() {
    int decision;
    printf("What Edit Would You Like to Make?\n");
    printf("1. Crop Image\n");
    printf("2. Dim Image\n");
    printf("3. Brighten Image\n");
    printf("4. Rotate Image\n");
    printf("0. Exit\n");
    printf("Choose from one of the options above: ");
    scanf("%d", &decision);

    return decision;
}

void cropImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int *finalrows, int *finalcolumns) {
    int outcome, newleft, newright, newtop, newbottom;
    printf("Image Dimensions are %d x %d\n", *finalrows, *finalcolumns);

    do {
        outcome = 0;
        printf("Which column do you want to be the new left side?: ");
        scanf("%d", &newleft);
        if (newleft < 1 || newleft > *finalcolumns) {
            printf("Out of range, must be between 1 and %d\n", *finalcolumns);
            outcome = -1;
        }
    } while (outcome == -1);

    do {
        outcome = 0;
        printf("Which column do you want to be the new right side?: ");
        scanf("%d", &newright);
        if (newright < newleft || newright > *finalcolumns) {
            printf("Out of range, must be between %d and %d\n", newleft, *finalcolumns);
            outcome = -1;
        }
    } while (outcome == -1);

    do {
        outcome = 0;
        printf("Which row do you want to be the new top side?: ");
        scanf("%d", &newtop);
        if (newtop < 1 || newtop > *finalrows) {
            printf("Out of range, must be between 1 and %d\n", *finalrows);
            outcome = -1;
        }
    } while (outcome == -1);

    do {
        outcome = 0;
        printf("Which row do you want to be the new bottom side?: ");
        scanf("%d", &newbottom);
        if (newbottom < newtop || newbottom > *finalrows) {
            printf("Out of range, must be between %d and %d\n", newtop, *finalrows);
            outcome = -1;
        }
    } while (outcome == -1);


    int newrows = newbottom - newtop + 1;
    int newcolumns = newright - newleft + 1;
    char croppedImage[MAX_HEIGHT][MAX_WIDTH];

    for (int i = 0; i < newrows; i++) {
        for (int j = 0; j < newcolumns; j++) {
            croppedImage[i][j] = pixels[newtop + i - 1][newleft + j - 1];
        }
    }

 
    *finalrows = newrows;
    *finalcolumns = newcolumns;
    for (int i = 0; i < newrows; i++) {
        for (int j = 0; j < newcolumns; j++) {
            pixels[i][j] = croppedImage[i][j];
        }
    }
}
void rotateImage(char pixels[MAX_HEIGHT][MAX_WIDTH], int *finalrows, int *finalcolumns) {
    char decision;
    printf("Do you want to rotate the image clockwise or counter-clockwise? (c for clockwise, C for counter clockwise): ");
    scanf(" %c", &decision);

    int i, j;
    char temp[MAX_WIDTH][MAX_HEIGHT];

    if (decision == 'c') {
        for (i = 0; i < *finalrows; ++i) {
            for (j = 0; j < *finalcolumns; ++j) {
                temp[j][*finalrows - i - 1] = pixels[i][j];
            }
        }
        int temp_num = *finalrows;
        *finalrows = *finalcolumns;
        *finalcolumns = temp_num;
        for (i = 0; i < *finalrows; ++i) {
            for (j = 0; j < *finalcolumns; ++j) {
                pixels[i][j] = temp[i][j];
            }
        }
    } else if (decision == 'C') {
        for (i = 0; i < *finalrows; ++i) {
            for (j = 0; j < *finalcolumns; ++j) {
                temp[*finalcolumns - j - 1][i] = pixels[i][j];
            }
        }
        int temp_num = *finalrows;
        *finalrows = *finalcolumns;
        *finalcolumns = temp_num;
        for (i = 0; i < *finalrows; ++i) {
            for (j = 0; j < *finalcolumns; ++j) {
                pixels[i][j] = temp[i][j];
            }
        }
    } else {
        printf("Invalid input. Image not rotated.\n");
    }
} 
