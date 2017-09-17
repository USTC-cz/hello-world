#include<stdio.h>
#include<math.h>
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
	printf("%d%d",a+b);
}
int main()
{
    char cmd[128];
    while(1)
    {
        scanf("%s",cmd);
	if(strcmp(cmd,"help")==0)
	    help();
	else if(strcmp(cmd,"abs")==0)
	    abs();
        else if(strcmp(cmd,"pow")==0)
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
}
