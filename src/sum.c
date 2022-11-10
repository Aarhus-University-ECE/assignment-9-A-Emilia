#include "sum.h"
#include <stdio.h>

int sum(int a[], int n) {
  if(n<=0)
    return 0;                       
  return (sum(a, n-1) + a[n-1]); // Runs through the array n times and sums the numbers
}