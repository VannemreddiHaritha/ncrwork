#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
using namespace std;
#define BUFFSIZE 100
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfile;
	TCHAR buffer[BUFFSIZE];
	hfile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("creation of file is error(%ld)"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File is opened"), argv[1]);
	DWORD dwnbr;//no.of bytes read
	while (1)
	{
		ZeroMemory(buffer, sizeof(buffer));
		BOOL ret = ReadFile(hfile, buffer, BUFFSIZE, &dwnbr, NULL);
		if (ret == 0)
		{
			_tprintf(_T("File doesnt exist Error[%d]"), GetLastError());
			getchar();
			return FALSE;
		}
		else if ( dwnbr == 0)//EOF
			break;

			_tprintf(_T("%S"), buffer);
	}

	CloseHandle(hfile);
	
	getchar();
}