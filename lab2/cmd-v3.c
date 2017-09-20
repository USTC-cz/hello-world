#include<stdio.h>
#include<string.h>
#include<stdbool.h>

enum cmdtpye {help,compare,oppnum,PI,hello,add,exit};
const char *cmds[] = { "help","compare","oppnum","PI","hello","add","exit" };


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
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
}
void oppnum()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",-a);	
}
void compare()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b)
	printf("%d<%d\n",a,b);
    else if(a==b)
	printf("%d=%d\n",a,b);
    else if(a>b)
	printf("%d>%d\n",a,b);
}
void PI()
{
    printf("3.14\n");
}

			
			
int main(void)
{
	char choice[128];
	enum cmdtype cmd;
	bool cmd_is_found=false;

	while (1)
	{
		for (cmd = help; cmd <= exit; cmd++)
		{
			if (strcmp(choice, cmds[cmd]) == 0)
			{
				cmd_is_found = true;
				break;
			}
		}
		if (cmd_is_found)
			switch (cmd)
			{
			case help: help();
				break;
			case compare:compare();
				break;
			case oppnum:oppnum();
				break;
			case PI:PI();
				break;
			case hello:hello();
				break;
			case add:add();
				break;
			case exit:exit(0);
				break;
			}
		else
			printf("commond not found\n");
		cmd_is_found = false;
		
	}
	

	return 0;
}
