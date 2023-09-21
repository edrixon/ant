#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../remoterx/cmd.h"
#include "../client/client.h"

int main(int argc, char *argv[])
{
    int sock;
    unsigned char msg[16];
    int msgLength;
    int c;
    int rtn;

    if(argc > 2)
    {
        rtn = -1;
    }
    else
    {

        rtn = 0;
        if(argc == 1)
        {
            msg[2] = '?';
        }
        else
        {
            if(strcmp(argv[1], "a") == 0)
            {
                msg[2] = 'A';
            }
            else
            {
                if(strcmp(argv[1], "b") == 0)
                {
                    msg[2] = 'B';
                }
                else
                {
                    rtn = -1;
                }
            }
        }
    }

    if(rtn == -1)
    {
        printf("ant [new selection]\n");
        return rtn;
    }

    msg[0] = 2;
    msg[1] = 'A';

    sock = clientConnect();
    clientSend(sock, msg);
    msgLength = clientReceive(sock, msg);
    clientDisconnect(sock);

    printf("Antenna %c selected\n", msg[2]);

    return 0;
}
