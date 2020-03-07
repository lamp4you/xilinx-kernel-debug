/**
  ******************************************************************************
  * @file    solid_dummy_net.h
  * @author  SOLiD Software 1 Team
  * @brief   <USER UPDATE>
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy;Copyright (c) 2017, SOLiD, Inc.  All rights reserved.</center></h2>
  *
  * This Software is the property of SOLiD. The Software and all
  * accompanying documentation are copyrighted.  The Software made available
  * here constitutes the proprietary information of SOLiD.  You
  * agree to take reasonable steps to prevent the disclosure, unauthorized use
  * or unauthorized distribution of the Software.
  *
  * Except as expressly permitted in a separate Software License Agreement
  * between You and SOLiD, you shall not modify, decompile,
  * disassemble, extract, or otherwise reverse engineer this Software.  You
  * shall not make any copy of the Software or its accompanying documentation,
  * except for copying incident to the ordinary and intended use of the
  * Software and the Underlying Program and except for the making of a single
  * archival copy.
  *
  * This Software, including technical data, may be subject to U.S. export
  * control laws, including the U.S.  Export Administration Act and its
  * associated regulations, and may be subject to export or import regulations
  * in other countries.  You warrant that You will comply strictly in all
  * respects with all such regulations and acknowledge that you have the
  * responsibility to obtain licenses to export, re-export or import the
  * Software.
  *
  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
  * AND WITH ALL FAULTS AND SOLiD MAKES NO PROMISES, REPRESENTATIONS OR
  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
  * TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
  * REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
  * DEFECTS, AND SOLID SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
  * OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
  * PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET
  * POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT
  * OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
  *
  ******************************************************************************
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef   _SOLID_DUMMY_NET_H_
#define   _SOLID_DUMMY_NET_H_

/* Includes */
#include <linux/netdevice.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/if_vlan.h>
#include <linux/net_tstamp.h>
#include <linux/phy.h>
#include <linux/of_platform.h>


#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup SOLID_DUMMY_NET Solid Dummy Net
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Private_Macros Solid Dummy Net Private Macros
  * @{
  */
/* End of SOLID_DUMMY_NET_Private_Macros */
/**
  * @}
  */

/* Exported macros ------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Exported_Macros Solid Dummy Net Exported Macros
  * @{
  */

#define SOLID_DUMMY_MAX_QUEUES		1

enum sdummy_net_type {
	SDUMMY_ENET_VLAN = 0,
    SDUMMY_ENET_MAX
};


/* End of SOLID_DUMMY_NET_Exported_Macros */
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Private_Types Solid Dummy Net Private Types
  * @{
  */
/* End of SOLID_DUMMY_NET_Private_Types */
/**
  * @}
  */

/* Exported types -------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Exported_Types Solid Dummy Net Exported Types
  * @{
  */

struct sdummy_net_local;

struct sdummy_net_dma_q {
    
	struct sdummy_net_local	*lp; /* parent */

	spinlock_t tx_lock;		/* tx lock */
	spinlock_t rx_lock;		/* rx lock */

	unsigned long tx_packets;
	unsigned long tx_bytes;
	unsigned long rx_packets;
	unsigned long rx_bytes;

#if 0
	void __iomem *dma_regs;

	int tx_irq;
	int rx_irq;


	/* Buffer descriptors */
	struct axidma_bd *tx_bd_v;
	struct axidma_bd *rx_bd_v;
	dma_addr_t rx_bd_p;
	dma_addr_t tx_bd_p;

	unsigned char *tx_buf[XAE_TX_BUFFERS];
	unsigned char *tx_bufs;
	dma_addr_t tx_bufs_dma;
	bool eth_hasdre;

	u32 tx_bd_ci;
	u32 rx_bd_ci;
	u32 tx_bd_tail;

	/* MCDMA fields */
	u16 chan_id;
	u32 rx_offset;
	struct aximcdma_bd *txq_bd_v;
	struct aximcdma_bd *rxq_bd_v;

    
#endif

};


struct sdummy_net_config_s {

#if 1

	enum dummy_net_type mactype;

#else
	void (*setoptions)(struct net_device *ndev, u32 options);
	int (*clk_init)(struct platform_device *pdev, struct clk **axi_aclk,
			struct clk **axis_clk, struct clk **ref_clk,
			struct clk **dclk);
	u32 tx_ptplen;
#endif

};



struct sdummy_net_local 
{
	struct net_device *ndev;
	struct device *dev;

	u16 num_tx_queues;	    /* Number of TX DMA queues */
	u16 num_rx_queues;	    /* Number of RX DMA queues */

	/* IO registers, dma functions and IRQs */
	void __iomem *regs;

	u32 features;
	u32 options;			/* Current options word */

#if 0

	/* Connection to PHY device */
	struct device_node *phy_node;

	/* MDIO bus data */
	struct mii_bus *mii_bus;	/* MII bus reference */

	void __iomem *mcdma_regs;

	struct tasklet_struct dma_err_tasklet[XAE_MAX_QUEUES];
	struct napi_struct napi[XAE_MAX_QUEUES];	/* NAPI Structure */

	#define XAE_TEMAC1 0
	#define XAE_TEMAC2 1
	u8     temac_no;
	struct axienet_dma_q *dq[XAE_MAX_QUEUES];	/* DAM queue data*/

	phy_interface_t phy_mode;

	bool is_tsn;
#ifdef CONFIG_XILINX_TSN
	u16    num_tc;		/* Number of TSN Traffic classes */
#ifdef CONFIG_XILINX_TSN_PTP
	void *timer_priv;
	int ptp_tx_irq;
	int ptp_rx_irq;
	int rtc_irq;
	int qbv_irq;
	int ptp_ts_type;
	u8  ptp_rx_hw_pointer;
	u8  ptp_rx_sw_pointer;
	struct sk_buff_head ptp_txq;
	struct work_struct tx_tstamp_work;
	spinlock_t ptp_tx_lock;		/* TSN PTP tx lock*/
#endif
#endif
	int eth_irq;

	u32 last_link;

	u32 max_frm_size;
	u32 rxmem;

	int csum_offload_on_tx_path;
	int csum_offload_on_rx_path;

	u32 coalesce_count_rx;
	u32 coalesce_count_tx;
	u32 phy_interface;
	u32 phy_flags;
	bool eth_hasnobuf;
	bool eth_hasptp;
	const struct axienet_config *axienet_config;

#if defined (CONFIG_XILINX_AXI_EMAC_HWTSTAMP) || defined (CONFIG_XILINX_TSN_PTP)
	void __iomem *tx_ts_regs;
	void __iomem *rx_ts_regs;
	struct hwtstamp_config tstamp_config;
	u8 *tx_ptpheader;
#endif
	struct clk *aclk;
	struct clk *eth_sclk;
	struct clk *eth_refclk;
	struct clk *eth_dclk;
	struct clk *dma_sg_clk;
	struct clk *dma_rx_clk;
	struct clk *dma_tx_clk;

	/* MCDMA Fields */
	int qnum[XAE_MAX_QUEUES];
	int chan_num[XAE_MAX_QUEUES];
	/* WRR Fields */
	u16 chan_id;
	u16 weight;

	u32 usxgmii_rate;
	u8 dma_mask;
#endif

};



/* End of SOLID_DUMMY_NET_Exported_Types */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Private_Variables Solid Dummy Net Private Variables
  * @{
  */
/* End of SOLID_DUMMY_NET_Private_Variables */
/**
  * @}
  */

/* Exported variables ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Exported_Variables Solid Dummy Net Exported Variables
  * @{
  */


/* End of SOLID_DUMMY_NET_Exported_Variables */
/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Private_Functions Solid Dummy Net Private Functions
  * @{
  */
/* End of SOLID_DUMMY_NET_Private_Functions */
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_NET_Exported_Functions Solid Dummy Net Exported Functions
  * @{
  */

void sdummy_net_set_mac_address(struct net_device *ndev, const void *address);


/* End of SOLID_DUMMY_NET_Exported_Functions */
/**
  * @}
  */

/* End of SOLID_DUMMY_NET */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* _SOLID_DUMMY_NET_H_ */

