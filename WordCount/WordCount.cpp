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
	file = fopen("input.txt","r");//���ļ� 
	if (file == NULL)
	{
		printf("�ļ�Ϊ��");
		return 0; 
	}
	Count(file,&charNum,&wordNum);
	if (strcmp(parameter,"-c") == 0 || strcmp(parameter,"-C") == 0)
	{
		printf("�ַ�����%d\n",charNum);
	}
	else if (strcmp(parameter,"-w") == 0 || strcmp(parameter,"-W") == 0)
	{
		printf("��������%d\n",wordNum);
	}
	fclose(file);
	system("pause");//����������н����Զ��ر����� 
	return 0;
}
//ͳ���ļ��ַ���������
int Count(FILE* file,int* charNum,int* wordNum)
{
	char temp;
	int flag = 0;
	while((temp = fgetc(file)) != EOF)//��������ļ���β����ִ���������� 
	{
		(*charNum)++;
		if (flag == 0 && (temp != ' ' || temp != ','))
		{
			(*wordNum)++;
			flag = 1;
		}
		else if(temp == ' ' || temp == ',')//�ÿո�Ͷ��Ÿ����Ķ���Ϊ���� 
		{
			flag = 0;
		}
	}
	return 0;
}
