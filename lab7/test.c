#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"

void Quit(int argc, char *argv[]);
void Version(int argc, char *argv[]);

void Quit(int argc, char *argv[])
{
  exit(0);
}

void Version(int argc, char *argv[])
{
  printf("version7.0\n");
}


int main(int argc,char* argv[])
{
  MenuConfig("version","Released Version 1.0(Menu program v7.0 inside)",NULL);
  MenuConfig("quit","Quit from Menu",Quit);
  ExecuteMenu();
}
