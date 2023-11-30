#include <stdio.h>

int main(void) {
    // scanf関数を用いて、標準入力で入力を受け取る
    int N, Y;
    scanf("%d %d", &N, &Y);

    // 制約を満たさない入力が渡された場合は、エラーを返す
    if ((N < 1 || N > 2000) || (Y < 1000 || Y > 20000000 || (Y % 1000 != 0)))
    {
        printf("%s", "The input is not appropriate");
    }

    // 10000円札、5000円札、1000円札の枚数をそれぞれ x, y, z とする
    int x, y, z;

    // すべての組み合わせを調べる
    x = 0; 
    while (x <= N) { // x が N 以下の間繰り返す
        y = 0; // y を 0 から始める
        while (y <= N - x) { // y が N - x 以下の間繰り返す
            // z は残りの枚数
            z = N - x - y;
            // 合計金額が Y に一致するかどうか
            if (10000 * x + 5000 * y + 1000 * z == Y) 
            {
                // 一致した場合は答えを出力
                printf("%d %d %d\n", x, y, z);
                return 0;
            }
            y++;
        }
        x++;
    }

    // すべての組み合わせを見ても、一致する組み合わせがなかった場合
    printf("-1 -1 -1\n");
    return 0;
}