

#include <stdio.h>
#define FILE_NAME_LIMIT 50
#define HEIGHTMAX 1000
#define WIDTHMAX 1000

void RetrieveNewImageData(char *filename, int *width, int *height, int imagearray[][HEIGHTMAX]) {
    int i, columns = 0, rows = 1, totalpixels = 0;
    FILE *filepointer = fopen(filename, "r");
    if (filepointer == NULL) {
        printf("Could not find an image with that filename.\n");
        return;
    }

    while (fscanf(filepointer, "%d", &i) != EOF) {
        totalpixels++;
        if (i == '\n') {
            rows++;
        }
    }
    columns = totalpixels / rows;
    fclose(filepointer);

    filepointer = fopen(filename, "r");
    *height = rows;
    *width = columns;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fscanf(filepointer, "%d", &imagearray[i][j]);
        }
    }

    fclose(filepointer);
}
