#pragma once
#include <iostream>
#include <string>

void menuShow();
void printBanner();  // <-- Только объявление (прототип), без тела функции
std::string readInput(const std::string& prompt);