// Задача 2. Дан непустой массив A, содержащий n вещественных чисел.
// Найти индексы k1 и k2 двух элементов массива, 
// расстояние |A[k1] – A[k2]| между которыми минимально.
// Если таких пар в массиве несколько, вернуть пару с наименьшими индексами.
// При невозможности найти пару, вернуть {-1,-1}.
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

struct Indices {
    int first_index;
    int second_index;
};

struct Indices task2(double A[], size_t n) {
    struct Indices indices = {-1, -1}; 

    if (n < 2) {
        return indices; 
    }

    double min_diff = DBL_MAX; 
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            double diff = fabs(A[i] - A[j]);

            if (diff < min_diff) {
                min_diff = diff;
                indices.first_index = (int)i;
                indices.second_index = (int)j;
            } else if (diff == min_diff) {
                
                if (i < indices.first_index || (i == indices.first_index && j < indices.second_index)) {
                    indices.first_index = (int)i;
                    indices.second_index = (int)j;
                }
            }
        }
    }

    return indices;
}
