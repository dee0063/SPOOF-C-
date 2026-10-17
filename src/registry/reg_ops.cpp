// src/registry/reg_ops.cpp — Win32 API для чтения/записи реестра
#include "reg_ops.h"
#include <iostream>

std::wstring GetRegistryValue(HKEY hKey, LPCWSTR subkey, LPCWSTR valueName) {
    DWORD dataSize = 0;
    RegQueryValueExW(hKey, subkey, nullptr, nullptr, nullptr, &dataSize);
    std::vector<BYTE> buffer(dataSize);
    RegQueryValueExW(hKey, subkey, nullptr, nullptr, buffer.data(), &dataSize);
    return std::wstring(reinterpret_cast<const wchar_t*>(buffer.data()), dataSize / sizeof(wchar_t));
}

bool SetRegistryValue(HKEY hKey, LPCWSTR subkey, LPCWSTR valueName, const std::wstring& data) {
    DWORD type = REG_SZ;
    RegSetValueExW(hKey, valueName, 0, type, reinterpret_cast<const BYTE*>(data.c_str()), (DWORD)(data.size() + 1) * sizeof(wchar_t));
    return true;
}
