//課題6-3
#include <stdio.h>

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
    //状態は、0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    int current_state=0; //現在の状態（初期状態）
    //終了状態
    int fin_states[6] = {60, 70, 80, 90, 100, -1};
    /* (2) 文字列の入力 */
    printf("t（10円）/f（50円）を入力してください。\n");
    scanf("%s", input);

    /* (3) 先頭から順に読み込みながら状態遷移 */
    while(input[i]!='\0') {
        switch(current_state) {
	case 0:
	    if(input[i]=='t') current_state = 10;
	    if(input[i]=='f') current_state = 50;
	    break;
	case 10:
	    if(input[i]=='t') current_state = 20;
	    if(input[i]=='f') current_state = 60;
	    break;
	case 20:
	    if(input[i]=='t') current_state = 30;
	    if(input[i]=='f') current_state = 70;
	    break;
	case 30:
	    if(input[i]=='t') current_state = 40;
	    if(input[i]=='f') current_state = 80;
	    break;
	case 40:
	    if(input[i]=='t') current_state = 50;
	    if(input[i]=='f') current_state = 90;
	    break;
	case 50:
	    if(input[i]=='t') current_state = 60;
	    if(input[i]=='f') current_state = 100;
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
