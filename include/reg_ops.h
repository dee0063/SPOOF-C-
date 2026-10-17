// include/reg_ops.h — объявления функций работы с реестром
#pragma once
#include <windows.h>
#include <string>

std::wstring GetRegistryValue(HKEY hKey, LPCWSTR subkey, LPCWSTR valueName);
bool SetRegistryValue(HKEY hKey, LPCWSTR subkey, LPCWSTR valueName, const std::wstring& data);
