#include "menu.h"
#include <iostream>

void printBanner() {
    std::cout << "\n";
    std::cout << "██████╗ ██████╗ ██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███████╗\n";
    std::cout << "██╔══██╗██╔══██╗██║    ██║██╔════╝██║     ██╔═══██╗██╔══██╗██╔════╝\n";
    std::cout << "██████╔╝██████╔╝██║ █╗ ██║█████╗  ██║     ██║   ██║██████╝█████╗  \n";
    std::cout << "██╔═══╝ ██╔══██╗██║███╗██║██╔══╝  ██║     ██║   ██║██╔══██╗██╔══╝  \n";
    std::cout << "██║     ██████╔╝╚██████╔╝███████╗███████╗╚██████╝██║  ██║███████╗\n";
    std::cout << "╚═╝     ╚═════╝  ╚══╝╚══╝ ══════╝╚══════╝ ═════╝ ╚═╝  ╚═╝╚══════╝\n";
    std::cout << "                                                                    \n";
    std::cout << "                    by RaccoonCity\n";
    std::cout << "\n";
}

void menuShow() {
    printBanner();
    while (true) {
        std::cout << "\n========================================\n";
        std::cout << "   TTY-SPOOFER-DAYZ — Main Menu\n";
        std::cout << "========================================\n\n";
        std::cout << "[1] Spoof CPU Serial Number\n";
        std::cout << "[2] Spoof Baseboard Serial Number\n";
        std::cout << "[3] Spoof Chassis Serial Number\n";
        std::cout << "[4] Spoof BIOS Version & Serial\n";
        std::cout << "[5] Spoof MAC Addresses (All Cards)\n";
        std::cout << "[6] Spoof UUID / MachineGuid\n";
        std::cout << "[7] Full HWID Spoof (All components)\n";
        std::cout << "[8] Restore Original HWIDs\n";
        std::cout << "[9] Exit\n";

        std::string input = readInput("Enter choice [1-9]: ");
        if (input.empty()) continue;

        switch (input[0]) {
            case '1': spoofCPU(); break;
            case '2': spoofBaseboardSerial(); break;
            case '3': spoofChassisSerial(); break;
            case '4': spoofBIOSVersionAndSerial(); break;
            case '5': spoofMACAddresses(); break;
            case '6': spoofUUID_GUID(); break;
            case '7': executeAllProtections(); break;
            case '8': restoreOriginalHWIDs(); break;
            case '9': std::cout << "\n[*] Exiting...\n"; return;
        }

        std::cout << "\n[*] Press any key to continue...";
        char dummy; std::cin >> dummy;
    }
}

std::string readInput(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    if (!std::getline(std::cin, line)) return "";
    // Remove carriage return if present (Windows console input)
    if (!line.empty() && line.back() == '\r') line.pop_back();
    return line;
}

// Stub функции — будут заменены на реальные вызовы драйвера/реестра
void spoofCPU() { std::cout << "[*] Spoof CPU Serial Number...\n"; }
void spoofBaseboardSerial() { std::cout << "[*] Spoof Baseboard Serial Number...\n"; }
void spoofChassisSerial() { std::cout << "[*] Spoof Chassis Serial Number...\n"; }
void spoofBIOSVersionAndSerial() { std::cout << "[*] Spoof BIOS Version & Serial...\n"; }
void spoofMACAddresses() { std::cout << "[*] Spoof MAC Addresses (All Cards)...\n"; }
void spoofUUID_GUID() { std::cout << "[*] Spoof UUID / MachineGuid...\n"; }
void executeAllProtections() { std::cout << "[*] Executing full HWID spoof...\n"; }
void restoreOriginalHWIDs() { std::cout << "[*] Restoring original HWIDs...\n"; }
