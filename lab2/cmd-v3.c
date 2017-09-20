#include<stdio.h>
#include<string.h>
#include<stdbool.h>

enum spectrum {};
const char *colors[] = { " };

#define LEN 30

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
	char choice[LEN];
	enum spectrum color;
	bool color_is_found=false;

	puts("enter a color(empty line to quit)：");
	while (gets(choice) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch (color)
			{
			case red:puts("rose are red.");
				break;
			case orange:puts("poppies are orange.");
				break;
			case yellow:puts("sunflowers are yellow.");
				break;
			case green:puts("grass is green.");
				break;
			case blue:puts("bluebells are blue.");
				break;
			case violet:puts("violets are violet.");
				break;
			}
		else
			printf("dont't know the color %s.\n",choice);
		color_is_found = false;
		puts("next color,please(empty line to quit):");
	}
	puts("goodbey");

	return 0;
}
