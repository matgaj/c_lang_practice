/* 
    Program for drawing a histogram of the lengths of "words" in a text.
    A "word" is a string of charachters surrounded by whitespace.
    If the text doesn't end in \n, the last "word" won't be counted.
*/

// "words" for testing
// aaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

#include <stdio.h>

#define IN 1
#define OUT 0
#define ARR_SIZE 15

int main()
{
    int c, nw, state, word_len;
    state = OUT;
    nw = word_len = 0;

    int word_lens_arr[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++)
        word_lens_arr[i] = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT) {
            state = IN;
            ++nw;
        }
        // if inside word, keep counting its length
        if(state == IN)
            word_len++;
        // if outside word and the length is non-zero, add the length to the tally
        // if the word is longer than the longest we account for, add it as the longest we account for.
        else if(state == OUT && word_len != 0) {
            if(word_len > ARR_SIZE)
                word_len = ARR_SIZE;
            word_lens_arr[word_len-1]++;
            word_len = 0;
        }
    }

    printf("-----word lengh histogram-----\n");
    for(int i = 0; i < ARR_SIZE; i++) {
        printf("%2d",i+1);
        putchar(' ');
        for(int j = 0; j < word_lens_arr[i]; j++)
            putchar('*');
        putchar('\n');
    }

    printf("Word count from counter:   %d\n",nw);

    int sum_lens = 0;
    for(int i = 0; i < ARR_SIZE; i++)
        sum_lens = sum_lens + word_lens_arr[i];
    printf("Word count from histogram: %d\n",sum_lens);
}
