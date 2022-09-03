#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <ctype.h>
#include <stdlib.h>

#include "sock.h"

int main(int argc, char **argv)
{
    int opt;
    char *server_host_name = NULL, *server_port = NULL;

    /* Parsing args */
    while ((opt = getopt(argc, argv, "h:p:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            server_host_name = malloc(strlen(optarg) + 1);
            strncpy(server_host_name, optarg, strlen(optarg));
            break;
        case 'p':
            server_port = malloc(strlen(optarg) + 1);
            strncpy(server_port, optarg, strlen(optarg));
            break;
        case '?':
            fprintf(stderr, "Unknown option \"-%c\"\n", isprint(optopt) ?
                    optopt : '#');
            return 0;
        }
    }

    if (!server_host_name)
    {
        fprintf(stderr, "Error!, No host name provided!\n");
        exit(1);
    }

    if (!server_port)
    {
        fprintf(stderr, "Error!, No port number provided!\n");
        exit(1);
    }

    /* Open a client socket fd */
    int clientfd __attribute__((unused)) = open_clientfd(server_host_name, server_port);

    /* Start your coding client code here! */
    char message[206] = {};
    char receiveMessage[300] = {};
    char ret[3];
    char *value = NULL;
    while(1)
    {
        fgets(message, sizeof(message), stdin);
        if (message[strlen(message)-1] == '\n')
            message[strlen(message)-1] = '\0';

        send(clientfd, message, sizeof(message), 0);
        if (recv(clientfd, ret, sizeof(ret), 0) < 0)
            printf("recv ret error\n");
        ret[3] = '\0';
        printf("receive return index: %s\n", ret);
        if (strcmp(ret, "-1") == 0)
        {
            printf("Unknown Command. Please Try Again.\n");
        }
        else if (strcmp(ret, "0") == 0)
        {
            if (recv(clientfd, value, sizeof(value), 0) < 0)
                printf("recv value error\n");
            printf("The value of your key is %s.\n", value);
            //printf("%s\n");
        }
        else if (strcmp(ret, "1") == 0)
        {
            printf("The key is not in the database.\n");
        }
        else if (strcmp(ret, "2") == 0)
        {
            printf("Your key has been deleted.\n");
        }
        else if (strcmp(ret, "3") == 0)
        {
            printf("The key is not exist.\n");
        }
        else if (strcmp(ret, "4") == 0)
        {
            printf("Your key has been stored.\n");
        }
        else if (strcmp(ret, "5") == 0)
        {
            printf("The key has already been in the database.\n");
        }
    }

    close(clientfd);

    return 0;
}
