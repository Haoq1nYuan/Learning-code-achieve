#include <windows.h>
#include <stdio.h>
int main(VOID)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	// Start the child process.
	if (!CreateProcess(NULL, // No module name (use command line).
		"C:\\Windows\\servicing\\LCU\\Package_for_RollupFix~31bf3856ad364e35~amd64~~22000.739.1.8\\amd64_microsoft-windows-mspaint_31bf3856ad364e35_10.0.22000.653_none_8965521b73d4ca7d\\f\\mspaint.exe", // Command line.
		NULL, // Process handle not inheritable.
		NULL, // Thread handle not inheritable.
		FALSE, // Set handle inheritance to FALSE.
		0, // No creation flags.
		NULL, // Use parent's environment block.
		NULL, // Use parent's starting directory.
		&si, // Pointer to STARTUPINFO structure.
		&pi) // Pointer to PROCESS_INFORMATION structure.
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return -1;
	}
	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);
	// Close process and thread handles.
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}