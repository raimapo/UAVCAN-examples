# Nucleo-F446ZE + CubeMX + FreeRTOS

# UAVCAN Examples

Main idea to reverse engineer and improve custom gimbal firmware, which was developed on STM32103 and ChibiOS and later skipped. For this reason was selected newer family of microcontrollers such as STM32F4 with board NUCLEO-F446ZE. Now implementing some UAVCAN tutorial examples which will help to renew firmware. With ChibiOS is everything OK, but I like easier to control libraries and Real Time OS, so I have choosed to use HAL libraries (I know they not perfect, maybe later LL) and FreeRTOS (maybe more mature and lightweight). Main issue with HAL libraries and FreeRTOS - they do not support natively C++, however, Libuavcan library are C++. STM32CubeIDE used for better integration and just working debug without any reconfigurations.

## Installation

Use the git

```bash
git clone https://github.com/raimapo/UAVCAN-examples.git
cd UAVCAN-examples
git submodule update --init --recursive
```
## Usage

```
STM32CubeIDE
```
Import each project from dowloaded directory.


## Info on Examples

1. Simple UAVCAN start
2. Dynamic ID Client
3. Dynamic ID Server Centralized control (Help needed)
4. Publisher (Use UAVCAN Tool GUI to monitor BUS)
5. Subscriber (Use any serial terminal to monitor values. UAVCAN Tool GUI -> Interactive console ->  broadcast(uavcan.protocol.debug.KeyValue(key='key', value=123), interval=1) and press ENTER)
6. Service Server (Use UAVCAN Tool GUI -> Interactive console ->  request(uavcan.protocol.file.BeginFirmwareUpdate,5) and press ENTER)
7. Service Client (Create in PC any txt document with any text inside -> Use UAVCAN Tool GUI -> at bottom left specify file -> launch file server -> in terminal must show SUCCESS and in bus monitor file size)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
<!--
## License
[MIT](https://choosealicense.com/licenses/mit/)
-->