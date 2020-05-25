start "" "C:/Program Files/mGBA/mGBA.exe" -g Two.gba
/opt/devkitPro/devkitARM/bin/arm-none-eabi-gdb Two.elf -ex "target remote localhost:2345"
