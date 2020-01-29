//
// Created by annika on 01.10.19.
//

#include "lib/xmem/xmem.h"
#include "lib/pinDefinition/fpgaRegisters.h"
#include "lib/pinDefinition/fpgaPins.h"
#include "EmbeddedUtilities/BitManipulation.h"

void xmem_initXmem(void) {

    /*XMCRA = (1 << SRW11 ) | (1 << SRW10);
    XMCRB = (1 << XMBK) | (1 << XMM1);*/
    //SRW10 in MCUCR

    BitManipulation_setBit(XMCRA, (SRW11 | SRW10));
    BitManipulation_setBit(XMCRB, (XMBK | XMM1));

}

void xmem_enableXmem(void){

    //spi disable
    BitManipulation_setBit(SPCR, SPE);

    *DDR_XMEM_A = XMEM_A_MASK;
    *DDR_XMEM_ALE = XMEM_AD_MASK;

    BitManipulation_setBit(DDR_XMEM_WR, P_XMEM_WR);
    BitManipulation_setBit(DDR_XMEM_RD, P_XMEM_RD);
    BitManipulation_setBit(DDR_XMEM_ALE, P_XMEM_ALE);

    XMEM_ENABLE_REG |= (1 << XMEM_ENABLE_P);
}

void xmem_disableXmem(void){

    BitManipulation_clearBit(XMEM_ENABLE_REG, XMEM_ENABLE_P);

    *DDR_XMEM_A = 0x00;
    *DDR_XMEM_AD = 0x00;

    BitManipulation_clearBit(DDR_XMEM_WR, P_XMEM_WR);
    BitManipulation_setBit(PORT_XMEM_RD, P_XMEM_RD);
    BitManipulation_clearBit(DDR_XMEM_ALE, P_XMEM_ALE);
}