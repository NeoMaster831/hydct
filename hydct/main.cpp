#include <ntddk.h>

VOID DriverUnload(PDRIVER_OBJECT DriverObject)
{
  UNREFERENCED_PARAMETER(DriverObject);
  (("Driver Unload Called\n"));
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
  UNREFERENCED_PARAMETER(RegistryPath);
  DriverObject->DriverUnload = DriverUnload;

  return STATUS_SUCCESS;
}