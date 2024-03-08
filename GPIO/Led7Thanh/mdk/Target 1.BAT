SET PATH=D:\Keil_v5\ARM\ARMCLANG\Bin;D:\Program Files\Python312\Scripts\;D:\Program Files\Python312\;C:\Program Files\Common Files\Oracle\Java\javapath;D:\Program Files (x86)\VMware\VMware Workstation\bin\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;D:\nodejs\;D:\Git\cmd;C:\Program Files\Docker\Docker\resources\bin;D:\MATLAB\runtime\win64;D:\MATLAB\bin;D:\src\flutter\bin;D:\Program Files\Java\jdk-21\bin;C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility;D:\Users\phong\anaconda3;D:\Users\phong\anaconda3\Library\mingw-w64\bin;D:\Users\phong\anaconda3\Library\usr\bin;D:\Users\phong\anaconda3\Library\bin;D:\Users\phong\anaconda3\Scripts;C:\Users\phong\AppData\Local\Microsoft\WindowsApps;C:\Users\phong\AppData\Roaming\npm;D:\Microsoft VS Code\bin;D:\Git\bin
SET ARMCC6_ASMOPT=--diag_suppress=9931
SET ARMCC6_CCOPT=--diag_suppress=9931
SET ARMCC6_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00B71B00
"D:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\main.__i"
"D:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\misc.__i"
"D:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\stm32f10x_gpio.__i"
"D:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\stm32f10x_rcc.__i"
"D:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\startup_stm32f10x_md._ac"
"D:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\system_stm32f10x.__i"
"D:\Keil_v5\ARM\ARMCLANG\Bin\ArmLink" --Via ".\Objects\led7Thanh.lnp"
"D:\Keil_v5\ARM\ARMCLANG\Bin\fromelf.exe" ".\Objects\led7Thanh.axf" --i32combined --output ".\Objects\led7Thanh.hex"
