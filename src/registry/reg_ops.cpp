#include "reg_ops.h"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

// Получить значение из реестра
std::wstring GetRegistryValue(HKEY hKey, LPCWSTR subkey, LPCWSTR valueName) {
    HKEY hOpenKey = nullptr;
    
    // Сначала открываем ключ
    LONG result = RegOpenKeyExW(hKey, subkey, 0, KEY_READ, &hOpenKey);
    if (result != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open key: " << subkey << std::endl;
        return L"";
    }
    
    // Узнаем размер данных
    DWORD dataSize = 0;
    DWORD type = 0;
    result = RegQueryValueExW(hOpenKey, valueName, nullptr, &type, nullptr, &dataSize);
    if (result != ERROR_SUCCESS) {
        std::wcerr << L"Failed to query value size: " << valueName << std::endl;
        RegCloseKey(hOpenKey);
        return L"";
    }
    
    // Читаем данные
    std::vector<BYTE> buffer(dataSize);
    result = RegQueryValueExW(hOpenKey, valueName, nullptr, &type, buffer.data(), &dataSize);
    
    RegCloseKey(hOpenKey);
    
    if (result != ERROR_SUCCESS) {
        std::wcerr << L"Failed to read value: " << valueName << std::endl;
        return L"";
    }
    
    // Конвертируем в wstring
    if (type == REG_SZ) {
        return std::wstring(reinterpret_cast<const wchar_t*>(buffer.data()), dataSize / sizeof(wchar_t) - 1);
    }
    
    return L"";
}

// Установить значение в реестре
bool SetRegistryValue(HKEY hKey, LPCWSTR subkey, LPCWSTR valueName, const std::wstring& data) {
    HKEY hOpenKey = nullptr;
    
    // Открываем ключ с правами на запись
    LONG result = RegOpenKeyExW(hKey, subkey, 0, KEY_WRITE, &hOpenKey);
    if (result != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open key for writing: " << subkey << std::endl;
        return false;
    }
    
    // Записываем значение
    DWORD dataSize = (DWORD)((data.size() + 1) * sizeof(wchar_t));
    result = RegSetValueExW(hOpenKey, valueName, 0, REG_SZ, 
                           reinterpret_cast<const BYTE*>(data.c_str()), dataSize);
    
    RegCloseKey(hOpenKey);
    
    if (result != ERROR_SUCCESS) {
        std::wcerr << L"Failed to set value: " << valueName << std::endl;
        return false;
    }
    
    return true;
}