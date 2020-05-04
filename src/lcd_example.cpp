#include "nvs_flash.h"
#include "esp_event_loop.h"
#include "freertos/event_groups.h"
#include "iot_lcd.h"

#define PROGMEM
#include "FreeSans9pt7b.h"
#include "unity.h"

#define TFT_DC 21
#define TFT_CS 5
#define TFT_LED_PIN 14
#define TFT_MOSI 23
#define TFT_MISO 19
#define TFT_SCLK 18
#define TFT_RST GPIO_NUM_MAX


static CEspLcd* tft = NULL;

extern "C" void app_lcd_init(int clk_freq)
{
    lcd_conf_t lcd_pins = {
        .lcd_model = LCD_MOD_AUTO_DET,
        .pin_num_miso = TFT_MISO,
        .pin_num_mosi = TFT_MOSI,
        .pin_num_clk  = TFT_SCLK,
        .pin_num_cs   = TFT_CS,
        .pin_num_dc   = TFT_DC,
        .pin_num_rst  = GPIO_NUM_MAX,
        .pin_num_bckl = TFT_LED_PIN,
        .clk_freq = clk_freq,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .spi_host = VSPI_HOST,
        .init_spi_bus = false,
    };
    tft = new CEspLcd(&lcd_pins);

    /*screen initialize*/
    tft->invertDisplay(false);
    tft->setRotation(3);
}

spi_device_handle_t spi;

extern "C" void app_main(void)
{
    esp_err_t ret;

    static spi_bus_config_t buscfg={
        .mosi_io_num=TFT_MOSI,
        .miso_io_num=TFT_MISO,
        .sclk_io_num=TFT_SCLK,
        .quadwp_io_num=-1,
        .quadhd_io_num=-1,
    };

    ret=spi_bus_initialize(VSPI_HOST, &buscfg, 1);
    ESP_ERROR_CHECK(ret);
    app_lcd_init(27000000);

    tft->fillScreen(COLOR_ORANGE);
    tft->printf("Hello PlatformIO");
}
