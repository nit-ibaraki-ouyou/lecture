/*
  ソケットを使った
  簡単なTCPクラアイントプログラム
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ソケット用にインクルードする */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* プロトタイプ宣言 */
void showError(char *message);

/* エラー処理のための関数の定義 */
void showError(char *message)
{
    fprintf(stderr, "%s", message);
    fprintf(stderr, "\n");
    exit(1);
}

int main()
{
    struct sockaddr_in sAddr;  /* サーバのアドレス情報 */
    int sock;                  /* ソケットディスクリプタ */
    int sPort;                 /* サーバのポート番号 */
    char sIP[15];              /* サーバのIPアドレス */
    int num;                   /* 【課題14-2】送受信用の整数 */
    int len, result;

    /* サーバのIPアドレスを入力する */
    printf("IPアドレス > ");
    scanf("%s", sIP);

    /* サーバのポート番号を入力する */
    printf("ポート番号 > ");
    scanf("%d", &sPort);

    /* 【課題14-2】サーバへ送る整数を入力する */
    printf("送信整数 > "); scanf("%d", &num);

    /* (1) TCPとアプリケーション間の通信路を作る */
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        showError("socket() failed.");
    }

    /* サーバのアドレス情報を構造体sAddrにセットする */
    sAddr.sin_family = AF_INET;
    /* inet_addr(): IPアドレスを文字列表現から2進表現する */
    sAddr.sin_addr.s_addr = inet_addr(sIP);
    /* htons(): データのバイト順を変換する（詳細は後ほど） */
    sAddr.sin_port = htons(sPort);

    /* (2) サーバに接続する */
    result = connect(sock, (struct sockaddr *)&sAddr, sizeof(struct sockaddr));
    if (result < 0) {
        showError("connect() failed.");
    }

    /* (3) 【課題14-2】サーバに要求メッセージを送信する */
    send(sock, &num, sizeof(num), 0);

    /* (4) 【課題14-2】サーバから応答メッセージを受信する */
    recv(sock, &num, sizeof(num), 0);

    /* 【課題14-2】受信した整数を表示する */
    printf("受信した整数: %d\n", num);

    /* ソケットを閉じる */
    close(sock);

    return 0;
}
