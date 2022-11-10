#include "search.h"
#include <stdbool.h>
#include <stdio.h>

bool search(int a[], int n, int x) {
  if (n <= -1)
    return false;
  if (a[n] != x)
    return search(a, n - 1, x);
  if (a[n] == x)
    return true;
}