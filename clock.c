#include <stdio.h>
#include <time.h>
#include <windows.h>
#define BUF_LEN 256
#define WINVER 0x0500
int main()
{
    HWND wh = GetConsoleWindow();
    MoveWindow(wh, 500, 200, 230, 120, TRUE);
    while(1)
    {
        char buf[BUF_LEN] = {0};
        system("color 0A");
        system("cls");
        time_t s;
        struct tm* current_time;
        time_t rawtime = time(NULL);
        struct tm *ptm = localtime(&rawtime);
        s = time(NULL);
        current_time = localtime(&s);
        if(current_time->tm_hour >12)
        {
            printf("\n\t");
            printf("%02d:%02d:%02d PM",
                   current_time->tm_hour-12,
                   current_time->tm_min,
                   current_time->tm_sec);
            printf("\n\t");
            strftime(buf, BUF_LEN, "(%A)", ptm);
            puts(buf);
            printf("\t");
            strftime(buf, BUF_LEN, "%d.%m.%Y", ptm);
            puts(buf);
        }
        else
        {
            printf("\n\t");
            printf("%02d:%02d:%02d AM",
                   current_time->tm_hour,
                   current_time->tm_min,
                   current_time->tm_sec);
            printf("\n\t");
            strftime(buf, BUF_LEN, "(%A)", ptm);
            puts(buf);
            printf("\t");
            strftime(buf, BUF_LEN, "%d.%m.%Y", ptm);
            puts(buf);
        }
        sleep(1);
    }
    return 0;
}
