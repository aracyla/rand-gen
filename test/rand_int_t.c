/*
@author aracyla
@brief basic tests for rand_int generation
*/
#include <stdio.h>
#include <stdlib.h>
#include "../core/include/randgen.h"
#include "utest.h"

int test__int_arr_range(){
    int *arr;
    int length = 100;
    arr = rand_int_arr(-5, 10, length);
    for(int i = 0; i < length; i++){
        __assert(arr[i] >= -5 && arr[i] < 10);
    }

    free(arr);
    return 0;
}

int test__int_mat_range(){
    int **a;
    int rows = 10;
    int cols = 5;
    a = rand_int_mat(-5, 10, rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            __assert(a[i][j] >= -5 && a[i][j] < 10);
        }
    }

    free_rand_mat((void*)a, rows);
    return 0;
}

int main(int argc, char **argv){

    __run_test(test__int_arr_range);
    __run_test(test__int_mat_range);

    __print_result();

    return 0;
}
