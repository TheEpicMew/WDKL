#include "includes.h"

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = DriverUnload;
    DriverObject->MajorFunction[IRP_MJ_CREATE] = CreateClose;
    DriverObject->MajorFunction[IRP_MJ_CLOSE] = CreateClose;
    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = IoControl;

    UNICODE_STRING deviceName = RTL_CONSTANT_STRING(L"\\Device\\Driver");
    UNICODE_STRING symbolicLink = RTL_CONSTANT_STRING(L"\\DosDevices\\Driver");

    PDEVICE_OBJECT DeviceObject = nullptr;
    NTSTATUS status = IoCreateDevice(DriverObject, 0, &deviceName, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &DeviceObject);

    if (NT_SUCCESS(status)) {
        status = IoCreateSymbolicLink(&symbolicLink, &deviceName);
    }

    if (!NT_SUCCESS(status)) {
        if (DeviceObject) {
            IoDeleteDevice(DeviceObject);
        }
    }

    return status;
}
