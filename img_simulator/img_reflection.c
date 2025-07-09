#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

void create_img(int row, int col, int img[MAX][MAX]);
bool valid_img(int row, int col, int img[MAX][MAX]);
void display_img(int row, int col, int img[MAX][MAX]);
void reflection(char direction, int row, int col, int img[MAX][MAX], int ref_img[MAX][MAX]);
bool all_zero(int row, int col, int ref_img[MAX][MAX]);

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
    } else {
        printf("\n\nORIGINAL IMAGE:\n");
        display_img(row, col, img);

        char input;
        int aux_img[MAX][MAX], ref_img[MAX][MAX];

        while (1) {
            printf("\npress \"1\" to reflect image up-down\n");
            printf("press \"2\" to reflect image left-right\n");
            printf("press \"0\" to end the program\nInput: ");
            scanf(" %c", &input);

            if (input == '0') {
                printf("Exiting...\n");
                break;
            }

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    aux_img[i][j] = img[i][j];
                }
            }

            reflection(input, row, col, img, ref_img);
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    img[i][j] = ref_img[i][j];                    
                }
            }

            printf("\nREFLECTED IMAGE:\n");
            display_img(row, col, img);

            if(all_zero(row, col, img)){
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < col; j++){
                        img[i][j] = aux_img[i][j];
                    }
                } 
            }
        }
    }

    return 0;
}

void create_img(int row, int col, int img[MAX][MAX]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("I[%d][%d]: ", i, j);
            scanf("%d", &img[i][j]);
        }
    }
}

bool valid_img(int row, int col, int img[MAX][MAX]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (img[i][j] != -1 && img[i][j] != 0 && img[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

void display_img(int row, int col, int img[MAX][MAX]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d\t", img[i][j]);
        }
        printf("\n");
    }
}

void reflection(char direction, int row, int col, int img[MAX][MAX], int ref_img[MAX][MAX]){
    if (direction == '1') { 
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                ref_img[i][j] = img[row - 1 - i][j];
            }
        }
    } else if (direction == '2') { 
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                ref_img[i][j] = img[i][col - 1 - j];
            }
        }
    } else {
        printf("Invalid reflection direction.\n");
        memset(ref_img, 0, sizeof(int) * MAX * MAX);
    }
}

bool all_zero(int row, int col, int ref_img[MAX][MAX]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(ref_img[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}
