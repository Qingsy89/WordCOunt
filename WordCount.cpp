#include <stdio.h>
#include<string.h> 
void CharCount()//统计字符数
{
	FILE *fp;
	int charCount = 0;
	char ch;//读取文件返回的字节
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		printf("文件打开失败.");
	}
	ch = fgetc(fp);
	while (ch !=EOF )
	{
		charCount++;
		ch = fgetc(fp);
	}
	printf("字符数为：%d个.\n", charCount);
	fclose(fp);
}
void WordCount()//统计单词数
{
	FILE *fp;
	int wordCount = 0, flag = 0;
	char ch;//读取文件返回的字节
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		printf("文件打开失败.");
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == ' ')
		{
			flag = 0;
			ch = fgetc(fp);
		}
		else
		{
			if (flag == 0)
			{
				wordCount++;
				flag = 1;
			}
			ch = fgetc(fp);
		}
	}
	printf("单词数为：%d个.\n", wordCount);
	fclose(fp);
}
int main(int argc, char *argv[])
{
	if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "test.txt") == 0))//统计单词数
	{
		WordCount();
	}
	if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "test.txt") == 0))//统计字符数
	{
		CharCount();
	}
	return 0;
} 
