#include <stdio.h>

#define LOWER -40
#define UPPER 300
#define STEP 15

/* print Celsius-Farenheit conversion table */
int main()
{
    float celsius;

    printf("Celsius to Farenheit temperature conversion table:\n");
    printf("%5s%6s\n","C","F");

    for(celsius = LOWER; celsius<=UPPER; celsius = celsius + STEP) {
        printf("%5.1f%6.1f\n",celsius,(9.0/5.0)*celsius+32.0);
    }
}
