#include <stdio.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

void RetrieveNewImage(char *filename, int *width, int *height, int imagearray[][MAX_WIDTH]);
void DisplayImage(int width, int height, int imagearray[][MAX_WIDTH]);

int main() {
    char filename[50];
    int width, height;
    int imagearray[MAX_HEIGHT][MAX_WIDTH];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    RetrieveNewImage(filename, &width, &height, imagearray);

    // Display the image
    DisplayImage(width, height, imagearray);

    return 0;
}

void RetrieveNewImage(char *filename, int *width, int *height, int imagearray[][MAX_WIDTH]) {
    FILE *filepointer = fopen(filename, "r");
    if (filepointer == NULL) {
        printf("Could not find an image with that filename.\n");
        return;
    }

    // Initialize width and height to 1
    *width = 1;
    *height = 1;

    // Read the brightness values into the image array
    while (fscanf(filepointer, "%1d", &imagearray[*height - 1][*width - 1]) == 1) {
        // Move to the next column
        (*width)++;

        // Check if we reached the end of the row
        if ((*width) > MAX_WIDTH) {
            // Increment the height
            (*height)++;
           
            // Reset width for the next row
            *width = 1;
        }
    }

    fclose(filepointer);
}

void DisplayImage(int width, int height, int imagearray[][MAX_WIDTH]) {
    printf("Image dimensions: %d x %d\n", width, height);
    printf("Image contents:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", imagearray[i][j]);
        }
        printf("\n");
    }
}
