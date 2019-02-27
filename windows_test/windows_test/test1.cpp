#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	CHAR a = 'A';
	char b = 'A';
	wchar_t c = L'A';
	int size1, size2;

	cout << "the normal char is" << a << endl;
	cout << "the wide character is " << c << endl;
	CHAR ansi[] = "ansi";
	WCHAR wide[] = L"wide";
	int value;//to find whether it is unicode or not,returns either 0 or 1
	value = IsTextUnicode(ansi, strlen(ansi), NULL);
	if (0 == value)
		cout << "ansic is not unicode" << endl;
	else
		cout << "ansic is unicode" << endl;
	int value2;
	value2 = IsTextUnicode(wide, wcslen(wide), NULL);

	if (0 == value2)
		cout << "wide is not unicode" << endl;
	else
		cout << "wide is unicode" << endl;
	//conversion of wide array to multi byte
	size1 = WideCharToMultiByte(CP_UTF8, 0, wide, -1, NULL, 0, NULL, NULL);
	CHAR *WideToAnsic = new CHAR[size1];
	WideCharToMultiByte(CP_UTF8, 0, wide, -1, WideToAnsic, size1, NULL, NULL);
	cout << "the multibyte code is" << WideToAnsic << endl;
	DWORD n = GetLastError();
	cout << "error in wide array to multi byte=" << n << endl;
	//conversion of multibyte to wide array
	size2 = MultiByteToWideChar(CP_UTF8, 0, ansi, -1, NULL, 0);
	WCHAR *AnsicToWide = new WCHAR[size2];
	MultiByteToWideChar(CP_UTF8, 0, ansi, -1, AnsicToWide, size2);
	wcout << "the multibyte code is" << AnsicToWide << endl;
	DWORD n1 = GetLastError();
	cout << "error in  multi code towide array to=" << n1 << endl;
}