# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.

SPLIT_KEYBOARD = yes

EXTRAFLAGS += -flto
# SRC += pmw3360/pmw3360.c

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360


OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = SSD1306
