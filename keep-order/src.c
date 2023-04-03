#include <stdio.h>
#include <sys/types.h>

/* *** Func *** */
ssize_t keep_order(size_t length, const int array[length], int value) {
    int i = 0;
    for(; i < length; i++) {
        if(value <= array[i]) {
            break;
        }
    }
    return i;
}
/* *** Func *** */


/* *** TESTS *** */
// -- True tests
void testSamples(void) {
    int testsCount          = 9;
    ssize_t ex_results[]    = {4, 0, 2, 4, 4, 0, 1, 0, 2};
    size_t lengths[]        = {5, 5, 5, 5, 4, 4, 4, 4, 4};
    int values[]            = {5, 0, 2, 5, 5, -1, 2, 0, 3};

    const int arr0[] = {1, 2, 3, 4, 7};
    const int arr1[] = {1, 2, 3, 4, 7};
    const int arr2[] = {1, 1, 2, 2, 2};
    const int arr3[] = {1, 2, 3, 4, 7};
    const int arr4[] = {1, 2, 3, 4};
    const int arr5[] = {1, 2, 3, 4};
    const int arr6[] = {1, 2, 3, 4};
    const int arr7[] = {1, 2, 3, 4};
    const int arr8[] = {1, 2, 3, 4};

    const int* arrays[] = {
        arr0,
        arr1,
        arr2,
        arr3,
        arr4,
        arr5,
        arr6,
        arr7,
        arr8
    };

    ssize_t result = -1;

    for(int i = 0; i < testsCount; i++) {

        result = keep_order(lengths[i], arrays[i], values[i]);

        printf("  [%d]: EX(%ld): RESULT(%ld)\t:\t", 
            i, 
            ex_results[i],
            result);

        if (result == ex_results[i]) {
            printf("Passed.\n");
        } else {
            printf("Not passed!\n");
        }
    }
}

/* *** Main Driver *** */
int main(void) {
    testSamples();
    return 0;
}