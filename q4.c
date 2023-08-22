#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>


int main()
{
	int ret=symlink("./softlink.txt","./link1.txt");
	if(ret<0)
	{
		perror("error");
		exit(1);
	}

	unlink("./link1.txt");
	return 0;
}