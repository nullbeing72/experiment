#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void create_img(int row, int col, int img[MAX][MAX]);
bool valid_pattern(int col_p, int pattern[]);
bool valid_img(int row, int col, int img[MAX][MAX]);
void display_img(int row, int col, int img[MAX][MAX]);
void display_pattern(int col_p, int pattern[]);
void tessalation(int row, int col, int col_p, int pattern[], int img[MAX][MAX]);

int main() {
    int row, col, col_p;

    printf("Size of image:\nEnter rows (1-%d): ", MAX);
    scanf("%d", &row);
    printf("Enter columns (1-%d): ", MAX);
    scanf("%d", &col);

    if (row <= 0 || row > MAX || col <= 0 || col > MAX) {
        printf("Invalid image dimensions\n");
        return 1;
    }

    int img[MAX][MAX];
    printf("\nEnter image values (-1, 0, or 1):\n");
    create_img(row, col, img);

    printf("\nSize of pattern:\nEnter columns (1-%d): ", MAX);
    scanf("%d", &col_p);

    if (col_p <= 0 || col_p > MAX) {
        printf("Invalid pattern size\n");
        return 1;
    }

    int pattern[MAX];
    printf("\nEnter pattern values (0 or 1):\n");
    for (int i = 0; i < col_p; i++) {
        printf("pattern[%d]: ", i);
        scanf("%d", &pattern[i]);
    }

    if (valid_pattern(col_p, pattern) && valid_img(row, col, img)) {
        printf("\033[1mIMAGE\033[0m\n");
        display_img(row, col, img);

        printf("\n\033[1mPATTERN\033[0m\n");
        display_pattern(col_p, pattern);

        printf("\n\033[1mTESSELLATION\033[0m\n");
        tessalation(row, col, col_p, pattern, img);
    } else {
        printf("Either pattern or image is invalid\n");
    }

    return 0;
}

void create_img(int row, int col, int img[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("img[%d][%d]: ", i, j);
            scanf("%d", &img[i][j]);
        }
    }
}

bool valid_pattern(int col_p, int pattern[]) {
    for (int i = 0; i < col_p; i++) {
        if (pattern[i] != 0 && pattern[i] != 1) {
            return false;
        }
    }
    return true;
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

void display_img(int row, int col, int img[MAX][MAX]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", img[i][j]);
        }
        printf("\n");
    }
}

void display_pattern(int col_p, int pattern[]) {
    for (int i = 0; i < col_p; i++) {
        printf("%d\t", pattern[i]);
    }
    printf("\n");
}

void tessalation(int row, int col, int col_p, int pattern[], int img[MAX][MAX]) {
    char tessallate[MAX][MAX * MAX];
    int m = 0;

    if (col * col_p > MAX * MAX) {
        printf("Tessellation size exceeds maximum limit\n");
        return;
    }


    for (int i = 0; i < col_p; i++) {
        if (pattern[i] == 1) {
            for (int j = 0; j < row; j++) {
                for (int k = 0; k < col; k++) {
                    tessallate[j][m + k] = (img[j][k] == -1) ? '-' : (img[j][k] + '0');
                }
            }
        } else {
            for (int j = 0; j < row; j++) {
                for (int k = 0; k < col; k++) {
                    tessallate[j][m + k] = '*';
                }
            }
        }
        m += col;
    }

    for (int j = 0; j < row; j++) {
        for (int k = 0; k < col * col_p; k++) {
            printf("%c\t", tessallate[j][k]);
        }
        printf("\n");
    }
}