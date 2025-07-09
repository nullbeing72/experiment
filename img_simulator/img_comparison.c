#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void create_img(int row, int col, int img[MAX][MAX]);
void display_img(int row, int col, int img[MAX][MAX]);
bool valid_image(int row, int col, int img[MAX][MAX]);
bool compare_size(int rowA, int colA, int rowB, int colB);
bool compare_pixVal(int row, int col, int imgA[MAX][MAX], int imgB[MAX][MAX]);

int main() {
    int rowA, rowB, colA, colB;
    printf("Size of image IA:\n");
    printf("Enter number of rows: ");
    scanf("%d", &rowA);
    printf("Enter number of columns: ");
    scanf("%d", &colA);

    printf("\n");

    printf("Size of image IB:\n");
    printf("Enter number of rows: ");
    scanf("%d", &rowB);
    printf("Enter number of columns: ");
    scanf("%d", &colB);

    printf("\n");
    
    if (compare_size(rowA, colA, rowB, colB) == true) {
        int imgA[MAX][MAX], imgB[MAX][MAX];

        printf("Enter pixel values for IA:\n");
        create_img(rowA, colA, imgA);

        printf("\n");

        printf("Enter pixel values for IB:\n");
        create_img(rowB, colB, imgB);

        printf("\n");

        if (!valid_image(rowA, colA, imgA) || !valid_image(rowB, colB, imgB)) {
            printf("One or both images contain invalid pixel values.\n");
        } else{
            printf("\nIA:\n");

            display_img(rowA, colA, imgA);

            printf("\n");

            printf("\nIB:\n");
            display_img(rowB, colB, imgB);

            printf("\n");

            if (compare_pixVal(rowA, colA, imgA, imgB)) {
                printf("\033[1mIA = IB\033[0m\n");
            } else {
                printf("\033[1mIA != IB\033[0m\n");
            }
        } 
    } else {
        printf("Size of IA and IB are not equal.\n");
    }

    return 0;
}

void create_img(int row, int col, int img[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Pixel value at [%d,%d]: ", i, j);
            scanf("%d", &img[i][j]);
        }
    }
}

void display_img(int row, int col, int img[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", img[i][j]);
        }
        printf("\n");
    }
}

bool valid_image(int row, int col, int img[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (img[i][j] != 1 && img[i][j] != 0 && img[i][j] != -1) {
                return false;
            }
        }
    }
    return true;
}

bool compare_size(int rowA, int colA, int rowB, int colB) {
    return (rowA == rowB) && (colA == colB);
}

bool compare_pixVal(int row, int col, int imgA[MAX][MAX], int imgB[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (imgA[i][j] != imgB[i][j]) {
                return false;
            }
        }
    }
    return true;
}
