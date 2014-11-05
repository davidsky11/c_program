/*
 * =====================================================================================
 *
 *       Filename:  work.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/04/2014 08:55:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "work.h"
#include "config.h"

char *rootdir = "/";				/* 初始页 */

#ifdef DEBUG
char *port = "12121";
char *host = "10.203.138.100";
#endif

/*
 * 回退至上级目录
 */
char
*dir_up(char *dirpath)
{
	static char path[MAXLINE];
	char *end;
	int len = 0;
	strcpy(path, dirpath);
	if (strcmp(dirpath, "/") == 0)	/* 比对dirpath 与 '/' */				
	  return path;
	if (len > 1)
	{
		while ((path[len-1] == '/'))
		{
			path[len-1] = '\0';
			len --;
		}
		end = (strrchr(path, '/'));	/* 返回最后一个'/'的位置 */
		*end = '\0';
	}
	if (path - end == 0)
	{
		path[0] = '/';
		path[1] = '\0';
		return path;
	}
	return path;
}

void
serve_machine(int *connfd)
{
	char buf[MAXLINE], query[MAXLINE+1];
	ssize_t n;
	n = recv(*connfd, buf, sizeof(buf), 0);			/* 读取客户端指令 */
	sscanf(buf, "GET %s HTTP", query);
	if (n <= 0)
	{
		close(*connfd);
		return;
	}
	FILE *file;
	file = fdopen(*connfd, "w");
	send_to_server(file, query);
	close(*connfd);
}

void 
send_to_server(FILE *client_sock, char *path)
{
	struct dirent *dirent;
	struct stat info;
	char filename[MAXLINE];
	DIR *dir;
	int fd, len, ret;
	int space = 1023, nread = 0;
	char *p, *realpath, *realfilename, *nport;
	len = strlen(rootdir) + strlen(path) + 1;
	realpath = malloc(len + 1);
	bzero(realpath, sizeof(realpath));
	sprintf(realpath, "%s/%s", rootdir, path);
	len = strlen(port) + 1;
	nport = malloc(len + 1);
	bzero(nport, sizeof(nport));
	sprintf(nport, ":%s", port);
	if (stat(realpath, &info)) {  
		printf("%s\n", realpath);
        fprintf(client_sock,  
                "HTTP/1.1 200 OK\r\nServer: DAS by renzhenwen\r\nConnection: close\r\n\r\n<html><head><title>%d - %s</title></head>"  
                "<body><font size=+4>基于Linux线程池的目录访问服务器</font><br><hr width=\"100%%\"><br><center>"  
                "<table border cols=3 width=\"100%%\">", errno,strerror(errno));  
        fprintf(client_sock,  
                "</table><font color=\"CC0000\" size=+2>不能获取当前信息：\n%s %s</font></body></html>", path, strerror(errno));  
        goto out;  
    }  
    if (S_ISREG(info.st_mode)) {  
        fd = open(realpath, O_RDONLY);  
        len = lseek(fd, 0, SEEK_END);  
                nread = 0;  
        fprintf(client_sock,  
                "HTTP/1.1 200 OK\r\nServer: DAS by renzhenwen\r\nConnection: keep-alive\r\nContent-type: application/*\r\nContent-Length:%d\r\n\r\n", len);  
                p = (char *) malloc(space + 1);  
        while ( len > 0 ) {       /*单缓冲读取文件*/  
            bzero(p, space + 1);  
            lseek(fd, nread, SEEK_SET);  
            ret = read(fd, p, space);  
            fwrite(p, ret, 1, client_sock);  
            len -= ret;  
            nread += ret;   
      }  
      free(p);  
      close(fd);  
    } else if (S_ISDIR(info.st_mode)) {  
        dir = opendir(realpath);  
        fprintf(client_sock,  
                "HTTP/1.1 200 OK\r\nServer: DAS by renzhenwen\r\nConnection: close\r\n\r\n<html><head><title>%s</title></head>"  
                "<body><font size=+4>基于Linux线程池的目录访问服务器</font><br><hr width=\"100%%\"><br><center>"  
                "<table border cols=3 width=\"100%%\">", path);  
        fprintf(client_sock,  
                "<caption><font size=+3>目录 %s</font></caption>\n", path);  
        fprintf(client_sock,  
                "<tr><td>名称</td><td>大小</td><td>修改时间</td></tr>\n");  
        if (dir == 0) {  
            fprintf(client_sock,  
                    "</table><font color=\"CC0000\" size=+2>%s</font></body></html>", strerror(errno));  
            return;  
        }  
        while ((dirent = readdir(dir)) != 0) {  
            if (strcmp(path, "/") == 0)  
                sprintf(filename, "/%s", dirent->d_name);  
            else  
                sprintf(filename, "%s/%s", path, dirent->d_name);  
            fprintf(client_sock, "<tr>");  
            len = strlen(rootdir) + strlen(filename) + 1;  
            realfilename = malloc(len + 1);  
            bzero(realfilename, len + 1);  
            sprintf(realfilename, "%s/%s", rootdir, filename);  
            if (stat(realfilename, &info) == 0) {  
                if (strcmp(dirent->d_name, "..") == 0)  
                    fprintf(client_sock,  
                            "<td><a href=\"http://%s%s%s\">(parent)</a></td>",  
                            host, atoi(port) == 80 ? "" : nport,  
                            dir_up(path));  
                else  
                    fprintf(client_sock,  
                            "<td><a href=\"http://%s%s%s\">%s</a></td>",  
                            host, atoi(port) == 80 ? "" : nport, filename,dirent->d_name);  
                if (S_ISDIR(info.st_mode))  
                    fprintf(client_sock, "<td>目录</td>");  
                else if (S_ISREG(info.st_mode))  
                    fprintf(client_sock, "<td>%d</td>", (int) info.st_size);  
                else if (S_ISLNK(info.st_mode))  
                    fprintf(client_sock, "<td>链接</td>");  
                else if (S_ISCHR(info.st_mode))  
                    fprintf(client_sock, "<td>字符设备</td>");  
                else if (S_ISBLK(info.st_mode))  
                    fprintf(client_sock, "<td>块设备</td>");  
                else if (S_ISFIFO(info.st_mode))  
                    fprintf(client_sock, "<td>FIFO</td>");  
                else if (S_ISSOCK(info.st_mode))  
                    fprintf(client_sock, "<td>Socket</td>");  
                else  
                    fprintf(client_sock, "<td>(未知)</td>");  
                fprintf(client_sock, "<td>%s</td>", ctime(&info.st_ctime));  
            }  
            fprintf(client_sock, "</tr>\n");  
            free(realfilename);  
        }  
        fprintf(client_sock, "</table></center></body></html>");  
    } else {  
        fprintf(client_sock,  
                "HTTP/1.1 200 OK\r\nServer: DAS by renzhenwen\r\nConnection: close\r\n\r\n<html><head><title>permission denied</title></head>"  
                "<body><font size=+4>基于Linux线程池的目录访问服务器</font><br><hr width=\"100%%\"><br><center>"  
                "<table border cols=3 width=\"100%%\">");  
        fprintf(client_sock,  
                "</table><font color=\"CC0000\" size=+2>你访问的资源'%s'被禁止访问，请联系管理员解决！</font></body></html>",path);  
    }  
  out:  
    free(realpath);  
    free(nport);  
}

#ifdef DEBUG
int main() 
{
	return 0; 
}
#endif
