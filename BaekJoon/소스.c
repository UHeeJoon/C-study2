#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char* message)
{
    int len = strlen(message);
    char* str = (char*)malloc(sizeof(char) * len);
    
    printf("%s ", message);
    for (int i = 0; i < len; i++)
        str[i] = message[len - i - 1];
    str[len]  = '\0';
    printf("%s\n", str);
    return str;
}
int main()
{
	//char* message = "abcdefghijklmnop";
    //message = reverse(message);
    //printf("%s", message);
	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <arpa/inet.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//
//#define BUFSIZE 30
//void error_handling(char* message);
//
//int main(int argc, char** argv)
//{
//	int sock;
//	pid_t pid;
//	char message[BUFSIZE];
//	int str_len, recv_len, recv_num;
//
//	struct sockaddr_in serv_addr;
//	if (argc != 3) {
//		printf("Usage : %s <IP> <port>\n", argv[0]);
//		exit(1);
//	}
//
//	sock = socket(PF_INET, SOCK_STREAM, 0);
//
//	memset(&serv_addr, 0, sizeof(serv_addr));
//	serv_addr.sin_family = AF_INET;
//	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
//	serv_addr.sin_port = htons(atoi(argv[2]));
//
//	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
//		error_handling("connect() error!");
//
//	pid = fork();
//	if (pid == 0) {
//		while (1) {
//			fputs("전송할 메세지를 입력 하세요 (q to quit) : ", stdout);
//			fgets(message, BUFSIZE, stdin);
//			if (!strcmp(message, "q\n")) {
//				shutdown(sock, SHUT_WR);
//				close(sock);
//				exit(0);
//			}
//			write(sock, message, strlen(message));
//			printf("sending data : %s ", message);
//		}                                            /* while(1) end */
//	}                                              /* if(pid==0) end */
//	while (1) {
//		int str_len = read(sock, message, BUFSIZE);
//		if (str_len == 0) {
//			break;
//		}                                        /* while(1) end */
//		message[str_len] = 0;
//		printf("received data : %s \n", message);
//	}                                          /* else end*/
//
//	close(sock);
//	return 0;
//
//}
//void error_handling(char* message)
//{
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}
