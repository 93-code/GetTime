/* 09:52 2015-04-14 Tuesday */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>

int Count_line(FILE *fp)
{
    int count = 0;
    char buf[1024];

    while (fgets(buf,sizeof(buf),fp) != NULL)
    {
        if (buf[strlen(buf)-1] == '\n')
            count++;
    }
    return count;
}

GetTime(struct tm *ptm)
{


}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,"Usage : %s filename\n",argv[0]);
        return -1;
    }

    FILE *fp;
    int count;
    time_t t;
    struct tm *Tm;

    fp = fopen(argv[1],"a+");
    if (fp == NULL)
    {
        printf("Fail to open %s : %s\n",argv[1],strerror(errno));
        return -1;
    }

    count = Count_line(fp);
   while (1)
    {
    t = time(NULL);
    Tm = localtime(&t);
        fprintf(fp,"%d: %d-%d-%d %d:%d:%d\n",count,Tm->tm_year+1900,Tm->tm_mon+1,Tm->tm_mday,Tm->tm_hour,Tm->tm_min,Tm->tm_sec);
        sleep(1);
        fflush(fp);
        count++;
    }

    fclose(fp);
    return 0;
}



