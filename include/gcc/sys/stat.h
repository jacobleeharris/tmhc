#ifndef	_SYS_STAT_H
#define	_SYS_STAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <time.h>
#include <sys/types.h>

#ifdef __i386__
#ifdef __MSDOS__
#include "stat-dj.h"
#endif
#endif

/* dj's stat defines _STAT_H_ */
#ifndef _STAT_H_

/* It is intended that the layout of this structure not change when the
   sizes of any of the basic types change (short, int, long) [via a compile
   time option].  */

struct	stat
{
  dev_t		st_dev;
  ino_t		st_ino;
  mode_t	st_mode;
  nlink_t	st_nlink;
  uid_t		st_uid;
  gid_t		st_gid;
  dev_t		st_rdev;
  off_t		st_size;
  /* SysV/sco doesn't have the rest... But Solaris, eabi does.  */
#if defined(__svr4__) && !defined(__PPC__) && !defined(__sun__)
  time_t	st_atime;
  time_t	st_mtime;
  time_t	st_ctime;
#else
  time_t	st_atime;
  long		st_spare1;
  time_t	st_mtime;
  long		st_spare2;
  time_t	st_ctime;
  long		st_spare3;
  long		st_blksize;
  long		st_blocks;
  long	st_spare4[2];
#endif
};

#define	_IFMT		0170000	/* type of file */
#define		_IFDIR	0040000	/* directory */
#define		_IFCHR	0020000	/* character special */
#define		_IFBLK	0060000	/* block special */
#define		_IFREG	0100000	/* regular */
#define		_IFLNK	0120000	/* symbolic link */
#define		_IFSOCK	0140000	/* socket */
#define		_IFIFO	0010000	/* fifo */

#define 	S_BLKSIZE  1024 /* size of a block */

#define	S_ISUID		0004000	/* set user id on execution */
#define	S_ISGID		0002000	/* set group id on execution */
#ifndef	_POSIX_SOURCE
#define	S_ISVTX		0001000	/* save swapped text even after use */
#define	S_IREAD		0000400	/* read permission, owner */
#define	S_IWRITE 	0000200	/* write permission, owner */
#define	S_IEXEC		0000100	/* execute/search permission, owner */

#define	S_ENFMT 	0002000	/* enforcement-mode locking */

#define	S_IFMT		_IFMT
#define	S_IFDIR		_IFDIR
#define	S_IFCHR		_IFCHR
#define	S_IFBLK		_IFBLK
#define	S_IFREG		_IFREG
#define	S_IFLNK		_IFLNK
#define	S_IFSOCK	_IFSOCK
#define	S_IFIFO		_IFIFO
#endif	/* !_POSIX_SOURCE */

#ifdef _WIN32
/* The Windows header files define _S_ forms of these, so we do too
   for easier portability.  */
#define _S_IFMT		_IFMT
#define _S_IFDIR	_IFDIR
#define _S_IFCHR	_IFCHR
#define _S_IFIFO	_IFIFO
#define _S_IFREG	_IFREG
#define _S_IREAD	0000400
#define _S_IWRITE	0000200
#define _S_IEXEC	0000100
#endif

#define	S_IRWXU 	0000700	/* rwx, owner */
#define		S_IRUSR	0000400	/* read permission, owner */
#define		S_IWUSR	0000200	/* write permission, owner */
#define		S_IXUSR	0000100	/* execute/search permission, owner */
#define	S_IRWXG		0000070	/* rwx, group */
#define		S_IRGRP	0000040	/* read permission, group */
#define		S_IWGRP	0000020	/* write permission, grougroup */
#define		S_IXGRP	0000010	/* execute/search permission, group */
#define	S_IRWXO		0000007	/* rwx, other */
#define		S_IROTH	0000004	/* read permission, other */
#define		S_IWOTH	0000002	/* write permission, other */
#define		S_IXOTH	0000001	/* execute/search permission, other */

#define	S_ISBLK(m)	(((m)&_IFMT) == _IFBLK)
#define	S_ISCHR(m)	(((m)&_IFMT) == _IFCHR)
#define	S_ISDIR(m)	(((m)&_IFMT) == _IFDIR)
#define	S_ISFIFO(m)	(((m)&_IFMT) == _IFIFO)
#define	S_ISREG(m)	(((m)&_IFMT) == _IFREG)
#define	S_ISLNK(m)	(((m)&_IFMT) == _IFLNK)
#define	S_ISSOCK(m)	(((m)&_IFMT) == _IFSOCK)


int	_EXFUN(chmod,( const char *__path, mode_t __mode ));
int     _EXFUN(fchmod,(int __fd, mode_t __mode));
int	_EXFUN(fstat,( int __fd, struct stat *__sbuf ));
int	_EXFUN(mkdir,( const char *_path, mode_t __mode ));
int	_EXFUN(mkfifo,( char *__path, mode_t __mode ));
int	_EXFUN(stat,( const char *__path, struct stat *__sbuf ));
mode_t	_EXFUN(umask,( mode_t __mask ));

/* Provide prototypes for most of the _<systemcall> names that are
   provided in newlib for some compilers.  */
int	_EXFUN(_fstat,( int __fd, struct stat *__sbuf ));
int	_EXFUN(_stat,( const char *__path, struct stat *__sbuf ));

#ifdef __CYGWIN32__
int	_EXFUN(lstat,( const char *__path, struct stat *__buf ));
#endif

#endif /* !_STAT_H_ */
#ifdef __cplusplus
}
#endif
#endif /* _SYS_STAT_H */
