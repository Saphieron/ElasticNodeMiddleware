//
// Created by annika on 26.02.20.
//

#ifndef ELASTICNODEMIDDLEWARE_ELASTICNODEMIDDLEWARE_CONFIGUREFPGA_H
#define ELASTICNODEMIDDLEWARE_ELASTICNODEMIDDLEWARE_CONFIGUREFPGA_H

#include <stdint.h>

void elasticnode_configureFPGA_configureFrom(uint32_t address);
uint32_t elasticnode_configureFPGA_getLoadedConfiguration(void);

#endif //ELASTICNODEMIDDLEWARE_ELASTICNODEMIDDLEWARE_CONFIGUREFPGA_H