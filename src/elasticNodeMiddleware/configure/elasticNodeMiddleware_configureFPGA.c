#include "src/reconfigure_multiboot_avr/reconfigure_multiboot_avr.h"
#include "src/elasticNodeMiddleware/configure/elasticNodeMiddleware_configureFPGA.h"


void elasticnode_configureFPGA_configureFrom(uint32_t address){
    reconfigure_fpgaMultiboot(address);
    while(!reconfigure_fpgaMultibootComplete());
}

uint32_t elasticnode_configureFPGA_getLoadedConfiguration(void){
    return reconfigure_getMultibootAddress();
}