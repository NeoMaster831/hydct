#include <ntddk.h>
#include "ioctl.h"

VOID DriverUnload(PDRIVER_OBJECT DriverObject)
{
  UNREFERENCED_PARAMETER(DriverObject);
  IoctlTerminate(DriverObject);
  HD_LOG_INFO("Driver unloaded");
}

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
  UNREFERENCED_PARAMETER(RegistryPath);

  DriverObject->DriverUnload = DriverUnload;

  if (!IoctlInit(DriverObject))
  {
    HD_LOG_ERROR("Failed to initialize IOCTL interface");
    return STATUS_UNSUCCESSFUL;
  }

  HD_LOG_INFO("Driver loaded");

  return STATUS_SUCCESS;
}