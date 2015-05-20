#include <stdio.h>

int main(void)
{
    int c;

    for (c = 'A'; c <= 'Z'; c++)        /* c の値は 'A' から 'Z' まで変化 */
        putchar(c);                     /* １文字画面に出力 */

    printf("\n");

    for (c = 'Z'; c >= 'A'; c--)        /* c の値は 'Z' から 'A' まで変化 */
        putchar(c);                     /* １文字画面に出力 */

    printf("\n\n");

    printf("アルファベットを入力して下さい\n");
    printf("eを入力するとループからぬけます\t");

    while ((c = getchar(  )) != EOF) {        /* 文字の入力 */
        putchar(c);
        if (c == 'e')            /* 入力された文字が 'e' なら */
            break;               /* ループから抜ける */
    }
}