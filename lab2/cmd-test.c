//版本二存在一点问题
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

enum cmdtype {help,compare,oppnum,PI,hello,add,quit};
const char *cmds[] = { "help","compare","oppnum","PI","hello","add","quit" };


void helpf()
{
    printf("enter help [-commandname] for details\n");
}
void hellof()
{
    printf("hello,user\n");
}
void addf()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
}
void oppnumf()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",-a);	
}
void comparef()
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
void PIf()
{
    printf("3.14\n");
}

			
			
int main(void)
{
	char choice[128];
	enum cmdtype cmd;
	bool cmd_is_found=false;

	while (gets(choice)!=NULL)
	{
		for (cmd = help; cmd <= quit; cmd++)
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
			case help: helpf();
				break;
			case compare:comparef();
				break;
			case oppnum:oppnumf();
				break;
			case PI:PIf();
				break;
			case hello:hellof();
				break;
			case add:addf();
				break;
			case quit:exit(0);
				break;
			}
		else
			printf("commond not found\n");
		cmd_is_found = false;
		
	}
	

	return 0;
}
