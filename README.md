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
```
IDE -> File -> import
```

## Info on Examples

1. Simple UAVCAN start <br />
2. Dynamic ID Client <br />
3. Dynamic ID Server Centralized control <br />
	a. Help needed <br />
	b. RAM or flash to use for data storage?
4. Publisher <br />
	a. Use UAVCAN Tool GUI to monitor BUS <br />
	b. Subscriber tool in GUI could show data
5. Subscriber <br />
	a. Use any serial terminal to monitor values <br />
	b. UAVCAN Tool GUI -> Interactive console ->  broadcast(uavcan.protocol.debug.KeyValue(key='key', value=123), interval=1) and press ENTER
6. Service Server <br />
	a. Use UAVCAN Tool GUI -> Interactive console ->  request(uavcan.protocol.file.BeginFirmwareUpdate,5) and press ENTER
7. Service Client <br />
	a. Create in PC any txt document with any text inside <br />
	b. Use UAVCAN Tool GUI -> at bottom left specify file -> launch file server -> in terminal must show SUCCESS and in bus monitor file size)
8. Custom Data Server  <br />
	a. Use in interactive console request(uavcan.thirdparty.custom_data_types.MyNumber, 5). it will print some info from server. <br />
	b. Request for additional data not implemented. Help is welcome. <br />
	c. Data Type ID change and nested Data types are not implemented. Help is welcome.
9. Custom Data Client <br />
	a. Use any serial terminal to monitor if connection was succesfull <br />
	b. Data response for the server additional request not implemented. Help is welcome. <br />
	c. Needed help on how to use received data. At structure initialization shows "Private" sturcture. <br />
10. Custom Data Publisher <br />
	a. No response data needed in Custom Data Types <br />

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
<!--
## License
[MIT](https://choosealicense.com/licenses/mit/)
-->