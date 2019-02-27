#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
//to know the path of all the environment
void DumpEnvStrings(PTSTR EnvBlocks[])
{
	int curr= 0;
	PTSTR *pelement = (PTSTR*)EnvBlocks;
	PTSTR pcurrent = NULL;
	while (pelement != NULL)
	{
		pcurrent = PTSTR(*pelement);
		if (pcurrent == NULL)
			pelement = NULL;
		else
		{
			_tprintf(TEXT("[%u]%s\n\n"), curr, pcurrent);
			curr++;
			pelement++;
		}
	}	
}
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env);
	TCHAR envVarString0[] = TEXT("%SystemRoot%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString0, buffer, MAX_PATH);
		if (!ret)
		{
			cout << GetLastError() << endl;
		}
		else
		{
			wcout << buffer << endl;
		}
    system("pause");
	return 0;
}