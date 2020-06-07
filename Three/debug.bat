start "" "C:/Program Files/mGBA/mGBA.exe" -g Three.gba
/opt/devkitPro/devkitARM/bin/arm-none-eabi-gdb Three.elf -ex "target remote localhost:2345"
