#include <stdio.h>

#include <stdlib.h> /* srand()を使うのに必要 */
#include <time.h>   /* time()を使うのに必要 */

/* 関数のプロトタイプ宣言 */
void set(int *array0, int length);

/*
  整数の配列の要素にランダムな値を設定する
  ランダムな値は、0〜length*10の範囲から選ばれる

  [引数] value[]：値を設定する配列
         length：配列の要素数
  [戻り値] なし
 */
void set(int value[], int length)
{
  int i;
  /* 乱数の種を設定する */
  srand((unsigned int)time(NULL));
  /* 配列の全要素に値を代入する */
  for(i=0; i<length; i++) { 
      value[i] = rand() % (length*10);
  }
}

/* set()の動作確認用のmain() */
int main(void)
{
    int array[70000];

    set(array, 70000);

    int i;
    for(i=0; i<70000; i++)
	printf("%d ", array[i]);
    printf("\n");

    return 0;
}
