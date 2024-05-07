#include <stdio.h>

#define MAX_ROWS 500
#define MAX_COLS 500
#define FILE_NAME_LIMIT 50

void readImageFile(char *filename, int image[MAX_ROWS][MAX_COLS], int *height, int *width) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int pixels, columns = 0, rows = 0, i = 0, j = 0;
    char NewLineCounter;
    
    while (fscanf(file, "%d%c", &pixels, &NewLineCounter) != EOF) {

        image[i][j] = pixels;
        j++;
  printf("j here is: %d\n", j);
        if (NewLineCounter == '\n') {
            i++;
            columns = columns + 1; // Incrementing height
            j = 0;
        }
    }
    *height = columns;
    *width =  rows; // Calculate width
printf("rows: %d, columns: %d \n", rows, columns);
    fclose(file);
}

void displayImage(int image[MAX_ROWS][MAX_COLS], int height, int width) {
    printf("Image Dimensions: %d x %d\n", height, width);
    printf("Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int imagearray[MAX_ROWS][MAX_COLS];
    int rows = 0, columns = 0; // Initialize rows and columns
    char filename[FILE_NAME_LIMIT + 1];

    printf("Enter file name: ");
    scanf("%50s", filename);

    readImageFile(filename, imagearray, &rows, &columns);
    displayImage(imagearray, rows, columns);

    return 0;
}

