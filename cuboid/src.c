#include <stdio.h>
#include <stdbool.h>

/* *** Func *** */
bool cube_checker(int volume, int side) {
    if (volume <= 0 || side <= 0) {
        return false;
    }

    int exp = 3;    // exponent
    int v = 1;      // volume calculated by side^3

    // -- Exponentiation
    for (;;) {
        if (exp & 1) {
            v *= side;
        }
        exp >>= 1;
        if (!exp) {
            break;
        }
        side *= side;
    }
    // -- Exponentiation

    return (volume == v);
}
/* *** Func *** */


/* *** TESTS *** */
// -- True tests
void testSamples(void) {
    int testsCount      = 12;
    int volumes[]       = {-12, 8, 8, -8, 0, 27, 1, 125, 125, 0, 12, 1};
    int sides[]         = {2, 3, 2, -2, 0, 3, 5, 5, -5, 12, -1, 1};
    bool ex_results[]   = {false, false, true, false, false, true, false, true, false, false, false, true};

    bool result = false;

    for(int i = 0; i < testsCount; i++) {

        result = cube_checker(volumes[i], sides[i]);

        printf("  [%d]: V(%d), S(%d), EX(%d): RESULT(%d)\t:\t", 
            i, 
            volumes[i],
            sides[i],
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