#include "common-defines.h"
#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/vector.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "core/uart.h"
#include "core/system.h"
#include "comms.h"
#include "bl_flash.h"

#define BOOTLOADER_SIZE         (0x8000U)
#define MAIN_APP_START_ADDRESS  (FLASH_BASE + BOOTLOADER_SIZE)

#define UART_PORT     (GPIOA)
#define RX_PIN        (GPIO3)
#define TX_PIN        (GPIO2)


static void gpio_setup(void){
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(UART_PORT , GPIO_MODE_AF, GPIO_PUPD_NONE , TX_PIN | RX_PIN);
    gpio_set_af(UART_PORT, GPIO_AF7, TX_PIN | RX_PIN);
}

static void jump_to_main(void){

    vector_table_t* main_vector_table = (vector_table_t*)(MAIN_APP_START_ADDRESS);
    main_vector_table->reset();
}

int main(void){
    system_setup();
    //gpio_setup();
    //uart_setup();
    //comms_setup();

   /*comms_packet_t packet = {
        .length = 9,
        .data = {1,2,3,4,5,6,7,8,9,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
        .crc = 0
    };
    packet.crc = comms_compute_crc(&packet);
 */
    uint8_t data[1024] = {0};
    for(uint16_t i=0; i<1024; i++){
        data[i] = i & 0xff;
    }

    bl_flash_erase_main_application();
    bl_flash_write(0x08008000, data , 1024);
    bl_flash_write(0x0800C000, data , 1024);
    bl_flash_write(0x08010000, data , 1024);
    bl_flash_write(0x08020000, data , 1024);
    bl_flash_write(0x08040000, data , 1024);
    bl_flash_write(0x08060000, data , 1024);
    while(true){
        /*comms_update();
        comms_write(&packet);
        system_delay(500);*/
    }
    jump_to_main();

    return 0;
}