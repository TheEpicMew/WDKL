#pragma once
#include <ntddk.h>

NTSTATUS CreateClose(PDEVICE_OBJECT DeviceObject, PIRP Irp);
NTSTATUS IoControl(PDEVICE_OBJECT DeviceObject, PIRP Irp);
void DriverUnload(PDRIVER_OBJECT DriverObject);
