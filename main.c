#include "libasm.h"

int		main(void)
{
	char	*s0 = "";
	char	*s10 = "1234567890";
	char	*s100 = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";

	printf("\n%s%17s%s\n", "\x1B[35m", "#ft_strlen#", _DEF_);
	printf("%s--------------------%s\n", "\x1B[35m", _DEF_);
	printf("%s%10s%s | %s%-10s%s\n", _GRN_, "orig",_DEF_, _YEL_, "my", _DEF_);
	printf("%10zu | %-10zu\n", strlen(s0), ft_strlen(s0));
	printf("%10zu | %-10zu\n", strlen(s10), ft_strlen(s10));
	printf("%10zu | %-10zu\n", strlen(s100), ft_strlen(s100));

	char	s1[500];
	char	s2[500];
	char	*s3 = "zzz";

	printf("\n%s%17s%s\n", "\x1B[35m", "#ft_strcpy#", _DEF_);
	printf("%s--------------------%s\n", "\x1B[35m", _DEF_);
	printf("%s%10s%s | %s%-10s%s\n", _GRN_, "orig",_DEF_, _YEL_, "my", _DEF_);
	printf("%10s | %-10s\n", strcpy(s1, ""), ft_strcpy(s2, ""));
	printf("%10s | %-10s\n", strcpy(s1, s3), ft_strcpy(s2, s3));
	printf("%10s | %-10s\n", strcpy(s1, s10), ft_strcpy(s2, s10));
	printf("%s%-5s%s%s\n%s%-5s%s%s\n", _GRN_, "orig",_DEF_, strcpy(s1, s100), _YEL_, "my", _DEF_, ft_strcpy(s2, s100));
	
	printf("\n%s%17s%s\n", "\x1B[35m", "#ft_strcmp#", _DEF_);
	printf("%s--------------------%s\n", "\x1B[35m", _DEF_);
	printf("%s%10s%s | %s%-10s%s\n", _GRN_, "orig",_DEF_, _YEL_, "my", _DEF_);
	printf("%10d | %-10d\n", strcmp(s10, s100), ft_strcmp(s10, s100));
	printf("%10d | %-10d\n", strcmp(s3, s100), ft_strcmp(s3, s100));
	printf("%10d | %-10d\n", strcmp(s3, ""), ft_strcmp(s3, ""));
	printf("%10d | %-10d\n", strcmp("", ""), ft_strcmp("", ""));

	char	*des1;
	char	*des2;

	printf("\n%s%17s%s\n", "\x1B[35m", "#ft_strdub#", _DEF_);
	printf("%s--------------------%s\n", "\x1B[35m", _DEF_);
	printf("%s%10s%s | %s%-10s%s\n", _GRN_, "orig",_DEF_, _YEL_, "my", _DEF_);
	des1 = strdup("");
	des2 = ft_strdup("");
	printf("%10s | ", des1);
	printf("%-10s\n", des2);
	free(des1);
	free(des2);
	des1 = strdup(s3);
	des2 = ft_strdup(s3);
	printf("%10s | ", des1);
	printf("%-10s\n", des2);
	free(des1);
	free(des2);
	des1 = strdup(s100);
	des2 = ft_strdup(s100);
	printf("%s%-5s%s%s\n", _GRN_, "orig",_DEF_, des1);
	printf("%s%-5s%s%s\n",  _YEL_, "my", _DEF_, des2);
	free(des1);
	free(des2);

	printf("\n%s%15s%s\n", "\x1B[35m", "#ft_write#", _DEF_);
	printf("%s--------------------%s\n", "\x1B[35m", _DEF_);
	printf("%s %s%s\n", _GRN_, "wrong fd orig (nothing)",_DEF_);
	write(-1, "hi\n", 3);
	printf("%s %s%s\n",  _YEL_, "wrong fd   my (nothing)", _DEF_);
	ft_write(-1, "hi\n", 3);
	printf("%s %s%s\n", _GRN_, "orig",_DEF_);
	write(1, "hi\n", 3);
	printf("%s %s%s\n",  _YEL_, "my", _DEF_);
	ft_write(1, "hi\n", 3);
	printf("%s %s%s\n", _GRN_, "orig",_DEF_);
	write(1, "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n", 101);
	printf("%s %s%s\n",  _YEL_, "my", _DEF_);
	ft_write(1, "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n", 101);
	int		fd;

	fd = open("test.txt", O_RDWR);
	write(fd, "The ", 4);
	ft_write(fd, "Ball\n", 5);
	close(fd);
	printf("%stest.txt has been modified%s\n", _GRN_, _DEF_);

	printf("\n%s%15s%s\n", "\x1B[35m", "#ft_read#", _DEF_);
	printf("%s--------------------%s\n", "\x1B[35m", _DEF_);
	char	line[300];

	fd = open("test.txt", O_RDONLY);
	read(fd, line, 9);
	printf("%s%s%s",  _GRN_, line, _DEF_);
	ft_read(fd, line, 32);
	printf("%s%s%s",  _YEL_, line, _DEF_);
	read(fd, line, 34);
	printf("%s%s%s",  _GRN_, line, _DEF_);
	ft_read(fd, line, 40);
	printf("%s%s%s",  _YEL_, line, _DEF_);
	line[36] = '\0';
	read(fd, line, 37);
	printf("%s%s%s\n",  _GRN_, line, _DEF_);
	

	return (0);
}