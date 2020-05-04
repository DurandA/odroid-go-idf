# odroid-go-idf
Example project for ODROID-GO using ESP-IDF on PlatformIO

## Features
- [x] LCD driver from [ESP32 IoT Solution](https://github.com/espressif/esp-iot-solution/tree/master/components/spi_devices/lcd) based on [Adafruit’s Library](https://github.com/adafruit/Adafruit-GFX-Library.git) for ILI9341
- [ ] GPIO buttons support through [button component](https://github.com/espressif/esp-iot-solution/tree/master/components/general/button/button)
- [ ] D-pad (ADC) support
- [ ] Sound driver (speaker)

## D-pad
The D-pad is connected to [IO34/35](https://github.com/hardkernel/ODROID-GO/blob/master/Documents/ODROID-GO_REV0.1_20180518.pdf) and uses analog multiplexing. It might be possible to poll the ADC from the ULP to generate interrupts.
