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

int main(void)
{
    struct sockaddr_in sAddr;  /* サーバのアドレス情報 */
    struct sockaddr_in cAddr;  /* クライアントのアドレス情報 */
    int sSock;                 /* サーバのソケットディスクリプタ */
    int cSock;                 /* クライアントのソケットディスクリプタ */
    int sPort;                 /* サーバのポート番号 */
    int result, cLen;
    Msg msg1, msg2;            /* 送受信用構造体 */

    /* サーバのポート番号を入力する */
    printf("ポート番号 >");
    scanf("%d", &sPort);

    /* (1) TCPとアプリケーション間の通信路を作る */
    sSock =socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sSock < 0) {
        showError("socket() failed");
    }

    /* サーバ（自分）のアドレス情報を構造体sAddrにセットする */
    sAddr.sin_family = AF_INET;
    /* INADDR_ANY: 全てのアドレスからの接続を許可する際に利用する */
    sAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    sAddr.sin_port = htons(sPort);

    /* (2) ポート番号とIPアドレスを指定する */
    result = bind(sSock, (struct sockaddr *)&sAddr, sizeof(struct sockaddr));
    if (result < 0) {
        showError("bind() failed.");
    }

    /* (3) 接続の受付を開始する */
    result = listen(sSock, 5);
    if (result < 0) {
        showError("listen() failed.");
    }
    printf("クライアントの受付を開始しました。\n");

    /* クライアントからの受付を待ち続ける */
    while(1) {
        cLen = sizeof(struct sockaddr);

        /* (4) 受付けた接続用のソケットを作る */
        cSock =accept(sSock, (struct sockaddr *)&cAddr, &cLen);
        if (cSock < 0) {
            showError("accept() failed");
        }
        printf("Handling client %s\n", inet_ntoa(cAddr.sin_addr));

        /* (5) クライアントから要求メッセージを受信する */
        recv(cSock, &msg1, sizeof(Msg), 0);

        /* 受信した文字列データを表示する */
	printf("受信した文字列: %s \n", msg1.message);
	printf("受信した整数: %d \n", msg1.num);

        /* (6) クライアントに応答メッセージを送信する */
        send(cSock, &msg1, sizeof(Msg), 0);

        /* クライアント用ソケットを閉じる */
        close(cSock);
    }

    return 0;
}
