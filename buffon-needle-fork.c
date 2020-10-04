#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>

const double PI = 3.14159265359;

int main()
{
    double length = 0.8;
    int N = 15;
    pid_t pid = fork();

    FILE *file;
    file = fopen("resultado.txt", "w");
    fprintf(file, "n\tapprox\t\tapprox-pi\n");

    int c = 0;
    if (pid == -1)
    {
        perror("Deu ruim!");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        for (int i = 0; i < N; i++)
        {

            double x = rand() % RAND_MAX;
            double y = 40 * rand() % RAND_MAX;
            double a = PI * rand() / RAND_MAX - 1.57;

            double x1 = x - (length / 2) * cos(a);
            double x2 = y + (length / 2) * sin(a);

            if (x1 * x2 <= 0)
            {
                c++;
            }

            double pi = 2 * length * (i + 1) / c;
            fprintf(file, "%d\t%f\t%f\n", i, pi, pi - PI);
        }

        fclose(file);

        double pi = 2 * length * N / c;

        printf("\n------------------------Resultado------------------------\n\n");
        printf("Aproximação com simulação:\npi = %f\n\n", pi);
        printf("Resultado exato:\npi = %f\n\n", PI);

        return 0;
    }
}
