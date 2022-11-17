#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( ) {
    int N = 15;
    int arr[15][15]; // 조건 2에 따라 최대 크기로 선언
    memset(arr, -1, sizeof(arr[0][0]) * 15 * 15);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\r\n");
    }

    return 0;
}
