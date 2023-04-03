# ***Find out whether the shape is a cube***

## [**Link**](https://www.codewars.com/kata/58d248c7012397a81800005c)

---

## **Description**

To find the `volume` (centimeters cubed) of a cuboid you use the formula:

`volume = Length * Width * Height`

But someone forgot to use proper record keeping, so we only have the volume, and the length of a single side!

It's up to you to find out whether the cuboid has equal sides (= is a cube).

Return `true` if the cuboid could have equal sides, return `false` otherwise.

Return `false` for invalid numbers too (e.g `volume` or `side` is less than or equal to `0`).

**Note:** *`side` will be an integer*

---

## **Solution**

**C** :

``` c
#include <stdbool.h>

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
```
