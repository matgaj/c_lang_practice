#include <stdio.h>

/* print Celsius-Farenheit table */
main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = -40;
    upper = 100;
    step = 20;

    printf("Celsius to Farenheit temperature conversion table:\n");
    printf("%3s%4s\n","C","F");

    celsius = lower;
    while(celsius <= upper) {
        fahr = (9.0/5.0)*celsius+32.0;
        printf("%3.0f%4.0f\n",celsius,fahr);
        celsius = celsius + step;
    }
}
