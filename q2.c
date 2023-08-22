#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>


int main(int argc,char *argv[])
{
	int ret;
	DIR *d;
	d=opendir(argv[1]);
	if(d==NULL)
	{
		perror("error");
		exit(1);
	}
	struct dirent *entry=readdir(d);
	struct stat buf;
	
	chdir(argv[1]);

	while(entry!=NULL)
	{
		if(strcmp(entry->d_name,argv[2])==0)
		{
			ret=stat(argv[2],&buf);
			if(ret)
			{
				perror("error404");
				return 1;
			}

			printf("%s",entry->d_name);
			printf("\nthe inode number of the file/directory is %ld \n",buf.st_ino);
			printf("\nthe id of the file/directory is %ld \n",buf.st_dev);
			printf("\nthe perm of the file/directory is %d",buf.st_mode);
			printf("\nthe  number of the hardlinks of file/directory is %d \n ",buf.st_nlink);
			printf("\nthe user id of the owner  of the file/directory is %d \n ",buf.st_uid);
			printf("\nthe grp id of the owner of the file/directory is %d\n ",buf.st_gid);
			printf("\nthe device id  of the file/directory is %ld\n",buf.st_rdev);
			printf("\nthe size  of the file/directory is %ld\n",buf.st_size);
		}

		entry=readdir(d);
		
	}

	
	
	return 0;
}