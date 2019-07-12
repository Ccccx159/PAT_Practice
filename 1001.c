#include <stdio.h>
#include <stdlib.h>
int main()
{
    int cnt=0, x=0;
    scanf("%d", &x);
    while(x > 1)
    {
        if (0 == x%2){
            x=x/2;
            cnt++;
        }
        else{
            x=(3*x+1)/2;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    system("pause");
    return 0;
}