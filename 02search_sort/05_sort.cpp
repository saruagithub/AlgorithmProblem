//
//  05_sort.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/11/18.
//

#include <stdio.h>
#include <string.h>

int test_bubsort() {
    int n = 10;
    int numbers[10];
    int i;

    // 读入给定的数字
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (i = 0; i < n; i++) {
        for ( int j = 0; j < n - 1 - i; j++) {
            if (numbers[j] < numbers[j+1]) {
                int temp;
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d", numbers[i]);
    }
    return 0;
}
