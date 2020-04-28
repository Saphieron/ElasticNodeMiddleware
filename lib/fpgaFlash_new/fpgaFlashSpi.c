#include "lib/fpgaFlash_new/fpgaFlash.h"
#include "lib/spi_new/spi.h"
#include "lib/xmem/xmem.h"
#include "lib/pinDefinition/fpgaPins.h"
#include "lib/pinDefinition/fpgaRegisters.h"

void fpgaFlashPerformSimpleTask(uint8_t command, uint16_t numRead, uint8_t *dataRead)
{
    spiPerformSimpleTaskBlocking(command, numRead, dataRead);
}

void fpgaFlashPerformTask(uint16_t numWrite, uint8_t *dataWrite, uint16_t numRead, uint8_t *dataRead)
{
    spiPerformTaskBlocking(numWrite, dataWrite, numRead, dataRead);
}

void selectFpgaFlash(void) {
    spiEnable();
    ////disableXmem();
    xmem_disableXmem();

    PORT_FLASH_CS &= ~_BV(P_FLASH_CS);
}


void deselectFpgaFlash(void)
{
    spiEnable();
    ////disableXmem();
    xmem_disableXmem();

    PORT_FLASH_CS |= _BV(P_FLASH_CS);

}