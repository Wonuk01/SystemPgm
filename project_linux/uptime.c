#include <stdio.h>

int main() {

    FILE *fp = fopen("/proc/uptime", "r");

    if (!fp) {
        perror("uptime");
        return 1;
    }

    double seconds;

    fscanf(fp, "%lf", &seconds);

    fclose(fp);

    int hours = (int)seconds / 3600;
    int minutes = ((int)seconds % 3600) / 60;
    int secs = (int)seconds % 60;

    printf("Uptime: %d hours %d minutes %d seconds\n",
           hours, minutes, secs);

    return 0;
}