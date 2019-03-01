#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
using namespace std;
#define BUFFSIZE 100
int _tmain(int argc,LPTSTR argv[])
{
	HANDLE hfile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2)
	{
		_tprintf(_T(" usage file"));
		getchar();
		return FALSE;
	}
	hfile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("creation of file is error(%ld)"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File is opened"),argv[1]);
	DWORD dwnbr;//no.of bytes read
	ZeroMemory(buffer, BUFFSIZE);
	BOOL ret = ReadFile(hfile, buffer, BUFFSIZE, &dwnbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("File doesnt exist Error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hfile);
	_tprintf(_T("contents of file(%s)(%S)\n"),argv[1],buffer);
	getchar();

}