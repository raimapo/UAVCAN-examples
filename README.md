# Nucleo-f446ZE + CubeMX + FreeRTOS

# UAVCAN Examples

Main idea to reverse engineer and improve custom gimbal firmware, which was developed on STM32103 and ChibiOS and later skipped. For this reason was selected newer family of microcontrollers such as STM32F4 with board NUCLEO-F446ZE. Now implementing some UAVCAN tutorial examples which will help to renew firmware. With ChibiOS is everything OK, but I like easier to control libraries and Real Time OS, so I have choosed to use HAL libraries (I know they not perfect, maybe later LL) and FreeRTOS (maybe more mature and lightweight). Main issue with HAL libraries and FreeRTOS - they do not support natively C++, however Libuavcan library are C++. STM32CubeIDE used for better integration and just working debug without any reconfigurations.

## Installation

Use the git

```bash
git clone https://github.com/raimapo/UAVCAN-examples.git
```

use git in module directory to clone libuavcan library
```bash
mkdir modules
cd modules
git clone https://github.com/UAVCAN/libuavcan.git
cd libuavcan
git submodule update --init --recursive
git checkout 67da0aa
```
commit changed because with master choeckout library has some issues.


## Usage

```
STM32CubeIDE
```
Import each project from dowloaded directory.


## Info on Examples

1. Simple UAVCAN start
2. Dynamic ID Client
3. Dynamic ID Server Centralized control (Help needed)
4. Publisher and subscriber (on going)
4. Bootloader (Help needed)
5. Application which understands to restart for the Bootloader (Help needed)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
