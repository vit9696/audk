/** @file
  This driver constructs Ring 3 wrappers for the EFI_BOOT_SERVICES.

  Copyright (c) 2024, Mikhail Krichanov. All rights reserved.
  SPDX-License-Identifier: BSD-3-Clause

**/

#include <Uefi.h>

#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>

#include "Ring3.h"

EFI_TPL
EFIAPI
Ring3RaiseTpl (
  IN EFI_TPL  NewTpl
  )
{
  return NewTpl;
}

VOID
EFIAPI
Ring3RestoreTpl (
  IN EFI_TPL  NewTpl
  )
{

}

EFI_STATUS
EFIAPI
Ring3AllocatePages (
  IN EFI_ALLOCATE_TYPE         Type,
  IN EFI_MEMORY_TYPE           MemoryType,
  IN UINTN                     NumberOfPages,
  IN OUT EFI_PHYSICAL_ADDRESS  *Memory
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3FreePages (
  IN EFI_PHYSICAL_ADDRESS  Memory,
  IN UINTN                 NumberOfPages
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3GetMemoryMap (
  IN OUT UINTN                  *MemoryMapSize,
  IN OUT EFI_MEMORY_DESCRIPTOR  *MemoryMap,
  OUT UINTN                     *MapKey,
  OUT UINTN                     *DescriptorSize,
  OUT UINT32                    *DescriptorVersion
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3AllocatePool (
  IN EFI_MEMORY_TYPE  PoolType,
  IN UINTN            Size,
  OUT VOID            **Buffer
  )
{
  EFI_STATUS  Status;

  Status = SysCall (
             SysCallAllocatePool,
             PoolType,
             Size,
             Buffer
             );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Ring3: Failed to allocate %d bytes.\n", Size));
  }

  return Status;
}

EFI_STATUS
EFIAPI
Ring3FreePool (
  IN VOID  *Buffer
  )
{
  EFI_STATUS  Status;

  Status = SysCall (
             SysCallFreePool,
             Buffer
             );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Ring3: Failed to free buffer.\n"));
  }

  return Status;
}

EFI_STATUS
EFIAPI
Ring3CreateEvent (
  IN UINT32            Type,
  IN EFI_TPL           NotifyTpl,
  IN EFI_EVENT_NOTIFY  NotifyFunction  OPTIONAL,
  IN VOID              *NotifyContext  OPTIONAL,
  OUT EFI_EVENT        *Event
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3SetTimer (
  IN EFI_EVENT        UserEvent,
  IN EFI_TIMER_DELAY  Type,
  IN UINT64           TriggerTime
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3WaitForEvent (
  IN UINTN      NumberOfEvents,
  IN EFI_EVENT  *UserEvents,
  OUT UINTN     *UserIndex
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3SignalEvent (
  IN EFI_EVENT  UserEvent
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3CloseEvent (
  IN EFI_EVENT  UserEvent
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3CheckEvent (
  IN EFI_EVENT  UserEvent
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3InstallProtocolInterface (
  IN OUT EFI_HANDLE      *UserHandle,
  IN EFI_GUID            *Protocol,
  IN EFI_INTERFACE_TYPE  InterfaceType,
  IN VOID                *Interface
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3ReinstallProtocolInterface (
  IN EFI_HANDLE  UserHandle,
  IN EFI_GUID    *Protocol,
  IN VOID        *OldInterface,
  IN VOID        *NewInterface
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3UninstallProtocolInterface (
  IN EFI_HANDLE  UserHandle,
  IN EFI_GUID    *Protocol,
  IN VOID        *Interface
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3HandleProtocol (
  IN EFI_HANDLE  UserHandle,
  IN EFI_GUID    *Protocol,
  OUT VOID       **Interface
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3RegisterProtocolNotify (
  IN EFI_GUID   *Protocol,
  IN EFI_EVENT  Event,
  OUT  VOID     **Registration
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3LocateHandle (
  IN EFI_LOCATE_SEARCH_TYPE  SearchType,
  IN EFI_GUID                *Protocol   OPTIONAL,
  IN VOID                    *SearchKey  OPTIONAL,
  IN OUT UINTN               *BufferSize,
  OUT EFI_HANDLE             *Buffer
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3LocateDevicePath (
  IN EFI_GUID                      *Protocol,
  IN OUT EFI_DEVICE_PATH_PROTOCOL  **DevicePath,
  OUT EFI_HANDLE                   *Device
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3InstallConfigurationTable (
  IN EFI_GUID  *Guid,
  IN VOID      *Table
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3LoadImage (
  IN BOOLEAN                   BootPolicy,
  IN EFI_HANDLE                ParentImageHandle,
  IN EFI_DEVICE_PATH_PROTOCOL  *FilePath,
  IN VOID                      *SourceBuffer   OPTIONAL,
  IN UINTN                     SourceSize,
  OUT EFI_HANDLE               *ImageHandle
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3StartImage (
  IN EFI_HANDLE  ImageHandle,
  OUT UINTN      *ExitDataSize,
  OUT CHAR16     **ExitData  OPTIONAL
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3Exit (
  IN EFI_HANDLE  ImageHandle,
  IN EFI_STATUS  Status,
  IN UINTN       ExitDataSize,
  IN CHAR16      *ExitData  OPTIONAL
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3UnloadImage (
  IN EFI_HANDLE  ImageHandle
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3ExitBootServices (
  IN EFI_HANDLE  ImageHandle,
  IN UINTN       MapKey
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3GetNextMonotonicCount (
  OUT UINT64  *Count
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3Stall (
  IN UINTN  Microseconds
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3SetWatchdogTimer (
  IN UINTN   Timeout,
  IN UINT64  WatchdogCode,
  IN UINTN   DataSize,
  IN CHAR16  *WatchdogData OPTIONAL
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3ConnectController (
  IN  EFI_HANDLE                ControllerHandle,
  IN  EFI_HANDLE                *DriverImageHandle    OPTIONAL,
  IN  EFI_DEVICE_PATH_PROTOCOL  *RemainingDevicePath  OPTIONAL,
  IN  BOOLEAN                   Recursive
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3DisconnectController (
  IN  EFI_HANDLE  ControllerHandle,
  IN  EFI_HANDLE  DriverImageHandle  OPTIONAL,
  IN  EFI_HANDLE  ChildHandle        OPTIONAL
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3OpenProtocol (
  IN  EFI_HANDLE  CoreUserHandle,
  IN  EFI_GUID    *Protocol,
  OUT VOID        **Interface OPTIONAL,
  IN  EFI_HANDLE  CoreImageHandle,
  IN  EFI_HANDLE  CoreControllerHandle,
  IN  UINT32      Attributes
  )
{
  EFI_STATUS  Status;

  EFI_LOADED_IMAGE_PROTOCOL *LoadedImage;
  EFI_BLOCK_IO_PROTOCOL     *BlockIo;
  EFI_DISK_IO_PROTOCOL      *DiskIo;

  Status = SysCall (
             SysCallOpenProtocol,
             CoreUserHandle,
             Protocol,
             Interface,
             CoreImageHandle,
             CoreControllerHandle,
             Attributes
             );
  if (EFI_ERROR (Status)) {
    // DEBUG ((DEBUG_ERROR, "Ring3: Failed to open protocol %g - %r\n", Protocol, Status));
    return Status;
  }

  if (CompareGuid (Protocol, &gEfiLoadedImageProtocolGuid)) {

    LoadedImage = (EFI_LOADED_IMAGE_PROTOCOL *)*Interface;

    // TODO: Copy User changes to Core? Resembles InstallMultipleProtocolInterfaces().

    LoadedImage->Unload = NULL;

  } else if (CompareGuid (Protocol, &gEfiBlockIoProtocolGuid)) {

    BlockIo = (EFI_BLOCK_IO_PROTOCOL *)*Interface;

    BlockIo->Reset       = Ring3BlockIoReset;
    BlockIo->ReadBlocks  = Ring3BlockIoRead;
    BlockIo->WriteBlocks = Ring3BlockIoWrite;
    BlockIo->FlushBlocks = Ring3BlockIoFlush;

  } else if (CompareGuid (Protocol, &gEfiDiskIoProtocolGuid)) {

    DiskIo = (EFI_DISK_IO_PROTOCOL *)*Interface;

    DiskIo->ReadDisk  = Ring3DiskIoRead;
    DiskIo->WriteDisk = Ring3DiskIoWrite;

  } else {
    Status = EFI_UNSUPPORTED;
  }

  return Status;
}

EFI_STATUS
EFIAPI
Ring3CloseProtocol (
  IN  EFI_HANDLE  UserHandle,
  IN  EFI_GUID    *Protocol,
  IN  EFI_HANDLE  AgentHandle,
  IN  EFI_HANDLE  ControllerHandle
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3OpenProtocolInformation (
  IN  EFI_HANDLE                           UserHandle,
  IN  EFI_GUID                             *Protocol,
  OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY  **EntryBuffer,
  OUT UINTN                                *EntryCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3ProtocolsPerHandle (
  IN EFI_HANDLE  UserHandle,
  OUT EFI_GUID   ***ProtocolBuffer,
  OUT UINTN      *ProtocolBufferCount
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3LocateHandleBuffer (
  IN EFI_LOCATE_SEARCH_TYPE  SearchType,
  IN EFI_GUID                *Protocol OPTIONAL,
  IN VOID                    *SearchKey OPTIONAL,
  IN OUT UINTN               *NumberHandles,
  OUT EFI_HANDLE             **Buffer
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3LocateProtocol (
  IN  EFI_GUID  *Protocol,
  IN  VOID      *CoreRegistration OPTIONAL,
  OUT VOID      **Interface
  )
{
  EFI_STATUS  Status;

  EFI_DEVICE_PATH_UTILITIES_PROTOCOL *DevicePath;

  Status = SysCall (
             SysCallLocateProtocol,
             Protocol,
             CoreRegistration,
             Interface
             );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Ring3: Failed to loacate protocol %g\n", Protocol));
    return Status;
  }

  if (CompareGuid (Protocol, &gEfiDevicePathUtilitiesProtocolGuid)) {
    DevicePath = (EFI_DEVICE_PATH_UTILITIES_PROTOCOL *)*Interface;

    DevicePath->GetDevicePathSize = NULL;
    DevicePath->DuplicateDevicePath = NULL;
    DevicePath->AppendDevicePath = NULL;
    DevicePath->AppendDeviceNode = NULL;
    DevicePath->AppendDevicePathInstance = NULL;
    DevicePath->GetNextDevicePathInstance = NULL;
    DevicePath->IsDevicePathMultiInstance = NULL;
    DevicePath->CreateDeviceNode = NULL;

    return Status;
  }

  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3InstallMultipleProtocolInterfaces (
  IN OUT EFI_HANDLE  *Handle,
  ...
  )
{
  VA_LIST Marker;
  VOID    *Argument;
  VOID    *ArgList[MAX_LIST];
  UINTN   Index;

  VA_START (Marker, Handle);
  for (Index = 0; Index < MAX_LIST; ++Index) {
    Argument       = VA_ARG (Marker, VOID *);
    ArgList[Index] = Argument;

    if (Argument == NULL) {
      break;
    }
  }
  VA_END (Marker);

  if (Index == MAX_LIST) {
    DEBUG ((DEBUG_ERROR, "Ring3: Too many arguments\n"));
    return EFI_INVALID_PARAMETER;
  }

  return SysCall (
           SysCallInstallMultipleProtocolInterfaces,
           Handle,
           ArgList
           );
}

EFI_STATUS
EFIAPI
Ring3UninstallMultipleProtocolInterfaces (
  IN EFI_HANDLE  Handle,
  ...
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3CalculateCrc32 (
  IN  VOID                              *Data,
  IN  UINTN                             DataSize,
  OUT UINT32                            *Crc32
  )
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Ring3CreateEventEx (
  IN UINT32            Type,
  IN EFI_TPL           NotifyTpl,
  IN EFI_EVENT_NOTIFY  NotifyFunction  OPTIONAL,
  IN CONST VOID        *NotifyContext  OPTIONAL,
  IN CONST EFI_GUID    *EventGroup     OPTIONAL,
  OUT EFI_EVENT        *Event
  )
{
  return EFI_UNSUPPORTED;
}
