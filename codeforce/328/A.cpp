#include <cstdio>
int main(int argc, char const *argv[])
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int x = b-a;
    if(x==c-b&&x==d-c){
        printf("%d\n",d+x);
    }else{
        if(b*b == a*c && c*c == b*d){
            if( (d*d)%c == 0)
                printf("%d\n",d*d/c );
            else
                printf("42\n");
        }
        else{
            printf("42\n");
        }
    }
    return 0;
}