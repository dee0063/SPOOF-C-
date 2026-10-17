#include "menu.h"
#include <iostream>
#include <string>
#include <random>

std::string generateRandomString(int length) {
    static const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += chars[dist(gen)];
    }
    return result;
}

std::string generateRandomMAC() {
    static const std::string hexChars = "0123456789abcdef";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 15);

    std::string mac;
    for (int i = 0; i < 6; ++i) {
        if (i > 0) mac += '-';
        mac += hexChars[dist(gen)];
    }
    // Set locally administered bit (second nibble of first byte to 2)
    mac[1] = '2';
    return mac;
}

std::string getWmiValue(const std::string& query) {
    // Placeholder — real WMI access requires COM or external library.
    // For now, return empty string.
    return "";
}
