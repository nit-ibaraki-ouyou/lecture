//課題6-1, 6-2
#include <stdio.h>

int isaccept(int c, int fin_states[]);

//［引数］c: 現在の状態  fin_states: 終了状態の配列
//［戻り値］0: 受理不可   1: 受理可能
//fin_statesは-1が出てきたら終了する
int isaccept(int c, int fin_states[])
{
    int i, result;
    result = 0;
    for(i=0; fin_states[i] != -1; i++) {
	if(fin_states[i]==c) return 1;
    }
    return 0;
}

int main(void)
{
    /* (1) 変数を宣言 */
    char input[100];     //入力を格納する配列
    int i=0;             //入力数をカウントする
    //状態は、0が奇数、1が偶数の状態を表す
    int current_state=0; //現在の状態（初期状態）
    int fin_state=1;     //終了状態
    int fin_states[2] = {1, -1};
    /* (2) 文字列の入力 */
    printf("数字を入力してください。\n");
    scanf("%s", input);

    /* (3) 先頭から順に読み込みながら状態遷移 */
    while(input[i]!='\0') {
        switch(current_state) {
        case 0:
            if(input[i]=='0' || input[i]=='2'
               || input[i]=='4' || input[i]=='6'
               || input[i]=='8') {
                current_state = 1;
            } else {
                current_state = 0;              
            }
            break;
        case 1:
            if(input[i]=='1' || input[i]=='3'
               || input[i]=='5' || input[i]=='7'
               || input[i]=='9') {
                current_state = 0;
            } else {
                current_state = 1;              
            }
            break;
        }
        printf("読み込んだ数値 : %c 遷移先 : %d\n", input[i], current_state);
        i++;
    }

    /* (4) 終了状態にいるか判定 */
    if(isaccept(current_state, fin_states)) {
        printf("受理する。\n");
    } else {
        printf("受理しない。\n");
    }
    return 0;
}
