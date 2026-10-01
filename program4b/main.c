#include <stdio.h>
#include <stdlib.h>
void toh(int n,char source,char dest,char temp)
{
    if (n>1)
    {
        toh(n-1,source, temp,dest);
        printf("\n move %d disc from %c to %c",n,source,dest);
        toh(n-1,temp,dest,source);
    }
    else
        printf("\n move %d disc from %c to %c",n,source,dest);
}
int main()
{
    int n;
    printf("\nRead number of discs:");
    scanf("%d",&n);
    toh(n,'S','D','T');
    return 0;
}
