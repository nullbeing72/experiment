#include<stdio.h>
#include<stdbool.h>

bool valid_pixel(int pixel);
bool compare(int pixel1, int pixel2);

int main(){
    int pval_A, pval_B;
    printf("enter pixel value, pA: ");
    scanf("%d", &pval_A);
    printf("enter pixel value, pB: ");
    scanf("%d", &pval_B);

    if(valid_pixel(pval_A) == true && valid_pixel(pval_B) == true){
        if(compare(pval_A, pval_B) == true){
            printf("\033[1mequal\033[0m\n");
        } else{
            printf("\033[1munequal\033[0m\n");
        }
    } else {
        printf("entered value invalid\n");
    }

    return 0;
}

bool valid_pixel(int pixel){
    return (pixel == 1 || pixel == 0 || pixel == -1);
}

bool compare(int pixel1, int pixel2){
    return pixel1 == pixel2;
}
