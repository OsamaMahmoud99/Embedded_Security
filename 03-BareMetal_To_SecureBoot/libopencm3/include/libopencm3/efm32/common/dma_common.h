/** @addtogroup dma_defines
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

/*
 * As per the datasheet, it is an PL230 (licenced from ARM)
 *  note: but only implement 12 channel (PL230 can have upto 32 channels)
 *
 * in-future: we can move this to a common peripherial directory
 *   that is idependent of core and as well as uC.
 * something like device tree in Linux kernel
 *
 * note: DMA_STATUS contain the number of PL230 channel are implemented
 */

#define DMA			DMA_BASE

#define DMA_STATUS		MMIO32(DMA_BASE + 0x000)
#define DMA_CONFIG		MMIO32(DMA_BASE + 0x004)
#define DMA_CTRLBASE		MMIO32(DMA_BASE + 0x008)
#define DMA_ALTCTRLBASE		MMIO32(DMA_BASE + 0x00C)

#define DMA_CHWAITSTATUS	MMIO32(DMA_BASE + 0x010)
#define DMA_CHSWREQ		MMIO32(DMA_BASE + 0x014)
#define DMA_CHUSEBURSTS		MMIO32(DMA_BASE + 0x018)
#define DMA_CHUSEBURSTC		MMIO32(DMA_BASE + 0x01C)
#define DMA_CHREQMASKS		MMIO32(DMA_BASE + 0x020)
#define DMA_CHREQMASKC		MMIO32(DMA_BASE + 0x024)
#define DMA_CHENS		MMIO32(DMA_BASE + 0x028)
#define DMA_CHENC		MMIO32(DMA_BASE + 0x02C)
#define DMA_CHALTS		MMIO32(DMA_BASE + 0x030)
#define DMA_CHALTC		MMIO32(DMA_BASE + 0x034)
#define DMA_CHPRIS		MMIO32(DMA_BASE + 0x038)
#define DMA_CHPRIC		MMIO32(DMA_BASE + 0x03C)
#define DMA_ERRORC		MMIO32(DMA_BASE + 0x04C)
#define DMA_CHREQSTATUS		MMIO32(DMA_BASE + 0xE10)
#define DMA_CHSREQSTATUS	MMIO32(DMA_BASE + 0xE18)
#define DMA_IF			MMIO32(DMA_BASE + 0x1000)
#define DMA_IFS			MMIO32(DMA_BASE + 0x1004)
#define DMA_IFC			MMIO32(DMA_BASE + 0x1008)
#define DMA_IEN			MMIO32(DMA_BASE + 0x100C)
#define DMA_CTRL		MMIO32(DMA_BASE + 0x1010)
#define DMA_RDS			MMIO32(DMA_BASE + 0x1014)

#define DMA_LOOPx(i)		MMIO32(DMA_BASE + 0x1020 + ((i) * 0x4))
#define DMA_LOOP0		DMA_LOOPx(0)
#define DMA_LOOP1		DMA_LOOPx(1)

#define DMA_RECTx(i)		MMIO32(DMA_BASE + 0x1060 + ((i) * 0x4))
#define DMA_RECT0		DMA_RECT(0)

#define DMA_CHx_CTRL(i)		MMIO32(DMA_BASE + 0x1100 + ((i) * 0x4))
#define DMA_CH0_CTRL		DMA_CHx_CTRL(0)
#define DMA_CH1_CTRL		DMA_CHx_CTRL(1)
#define DMA_CH2_CTRL		DMA_CHx_CTRL(2)
#define DMA_CH3_CTRL		DMA_CHx_CTRL(3)
#define DMA_CH4_CTRL		DMA_CHx_CTRL(4)
#define DMA_CH5_CTRL		DMA_CHx_CTRL(5)
#define DMA_CH6_CTRL		DMA_CHx_CTRL(6)
#define DMA_CH7_CTRL		DMA_CHx_CTRL(7)
#define DMA_CH8_CTRL		DMA_CHx_CTRL(8)
#define DMA_CH9_CTRL		DMA_CHx_CTRL(9)
#define DMA_CH10_CTRL		DMA_CHx_CTRL(10)
#define DMA_CH11_CTRL		DMA_CHx_CTRL(11)

/* DMA_STATUS */
#define DMA_STATUS_CHNUM_SHIFT	(16)
#define DMA_STATUS_CHNUM_MASK	(0x1F << DMA_STATUS_CHNUM_SHIFT)

#define DMA_STATUS_STATE_SHIFT	(4)
#define DMA_STATUS_STATE_MASK	(0xF << DMA_STATUS_STATE_SHIFT)
#define DMA_STATUS_STATE(v)				\
	(((v) << DMA_STATUS_STATE_SHIFT) & DMA_STATUS_STATE_MASK)
#define DMA_STATUS_STATE_IDLE		0
#define DMA_STATUS_STATE_RDCHCTRLDATA	1
#define DMA_STATUS_STATE_RDSRCENDPTR	2
#define DMA_STATUS_STATE_RDDSTENDPTR	3
#define DMA_STATUS_STATE_RDSRCDATA	4
#define DMA_STATUS_STATE_WRDSTDATA	5
#define DMA_STATUS_STATE_WAITREQCLR	6
#define DMA_STATUS_STATE_WRCHCTRLDATA	7
#define DMA_STATUS_STATE_STALLED	8
#define DMA_STATUS_STATE_DONE		9
#define DMA_STATUS_STATE_PERSCATTRANS	10

#define DMA_STATUS_EN			(1 << 0)

/* DMA_CONFIG */
#define DMA_CONFIG_CHPROT		(1 << 5)
#define DMA_CONFIG_EN			(1 << 0)

/* DMA_CHWAITSTATUS */
#define DMA_CHWAITSTATUS_CHxWAITSTATUS(i)	(1 << (i))
#define DMA_CHWAITSTATUS_CH11WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(11)
#define DMA_CHWAITSTATUS_CH10WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(10)
#define DMA_CHWAITSTATUS_CH9WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(9)
#define DMA_CHWAITSTATUS_CH8WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(8)
#define DMA_CHWAITSTATUS_CH7WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(7)
#define DMA_CHWAITSTATUS_CH6WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(6)
#define DMA_CHWAITSTATUS_CH5WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(5)
#define DMA_CHWAITSTATUS_CH4WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(4)
#define DMA_CHWAITSTATUS_CH3WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(3)
#define DMA_CHWAITSTATUS_CH2WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(2)
#define DMA_CHWAITSTATUS_CH1WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(1)
#define DMA_CHWAITSTATUS_CH0WAITSTATUS	DMA_CHWAITSTATUS_CHxWAITSTATUS(0)

/* DMA_CHSWREQ */
#define DMA_CHSWREQ_CHxSWREQ(i)		(1 << (i))
#define DMA_CHSWREQ_CH11SWREQ		DMA_CHSWREQ_CHxSWREQ(11)
#define DMA_CHSWREQ_CH10SWREQ		DMA_CHSWREQ_CHxSWREQ(10)
#define DMA_CHSWREQ_CH9SWREQ		DMA_CHSWREQ_CHxSWREQ(9)
#define DMA_CHSWREQ_CH8SWREQ		DMA_CHSWREQ_CHxSWREQ(8)
#define DMA_CHSWREQ_CH7SWREQ		DMA_CHSWREQ_CHxSWREQ(7)
#define DMA_CHSWREQ_CH6SWREQ		DMA_CHSWREQ_CHxSWREQ(6)
#define DMA_CHSWREQ_CH5SWREQ		DMA_CHSWREQ_CHxSWREQ(5)
#define DMA_CHSWREQ_CH4SWREQ		DMA_CHSWREQ_CHxSWREQ(4)
#define DMA_CHSWREQ_CH3SWREQ		DMA_CHSWREQ_CHxSWREQ(3)
#define DMA_CHSWREQ_CH2SWREQ		DMA_CHSWREQ_CHxSWREQ(2)
#define DMA_CHSWREQ_CH1SWREQ		DMA_CHSWREQ_CHxSWREQ(1)
#define DMA_CHSWREQ_CH0SWREQ		DMA_CHSWREQ_CHxSWREQ(0)

/* DMA_CHUSEBURSTS */
#define DMA_CHUSEBURSTS_CHxSUSEBURSTS(i)	(1 << (i))
#define DMA_CHUSEBURSTS_CH11SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(11)
#define DMA_CHUSEBURSTS_CH10SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(10)
#define DMA_CHUSEBURSTS_CH9SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(9)
#define DMA_CHUSEBURSTS_CH8SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(8)
#define DMA_CHUSEBURSTS_CH7SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(7)
#define DMA_CHUSEBURSTS_CH6SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(6)
#define DMA_CHUSEBURSTS_CH5SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(5)
#define DMA_CHUSEBURSTS_CH4SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(4)
#define DMA_CHUSEBURSTS_CH3SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(3)
#define DMA_CHUSEBURSTS_CH2SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(2)
#define DMA_CHUSEBURSTS_CH1SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(1)
#define DMA_CHUSEBURSTS_CH0SUSEBURSTS	DMA_CHUSEBURSTS_CHxSUSEBURSTS(0)

/* DMA_CHUSEBURSTC */
#define DMA_CHUSEBURSTC_CHxSUSEBURSTC(i)	(1 << (i))
#define DMA_CHUSEBURSTC_CH11SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(11)
#define DMA_CHUSEBURSTC_CH10SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(10)
#define DMA_CHUSEBURSTC_CH9SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(9)
#define DMA_CHUSEBURSTC_CH8SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(8)
#define DMA_CHUSEBURSTC_CH7SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(7)
#define DMA_CHUSEBURSTC_CH6SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(6)
#define DMA_CHUSEBURSTC_CH5SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(5)
#define DMA_CHUSEBURSTC_CH4SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(4)
#define DMA_CHUSEBURSTC_CH3SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(3)
#define DMA_CHUSEBURSTC_CH2SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(2)
#define DMA_CHUSEBURSTC_CH1SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(1)
#define DMA_CHUSEBURSTC_CH0SUSEBURSTC	DMA_CHUSEBURSTC_CHxSUSEBURSTC(0)

/* DMA_CHREQMASKS */
#define DMA_CHREQMASKS_CHxSREQMASKS(i)	(1 << (i))
#define DMA_CHREQMASKS_CH11SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(11)
#define DMA_CHREQMASKS_CH10SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(10)
#define DMA_CHREQMASKS_CH9SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(9)
#define DMA_CHREQMASKS_CH8SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(8)
#define DMA_CHREQMASKS_CH7SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(7)
#define DMA_CHREQMASKS_CH6SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(6)
#define DMA_CHREQMASKS_CH5SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(5)
#define DMA_CHREQMASKS_CH4SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(4)
#define DMA_CHREQMASKS_CH3SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(3)
#define DMA_CHREQMASKS_CH2SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(2)
#define DMA_CHREQMASKS_CH1SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(1)
#define DMA_CHREQMASKS_CH0SREQMASKS	DMA_CHREQMASKS_CHxSREQMASKS(0)

/* DMA_CHREQMASKC */
#define DMA_CHREQMASKC_CHxSREQMASKC(i)	(1 << (i))
#define DMA_CHREQMASKC_CH11SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(11)
#define DMA_CHREQMASKC_CH10SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(10)
#define DMA_CHREQMASKC_CH9SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(9)
#define DMA_CHREQMASKC_CH8SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(8)
#define DMA_CHREQMASKC_CH7SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(7)
#define DMA_CHREQMASKC_CH6SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(6)
#define DMA_CHREQMASKC_CH5SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(5)
#define DMA_CHREQMASKC_CH4SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(4)
#define DMA_CHREQMASKC_CH3SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(3)
#define DMA_CHREQMASKC_CH2SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(2)
#define DMA_CHREQMASKC_CH1SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(1)
#define DMA_CHREQMASKC_CH0SREQMASKC	DMA_CHREQMASKC_CHxSREQMASKC(0)

/* DMA_CHENS */
#define DMA_CHENS_CHxSENS(i)		(1 << (i))
#define DMA_CHENS_CH11SENS		DMA_CHENS_CHxSENS(11)
#define DMA_CHENS_CH10SENS		DMA_CHENS_CHxSENS(10)
#define DMA_CHENS_CH9SENS		DMA_CHENS_CHxSENS(9)
#define DMA_CHENS_CH8SENS		DMA_CHENS_CHxSENS(8)
#define DMA_CHENS_CH7SENS		DMA_CHENS_CHxSENS(7)
#define DMA_CHENS_CH6SENS		DMA_CHENS_CHxSENS(6)
#define DMA_CHENS_CH5SENS		DMA_CHENS_CHxSENS(5)
#define DMA_CHENS_CH4SENS		DMA_CHENS_CHxSENS(4)
#define DMA_CHENS_CH3SENS		DMA_CHENS_CHxSENS(3)
#define DMA_CHENS_CH2SENS		DMA_CHENS_CHxSENS(2)
#define DMA_CHENS_CH1SENS		DMA_CHENS_CHxSENS(1)
#define DMA_CHENS_CH0SENS		DMA_CHENS_CHxSENS(0)

/* DMA_CHENC */
#define DMA_CHENC_CHxSENC(i)		(1 << (i))
#define DMA_CHENC_CH11SENC		DMA_CHENC_CHxSENC(11)
#define DMA_CHENC_CH10SENC		DMA_CHENC_CHxSENC(10)
#define DMA_CHENC_CH9SENC		DMA_CHENC_CHxSENC(9)
#define DMA_CHENC_CH8SENC		DMA_CHENC_CHxSENC(8)
#define DMA_CHENC_CH7SENC		DMA_CHENC_CHxSENC(7)
#define DMA_CHENC_CH6SENC		DMA_CHENC_CHxSENC(6)
#define DMA_CHENC_CH5SENC		DMA_CHENC_CHxSENC(5)
#define DMA_CHENC_CH4SENC		DMA_CHENC_CHxSENC(4)
#define DMA_CHENC_CH3SENC		DMA_CHENC_CHxSENC(3)
#define DMA_CHENC_CH2SENC		DMA_CHENC_CHxSENC(2)
#define DMA_CHENC_CH1SENC		DMA_CHENC_CHxSENC(1)
#define DMA_CHENC_CH0SENC		DMA_CHENC_CHxSENC(0)

/* DMA_CHALTS */
#define DMA_CHALTS_CHxSALTS(i)	(1 << (i))
#define DMA_CHALTS_CH11SALTS	DMA_CHALTS_CHxSALTS(11)
#define DMA_CHALTS_CH10SALTS	DMA_CHALTS_CHxSALTS(10)
#define DMA_CHALTS_CH9SALTS	DMA_CHALTS_CHxSALTS(9)
#define DMA_CHALTS_CH8SALTS	DMA_CHALTS_CHxSALTS(8)
#define DMA_CHALTS_CH7SALTS	DMA_CHALTS_CHxSALTS(7)
#define DMA_CHALTS_CH6SALTS	DMA_CHALTS_CHxSALTS(6)
#define DMA_CHALTS_CH5SALTS	DMA_CHALTS_CHxSALTS(5)
#define DMA_CHALTS_CH4SALTS	DMA_CHALTS_CHxSALTS(4)
#define DMA_CHALTS_CH3SALTS	DMA_CHALTS_CHxSALTS(3)
#define DMA_CHALTS_CH2SALTS	DMA_CHALTS_CHxSALTS(2)
#define DMA_CHALTS_CH1SALTS	DMA_CHALTS_CHxSALTS(1)
#define DMA_CHALTS_CH0SALTS	DMA_CHALTS_CHxSALTS(0)

/* DMA_CHALTC */
#define DMA_CHALTC_CHxSALTC(i)	(1 << (i))
#define DMA_CHALTC_CH11SALTC	DMA_CHALTC_CHxSALTC(11)
#define DMA_CHALTC_CH10SALTC	DMA_CHALTC_CHxSALTC(10)
#define DMA_CHALTC_CH9SALTC	DMA_CHALTC_CHxSALTC(9)
#define DMA_CHALTC_CH8SALTC	DMA_CHALTC_CHxSALTC(8)
#define DMA_CHALTC_CH7SALTC	DMA_CHALTC_CHxSALTC(7)
#define DMA_CHALTC_CH6SALTC	DMA_CHALTC_CHxSALTC(6)
#define DMA_CHALTC_CH5SALTC	DMA_CHALTC_CHxSALTC(5)
#define DMA_CHALTC_CH4SALTC	DMA_CHALTC_CHxSALTC(4)
#define DMA_CHALTC_CH3SALTC	DMA_CHALTC_CHxSALTC(3)
#define DMA_CHALTC_CH2SALTC	DMA_CHALTC_CHxSALTC(2)
#define DMA_CHALTC_CH1SALTC	DMA_CHALTC_CHxSALTC(1)
#define DMA_CHALTC_CH0SALTC	DMA_CHALTC_CHxSALTC(0)

/* DMA_CHPRIS */
#define DMA_CHPRIS_CHxSPRIC(i)	(1 << (i))
#define DMA_CHPRIS_CH11SPRIC	DMA_CHPRIS_CHxSPRIC(11)
#define DMA_CHPRIS_CH10SPRIC	DMA_CHPRIS_CHxSPRIC(10)
#define DMA_CHPRIS_CH9SPRIC	DMA_CHPRIS_CHxSPRIC(9)
#define DMA_CHPRIS_CH8SPRIC	DMA_CHPRIS_CHxSPRIC(8)
#define DMA_CHPRIS_CH7SPRIC	DMA_CHPRIS_CHxSPRIC(7)
#define DMA_CHPRIS_CH6SPRIC	DMA_CHPRIS_CHxSPRIC(6)
#define DMA_CHPRIS_CH5SPRIC	DMA_CHPRIS_CHxSPRIC(5)
#define DMA_CHPRIS_CH4SPRIC	DMA_CHPRIS_CHxSPRIC(4)
#define DMA_CHPRIS_CH3SPRIC	DMA_CHPRIS_CHxSPRIC(3)
#define DMA_CHPRIS_CH2SPRIC	DMA_CHPRIS_CHxSPRIC(2)
#define DMA_CHPRIS_CH1SPRIC	DMA_CHPRIS_CHxSPRIC(1)
#define DMA_CHPRIS_CH0SPRIC	DMA_CHPRIS_CHxSPRIC(0)

/* DMA_CHPRIC */
#define DMA_CHPRIC_CHxSPRIC(i)	(1 << (i))
#define DMA_CHPRIC_CH11SPRIC	DMA_CHPRIC_CHxSPRIC(11)
#define DMA_CHPRIC_CH10SPRIC	DMA_CHPRIC_CHxSPRIC(10)
#define DMA_CHPRIC_CH9SPRIC	DMA_CHPRIC_CHxSPRIC(9)
#define DMA_CHPRIC_CH8SPRIC	DMA_CHPRIC_CHxSPRIC(8)
#define DMA_CHPRIC_CH7SPRIC	DMA_CHPRIC_CHxSPRIC(7)
#define DMA_CHPRIC_CH6SPRIC	DMA_CHPRIC_CHxSPRIC(6)
#define DMA_CHPRIC_CH5SPRIC	DMA_CHPRIC_CHxSPRIC(5)
#define DMA_CHPRIC_CH4SPRIC	DMA_CHPRIC_CHxSPRIC(4)
#define DMA_CHPRIC_CH3SPRIC	DMA_CHPRIC_CHxSPRIC(3)
#define DMA_CHPRIC_CH2SPRIC	DMA_CHPRIC_CHxSPRIC(2)
#define DMA_CHPRIC_CH1SPRIC	DMA_CHPRIC_CHxSPRIC(1)
#define DMA_CHPRIC_CH0SPRIC	DMA_CHPRIC_CHxSPRIC(0)

/* DMA_ERRORC */
#define DMA_ERRORC_ERRORC	(1 << 0)

/* DMA_CHREQSTATUS */
#define DMA_CHREQSTATUS_CHxSREQSTATUS(i)	(1 << (i))
#define DMA_CHREQSTATUS_CH11SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(11)
#define DMA_CHREQSTATUS_CH10SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(10)
#define DMA_CHREQSTATUS_CH9SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(9)
#define DMA_CHREQSTATUS_CH8SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(8)
#define DMA_CHREQSTATUS_CH7SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(7)
#define DMA_CHREQSTATUS_CH6SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(6)
#define DMA_CHREQSTATUS_CH5SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(5)
#define DMA_CHREQSTATUS_CH4SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(4)
#define DMA_CHREQSTATUS_CH3SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(3)
#define DMA_CHREQSTATUS_CH2SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(2)
#define DMA_CHREQSTATUS_CH1SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(1)
#define DMA_CHREQSTATUS_CH0SREQSTATUS	DMA_CHREQSTATUS_CHxSREQSTATUS(0)

/* DMA_CHSREQSTATUS */
#define DMA_CHSREQSTATUS_CHxSREQSTATUS(i)	(1 << (i))
#define DMA_CHSREQSTATUS_CH11SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(11)
#define DMA_CHSREQSTATUS_CH10SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(10)
#define DMA_CHSREQSTATUS_CH9SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(9)
#define DMA_CHSREQSTATUS_CH8SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(8)
#define DMA_CHSREQSTATUS_CH7SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(7)
#define DMA_CHSREQSTATUS_CH6SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(6)
#define DMA_CHSREQSTATUS_CH5SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(5)
#define DMA_CHSREQSTATUS_CH4SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(4)
#define DMA_CHSREQSTATUS_CH3SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(3)
#define DMA_CHSREQSTATUS_CH2SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(2)
#define DMA_CHSREQSTATUS_CH1SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(1)
#define DMA_CHSREQSTATUS_CH0SREQSTATUS	DMA_CHSREQSTATUS_CHxSREQSTATUS(0)

/* DMA_IF */
#define DMA_IF_ERR		(1UL << 31)
#define DMA_IF_CHxDONE(x)	(1 << (x))
#define DMA_IF_CH11DONE		DMA_IF_CHxDONE(11)
#define DMA_IF_CH10DONE		DMA_IF_CHxDONE(10)
#define DMA_IF_CH9DONE		DMA_IF_CHxDONE(9)
#define DMA_IF_CH8DONE		DMA_IF_CHxDONE(8)
#define DMA_IF_CH7DONE		DMA_IF_CHxDONE(7)
#define DMA_IF_CH6DONE		DMA_IF_CHxDONE(6)
#define DMA_IF_CH5DONE		DMA_IF_CHxDONE(5)
#define DMA_IF_CH4DONE		DMA_IF_CHxDONE(4)
#define DMA_IF_CH3DONE		DMA_IF_CHxDONE(3)
#define DMA_IF_CH2DONE		DMA_IF_CHxDONE(2)
#define DMA_IF_CH1DONE		DMA_IF_CHxDONE(1)
#define DMA_IF_CH0DONE		DMA_IF_CHxDONE(0)


/* DMA_IFS */
#define DMA_IFS_ERR		(1 << 31)
#define DMA_IFS_CHxDONE(x)	(1 << (x))
#define DMA_IFS_CH11DONE	DMA_IFS_CHxDONE(11)
#define DMA_IFS_CH10DONE	DMA_IFS_CHxDONE(10)
#define DMA_IFS_CH9DONE		DMA_IFS_CHxDONE(9)
#define DMA_IFS_CH8DONE		DMA_IFS_CHxDONE(8)
#define DMA_IFS_CH7DONE		DMA_IFS_CHxDONE(7)
#define DMA_IFS_CH6DONE		DMA_IFS_CHxDONE(6)
#define DMA_IFS_CH5DONE		DMA_IFS_CHxDONE(5)
#define DMA_IFS_CH4DONE		DMA_IFS_CHxDONE(4)
#define DMA_IFS_CH3DONE		DMA_IFS_CHxDONE(3)
#define DMA_IFS_CH2DONE		DMA_IFS_CHxDONE(2)
#define DMA_IFS_CH1DONE		DMA_IFS_CHxDONE(1)
#define DMA_IFS_CH0DONE		DMA_IFS_CHxDONE(0)

/* DMA_IFC */
#define DMA_IFC_ERR		(1 << 31)
#define DMA_IFC_CHxDONE(x)	(1 << (x))
#define DMA_IFC_CH11DONE	DMA_IFC_CHxDONE(11)
#define DMA_IFC_CH10DONE	DMA_IFC_CHxDONE(10)
#define DMA_IFC_CH9DONE		DMA_IFC_CHxDONE(9)
#define DMA_IFC_CH8DONE		DMA_IFC_CHxDONE(8)
#define DMA_IFC_CH7DONE		DMA_IFC_CHxDONE(7)
#define DMA_IFC_CH6DONE		DMA_IFC_CHxDONE(6)
#define DMA_IFC_CH5DONE		DMA_IFC_CHxDONE(5)
#define DMA_IFC_CH4DONE		DMA_IFC_CHxDONE(4)
#define DMA_IFC_CH3DONE		DMA_IFC_CHxDONE(3)
#define DMA_IFC_CH2DONE		DMA_IFC_CHxDONE(2)
#define DMA_IFC_CH1DONE		DMA_IFC_CHxDONE(1)
#define DMA_IFC_CH0DONE		DMA_IFC_CHxDONE(0)

/* DMA_IEN */
#define DMA_IEN_ERR		(1 << 31)
#define DMA_IEN_CHxDONE(x)	(1 << (x))
#define DMA_IEN_CH11DONE	DMA_IEN_CHxDONE(11)
#define DMA_IEN_CH10DONE	DMA_IEN_CHxDONE(10)
#define DMA_IEN_CH9DONE		DMA_IEN_CHxDONE(9)
#define DMA_IEN_CH8DONE		DMA_IEN_CHxDONE(8)
#define DMA_IEN_CH7DONE		DMA_IEN_CHxDONE(7)
#define DMA_IEN_CH6DONE		DMA_IEN_CHxDONE(6)
#define DMA_IEN_CH5DONE		DMA_IEN_CHxDONE(5)
#define DMA_IEN_CH4DONE		DMA_IEN_CHxDONE(4)
#define DMA_IEN_CH3DONE		DMA_IEN_CHxDONE(3)
#define DMA_IEN_CH2DONE		DMA_IEN_CHxDONE(2)
#define DMA_IEN_CH1DONE		DMA_IEN_CHxDONE(1)
#define DMA_IEN_CH0DONE		DMA_IEN_CHxDONE(0)

/* DMA_CTRL */
#define DMA_CTRL_PRDU		(1 << 1)
#define DMA_CTRL_DESCRECT	(1 << 0)

/* DMA_RDS */
#define DMA_RDS_RDSCHx(i)	(1 << (i))
#define DMA_RDS_RDSCH11		DMA_RDS_RDSCHx(11)
#define DMA_RDS_RDSCH10		DMA_RDS_RDSCHx(10)
#define DMA_RDS_RDSCH9		DMA_RDS_RDSCHx(9)
#define DMA_RDS_RDSCH8		DMA_RDS_RDSCHx(8)
#define DMA_RDS_RDSCH7		DMA_RDS_RDSCHx(7)
#define DMA_RDS_RDSCH6		DMA_RDS_RDSCHx(6)
#define DMA_RDS_RDSCH5		DMA_RDS_RDSCHx(5)
#define DMA_RDS_RDSCH4		DMA_RDS_RDSCHx(4)
#define DMA_RDS_RDSCH3		DMA_RDS_RDSCHx(3)
#define DMA_RDS_RDSCH2		DMA_RDS_RDSCHx(2)
#define DMA_RDS_RDSCH1		DMA_RDS_RDSCHx(1)
#define DMA_RDS_RDSCH0		DMA_RDS_RDSCHx(0)

/* DMA_LOOP */
#define DMA_LOOP_EN		(1 << 16)
#define DMA_LOOP_WIDTH_SHIFT	(0)
#define DMA_LOOP_WIDTH_MASK	(0x3FF << DMA_LOOP_WIDTH_SHIFT)
#define DMA_LOOP_WIDTH(v)	\
	(((v) << DMA_LOOP_WIDTH_SHIFT) & DMA_LOOP_WIDTH_MASK)

/* DMA_RECT */
#define DMA_RECT_DSTSTRIDE_SHIFT	(21)
#define DMA_RECT_DSTSTRIDE_MASK		(0x7FF << DMA_RECT_DSTSTRIDE_SHIFT)
#define DMA_RECT_DSTSTRIDE(v)		\
	(((v) << DMA_RECT_DSTSTRIDE_SHIFT) & DMA_RECT_DSTSTRIDE_MASK)

#define DMA_RECT_SRCSTRIDE_SHIFT	(10)
#define DMA_RECT_SRCSTRIDE_MASK		(0x7FF << DMA_RECT_SRCSTRIDE_SHIFT)
#define DMA_RECT_SRCSTRIDE(v)		\
	(((v) << DMA_RECT_SRCSTRIDE_SHIFT) & DMA_RECT_SRCSTRIDE_MASK)

#define DMA_RECT_HEIGHT_SHIFT		(0)
#define DMA_RECT_HEIGHT_MASK		(0x3FF << DMA_RECT_HEIGHT_SHIFT)
#define DMA_RECT_HEIGHT(v)		\
			(((v) << DMA_RECT_HEIGHT_SHIFT) & DMA_RECT_HEIGHT_MASK)

/* DMA_CH_CTRL */
#define DMA_CH_CTRL_SOURCESEL_SHIFT	(16)
#define DMA_CH_CTRL_SOURCESEL_MASK	(0x3F << DMA_CH_CTRL_SOURCESEL_SHIFT)
#define DMA_CH_CTRL_SOURCESEL(v)	\
	(((v) << DMA_CH_CTRL_SOURCESEL_SHIFT) & DMA_CH_CTRL_SOURCESEL_MASK)
#define DMA_CH_CTRL_SOURCESEL_NONE	0b000000
#define DMA_CH_CTRL_SOURCESEL_ADC0	0b001000
#define DMA_CH_CTRL_SOURCESEL_DAC0	0b001010
#define DMA_CH_CTRL_SOURCESEL_USART0	0b001100
#define DMA_CH_CTRL_SOURCESEL_USART1	0b001101
#define DMA_CH_CTRL_SOURCESEL_USART2	0b001110
#define DMA_CH_CTRL_SOURCESEL_LEUART0	0b010000
#define DMA_CH_CTRL_SOURCESEL_LEUART1	0b010001
#define DMA_CH_CTRL_SOURCESEL_I2C0	0b010100
#define DMA_CH_CTRL_SOURCESEL_I2C1	0b010101
#define DMA_CH_CTRL_SOURCESEL_TIMER0	0b011000
#define DMA_CH_CTRL_SOURCESEL_TIMER1	0b011001
#define DMA_CH_CTRL_SOURCESEL_TIMER2	0b011010
#define DMA_CH_CTRL_SOURCESEL_TIMER3	0b011011
#define DMA_CH_CTRL_SOURCESEL_UART0	0b101100
#define DMA_CH_CTRL_SOURCESEL_UART1	0b101101
#define DMA_CH_CTRL_SOURCESEL_MSC	0b110000
#define DMA_CH_CTRL_SOURCESEL_AES	0b110001
#define DMA_CH_CTRL_SOURCESEL_LESENSE	0b110010
#define DMA_CH_CTRL_SOURCESEL_EBI	0b110011

#define DMA_CH_CTRL_SIGSEL_SHIFT	(0)
#define DMA_CH_CTRL_SIGSEL_MASK		(0xF << DMA_CH_CTRL_SIGSEL_SHIFT)
#define DMA_CH_CTRL_SIGSEL(v)		\
	(((v) << DMA_CH_CTRL_SIGSEL_SHIFT) & DMA_CH_CTRL_SIGSEL_MASK)

#define DMA_CH_CTRL_SIGSEL_OFF			0
#define DMA_CH_CTRL_SIGSEL_ADC0SINGLE		0
#define DMA_CH_CTRL_SIGSEL_ADC0SCAN		1
#define DMA_CH_CTRL_SIGSEL_DAC0CH0		0
#define DMA_CH_CTRL_SIGSEL_DAC0CH1		1
#define DMA_CH_CTRL_SIGSEL_USART0RXDATAV	0
#define DMA_CH_CTRL_SIGSEL_USART0TXBL		1
#define DMA_CH_CTRL_SIGSEL_USART0TXEMPTY	2
#define DMA_CH_CTRL_SIGSEL_USART1RXDATAV	0
#define DMA_CH_CTRL_SIGSEL_USART1TXBL		1
#define DMA_CH_CTRL_SIGSEL_USART1TXEMPTY	2
#define DMA_CH_CTRL_SIGSEL_USART1RXDATAVRIGHT	3
#define DMA_CH_CTRL_SIGSEL_USART1TXBLRIGHT	4
#define DMA_CH_CTRL_SIGSEL_USART2RXDATAV	0
#define DMA_CH_CTRL_SIGSEL_USART2TXBL		1
#define DMA_CH_CTRL_SIGSEL_USART2TXEMPTY	2
#define DMA_CH_CTRL_SIGSEL_USART2RXDATAVRIGHT	3
#define DMA_CH_CTRL_SIGSEL_USART2TXBLRIGHT	4
#define DMA_CH_CTRL_SIGSEL_LEUART0RXDATAV	0
#define DMA_CH_CTRL_SIGSEL_LEUART0TXBL		1
#define DMA_CH_CTRL_SIGSEL_LEUART0TXEMPTY	2
#define DMA_CH_CTRL_SIGSEL_LEUART1RXDATAV	0
#define DMA_CH_CTRL_SIGSEL_LEUART1TXBL		1
#define DMA_CH_CTRL_SIGSEL_LEUART1TXEMPTY	2
#define DMA_CH_CTRL_SIGSEL_I2C0RXDATAV		0
#define DMA_CH_CTRL_SIGSEL_I2C0TXBL		1
#define DMA_CH_CTRL_SIGSEL_I2C1RXDATAV		0
#define DMA_CH_CTRL_SIGSEL_I2C1TXBL		1
#define DMA_CH_CTRL_SIGSEL_TIMER0UFOF		0
#define DMA_CH_CTRL_SIGSEL_TIMER0CC0		1
#define DMA_CH_CTRL_SIGSEL_TIMER0CC1		2
#define DMA_CH_CTRL_SIGSEL_TIMER0CC2		3
#define DMA_CH_CTRL_SIGSEL_TIMER1UFOF		0
#define DMA_CH_CTRL_SIGSEL_TIMER1CC0		1
#define DMA_CH_CTRL_SIGSEL_TIMER1CC1		2
#define DMA_CH_CTRL_SIGSEL_TIMER1CC2		3
#define DMA_CH_CTRL_SIGSEL_TIMER2UFOF		0
#define DMA_CH_CTRL_SIGSEL_TIMER2CC0		1
#define DMA_CH_CTRL_SIGSEL_TIMER2CC1		2
#define DMA_CH_CTRL_SIGSEL_TIMER2CC2		3
#define DMA_CH_CTRL_SIGSEL_TIMER3UFOF		0
#define DMA_CH_CTRL_SIGSEL_TIMER3CC0		1
#define DMA_CH_CTRL_SIGSEL_TIMER3CC1		2
#define DMA_CH_CTRL_SIGSEL_TIMER3CC2		3
#define DMA_CH_CTRL_SIGSEL_UART0RXDATAV		0
#define DMA_CH_CTRL_SIGSEL_UART0TXBL		1
#define DMA_CH_CTRL_SIGSEL_UART0TXEMPTY		2
#define DMA_CH_CTRL_SIGSEL_UART1RXDATAV		0
#define DMA_CH_CTRL_SIGSEL_UART1TXBL		1
#define DMA_CH_CTRL_SIGSEL_UART1TXEMPTY		2
#define DMA_CH_CTRL_SIGSEL_MSCWDATA		0
#define DMA_CH_CTRL_SIGSEL_AESDATAWR		0
#define DMA_CH_CTRL_SIGSEL_AESXORDATAWR		1
#define DMA_CH_CTRL_SIGSEL_AESDATARD		2
#define DMA_CH_CTRL_SIGSEL_AESKEYWR		3
#define DMA_CH_CTRL_SIGSEL_LESENSEBUFDATAV	0
#define DMA_CH_CTRL_SIGSEL_EBIPXL0EMPTY		0
#define DMA_CH_CTRL_SIGSEL_EBIPXL1EMPTY		1
#define DMA_CH_CTRL_SIGSEL_EBIPXLFULL		2
#define DMA_CH_CTRL_SIGSEL_EBIDDEMPTY		3

/* generic of above */
#define DMA_CH_CTRL_SIGSEL_ADC_SINGLE		0
#define DMA_CH_CTRL_SIGSEL_ADC_SCAN		1
#define DMA_CH_CTRL_SIGSEL_DAC_CHx(x)		DMA_CH_CTRL_SIGSEL(x)
#define DMA_CH_CTRL_SIGSEL_DAC_CH0		0
#define DMA_CH_CTRL_SIGSEL_DAC_CH1		1
#define DMA_CH_CTRL_SIGSEL_USART_RXDATAV	0
#define DMA_CH_CTRL_SIGSEL_USART_TXBL		1
#define DMA_CH_CTRL_SIGSEL_USART_TXEMPTY	2
#define DMA_CH_CTRL_SIGSEL_USART_RXDATAVRIGHT	3
#define DMA_CH_CTRL_SIGSEL_USART_TXBLRIGHT	4
#define DMA_CH_CTRL_SIGSEL_LEUART_RXDATAV	0
#define DMA_CH_CTRL_SIGSEL_LEUART_TXBL		1
#define DMA_CH_CTRL_SIGSEL_LEUART_TXEMPTY	2
#define DMA_CH_CTRL_SIGSEL_I2C_RXDATAV		0
#define DMA_CH_CTRL_SIGSEL_I2C_TXBL		1
#define DMA_CH_CTRL_SIGSEL_I2C_RXDATAV		0
#define DMA_CH_CTRL_SIGSEL_I2C_TXBL		1
#define DMA_CH_CTRL_SIGSEL_TIMER_UFOF		0
#define DMA_CH_CTRL_SIGSEL_TIMER_CCx(x)		DMA_CH_CTRL_SIGSEL((x) + 1)
#define DMA_CH_CTRL_SIGSEL_TIMER_CC0		DMA_CH_CTRL_SIGSEL_TIMER_CCx(0)
#define DMA_CH_CTRL_SIGSEL_TIMER_CC1		DMA_CH_CTRL_SIGSEL_TIMER_CCx(1)
#define DMA_CH_CTRL_SIGSEL_TIMER_CC2		DMA_CH_CTRL_SIGSEL_TIMER_CCx(3)
#define DMA_CH_CTRL_SIGSEL_UART_RXDATAV		0
#define DMA_CH_CTRL_SIGSEL_UART_TXBL		1
#define DMA_CH_CTRL_SIGSEL_UART_TXEMPTY		2
#define DMA_CH_CTRL_SIGSEL_MSC_WDATA		0
#define DMA_CH_CTRL_SIGSEL_AES_DATA_WR		0
#define DMA_CH_CTRL_SIGSEL_AES_XOR_DATA_WR	1
#define DMA_CH_CTRL_SIGSEL_AES_DATA_RD		2
#define DMA_CH_CTRL_SIGSEL_AES_KEY_WR		3
#define DMA_CH_CTRL_SIGSEL_LESENSE_BUF_DATAV	0
#define DMA_CH_CTRL_SIGSEL_EBI_PXLx_EMPTY(x)	DMA_CH_CTRL_SIGSEL(x)
#define DMA_CH_CTRL_SIGSEL_EBI_PXL0_EMPTY	\
	0
#define DMA_CH_CTRL_SIGSEL_EBI_PXL1_EMPTY	\
	1
#define DMA_CH_CTRL_SIGSEL_EBI_PXL_FULL		2
#define DMA_CH_CTRL_SIGSEL_EBI_DD_EMPTY		3

/**
 * Application needs to allocate (DMA_DESC_CH_SIZE * N) byte
 *   where N is the number of first N channels to use.
 * and this allocated memory needs to be assigned to DMA using
 *   dma_set_desc_address().
 *
 * if the application code needs alternate descriptor facility also.
 *   it needs to allocate the required memory (usually equal to the one above)
 *  and assign the memory using dma_set_alternate_desc_address()
 *
 * rest of the work will be transparently managed by convience functions.
 *
 * all the memory above should be aligned to 256bit
 *   (ie LSB 8bits of array address should be 0)
 *  use gcc's __attribute__((aligned(256)))
 */
#define DMA_DESC_CH_SIZE			(0x4 * 0x4)
#define DMA_DESC_CHx_BASE(base, x)		\
	((base) + ((x) * DMA_DESC_CH_SIZE))
#define DMA_DESC_CHx_SRC_DATA_END_PTR(base, x)	\
	MMIO32(DMA_DESC_CHx_BASE(base, x) + 0x00)
#define DMA_DESC_CHx_DEST_DATA_END_PTR(base, x)	\
	MMIO32(DMA_DESC_CHx_BASE(base, x) + 0x04)
#define DMA_DESC_CHx_CFG(base, x)		\
	MMIO32(DMA_DESC_CHx_BASE(base, x) + 0x08)
#define DMA_DESC_CHx_USER_DATA(base, x)		\
	MMIO32(DMA_DESC_CHx_BASE(base, x) + 0x0C)

/* DMA_DESC_CH_CFG */
#define DMA_DESC_CH_CFG_DEST_INC_SHIFT		(30)
#define DMA_DESC_CH_CFG_DEST_INC_MASK		\
	(0x3 << DMA_DESC_CH_CFG_DEST_INC_SHIFT)
#define DMA_DESC_CH_CFG_DEST_INC(v)		\
	(((v) << DMA_DESC_CH_CFG_DEST_INC_SHIFT) &	\
	DMA_DESC_CH_CFG_DEST_INC_MASK)
#define DMA_DESC_CH_CFG_DEST_INC_BYTE		DMA_DESC_CH_CFG_DEST_INC(0)
#define DMA_DESC_CH_CFG_DEST_INC_HALFWORD	DMA_DESC_CH_CFG_DEST_INC(1)
#define DMA_DESC_CH_CFG_DEST_INC_WORD		DMA_DESC_CH_CFG_DEST_INC(2)
#define DMA_DESC_CH_CFG_DEST_INC_NOINC		DMA_DESC_CH_CFG_DEST_INC(3)

#define DMA_DESC_CH_CFG_DEST_SIZE_SHIFT			(28)
#define DMA_DESC_CH_CFG_DEST_SIZE_MASK		\
	(0x3 << DMA_DESC_CH_CFG_DEST_SIZE_SHIFT)
#define DMA_DESC_CH_CFG_DEST_SIZE(v)		\
	(((v) << DMA_DESC_CH_CFG_DEST_SIZE_SHIFT) &	\
	DMA_DESC_CH_CFG_DEST_SIZE_MASK)
#define DMA_DESC_CH_CFG_DEST_SIZE_BYTE		DMA_DESC_CH_CFG_DEST_SIZE(0)
#define DMA_DESC_CH_CFG_DEST_SIZE_HALFWORD	DMA_DESC_CH_CFG_DEST_SIZE(1)
#define DMA_DESC_CH_CFG_DEST_SIZE_WORD		DMA_DESC_CH_CFG_DEST_SIZE(2)
#define DMA_DESC_CH_CFG_DEST_SIZE_NOINC		DMA_DESC_CH_CFG_DEST_SIZE(3)

#define DMA_DESC_CH_CFG_SRC_INC_SHIFT		(26)
#define DMA_DESC_CH_CFG_SRC_INC_MASK		\
	(0x3 << DMA_DESC_CH_CFG_SRC_INC_SHIFT)
#define DMA_DESC_CH_CFG_SRC_INC(v)		\
	(((v) << DMA_DESC_CH_CFG_SRC_INC_SHIFT) &	\
	DMA_DESC_CH_CFG_SRC_INC_MASK)
#define DMA_DESC_CH_CFG_SRC_INC_BYTE		DMA_DESC_CH_CFG_SRC_INC(0)
#define DMA_DESC_CH_CFG_SRC_INC_HALFWORD	DMA_DESC_CH_CFG_SRC_INC(1)
#define DMA_DESC_CH_CFG_SRC_INC_WORD		DMA_DESC_CH_CFG_SRC_INC(2)
#define DMA_DESC_CH_CFG_SRC_INC_NOINC		DMA_DESC_CH_CFG_SRC_INC(3)

#define DMA_DESC_CH_CFG_SRC_SIZE_SHIFT		(24)
#define DMA_DESC_CH_CFG_SRC_SIZE_MASK		\
	(0x3 << DMA_DESC_CH_CFG_SRC_SIZE_SHIFT)
#define DMA_DESC_CH_CFG_SRC_SIZE(v)		\
	(((v) << DMA_DESC_CH_CFG_SRC_SIZE_SHIFT) &	\
	DMA_DESC_CH_CFG_SRC_SIZE_MASK)
#define DMA_DESC_CH_CFG_SRC_SIZE_BYTE		DMA_DESC_CH_CFG_SRC_SIZE(0)
#define DMA_DESC_CH_CFG_SRC_SIZE_HALFWORD	DMA_DESC_CH_CFG_SRC_SIZE(1)
#define DMA_DESC_CH_CFG_SRC_SIZE_WORD		DMA_DESC_CH_CFG_SRC_SIZE(2)
#define DMA_DESC_CH_CFG_SRC_SIZE_NOINC		DMA_DESC_CH_CFG_SRC_SIZE(3)

#define DMA_DESC_CH_CFG_R_POWER_SHIFT		(14)
#define DMA_DESC_CH_CFG_R_POWER_MASK		\
	(0xF << DMA_DESC_CH_CFG_R_POWER_SHIFT)
#define DMA_DESC_CH_CFG_R_POWER(v)			\
	(((v) << DMA_DESC_CH_CFG_R_POWER_SHIFT) &	\
	DMA_DESC_CH_CFG_R_POWER_MASK)

#define DMA_DESC_CH_CFG_CYCLE_CTRL_SHIFT	(0)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_MASK		\
	(0x7 << DMA_DESC_CH_CFG_CYCLE_CTRL_SHIFT)
#define DMA_DESC_CH_CFG_CYCLE_CTRL(v)		\
	(((v) << DMA_DESC_CH_CFG_CYCLE_CTRL_SHIFT) &	\
	DMA_DESC_CH_CFG_CYCLE_CTRL_MASK)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_INVALD		\
	DMA_DESC_CH_CFG_CYCLE_CTRL(0)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_BASIC		\
	DMA_DESC_CH_CFG_CYCLE_CTRL(1)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_AUTOREQUEST		\
	DMA_DESC_CH_CFG_CYCLE_CTRL(2)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_PINGPONG		\
	DMA_DESC_CH_CFG_CYCLE_CTRL(3)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_MEM_SCAT_GATH_PRIM	\
	DMA_DESC_CH_CFG_CYCLE_CTRL(4)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_MEM_SCAT_GATH_ALT	\
	DMA_DESC_CH_CFG_CYCLE_CTRL(5)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_PERIPH_SCAT_GATH_PRIM	\
	DMA_DESC_CH_CFG_CYCLE_CTRL(6)
#define DMA_DESC_CH_CFG_CYCLE_CTRL_PERIPH_SCAT_GATH_ALT	\
	DMA_DESC_CH_CFG_CYCLE_CTRL(7)

#define DMA_DESC_CH_CFG_DEST_PROT_CTRL_SHIFT	(21)
#define DMA_DESC_CH_CFG_DEST_PROT_CTRL_MASK	\
	(0x7 << DMA_DESC_CH_CFG_DEST_PROT_CTRL_SHIFT)
#define DMA_DESC_CH_CFG_DEST_PROT_CTRL(v)	\
	(((v) << DMA_DESC_CH_CFG_DEST_PROT_CTRL_SHIFT) &	\
	DMA_DESC_CH_CFG_DEST_PROT_CTRL_MASK)

#define DMA_DESC_CH_CFG_SRC_PROT_CTRL_SHIFT	(18)
#define DMA_DESC_CH_CFG_SRC_PROT_CTRL_MASK	\
	(0x7 << DMA_DESC_CH_CFG_SRC_PROT_CTRL_SHIFT)
#define DMA_DESC_CH_CFG_SRC_PROT_CTRL(v)	\
	(((v) << DMA_DESC_CH_CFG_SRC_PROT_CTRL_SHIFT) &	\
	DMA_DESC_CH_CFG_SRC_PROT_CTRL_SHIFT)

#define DMA_DESC_CH_CFG_N_MINUS_1_SHIFT		(4)
#define DMA_DESC_CH_CFG_N_MINUS_1_MASK		\
	(0x3FF << DMA_DESC_CH_CFG_N_MINUS_1_SHIFT)
#define DMA_DESC_CH_CFG_N_MINUS_1(v)		\
	(((v) << DMA_DESC_CH_CFG_N_MINUS_1_SHIFT) &	\
	DMA_DESC_CH_CFG_N_MINUS_1_MASK)

#define DMA_DESC_CH_CFG_NEXT_USEBURST		(1 << 3)

/* DMA Channel Descriptor in structure style */
struct dma_chan_desc {
	uint32_t src_data_end_ptr;
	uint32_t dst_data_end_ptr;
	uint32_t cfg;
	uint32_t user_data;
} __attribute__((packed));

/** @defgroup dma_ch DMA Channel Number
@ingroup dma_defines

@{*/
enum dma_ch {
	DMA_CH0 = 0,
	DMA_CH1,
	DMA_CH2,
	DMA_CH3,
	DMA_CH4,
	DMA_CH5,
	DMA_CH6,
	DMA_CH7,
	DMA_CH8,
	DMA_CH9,
	DMA_CH10,
	DMA_CH11
};
/**@}*/

/* API version for {src, dest} * {size, inc} */
enum dma_mem {
	DMA_MEM_BYTE = 0,
	DMA_MEM_HALF_WORD,
	DMA_MEM_WORD,
	DMA_MEM_NONE
};

/* API version of DMA_DESC_CH_CFG_CYCLE_CTRL_* */
enum dma_mode {
	DMA_MODE_INVALID = 0,
	DMA_MODE_BASIC,
	DMA_MODE_AUTO_REQUEST,
	DMA_MODE_PING_PONG,
	DMA_MODE_MEM_SCAT_GATH_PRIM,
	DMA_MODE_MEM_SCAT_GATH_ALT,
	DMA_MODE_PERIPH_SCAT_GATH_PRIM,
	DMA_MODE_PERIPH_SCAT_GATH_ALT,
};

/* API version of DMA_DESC_CH_CFG_R_POWER() */
enum dma_r_power {
	DMA_R_POWER_1 = 0,
	DMA_R_POWER_2,
	DMA_R_POWER_4,
	DMA_R_POWER_8,
	DMA_R_POWER_16,
	DMA_R_POWER_32,
	DMA_R_POWER_64,
	DMA_R_POWER_128,
	DMA_R_POWER_256,
	DMA_R_POWER_512,
	DMA_R_POWER_1024
};

BEGIN_DECLS

void dma_enable(void);
void dma_disable(void);

bool dma_get_wait_on_request_flag(enum dma_ch ch);

/*bool dma_get_wait_flag(enum dma_ch ch);*/

void dma_enable_with_unprivileged_access(void);
void dma_enable_with_privileged_access(void);

void dma_set_desc_address(uint32_t desc_base);

void dma_generate_software_request(enum dma_ch ch);

void dma_enable_burst_only(enum dma_ch ch);
void dma_enable_single_and_burst(enum dma_ch ch);

void dma_enable_periph_request(enum dma_ch ch);
void dma_disable_periph_request(enum dma_ch ch);

void dma_enable_channel(enum dma_ch ch);
void dma_disable_channel(enum dma_ch ch);

void dma_disable_alternate_structure(enum dma_ch ch);
void dma_enable_alternate_structure(enum dma_ch ch);

void dma_enable_priority(enum dma_ch ch);
void dma_disable_priority(enum dma_ch ch);

bool dma_get_bus_error_flag(void);
void dma_clear_bus_error_flag(void);

bool dma_get_request_flag(enum dma_ch ch);

/*bool dma_get_single_request_flag(enum dma_ch ch);*/

bool dma_get_bus_error_interrupt_flag(void);
bool dma_get_done_interrupt_flag(enum dma_ch ch);

void dma_set_bus_error_interrupt_flag(void);
void dma_set_done_interrupt_flag(enum dma_ch ch);

void dma_clear_bus_error_interrupt_flag(void);
void dma_clear_done_interrupt_flag(enum dma_ch ch);

void dma_enable_bus_error_interrupt(void);
void dma_disable_bus_error_interrupt(void);
void dma_enable_done_interrupt(enum dma_ch ch);
void dma_disable_done_interrupt(enum dma_ch ch);

/* TODO: DMA_CTRL, DMA_RDS, DMA_LOOP0, DMA_LOOP1, DMA_RECT0 */

void dma_set_source(enum dma_ch ch, uint32_t source);
void dma_set_signal(enum dma_ch ch, uint32_t signal);

void dma_channel_reset(enum dma_ch ch);

void dma_set_loop_count(enum dma_ch ch, uint16_t count);
void dma_enable_loop(enum dma_ch ch);
void dma_disable_loop(enum dma_ch ch);

/* descriptor convient function. (prefix "dma_desc_") */
void dma_desc_set_dest_size(uint32_t desc_base, enum dma_ch ch,
		enum dma_mem size);
void dma_desc_set_dest_inc(uint32_t desc_base, enum dma_ch ch,
		enum dma_mem inc);
void dma_desc_set_src_size(uint32_t desc_base, enum dma_ch ch,
		enum dma_mem size);
void dma_desc_set_src_inc(uint32_t desc_base, enum dma_ch ch,
		enum dma_mem inc);

void dma_desc_set_r_power(uint32_t desc_base, enum dma_ch ch,
		enum dma_r_power r_power);

void dma_desc_enable_next_useburst(uint32_t desc_base, enum dma_ch ch);
void dma_desc_disable_next_useburst(uint32_t desc_base, enum dma_ch ch);

void dma_desc_set_count(uint32_t desc_base, enum dma_ch ch, uint16_t count);

void dma_desc_set_user_data(uint32_t desc_base, enum dma_ch ch,
		uint32_t user_data);
uint32_t dma_desc_get_user_data(uint32_t desc_base, enum dma_ch ch);

void dma_desc_set_src_address(uint32_t desc_base, enum dma_ch ch,
		uint32_t src);
void dma_desc_set_dest_address(uint32_t desc_base, enum dma_ch ch,
		uint32_t dest);

void dma_desc_set_mode(uint32_t desc_base, enum dma_ch ch, enum dma_mode mode);

/* based on descriptor convient, macro are passing
 *  {DMA_CTRLBASE, CTRL_ALTCTRLBASE} as per naming */
#define dma_set_dest_size(ch, size)	\
	dma_desc_set_dest_size(DMA_CTRLBASE, ch, size)
#define dma_set_dest_inc(ch, inc)	\
	dma_desc_set_dest_inc(DMA_CTRLBASE, ch, inc)
#define dma_set_src_size(ch, size)	\
	dma_desc_set_src_size(DMA_CTRLBASE, ch, size)
#define dma_set_src_inc(ch, inc)	\
	dma_desc_set_src_inc(DMA_CTRLBASE, ch, inc)

#define dma_set_alt_dest_size(ch, size)	\
	dma_desc_set_dest_size(DMA_ALTCTRLBASE, ch, size)
#define dma_set_alt_dest_inc(ch, inc)	\
	dma_desc_set_dest_inc(DMA_ALTCTRLBASE, ch, inc)
#define dma_set_alt_src_size(ch, size)	\
	dma_desc_set_src_size(DMA_ALTCTRLBASE, ch, size)
#define dma_set_alt_src_inc(ch, inc)	\
	dma_desc_set_src_inc(DMA_ALTCTRLBASE, ch, inc)

#define dma_set_r_power(ch, r_power)				\
			dma_desc_set_r_power(DMA_CTRLBASE, ch, r_power)
#define dma_set_alt_r_power(ch, r_power)			\
			dma_desc_set_r_power(DMA_ALTCTRLBASE, ch, r_power)

#define dma_enable_next_useburst(ch)				\
			dma_desc_enable_next_useburst(DMA_CTRLBASE, ch)
#define dma_disable_next_useburst(ch)				\
			dma_desc_disable_next_useburst(DMA_CTRLBASE, ch)
#define dma_enable_alt_next_useburst(ch)			\
			dma_desc_enable_alt_next_useburst(DMA_CTRLBASE, ch)
#define dma_disable_alt_next_useburst(ch)			\
			dma_desc_disable_alt_next_useburst(DMA_CTRLBASE, ch)

#define dma_set_count(ch, count)				\
			dma_desc_set_count(DMA_CTRLBASE, ch, count)
#define dma_set_alt_count(ch, count)				\
			dma_desc_set_count(DMA_ALTCTRLBASE, ch, count)

#define dma_set_user_data(ch, user_data)			\
			dma_desc_set_user_data(DMA_CTRLBASE, ch, user_data)
#define dma_set_alt_user_data(ch, user_data)		\
			dma_desc_set_user_data(DMA_ALTCTRLBASE, ch, user_data)

#define dma_get_user_data(ch)	\
	dma_desc_get_user_data(DMA_CTRLBASE, ch)
#define dma_get_alt_user_data(ch)	\
	dma_desc_get_user_data(DMA_ALTCTRLBASE, ch)

#define dma_set_src_address(ch, src)				\
			dma_desc_set_src_address(DMA_CTRLBASE, ch, src)
#define dma_set_alt_src_address(ch, src)			\
			dma_desc_set_src_address(DMA_ALTCTRLBASE, ch, src)
#define dma_set_dest_address(ch, dest)				\
			dma_desc_set_dest_address(DMA_CTRLBASE, ch, dest)
#define dma_set_alt_dest_address(ch, dest)			\
			dma_desc_set_dest_address(DMA_ALTCTRLBASE, ch, dest)

#define dma_set_mode(ch, mode)	\
	dma_desc_set_mode(DMA_CTRLBASE, ch, mode)
#define dma_set_alt_mode(ch, mode)	\
	dma_desc_set_mode(DMA_ALTCTRLBASE, ch, mode)

END_DECLS

/**@}*/