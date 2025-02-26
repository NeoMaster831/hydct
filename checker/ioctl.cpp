#include "ioctl.h"

bool Ioctl::Init() {
	HANDLE hDevice;

	hDevice = CreateFile(
		L"\\\\.\\Hydct",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	if (hDevice == INVALID_HANDLE_VALUE) {
		LogConsole("Failed to open device. Error code: %d\n", GetLastError());
		return false;
	}

	GloVar::Ioctl::hDevice = hDevice;

	return true;
}

bool Ioctl::Request(
	DWORD Request,
	PVOID InputBuffer,
	DWORD InputBufferLength,
	PVOID OutputBuffer,
	DWORD OutputBufferLength
) {
	DWORD BytesReturned;
	if (!DeviceIoControl(
		GloVar::Ioctl::hDevice,
		Request,
		InputBuffer,
		InputBufferLength,
		OutputBuffer,
		OutputBufferLength,
		&BytesReturned,
		NULL
	)) {
		LogConsole("Failed to send request. Error code: %d\n", GetLastError());
		return false;
	}
	return true;
}

void Ioctl::Terminate() {
	CloseHandle(GloVar::Ioctl::hDevice);
}