#include <stdio.h>
#include <math.h>

unsigned suma(unsigned n);

int main (){
  unsigned n, mejor, mejorsum, limite;
  printf ("Ingresa el numero ");
  scanf ("%u", &n);
  mejor = n;
  mejorsum = suma (n);
  limite = (unsigned) sqrt (n);

  for (unsigned i = 1; i <= limite; i++){
    if (n % i == 0){
      unsigned sum = suma (i);
      if (sum > mejorsum || sum == mejorsum && i < mejor){
        mejorsum = sum;
        mejor = i;
      }
      sum = suma (n / i);
      if (sum > mejorsum || sum == mejorsum && n / i < mejor){
        mejorsum = sum;
        mejor = n / i;
      }
    }
  }
  printf("El mejor numero es ");
  printf ("%u\n", mejor);
  return 0;
}

unsigned suma(unsigned n) {
  unsigned s = 0;
  while (n > 0) {
    s+= n % 10;
    n = n / 10;
  }
  return s;
}