// include/driver.h — объявления функций драйвера и инъектора
#pragma once
#include <ntstatus.h>

NTSTATUS loadDriver(const wchar_t* driverPath);
NTSTATUS callSpoofCPU();
NTSTATUS callSpoofBaseboardSerial();
NTSTATUS callSpoofChassisSerial();
NTSTATUS callSpoofBIOSVersionAndSerial();
NTSTATUS callSpoofMACAddresses();
NTSTATUS callSpoofUUID_GUID();
NTSTATUS callExecuteAllProtections();
NTSTATUS callRestoreOriginalHWIDs();
