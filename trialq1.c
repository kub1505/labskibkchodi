#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
	int ret;

	DIR *d;
	
	d=opendir(argv[1]);
	if(d==NULL)
		{
			printf("directory not found");
			exit(1);
		}
	chdir(argv[1]);
	struct stat buf;
	struct dirent *entry=readdir(d);
	while(entry!=NULL)
	{
		stat(entry->d_name,&buf);
		printf("the inode number of %s is .. %ld \n",entry->d_name,buf.st_ino);
		entry=readdir(d);

	}
	

	return  0;
}