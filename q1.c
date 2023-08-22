#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
	int ret;
	struct stat buf;
	ret=stat(argv[1],&buf);
	if(ret)
	{
		perror("error404");
		return 1;
	}

	chdir(argv[1]);
	printf("the inode number of the file/directory is %ld",buf.st_ino);
	return 0;
}