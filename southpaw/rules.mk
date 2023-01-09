# Build Options
#   change yes to no to disable
#
LTO_ENABLE = yes			# Save Runtime Ram (Longer Compile)
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
# RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes

DEFAULT_FOLDER = petecb/southpaw/kb2040

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

# dont forget WS2812_DRIVER in your controllers rules.mk
