#include<stdio.h>
#include<string.h>

int i,j,n,x,y,m,f[110000];
char a[110000];



int
main()
{
    gets(a);
    m=strlen(a);
    f[0]=0;
    for(i=1;i<m;i++)
    {
        if(a[i]==a[i-1]){
            f[i]=f[i-1]+1;
        }
        else{
            f[i]=f[i-1];
        }
    }

   scanf("%d",&n);
   while(n--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",f[y-1]-f[x-1]);
    }

    return 0;
}