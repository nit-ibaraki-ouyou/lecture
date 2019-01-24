/*
  構造体のTCPクラアイントプログラム
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ソケット用にインクルードする */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct Msg {
    char message[50];
    int num;
} Msg;

/* プロトタイプ宣言 */
void showError(char *message);

/* エラー処理のための関数の定義 */
void showError(char *message)
{
    fprintf(stderr, "%s", message);
    fprintf(stderr, "\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in sAddr;  /* サーバのアドレス情報 */
    int sock;                  /* ソケットディスクリプタ */
    int sPort;                 /* サーバのポート番号 */
    char sIP[15];              /* サーバのIPアドレス */
    int result;
    Msg msg1, msg2;            /* 送受信用構造体 */

    /* サーバのポート番号を入力する */
    printf("ポート番号 >");
    scanf("%d", &sPort);

    /* サーバへ送る文字列を入力する */
    printf("文字列 >");
    scanf("%s", msg1.message);
    printf("整数 >");
    scanf("%d", &msg1.num);
    
    /* (1) TCPとアプリケーション間の通信路を作る */
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        showError("socket() failed.");
    }

    /* サーバのアドレス情報を構造体sAddrにセットする */
    sAddr.sin_family = AF_INET;
    /* inet_addr(): IPアドレスを文字列表現から2進表現する */
    sAddr.sin_addr.s_addr = inet_addr(argv[1]); //sIP);
    /* htons(): データのバイト順を変換する（詳細は後ほど） */
    sAddr.sin_port = htons(sPort);

    /* (2) サーバに接続する */
    result = connect(sock, (struct sockaddr *)&sAddr, sizeof(struct sockaddr));
    if (result < 0) {
        showError("connect() failed.");
    }

    /* (3) サーバに要求メッセージを送信する */
    send(sock, &msg1, sizeof(Msg), 0);

    /* (4) サーバから応答メッセージを受信する */
    recv(sock, &msg2, sizeof(Msg), 0);

    /* 受信した文字列データを表示する */
    printf("受信した文字列: %s \n", msg2.message);
    printf("受信した整数: %d \n", msg2.num);

    /* ソケットを閉じる */
    close(sock);

    return 0;
}
