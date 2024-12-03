/*
#include "TrailWave.h"
#include "I2C_eeprom.h"

// Configurable constants for EEPROM
#define EEPROM_DEVICE_ADDR 0x50    // I2C address for EEPROM
#define EEPROM_PAGE_SIZE 16        // Page size for EEPROM
#define EEPROM_SIZE 256            // EEPROM size (adjust for your model)

// EEPROM Address definitions
#define EEPROM_INIT_ADDR 0         // Address to check if EEPROM is initialized
#define EEPROM_FREQ_A_ADDR 10      // Address for VFO A frequency
#define EEPROM_FREQ_B_ADDR 20      // Address for VFO B frequency
#define EEPROM_MODE_ADDR 30        // Address for mode (USB/LSB/CW/DIG)
#define EEPROM_MEM_ADDR 40         // Address for band memory
#define EEPROM_STEP_ADDR 50        // Address for tuning step size
#define EEPROM_VFO_SELECT_ADDR 60  // Address for VFO A/B selection

// I2C EEPROM instance
I2C_eeprom i2cEEPROM(EEPROM_DEVICE_ADDR, EEPROM_PAGE_SIZE);

// Default TrailRadio struct initialization
struct TrailRadio {
    uint32_t freqA = 14000000;    // Default frequency for VFO A (14 MHz)
    uint32_t freqB = 14400000;     // Default frequency for VFO B (7 MHz)
    uint8_t mode = 1;             // Default mode (e.g., USB)
    uint8_t MEM_INIT = 0;         // Default memory initialization
    uint16_t step = 10;           // Default tuning step size (10 Hz)
    uint8_t vfo_is_A = 1;         // Default VFO selection (VFO A)
};

// Function to initialize EEPROM if not already initialized
void initEEPROM(TrailRadio& radio) {
    uint8_t initFlag = 0;
    if (!i2cEEPROM.read(EEPROM_INIT_ADDR, &initFlag, sizeof(initFlag))) {
        Serial.println("Failed to read initialization flag from EEPROM!");
        return;
    }

    if (initFlag != 1) {
        Serial.println("EEPROM not initialized. Writing default values...");

        // Mark EEPROM as initialized
        initFlag = 1;
        if (!i2cEEPROM.write(EEPROM_INIT_ADDR, &initFlag, sizeof(initFlag))) {
            Serial.println("Failed to write initialization flag to EEPROM!");
            return;
        }

        // Write default values
        saveSettingsToEEPROM(radio);
    }
}

// Function to load settings from EEPROM on power-up
void loadSettingsFromEEPROM(TrailRadio& radio) {
    if (!i2cEEPROM.read(EEPROM_FREQ_A_ADDR, &radio.freqA, sizeof(radio.freqA)) ||
        !i2cEEPROM.read(EEPROM_FREQ_B_ADDR, &radio.freqB, sizeof(radio.freqB)) ||
        !i2cEEPROM.read(EEPROM_MODE_ADDR, &radio.mode, sizeof(radio.mode)) ||
        !i2cEEPROM.read(EEPROM_MEM_ADDR, &radio.MEM_INIT, sizeof(radio.MEM_INIT)) ||
        !i2cEEPROM.read(EEPROM_STEP_ADDR, &radio.step, sizeof(radio.step)) ||
        !i2cEEPROM.read(EEPROM_VFO_SELECT_ADDR, &radio.vfo_is_A, sizeof(radio.vfo_is_A))) {
        Serial.println("Failed to load settings from EEPROM!");
    } else {
        Serial.println("Settings successfully loaded from EEPROM.");
    }
}

// Function to save settings to EEPROM after changes
void saveSettingsToEEPROM(TrailRadio& radio) {
    if (!i2cEEPROM.write(EEPROM_FREQ_A_ADDR, &radio.freqA, sizeof(radio.freqA)) ||
        !i2cEEPROM.write(EEPROM_FREQ_B_ADDR, &radio.freqB, sizeof(radio.freqB)) ||
        !i2cEEPROM.write(EEPROM_MODE_ADDR, &radio.mode, sizeof(radio.mode)) ||
        !i2cEEPROM.write(EEPROM_MEM_ADDR, &radio.MEM_INIT, sizeof(radio.MEM_INIT)) ||
        !i2cEEPROM.write(EEPROM_STEP_ADDR, &radio.step, sizeof(radio.step)) ||
        !i2cEEPROM.write(EEPROM_VFO_SELECT_ADDR, &radio.vfo_is_A, sizeof(radio.vfo_is_A))) {
        Serial.println("Failed to save settings to EEPROM!");
    } else {
        Serial.println("Settings successfully saved to EEPROM.");
    }
}
*/