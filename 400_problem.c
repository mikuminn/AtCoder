// https://atcoder.jp/contests/abc264/tasks/abc264_d?lang=ja

#include <stdio.h>

int main(void) {
  // scanf関数を用いて、標準入力で入力を受け取る
  char initial[8];
  scanf("%s", initial);

  // 目標となる文字列
  char target[] = "atcoder";

  // 操作回数をカウントする変数
  int count = 0;

  int len = sizeof(initial) - 1;

  int i = 0; 
    while (i < len) 
    { 
      // initial[i] が目標と一致してなかった場合にのみスワップを実行する
      if (initial[i] != target[i]) 
      {
        int j = i + 1;
        while (initial[j] != target[i])
          j++;
        // j は initial[i] と入れ替えるべき文字のインデックスである
        while (j > i) 
        {
          // 目標と一致する文字を左に一文字ずつ移動させる
          char temp = initial[j];
          initial[j] = initial[j - 1];
          initial[j - 1] = temp;
          j--;
          count++;
        }
      }
      i++;
    }
    printf("%d\n", count);
    return 0;
}
