#include <errno.h>
#include <sys/fcntl.h>
#include <pspstdio.h>

#ifdef __cplusplus
extern "C" {
#endif
int truncate(const char *path, off_t length);
#ifdef __cplusplus
}
#endif

/* __psp_descriptormap was an internal pspsdk symbol used to map a POSIX fd  */
/* back to its filename so we could call truncate() on the path instead --  */
/* it no longer exists in the modern pspsdk. Resizing an already-open file  */
/* handle isn't needed to boot/play; report "not supported" instead.        */
int ftruncate(int fd, off_t length)
{
	(void)fd;
	(void)length;
	errno = EINVAL;
	return -1;
}

