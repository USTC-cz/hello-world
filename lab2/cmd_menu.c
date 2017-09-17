#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void help()
{
    printf("enter help [-commandname] for details\n");
}
void hello()
{
    printf("hello,user\n");
}
void add()
{
    int a,b;
    scaf("%d %d".&a &b);
    printf("%d\n",a+b);
}
void oppnum()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",-a);	
}
void compare();
{
    int a,b;
    scanf("%d %d",&a &b);
    if(a<b)
	printf("a<b\n");
    else if(a=b)
	printf("a=b\n");
    else
	printf("a>b\n");
}


int main()
{
    char cmd[128];
    while(1)
    {
        scanf("%s",cmd);
	if(strcmp(cmd,"help")==0)
	    help();
	else if(strcmp(cmd,"compare")==0)
	    compare();
        else if(strcmp(cmd,"oppnum")==0)
	    oppnum();
	else if(strcmp(cmd,"time")==0)
	    time();
	else if(strcmp(cmd,"hello")==0)
	    hello();
	else if(strcmp(cmd,"add")==0)
	    add();	
	else if(strcmp(cmd,"exit")==0)
            exit(0); 
	else 
	    printf("commond not found\n");		  
     }
    return 0;
}
