#pragma once

#include "global.h"

#include "d_rdtsc.h"

typedef struct _DEVICE_EXTENSION {
  UNICODE_STRING DeviceName;
  UNICODE_STRING SymLinkName;
} DEVICE_EXTENSION, * PDEVICE_EXTENSION;

/*
 * @brief Initialize the IOCTL interface
 * @details This function creates a device object and a symbolic link for the
 * IOCTL interface, and sets the major functions for the driver object.
 * The driver object has symlink and device name in the device extension.
 * @param DriverObject The driver object
 * @return TRUE if the initialization was successful, FALSE otherwise
 */
BOOL IoctlInit(PDRIVER_OBJECT DriverObject);

/*
 * @brief Handle IOCTL requests.
 * @details The routine is called by `DeviceObject`
 */
NTSTATUS IoctlHandle(_In_ PDEVICE_OBJECT DeviceObject, _In_ PIRP Irp);

/*
 * @brief Terminate the IOCTL interface
 */
VOID IoctlTerminate(PDRIVER_OBJECT DriverObject);