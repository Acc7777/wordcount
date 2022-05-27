#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Count(FILE* file,int* charNum,int* wordNum);
int main(int argc,char *argv[])
{
	int charNum = 0;
	int wordNum = 0;
	char parameter[100];
	char input_file_name[100];
	FILE* file;
	scanf("%s", &parameter);
	scanf("%s",&input_file_name);
	file = fopen("input.txt","r");//打开文件 
	if (file == NULL)
	{
		printf("文件为空");
		return 0; 
	}
	Count(file,&charNum,&wordNum);
	if (strcmp(parameter,"-c") == 0 || strcmp(parameter,"-C") == 0)
	{
		printf("字符数：%d\n",charNum);
	}
	else if (strcmp(parameter,"-w") == 0 || strcmp(parameter,"-W") == 0)
	{
		printf("单词数：%d\n",wordNum);
	}
	fclose(file);
	system("pause");//解决程序运行结束自动关闭问题 
	return 0;
}
//统计文件字符及单词数
int Count(FILE* file,int* charNum,int* wordNum)
{
	char temp;
	int flag = 0;
	while((temp = fgetc(file)) != EOF)//如果不是文件结尾，就执行下面程序段 
	{
		(*charNum)++;
		if (flag == 0 && (temp != ' ' || temp != ','))
		{
			(*wordNum)++;
			flag = 1;
		}
		else if(temp == ' ' || temp == ',')//用空格和逗号隔开的都视为单词 
		{
			flag = 0;
		}
	}
	return 0;
}
