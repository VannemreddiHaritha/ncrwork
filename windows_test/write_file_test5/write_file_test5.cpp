#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfile;
	TCHAR buffer[BUFFSIZE]=L"file is created and some text is written in this file ";
	if (argc != 2)
	{
		_tprintf(_T(" usage file"));
		getchar();
		return FALSE;
	}
	hfile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("creation of file is error(%ld)"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File is opened"), argv[1]);
	printf("\n");
	DWORD dwnbr;//no.of bytes read
	BOOL ret =WriteFile(hfile, buffer, sizeof(buffer), &dwnbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("File doesnt exist Error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hfile);
	_tprintf(_T("contents of file(%s)\n"), argv[1]);
	printf("%S\n", buffer);
	getchar();

}