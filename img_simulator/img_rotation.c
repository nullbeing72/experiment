#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void create_img(int row, int col, int img[MAX][MAX]);
void display_img(int row, int col, int img[MAX][MAX]);
bool valid_img(int row, int col, int img[MAX][MAX]);
void clkrot_img(int row, int col, int img[MAX][MAX], int rot[MAX][MAX]);
void anticlkrot_img(int row, int col, int img[MAX][MAX], int rot[MAX][MAX]);

int main() {
    int row, col;
    printf("Size of the image:\nEnter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    int img[MAX][MAX];
    printf("\nEnter pixel values:\n");
    create_img(row, col, img);

    if (!valid_img(row, col, img)) {
        printf("Image contains invalid pixel values.\n");
    } else{
        printf("\n\nORIGINAL IMAGE:\n");
        display_img(row, col, img);

        printf("\n");

        int input;
        int rot_img[MAX][MAX];
        int clk_count = 0, aclk_count = 0;

        while (true) {
            printf("\npress \"1\" to rotate image clockwise\n");
            printf("press \"2\" to rotate image anticlockwise\n");
            printf("press \"0\" to end the program:\ninput: ");
            scanf("%d", &input);

            if (input == 1) {
                printf("\n\033[1mClockwise rotation\033[0m\n");
                clkrot_img(row, col, img, rot_img);
                int temp = row;
                row = col;
                col = temp;
                for (int i = 0; i < row; i++)
                    for (int j = 0; j < col; j++)
                        img[i][j] = rot_img[i][j];
                display_img(row, col, img);
                printf("Clockwise rotation count: %d\n", ++clk_count);
            } else if (input == 2) {
                printf("\n\033[1mAnticlockwise rotation\033[0m\n");
                anticlkrot_img(row, col, img, rot_img);
                int temp = row;
                row = col;
                col = temp;
                for (int i = 0; i < row; i++)
                    for (int j = 0; j < col; j++)
                        img[i][j] = rot_img[i][j];
                display_img(row, col, img);
                printf("Anticlockwise rotation count: %d\n", ++aclk_count);
            } else if (input == 0) {
                printf("Exiting program ...\n");
                break;
            } else {
                printf("Invalid input\n");
            }         
        }
    }
    return 0;
}

void create_img(int row, int col, int img[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("p[%d][%d]: ", i, j);
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

bool valid_img(int row, int col, int img[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (img[i][j] != -1 && img[i][j] != 0 && img[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

void clkrot_img(int row, int col, int img[MAX][MAX], int rot[MAX][MAX]) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            rot[i][j] = img[row - 1 - j][i];
        }
    }
}

void anticlkrot_img(int row, int col, int img[MAX][MAX], int rot[MAX][MAX]) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            rot[i][j] = img[j][col - 1 - i];
        }
    }
}
