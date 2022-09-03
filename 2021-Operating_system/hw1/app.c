#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int req;

void check_req(char input[])
{
    if ( strncmp(input, "v", 1) == 0 )
        req = 1;
    else if ( strncmp(input, "c", 1) == 0 )
        req = 2;
    else if ( strncmp(input, "m", 1) == 0 )
        req = 3;
    else if ( strncmp(input, "t", 1) == 0 )
        req = 4;
    else if ( strncmp(input, "a", 1) == 0 )
        req = 5;
    else if ( strncmp(input, "e", 1) == 0 )
        req = 6;
}

int main()
{
    char input[10];
    printf("Which information do you want?\n"
           "Version(v),CPU(c),Memory(m),Time(t),All(a),Exit(e)?\n");

    while(scanf("%s", input))
    {
        check_req(input);
        if (req == 6)
            break;

        FILE *fp = fopen("/proc/my_info", "r");

        char buf[100] = {0x0};
        int c = 0;
        while( (fgets(buf, 100, fp) != NULL) )
        {
            c++;
            if (req == 1 && c >= 3 && c < 5)
            {
                if (c == 3)
                    printf("\nVersion: ");
                printf("%s", buf);
            }
            if (req == 2 && c >= 6 && c < 47)
            {
                if (c == 6)
                    printf("\nCPU information: \n");
                printf("%s", buf);
            }
            if (req == 3 && c >= 48 && c < 60)
            {
                if (c == 48)
                    printf("\nMemory information: \n");
                printf("%s", buf);
            }
            if (req == 4 && c >= 61)
            {
                if (c == 61)
                    printf("\nTime information: \n");
                printf("%s", buf);
            }
            if (req == 5)
                printf("%s", buf);
        }

        fclose(fp);

        printf("Which information do you want?\n"
               "Version(v),CPU(c),Memory(m),Time(t),All(a),Exit(e)?\n");
    }

    return 0;
}
