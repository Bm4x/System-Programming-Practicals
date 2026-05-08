/** ls1.c revised
 **   purpose  list contents of directory or directories
 **   action   if no args, use .  else list files in args
  **  file information.
 **/
#include	<stdio.h>
#include	<sys/types.h>
#include	<dirent.h>
#include <sys/stat.h> //  to allow stat to work

void do_ls(char []);

void show_stat_info(char *, struct stat *); // used for fileinfo.c

struct stat info; // my own buffer used file info

int main(int ac, char *av[])
{
	if ( ac == 1 )
		do_ls( "." );
	else
		while ( --ac ){
			printf("%s:\n", *++av );
			do_ls( *av );
		}
}

void do_ls( char dirname[] )
/*
 *	list files in directory called dirname
 */
{
	DIR		*dir_ptr;		/* the directory */
	struct dirent	*direntp;		/* each entry	 */

	if ( ( dir_ptr = opendir( dirname ) ) == NULL )
		fprintf(stderr,"ls1: cannot open %s\n", dirname);
	else
	{
		while ( ( direntp = readdir( dir_ptr ) ) != NULL ){
			printf("%s\n", direntp->d_name );
			printf("   inode: %lu\n", direntp->d_ino);  // prints inode for every file
		}
		closedir(dir_ptr);

		// own implementation
		if( stat(dirname, &info) != -1 ){
            show_stat_info(dirname, &info ); // av is passed into dirname so replaced it
        }
        else
            perror(dirname);  /* report stat() errors  */
	}
}

void show_stat_info(char *fname, struct stat *buf)
/*
 * displays some info from stat in a name=value format from fileinfo.c
 */
{
    printf("   mode: %o\n", buf->st_mode);         /* type + mode */
    printf("  links: %d\n", buf->st_nlink);        /* # links     */
    printf("   user: %d\n", buf->st_uid);          /* user id     */
    printf("  group: %d\n", buf->st_gid);          /* group id    */
    printf("   size: %d\n", buf->st_size);         /* file size   */
    printf("modtime: %d\n", buf->st_mtime);        /* modified    */
    printf("   name: %s\n", fname );               /* filename    */
}
