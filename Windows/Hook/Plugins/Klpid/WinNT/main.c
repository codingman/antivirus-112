#include "precomp.h"
#pragma hdrstop

#define ANSI_DRV_NAME       "KLPID"
#define MYDRV				L"KLPID"
#define LINKNAME_STRING     L"\\DosDevices\\"MYDRV
#define NTDEVICE_STRING     L"\\Device\\"MYDRV

PVOID              Klick_Device    = NULL;

NTSTATUS	MySetupDriver();

NTSTATUS	
Dispatch(
                PDEVICE_OBJECT	DeviceObject,
                PIRP				Irp);

VOID	
MyUnload(IN	PDRIVER_OBJECT	DriverObject)
{
	UNICODE_STRING	DeviceLinkUnicodeString;

	RtlInitUnicodeString(&DeviceLinkUnicodeString, LINKNAME_STRING);
	IoDeleteSymbolicLink(&DeviceLinkUnicodeString);

    if ( Klick_Device )
        DEREGISTER_KLICK_PLUGIN( Klick_Device, KlickPluginID );
	
	IoDeleteDevice ( DriverObject->DeviceObject );
}

NTSTATUS
DriverEntry(
				IN	PDRIVER_OBJECT	DriverObject,
				IN	PUNICODE_STRING	RegistryPath
)
/*
	Driver Initialization
*/
{
	NTSTATUS					ntStatus;

	UNICODE_STRING				DeviceName, 
								DeviceLinkName;

	PDEVICE_OBJECT				DeviceObject;

	ULONG						i;

    DbgPrint ("%s : Start %s plugin\n", ANSI_DRV_NAME, ANSI_DRV_NAME);

	RtlInitUnicodeString(&DeviceName,		NTDEVICE_STRING);
	RtlInitUnicodeString(&DeviceLinkName,	LINKNAME_STRING);

	ntStatus = IoCreateDevice(
                        DriverObject,
		                0,
		                &DeviceName,
		                FILE_DEVICE_UNKNOWN,
		                0,
		                FALSE,
		                &DeviceObject);

	for ( i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; ++i )
	{
		DriverObject->MajorFunction[i]  =  Dispatch;
	}

	DriverObject->DriverUnload = MyUnload;

	ntStatus = IoCreateSymbolicLink(&DeviceLinkName, &DeviceName);
    
    InitializeGlobalStore();

    InitializeStealthMode();

    MySetupDriver();

	return ntStatus;
}

NTSTATUS	
Dispatch(
		   IN PDEVICE_OBJECT	DeviceObject,
		   IN PIRP				Irp
)
{
    NTSTATUS			ntStatus	= STATUS_SUCCESS;
	PIO_STACK_LOCATION	IrpSp		= IoGetCurrentIrpStackLocation(Irp);
	PVOID				ioBuffer	= Irp->AssociatedIrp.SystemBuffer;
	ULONG               inBufLength = IrpSp->Parameters.DeviceIoControl.InputBufferLength;
    ULONG               outBufLength= IrpSp->Parameters.DeviceIoControl.OutputBufferLength;
	ULONG               IOCTL_Code	= IrpSp->Parameters.DeviceIoControl.IoControlCode;

    switch ( MyIoctlHandler( IOCTL_Code,ioBuffer, inBufLength, ioBuffer, outBufLength, &Irp->IoStatus.Information ) )
    {
    case KL_SUCCESS :
        ntStatus = STATUS_SUCCESS;
        break;
    default:
        ntStatus = STATUS_SUCCESS;
        break;
    }

    Irp->IoStatus.Status = ntStatus;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);	
	return ntStatus;
}

