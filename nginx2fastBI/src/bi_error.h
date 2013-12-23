/* 
 *fastBI error file
 */
#ifndef _BI_ERROR_H_
#define _BI_ERROR_H_

typedef int             bi_err_t
#define BI_EPERM        EPERM	/* Operation not permitted */
#define BI_ENOENT       ENOENT	/* No such file or directory */
#define BI_ESRCH        ESRCH	/* No such process  */
#define BI_EINTR        EINTR	/* Interrupted system call */
#define BI_ECHILD       ECHILD	/* No child processes */
#define BI_ENOMEM       ENOMEM
#define BI_EACCESS      EACCESS
#define BI_EBUSY        EBUSY
#define BI_EEXIST       EEXIST
#define BI_EXDEV        EXDEV
#define BI_ENOTDIR      ENOTDIR
#define BI_EISDIR       EISDIR
#define BI_EINVAL       EINVAL
#define BI_ENOSPC       ENOSPC
#define BI_EPIPE        EPIPE
#define BI_EAGAIN       EAGAIN
#define BI_EINPROGRESS  EINPROGRESS /* in progress */
#define BI_EADDRINUSE   EADDRINUSE /* address in use */
#define BI_ECONNABORTED ECONNABORTED /* connection aborted */
#define BI_ECONNRESET   ECONNRESET   /* connection reset */
#define BI_ENOTCONN     ENOTCONN     /* not connection */
#define BI_ETIMEDOUT    ETIMEDOUT    /* timed out */
#define BI_ECONNREFUSED ECONNREFUSED /* connection ref used */


#endif


