#include <stdio.h>
#include<string.h> 
void CharCount()//ͳ���ַ���
{
	FILE *fp;
	int charCount = 0;
	char ch;//��ȡ�ļ����ص��ֽ�
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��.");
	}
	ch = fgetc(fp);
	while (ch != c)
	{
		charCount++;
		ch = fgetc(fp);
	}
	printf("�ַ���Ϊ��%d��.\n", charCount);
	fclose(fp);
}
void WordCount()//ͳ�Ƶ�����
{
	FILE *fp;
	int wordCount = 0, flag = 0;
	char ch;//��ȡ�ļ����ص��ֽ�
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��.");
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
	printf("������Ϊ��%d��.\n", wordCount);
	fclose(fp);
}
int main(int argc, char *argv[])
{
	if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "test.txt") == 0))//ͳ�Ƶ�����
	{
		WordCount();
	}
	if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "test.txt") == 0))//ͳ���ַ���
	{
		CharCount();
	}
	return 0;
} 
