#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void help()
{
    printf("enter help [-commandname] for details");
}
void hello()
{
    printf("hello,user");
}
void add()
{
    int a,b;
    printf("%d+%d",a,b);
}
void oppnum()
{
    int a;
    printf("%d",-a);	
}
void compare();
{
    int a,b;
    if(a<b)
	printf("a<b");
    else if(a=b)
	printf("a=b");
    else
	printf("a>b");
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
	    abs();
        else if(strcmp(cmd,"oppnum")==0)
	    pow();
	else if(strcmp(cmd,"time")==0)
	    time();
	else if(strcmp(cmd,"hello")==0)
	    hello();
	else if(strcmp(cmd,"add")==0)
	    add();	
	else if(strcmp(cmd,"exit")==0)
            exit(0); 
	else 
	    printf("commond not found");		  
     }
    return 0;
}
