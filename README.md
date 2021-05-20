# FRDM-k64f-VSCODE-example
Based on https://mcuoneclipse.com/2021/05/01/visual-studio-code-for-c-c-with-arm-cortex-m-part-1/

## Changes
- Using FRDM-K64F board
- The base example didn't have any hardware interaction so I've made simple led and button functions
- Implemented openOCD debug configuration (needs openOCD installed)
- Using MCUXPRESSO SDK from github: https://github.com/NXPmicro/mcux-sdk as submodule and linking files from that folder
- Implemented Ceedling for unit testing (http://www.throwtheswitch.org/ceedling)

## Example Description
  - When no switches pressed the led is RED
  - Pressing SW2 turns led GREEN
  - Holding a while SW2 turns led YELLOW
  - Pressing SW3 turns led BLUE
  - Holding a while SW3 turns led PINK
  - Pressing both switches turns led CYAN
  - Holding a while both switches turns led WHITE

## OpenOCD
  - Installation instructions: https://www.playembedded.org/blog/building-openocd-under-windows-using-msys2/
  - k64.cfg file found here: https://community.nxp.com/t5/Kinetis-Microcontrollers/OpenOCD-with-FRDM-K64F-support/m-p/315221
  - frdm-k64f.cfg board cfg file based on frdm-kl46z.cfg
  
