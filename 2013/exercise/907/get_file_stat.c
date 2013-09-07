#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char **argv)
{
//dev_t     st_dev;     /* ID of device containing file */
//ino_t     st_ino;     /* inode number */
//mode_t    st_mode;    /* protection */
//nlink_t   st_nlink;   /* number of hard links */
//uid_t     st_uid;     /* user ID of owner */
//gid_t     st_gid;     /* group ID of owner */
//dev_t     st_rdev;    /* device ID (if special file) */
//off_t     st_size;    /* total size, in bytes */
//blksize_t st_blksize; /* blocksize for filesystem I/O */
//blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
//time_t    st_atime;   /* time of last access */
//time_t    st_mtime;   /* time of last modification */
//time_t    st_ctime;   /* time of last status change */

  struct stat buf;

  if(argc < 2)
    {
      printf("the must most argc,the current argc is %d\n",argc);
      exit(1);
    }
  stat(argv[1],&buf);
  printf("uid %d gid %d\n", buf.st_uid, buf.st_gid);
  printf("blksize %d blocks %d\n", buf.st_blksize, buf.st_blocks);
  printf("file[%s] size is %d the dev %d \n", argv[1],buf.st_size,buf.st_dev );
  printf("inode number %d\n",buf.st_ino);
  printf("protection %d\n",buf.st_mode);
  printf("number of hard links %d\n",buf.st_nlink);
  return 0;
}

