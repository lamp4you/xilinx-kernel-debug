/**
  ******************************************************************************
  * @file    solid_dummy_main.h
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
#ifndef   _SOLID_DUMMY_MAIN_H_
#define   _SOLID_DUMMY_MAIN_H_

/* Includes */
#include <linux/netdevice.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/if_vlan.h>
#include <linux/net_tstamp.h>
#include <linux/phy.h>
#include <linux/of_platform.h>
#include <linux/circ_buf.h>
#include <linux/delay.h>
#include <linux/etherdevice.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/of_mdio.h>
#include <linux/of_net.h>
#include <linux/of_platform.h>
#include <linux/of_irq.h>
#include <linux/of_address.h>
#include <linux/of_net.h>
#include <linux/skbuff.h>
#include <linux/spinlock.h>
#include <linux/phy.h>
#include <linux/mii.h>
#include <linux/ethtool.h>
#include <linux/iopoll.h>
#include <linux/ptp_classify.h>
#include <linux/net_tstamp.h>
#include <linux/random.h>
#include <net/sock.h>
#include <linux/xilinx_phy.h>
#include <linux/clk.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup SOLID_DUMMY_MAIN Solid Dummy Main
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Private_Macros Solid Dummy Main Private Macros
  * @{
  */
/* End of SOLID_DUMMY_MAIN_Private_Macros */
/**
  * @}
  */

/* Exported macros ------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Exported_Macros Solid Dummy Main Exported Macros
  * @{
  */

// #define DEBUG_SDUMMY

#define SDUMMY_STATICS_TEST

#define SDUMMY_MAX_QUEUES       1
#define SDUMMY_JUMBO_MTU        9000 /* Max MTU of a jumbo Eth. frame */

/* VLAN Rx & Tx frame support. Default: disabled (cleared) */
#define SDUMMY_OPTION_VLAN      BIT(2)


/*  Default options set when device is initialized or reset */
#define SDUMMY_OPTION_DEFAULTS        (SDUMMY_OPTION_VLAN)


#ifdef    DEBUG_SDUMMY

#ifdef    DEBUG_DEVICE_DRIVER

#define sdummy_debug_enter(fmt, ...) dev_debug_enter(fmt, ##__VA_ARGS__)
#define sdummy_debug_exit(fmt, ...)  dev_debug_exit(fmt, ##__VA_ARGS__)
#define sdummy_debug_msg(fmt, ...)   dev_debug_msg(fmt, ##__VA_ARGS__)

#else  /* DEBUG_DEVICE_DRIVER */

#define MAX_DEBUG_DEPTH             32
#define NUM_OF_BLANK_PER_DEPTH      2

int sdummy_inc_debug_depth(void);
int sdummy_dec_debug_depth(void);
int sdummy_get_debug_depth(void);
void sdummy_debug_printk(const char *file_name, int line_no, int depth, const char *hdr, const char *fmt, ...);

#define sdummy_debug_enter(fmt, ...)  do { sdummy_debug_printk(__FILE__, __LINE__, sdummy_get_debug_depth(), "Enter", fmt, ##__VA_ARGS__); sdummy_inc_debug_depth(); } while(0);
#define sdummy_debug_exit(fmt, ...)   do { sdummy_dec_debug_depth(); sdummy_debug_printk(__FILE__, __LINE__, sdummy_get_debug_depth(), "Exit ", fmt, ##__VA_ARGS__); } while(0);
#define sdummy_debug_msg(fmt, ...)    do { sdummy_debug_printk(__FILE__, __LINE__,  sdummy_get_debug_depth(), NULL, fmt, ##__VA_ARGS__); } while(0);

#endif /* DEBUG_DEVICE_DRIVER */


#else  /* DEBUG_SDUMMY */

#define sdummy_debug_enter(fmt, ...)
#define sdummy_debug_exit(fmt, ...)
#define sdummy_debug_msg(fmt, ...)

#endif /* DEBUG_SDUMMY */

#define sdummy_emerg(dev, fmt, ...)    netdev_emerg_once(dev, fmt, ##__VA_ARGS__)
#define sdummy_alert(dev, fmt, ...)    netdev_alert_once(dev, fmt, ##__VA_ARGS__)
#define sdummy_crit(dev, fmt, ...)     netdev_crit_once(dev, fmt, ##__VA_ARGS__)
#define sdummy_err(dev, fmt, ...)      netdev_err_once(dev, fmt, ##__VA_ARGS__)
#define sdummy_warn(dev, fmt, ...)     netdev_warn(dev, fmt, ##__VA_ARGS__)
#define sdummy_notice(dev, fmt, ...)   netdev_notice(dev, fmt, ##__VA_ARGS__)
#define sdummy_info(dev, fmt, ...)     netdev_info(dev, fmt, ##__VA_ARGS__)

enum sdummy_net_type {
    SDUMMY_ENET_VLAN = 0,
    SDUMMY_ENET_MAX
};


#define SDUMMY_STATS_NETDEV                 0x00000001
#define SDUMMY_STATS_NETLINK                0x00000002
#define SDUMMY_STATS_HW                     0x00000004
#define SDUMMY_STATS_SW                     0x00000008

#define SDUMMY_REG_RX_PACKETS_CNT           0x00000000
#define SDUMMY_REG_TX_PACKETS_CNT           0x00000004
#define SDUMMY_REG_RX_BYTES_CNT             0x00000008
#define SDUMMY_REG_TX_BYTES_CNT             0x0000000C

#define SDUMMY_REG_RX_ERRORS_CNT            0xDEADBEEF
#define SDUMMY_REG_TX_ERRORS_CNT            0xDEADBEEF

#define SDUMMY_REG_RX_DROPPED_CNT           0xDEADBEEF
#define SDUMMY_REG_TX_DROPPED_CNT           0xDEADBEEF

#define SDUMMY_REG_MULTICAST_CNT            0xDEADBEEF
#define SDUMMY_REG_COLLISIONS_CNT           0xDEADBEEF

#define SDUMMY_REG_RX_LENGTH_ERRORS_CNT     0xDEADBEEF
#define SDUMMY_REG_RX_OVER_ERRORS_CNT       0xDEADBEEF
#define SDUMMY_REG_RX_CRC_ERRORS_CNT        0xDEADBEEF

#define SDUMMY_REG_RX_FRAME_ERRORS_CNT      0xDEADBEEF
#define SDUMMY_REG_RX_FIFO_ERRORS_CNT       0xDEADBEEF
#define SDUMMY_REG_RX_MISSED_ERRORS_CNT     0xDEADBEEF

#define SDUMMY_REG_TX_ABORTED_ERRORS_CNT    0xDEADBEEF
#define SDUMMY_REG_TX_CARRIER_ERRORS_CNT    0xDEADBEEF
#define SDUMMY_REG_TX_FIFO_ERRORS_CNT       0xDEADBEEF
#define SDUMMY_REG_TX_HEARTBEAT_ERRORS_CNT  0xDEADBEEF
#define SDUMMY_REG_TX_WINDOW_ERRORS_CNT     0xDEADBEEF

#define SDUMMY_REG_RX_COMPRESSED_CNT        0xDEADBEEF
#define SDUMMY_REG_TX_COMPRESSED_CNT        0xDEADBEEF

#define SDUMMY_REG_RX_NOHANDLER_CNT         0xDEADBEEF

#define SDUMMY_REG_RX_EARLY_CNT             0xDEADBEEF
#define SDUMMY_REG_RX_LATE_CNT              0xDEADBEEF


enum enum_stat_id {

    SDUMMY_RX_PACKETS_STAT_ID = 0,
    SDUMMY_TX_PACKETS_STAT_ID,
    SDUMMY_RX_BYTES_STAT_ID,
    SDUMMY_TX_BYTES_STAT_ID,

    SDUMMY_RX_ERRORS_STAT_ID,
    SDUMMY_TX_ERRORS_STAT_ID,
    
    SDUMMY_RX_DROPPED_STAT_ID,
    SDUMMY_TX_DROPPED_STAT_ID,

    SDUMMY_MULTICAST_STAT_ID,
    SDUMMY_COLLISIONS_STAT_ID,

    SDUMMY_RX_LENGTH_ERRORS_STAT_ID,
    SDUMMY_RX_OVER_ERRORS_STAT_ID,
    SDUMMY_RX_CRC_ERRORS_STAT_ID,

    SDUMMY_RX_FRAME_ERRORS_STAT_ID,
    SDUMMY_RX_FIFO_ERRORS_STAT_ID,
    SDUMMY_RX_MISSED_ERRORS_STAT_ID,

    SDUMMY_TX_ABORTED_ERRORS_STAT_ID,
    SDUMMY_TX_CARRIER_ERRORS_STAT_ID,
    SDUMMY_TX_FIFO_ERRORS_STAT_ID,
    SDUMMY_TX_HEARTBEAT_ERRORS_STAT_ID,
    SDUMMY_TX_WINDOW_ERRORS_STAT_ID,

    SDUMMY_RX_COMPRESSED_STAT_ID,
    SDUMMY_TX_COMPRESSED_STAT_ID,

    SDUMMY_RX_NOHANDLER_STAT_ID,

    SDUMMY_RX_EARLY_STAT_ID,
    SDUMMY_RX_LATE_STAT_ID,

    SDUMMY_STAT_ID_MAX

};


#define SDUMMY_NETDEV_STAT_HW(m, reg_name) { \
    .stat_id = SDUMMY_ ## reg_name ## _STAT_ID, \
    .stat_string = # m, \
    .type_flag = SDUMMY_STATS_HW, \
    .sizeof_stat = sizeof(((struct sdummy_stats *)0)->m), \
    .offset_stat = offsetof(struct sdummy_stats, m), \
    .reg_offset = SDUMMY_REG_ ## reg_name ## _CNT \
}

#define SDUMMY_NETDEV_STAT_SW(m, reg_name) { \
    .stat_id = SDUMMY_ ## reg_name ## _STAT_ID, \
    .stat_string = # m, \
    .type_flag = SDUMMY_STATS_SW, \
    .sizeof_stat = sizeof(((struct sdummy_stats *)0)->m), \
    .offset_stat = offsetof(struct sdummy_stats, m), \
    .reg_offset = 0 \
}


/* End of SOLID_DUMMY_MAIN_Exported_Macros */
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Private_Types Solid Dummy Main Private Types
  * @{
  */
/* End of SOLID_DUMMY_MAIN_Private_Types */
/**
  * @}
  */

/* Exported types -------------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Exported_Types Solid Dummy Main Exported Types
  * @{
  */

struct sdummy_local;

struct sdummy_config_s {
    const char *name;
};


struct sdummy_stats_info;

struct sdummy_stats_info {
    int stat_id;
    int type_flag;
    char stat_string[ETH_GSTRING_LEN];
    int sizeof_stat;
    int offset_stat;
    int reg_offset;
};


/* Statistics counters collected by the MAC */
struct sdummy_stats
{
    /* The main device statistics structure */
    u64   rx_packets;         /* total packets received       */
    u64   tx_packets;         /* total packets transmitted    */
    u64   rx_bytes;           /* total bytes received         */
    u64   tx_bytes;           /* total bytes transmitted      */
    u64   rx_errors;          /* bad packets received         */
    u64   tx_errors;          /* packet transmit problems     */
    u64   rx_dropped;         /* no space in linux buffers    */
    u64   tx_dropped;         /* no space available in linux  */
    u64   multicast;          /* multicast packets received   */
    u64   collisions;

    /* detailed rx_errors: */
    u64   rx_length_errors;
    u64   rx_over_errors;     /* receiver ring buff overflow  */
    u64   rx_crc_errors;      /* recved pkt with crc error    */
    u64   rx_frame_errors;    /* recv'd frame alignment error */
    u64   rx_fifo_errors;     /* recv'r fifo overrun          */
    u64   rx_missed_errors;   /* receiver missed packet       */

    /* detailed tx_errors */
    u64   tx_aborted_errors;
    u64   tx_carrier_errors;
    u64   tx_fifo_errors;
    u64   tx_heartbeat_errors;
    u64   tx_window_errors;

    /* for cslip etc */
    u64   rx_compressed;
    u64   tx_compressed;

    u64   rx_nohandler;       /* dropped, no handler found    */

    /* */
    u64   rx_early;           /* dropped, no handler found    */
    u64   rx_late;            /* dropped, no handler found    */
    
};

struct sdummy_local;

struct sdummy_local {
    struct net_device *ndev;
    struct device *dev;

    /* IO registers */
    void __iomem *regs;

    /* hardware IO accessors */
    int (*sdummy_reg_read_u32)(struct net_device *ndev, int offset, u32 *value);
    int (*sdummy_reg_write_u32)(struct net_device *ndev, int offset, u32 *value);
    int (*sdummy_reg_read_u64)(struct net_device *ndev, int offset, u64 *value);
    int (*sdummy_reg_write_u64)(struct net_device *ndev, int offset, u64 *value);

    netdev_features_t features;
    u32 options;                /* Current options word */

    u16 num_tx_queues;          /* Number of TX DMA queues */
    u16 num_rx_queues;          /* Number of RX DMA queues */

	u32 msg_enable;
    bool link_active;
    u16 link_speed;

    spinlock_t stats64_lock;            /* protects statistics counters */
    struct net_device_stats     netdev_stat;
    struct rtnl_link_stats64    netlink_stat64;
    struct sdummy_stats         stats;    
    
};

struct pcpu_dstats {
	u64			tx_packets;
	u64			tx_bytes;
	struct u64_stats_sync	syncp;
};

/* End of SOLID_DUMMY_MAIN_Exported_Types */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Private_Variables Solid Dummy Main Private Variables
  * @{
  */
/* End of SOLID_DUMMY_MAIN_Private_Variables */
/**
  * @}
  */

/* Exported variables ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Exported_Variables Solid Dummy Main Exported Variables
  * @{
  */
/* End of SOLID_DUMMY_MAIN_Exported_Variables */
/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Private_Functions Solid Dummy Main Private Functions
  * @{
  */
static inline const char *sdummy_dev_name(const struct net_device *ndev)
{
    if(ndev) {
        return (const char *)ndev->name;
    }
    else {
        return (const char *)"-";
    }
}

/* End of SOLID_DUMMY_MAIN_Private_Functions */
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup SOLID_DUMMY_MAIN_Exported_Functions Solid Dummy Main Exported Functions
  * @{
  */
void sdummy_get_driver_info(struct net_device *ndev, struct ethtool_drvinfo *drvinfo);
void sdummy_set_netdev_ops(struct net_device *netdev);
void sdummy_set_ethtool_ops(struct net_device *netdev);
void sdummy_update_stats(struct net_device *ndev);


#ifdef    DEBUG_SDUMMY
#ifndef   DEBUG_DEVICE_DRIVER

int sdummy_inc_debug_depth(void);
int sdummy_dec_debug_depth(void);
int sdummy_get_debug_depth(void);
void sdummy_debug_printk(const char *file_name, int line_no, int depth, const char *hdr, const char *fmt, ...);

#endif /* DEBUG_DEVICE_DRIVER */
#endif /* DEBUG_SDUMMY */

/* End of SOLID_DUMMY_MAIN_Exported_Functions */
/**
  * @}
  */

/* End of SOLID_DUMMY_MAIN */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* _SOLID_DUMMY_MAIN_H_ */

