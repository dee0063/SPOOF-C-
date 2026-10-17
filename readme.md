Директория UI: 
1.src/ui/menu.cpp — консольное меню и логика вывода

2.src/ui/main.cpp — точка входа UI-слоя

3.src/ui/input.cpp — вспомогательные функции ввода и генерации случайных данных

Директория driver:
1. // src/driver/spoof_driver.cpp — код драйвера (ядро Windows)

2. // src/driver/injector.cpp — загрузка драйвера в ядро и вызов функций

Директория Include: 
1. // include/driver.h — объявления функций драйвера и инъектора

2. // include/menu.h — объявления функций UI-слоя

3. // include/reg_ops.h — объявления функций работы с реестром

Директория registry: 
1. // src/registry/reg_ops.cpp — Win32 API для чтения/записи реестра
