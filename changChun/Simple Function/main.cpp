#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int T, A, B, C, D, E;
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
        if(B-A*D == 0)
        {
            if(C-A*E > 0)
            {
                double a = E - (double)D*D/4;
                double b = (C-A*E)/a;
                if(a<0)
                {
                    printf("(-INF, %.4lf] U (%.4lf, INF)\n", A+b, double(A));
                }
                else if(a == 0)
                {
                    printf("(%.4lf, INF)\n", double(A));
                }
                else
                {
                    printf("(%.4lf, %.4lf]", double(A), b);
                }
            }
            else if(C-A*E < 0)
            {
                double a = E - (double)D*D/4;
                double b = (C-A*E)/a;
                if(a<0)
                {
                    printf("(-INF, %.4lf] U (%.4lf, INF)\n", double(A), A+b);
                }
                else if(a == 0)
                {
                    printf("(-INF, %.4lf)\n", double(A));
                }
                else
                {
                    printf("[%.4lf, %.4lf)\n", b+A, double(A));
                }
            }
            else
            {
                printf("[%.4lf, %.4lf]\n", double(A), double(A));
            }
        }
        else
        {
            double m = double(C-A*E)/(B-A*D);
            double n = double(E)-m*(D-m);
            double r1, r2;
            if(n>0)
            {
                r1 = -2*sqrt(n)+D-2*m, r2 = 2*sqrt(n)+D-2*m;
            }
            else if(n == 0)
            {
                printf("[%.4lf, %.4lf]", double(A)+(B-A*D)/(D-2*m), double(A)+(B-A*D)/(D-2*m));
                continue;
            }
            else
            {
                r1 = -2*sqrt(-1*n)+D-2*m, r2 =2*sqrt(-1*n)+D-2*m;
            }
            if(B-A*D > 0)
            {

                if(r2 < 0)
                {
                    printf("(-INF, %.4lf] U [%.4lf, %.4lf) U (%.4lf, INF)\n", (B-A*D)/(r2)+A, r1+A, double(A), double(A));
                }
                else if(r2 == 0)
                {
                    printf("[%.4lf, %.4lf) U (%.4lf, INF]\n", A+(B-A*D)/r1, double(A),double(A));
                }
                else
                {
                    if(r1<0)
                    {
                        printf("[%.4lf, %.4lf) U (%.4lf, %.4lf]\n", (B-A*D)/r1+A, double(A), double(A), A+(B-A*D)/r2);
                    }
                    else if( r1 == 0)
                    {
                        printf("[-INF, %.4lf) U (%.4lf, %.4lf]\n", double(A), double(A), A+(B-A*D)/r2);
                    }
                    else
                    {
                        printf("(-INF, %.4lf) U (%.4lf, %.4lf] U [%.4lf, INF)\n", double(A), double(A), A+(B-A*D)/r2, A+(B-A*D)/r1);
                    }
                }
            }
            else
            {

                if(r2 < 0)
                {
                    printf("(-INF,%.4lf) U (%.4lf, %.4lf] U [%.4lf, INF)\n", double(A), double(A),(B-A*D)/r1+A,(B-A*D)/r2+A);
                }
                else if(r2 == 0)
                {
                    printf("(-INF,%.4lf) U (%.4lf, %.4lf]\n", double(A), double(A),(B-A*D)/r1);
                }
                else
                {
                    if(r1<0)
                    {
                        printf("[%.4lf, %.4lf) U (%.4lf, %.4lf]\n", (B-A*D)/r2+A, double(A), double(A), A+(B-A*D)/r1);
                    }
                    else if( r1 == 0)
                    {
                        printf("[%.4lf, %.4lf) U (%.4lf, INF)\n", (B-A*D)/r2+A, double(A), double(A));
                    }
                    else
                    {
                        printf("(-INF, %.4lf] U [%.4lf, %.4lf) U [%.4lf, INF)\n", (B-A*D)/r1+A,(B-A*D)/r2+A,double(A), double(A));
                    }
                }
            }
        }
    }
    return 0;
}
