/**
  ******************************************************************************
  * @file    solid_dummy_ethtool.c
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
/* Includes */
#include "solid_dummy_main.h"

/** @addtogroup SOLID_DUMMY_ETHTOOL
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_ETHTOOL_Private_Macros
  * @{
  */
/* End of SOLID_DUMMY_ETHTOOL_Private_Macros */
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_ETHTOOL_Private_Types
  * @{
  */
/* End of SOLID_DUMMY_ETHTOOL_Private_Types */
/**
  * @}
  */

/* Private functions Prototype ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_ETHTOOL_Private_Functions
  * @{
  */

/* 
    struct ethtool_ops 
*/

#if 0
static int sdummy_ethtools_get_settings(struct net_device *ndev, struct ethtool_cmd *cmd);
static int sdummy_ethtools_set_settings(struct net_device *ndev, struct ethtool_cmd *cmd);
#endif 

static void sdummy_ethtools_get_drvinfo(struct net_device *ndev, struct ethtool_drvinfo *drvinfo);
static int sdummy_ethtools_get_regs_len(struct net_device *ndev);
static void sdummy_ethtools_get_regs(struct net_device *ndev, struct ethtool_regs *regs, void *p);

#if 0
static void sdummy_ethtools_get_wol(struct net_device *ndev, struct ethtool_wolinfo *wolinfo);
static int sdummy_ethtools_set_wol(struct net_device *ndev, struct ethtool_wolinfo *wolinfo);
#endif

static u32 sdummy_ethtools_get_msglevel(struct net_device *ndev);
static void sdummy_ethtools_set_msglevel(struct net_device *ndev, u32 value);

#if 0
static int sdummy_ethtools_nway_reset(struct net_device *ndev);
#endif

static u32 sdummy_ethtools_get_link(struct net_device *ndev);

#if 0
static int sdummy_ethtools_get_eeprom_len(struct net_device *ndev);
static int sdummy_ethtools_get_eeprom(struct net_device *ndev, struct ethtool_eeprom *eeprom, u8 *value);
static int sdummy_ethtools_set_eeprom(struct net_device *ndev, struct ethtool_eeprom *eeprom, u8 *value);

static int sdummy_ethtools_get_coalesce(struct net_device *ndev, struct ethtool_coalesce *coalesce);
static int sdummy_ethtools_set_coalesce(struct net_device *ndev, struct ethtool_coalesce *coalesce);

static void sdummy_ethtools_get_ringparam(struct net_device *ndev, struct ethtool_ringparam *ringparam);
static int sdummy_ethtools_set_ringparam(struct net_device *ndev, struct ethtool_ringparam *ringparam);

static void sdummy_ethtools_get_pauseparam(struct net_device *ndev, struct ethtool_pauseparam *pauseparam);
static int sdummy_ethtools_set_pauseparam(struct net_device *ndev, struct ethtool_pauseparam *pauseparam);
#endif

static void sdummy_ethtools_self_test(struct net_device *ndev, struct ethtool_test *tst, u64 *value);
static void sdummy_ethtools_get_strings(struct net_device *ndev, u32 stringset, u8 *value);
static int sdummy_ethtools_set_phys_id(struct net_device *ndev, enum ethtool_phys_id_state phys_id_state);
static void sdummy_ethtools_get_ethtool_stats(struct net_device *ndev, struct ethtool_stats *stats, u64 *value);

#if 0

static int sdummy_ethtools_begin(struct net_device *ndev);
static void sdummy_ethtools_complete(struct net_device *ndev);
static u32 sdummy_ethtools_get_priv_flags(struct net_device *ndev);
static int sdummy_ethtools_set_priv_flags(struct net_device *ndev, u32 value);

#endif
static int sdummy_ethtools_get_sset_count(struct net_device *ndev, int sset);

#if 0
static int sdummy_ethtools_get_rxnfc(struct net_device *ndev, struct ethtool_rxnfc *rxnfc, u32 *rule_locs);
static int sdummy_ethtools_set_rxnfc(struct net_device *ndev, struct ethtool_rxnfc *rxnfc);

static int sdummy_ethtools_flash_device(struct net_device *ndev, struct ethtool_flash *flash);
#endif

static int sdummy_ethtools_reset(struct net_device *ndev, u32 *value);

#if 0
static u32 sdummy_ethtools_get_rxfh_key_size(struct net_device *ndev);
static u32 sdummy_ethtools_get_rxfh_indir_size(struct net_device *ndev);
static int sdummy_ethtools_get_rxfh(struct net_device *ndev, u32 *indir, u8 *key, u8 *hfunc);
static int sdummy_ethtools_set_rxfh(struct net_device *ndev, const u32 *indir, const u8 *key, const u8 hfunc);
static int sdummy_ethtools_get_rxfh_context(struct net_device *ndev, u32 *indir, u8 *key, u8 *hfunc, u32 rss_context);
static int sdummy_ethtools_set_rxfh_context(struct net_device *ndev, const u32 *indir, const u8 *key, const u8 hfunc, u32 *rss_context, bool delete);
#endif

static void sdummy_ethtools_get_channels(struct net_device *ndev, struct ethtool_channels *chan);
static int sdummy_ethtools_set_channels(struct net_device *ndev, struct ethtool_channels *chan);

#if 0
static int sdummy_ethtools_get_dump_flag(struct net_device *ndev, struct ethtool_dump *dump);
static int sdummy_ethtools_get_dump_data(struct net_device *ndev, struct ethtool_dump *dump, void *p);
static int sdummy_ethtools_set_dump(struct net_device *ndev, struct ethtool_dump *dump);

static int sdummy_ethtools_get_ts_info(struct net_device *ndev, struct ethtool_ts_info *ts_info);

static int sdummy_ethtools_get_module_info(struct net_device *ndev, struct ethtool_modinfo *modinfo);
static int sdummy_ethtools_get_module_eeprom(struct net_device *ndev, struct ethtool_eeprom *eeprom, u8 *value);

static int sdummy_ethtools_get_eee(struct net_device *ndev, struct ethtool_eee *eee);
static int sdummy_ethtools_set_eee(struct net_device *ndev, struct ethtool_eee *eee);

static int sdummy_ethtools_get_tunable(struct net_device *ndev, const struct ethtool_tunable *tunable, void *p);
static int sdummy_ethtools_set_tunable(struct net_device *ndev, const struct ethtool_tunable *tunable, const void *p);

static int sdummy_ethtools_get_per_queue_coalesce(struct net_device *ndev, u32 value, struct ethtool_coalesce *coalesce);
static int sdummy_ethtools_set_per_queue_coalesce(struct net_device *ndev, u32 value, struct ethtool_coalesce *coalesce);
#endif

static int sdummy_ethtools_get_link_ksettings(struct net_device *ndev, struct ethtool_link_ksettings *cmd);
static int sdummy_ethtools_set_link_ksettings(struct net_device *ndev, const struct ethtool_link_ksettings *cmd);

#if 0
static int sdummy_ethtools_get_fecparam(struct net_device *ndev, struct ethtool_fecparam *fecparam);
static int sdummy_ethtools_set_fecparam(struct net_device *ndev, struct ethtool_fecparam *fecparam);
#endif

static void sdummy_ethtools_get_ethtool_phy_stats(struct net_device *ndev, struct ethtool_stats *stats, u64 *value);
static int sdummy_update_stats_sw(struct net_device *ndev, const struct sdummy_stats_info *stats_info);
static int sdummy_update_netdev_stats(struct net_device *ndev);
static int sdummy_update_netlink_stats(struct net_device *ndev);


/* End of SOLID_DUMMY_ETHTOOL_Private_Functions */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_ETHTOOL_Private_Variables
  * @{
  */
  
static const struct ethtool_ops sdummy_ethtool_ops = {

    // replaced sdummy_ethtools_get_link_ksettings / sdummy_ethtools_set_link_ksettings
    // Don't need to implement : .get_settings                    = sdummy_ethtools_get_settings,
    // Don't need to implement : .set_settings                    = sdummy_ethtools_set_settings,

    .get_drvinfo                     = sdummy_ethtools_get_drvinfo,
    .get_regs_len                    = sdummy_ethtools_get_regs_len,
    .get_regs                        = sdummy_ethtools_get_regs,

    // Wake-On-Lan configuration
    // Don't need to implement : .get_wol                         = sdummy_ethtools_get_wol,         
    // Don't need to implement : .set_wol                         = sdummy_ethtools_set_wol,         

    .get_msglevel                    = sdummy_ethtools_get_msglevel,
    .set_msglevel                    = sdummy_ethtools_set_msglevel,
    
    // Don't need to implement : .nway_reset                      = sdummy_ethtools_nway_reset,      // Don't need to implement 

    .get_link                        = sdummy_ethtools_get_link,

    // Don't need to implement : .get_eeprom_len                  = sdummy_ethtools_get_eeprom_len,
    // Don't need to implement : .get_eeprom                      = sdummy_ethtools_get_eeprom,    
    // Don't need to implement : .set_eeprom                      = sdummy_ethtools_set_eeprom,    
    
    // Don't need to implement : .get_coalesce                    = sdummy_ethtools_get_coalesce,    
    // Don't need to implement : .set_coalesce                    = sdummy_ethtools_set_coalesce,    
    
    // Don't need to implement : .get_ringparam                   = sdummy_ethtools_get_ringparam,   
    // Don't need to implement : .set_ringparam                   = sdummy_ethtools_set_ringparam,   
    
    // Don't need to implement : .get_pauseparam                  = sdummy_ethtools_get_pauseparam,  
    // Don't need to implement : .set_pauseparam                  = sdummy_ethtools_set_pauseparam,  
    
    .self_test                       = sdummy_ethtools_self_test,
    .get_strings                     = sdummy_ethtools_get_strings,
    .set_phys_id                     = sdummy_ethtools_set_phys_id,
    .get_ethtool_stats               = sdummy_ethtools_get_ethtool_stats,
    
    // Don't need to implement : .begin                           = sdummy_ethtools_begin,           
    // Don't need to implement : .complete                        = sdummy_ethtools_complete,            

    // Don't need to implement : .get_priv_flags                  = sdummy_ethtools_get_priv_flags,
    // Don't need to implement : .set_priv_flags                  = sdummy_ethtools_set_priv_flags,
    
    .get_sset_count                  = sdummy_ethtools_get_sset_count,

    // command to get or set RX flow classification rules
    // Don't need to implement : .get_rxnfc                       = sdummy_ethtools_get_rxnfc,       
    // Don't need to implement : .set_rxnfc                       = sdummy_ethtools_set_rxnfc,      

    // firmware flashing related parameters 
    // Don't need to implement : .flash_device                    = sdummy_ethtools_flash_device,
    
    .reset                           = sdummy_ethtools_reset,

    /* Get/Set RX flow hash configuration */
    // Don't need to implement : .get_rxfh_key_size               = sdummy_ethtools_get_rxfh_key_size,
    // Don't need to implement : .get_rxfh_indir_size             = sdummy_ethtools_get_rxfh_indir_size,
    // Don't need to implement : .get_rxfh                        = sdummy_ethtools_get_rxfh,
    // Don't need to implement : .set_rxfh                        = sdummy_ethtools_set_rxfh,
    // Don't need to implement : .get_rxfh_context                = sdummy_ethtools_get_rxfh_context,
    // Don't need to implement : .set_rxfh_context                = sdummy_ethtools_set_rxfh_context,
    
    .get_channels                    = sdummy_ethtools_get_channels,
    .set_channels                    = sdummy_ethtools_set_channels,
    
    // Don't need to implement : .get_dump_flag                   = sdummy_ethtools_get_dump_flag,
    // Don't need to implement : .get_dump_data                   = sdummy_ethtools_get_dump_data,
    // Don't need to implement : .set_dump                        = sdummy_ethtools_set_dump,
    
    // Don't need to implement : .get_ts_info                     = sdummy_ethtools_get_ts_info,
    
    // Don't need to implement : .get_module_info                 = sdummy_ethtools_get_module_info,
    // Don't need to implement : .get_module_eeprom               = sdummy_ethtools_get_module_eeprom,
    
    // Don't need to implement : .get_eee                         = sdummy_ethtools_get_eee,
    // Don't need to implement : .set_eee                         = sdummy_ethtools_set_eee,
    
    // Don't need to implement : .get_tunable                     = sdummy_ethtools_get_tunable,
    // Don't need to implement : .set_tunable                     = sdummy_ethtools_set_tunable,
    
    // Don't need to implement : .get_per_queue_coalesce          = sdummy_ethtools_get_per_queue_coalesce,
    // Don't need to implement : .set_per_queue_coalesce          = sdummy_ethtools_set_per_queue_coalesce,
    
    .get_link_ksettings              = sdummy_ethtools_get_link_ksettings,
    .set_link_ksettings              = sdummy_ethtools_set_link_ksettings,

    // Don't need to implement : .get_fecparam                    = sdummy_ethtools_get_fecparam,
    // Don't need to implement : .set_fecparam                    = sdummy_ethtools_set_fecparam,

    .get_ethtool_phy_stats           = sdummy_ethtools_get_ethtool_phy_stats
};


const struct sdummy_stats_info sdummy_gstrings_stats_tbl[] = 
{

    SDUMMY_NETDEV_STAT_HW(rx_packets, RX_PACKETS),
    SDUMMY_NETDEV_STAT_HW(tx_packets, TX_PACKETS),

    SDUMMY_NETDEV_STAT_HW(rx_bytes, RX_BYTES),
    SDUMMY_NETDEV_STAT_HW(tx_bytes, TX_BYTES),
    
    SDUMMY_NETDEV_STAT_SW(rx_errors, RX_ERRORS),
    SDUMMY_NETDEV_STAT_SW(tx_errors, TX_ERRORS),

    SDUMMY_NETDEV_STAT_HW(rx_dropped, RX_DROPPED),
    SDUMMY_NETDEV_STAT_HW(tx_dropped, TX_DROPPED),

    SDUMMY_NETDEV_STAT_HW(multicast, MULTICAST),
    SDUMMY_NETDEV_STAT_HW(collisions, COLLISIONS),

    SDUMMY_NETDEV_STAT_HW(rx_length_errors, RX_LENGTH_ERRORS),
    SDUMMY_NETDEV_STAT_HW(rx_over_errors, RX_OVER_ERRORS),
    SDUMMY_NETDEV_STAT_HW(rx_crc_errors, RX_CRC_ERRORS),

    SDUMMY_NETDEV_STAT_HW(rx_frame_errors, RX_FRAME_ERRORS),
    SDUMMY_NETDEV_STAT_HW(rx_fifo_errors, RX_FIFO_ERRORS),
    SDUMMY_NETDEV_STAT_HW(rx_missed_errors, RX_MISSED_ERRORS),

    SDUMMY_NETDEV_STAT_HW(tx_aborted_errors, TX_ABORTED_ERRORS),
    SDUMMY_NETDEV_STAT_HW(tx_carrier_errors, TX_CARRIER_ERRORS),
    SDUMMY_NETDEV_STAT_HW(tx_fifo_errors, TX_FIFO_ERRORS),
    SDUMMY_NETDEV_STAT_HW(tx_heartbeat_errors, TX_HEARTBEAT_ERRORS),

    SDUMMY_NETDEV_STAT_HW(rx_compressed, RX_COMPRESSED),
    SDUMMY_NETDEV_STAT_HW(tx_compressed, TX_COMPRESSED),

    SDUMMY_NETDEV_STAT_HW(rx_nohandler, RX_NOHANDLER),

    SDUMMY_NETDEV_STAT_HW(rx_early, RX_EARLY),
    SDUMMY_NETDEV_STAT_SW(rx_late, RX_LATE)

};

#define SDUMMY_STATS_LEN ARRAY_SIZE(sdummy_gstrings_stats_tbl)


/* End of SOLID_DUMMY_ETHTOOL_Private_Variables */
/**
  * @}
  */

/* Exported variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_ETHTOOL_Exported_Variables
  * @{
  */
/* End of SOLID_DUMMY_ETHTOOL_Exported_Variables */
/**
  * @}
  */

/* Private functions ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_ETHTOOL_Private_Functions
  * @{
  */

#if 0

static int sdummy_ethtools_get_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_settings : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_settings is under construction !!!\n");    
    sdummy_debug_exit(".get_settings : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_settings : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_settings is under construction !!!\n");    
    sdummy_debug_exit(".set_settings : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#endif 

static void sdummy_ethtools_get_drvinfo(struct net_device *ndev, struct ethtool_drvinfo *drvinfo)
{
    sdummy_debug_enter(".get_drvinfo : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_get_driver_info(ndev, drvinfo);
    sdummy_debug_exit(".get_drvinfo : ndev(%s)\n", netdev_name_safe(ndev));
}

static int sdummy_ethtools_get_regs_len(struct net_device *ndev)
{
    int ret = 0;

    sdummy_debug_enter(".get_regs_len : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_regs_len is under construction !!!\n");    
    /* TODO BEGIN */

    /* TODO END   */
    sdummy_debug_exit(".get_regs_len : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static void sdummy_ethtools_get_regs(struct net_device *ndev, struct ethtool_regs *regs, void *p)
{
    sdummy_debug_enter(".get_regs : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_regs is under construction !!!\n"); 
    /* TODO BEGIN */

    /* TODO END   */
    sdummy_debug_exit(".get_regs : ndev(%s)\n", netdev_name_safe(ndev));

}

#if 0

/* Wake On Lan */
static void sdummy_ethtools_get_wol(struct net_device *ndev, struct ethtool_wolinfo *wolinfo)
{
    sdummy_debug_enter(".get_wol : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_wol is under construction !!!\n");    
    sdummy_debug_exit(".get_wol : ndev(%s)\n", netdev_name_safe(ndev));
}

static int sdummy_ethtools_set_wol(struct net_device *ndev, struct ethtool_wolinfo *wolinfo)
{
    int ret = -ENOTSUPP;

    sdummy_debug_enter(".set_wol : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_wol is under construction !!!\n");    
    sdummy_debug_exit(".set_wol : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}

#endif

static u32 sdummy_ethtools_get_msglevel(struct net_device *ndev)
{
    u32 ret = 0;
    struct sdummy_local *lp = netdev_priv(ndev); 

    sdummy_debug_enter(".get_msglevel : ndev(%s)\n", netdev_name_safe(ndev));
    ret = lp->msg_enable;
    sdummy_debug_exit(".get_msglevel : ndev(%s)\n", netdev_name_safe(ndev));

	return ret;
}

static void sdummy_ethtools_set_msglevel(struct net_device *ndev, u32 value)
{
    struct sdummy_local *lp = netdev_priv(ndev); 

    sdummy_debug_enter(".set_msglevel : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_msglevel is under construction !!!\n");  
    lp->msg_enable = value;
    sdummy_debug_exit(".set_msglevel : ndev(%s)\n", netdev_name_safe(ndev));
}

#if 0
static int sdummy_ethtools_nway_reset(struct net_device *ndev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".nway_reset : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".nway_reset is under construction !!!\n");    
    sdummy_debug_exit(".nway_reset : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

static u32 sdummy_ethtools_get_link(struct net_device *ndev)
{
    u32 ret = 0;
    struct sdummy_local *lp = netdev_priv(ndev); 
    sdummy_debug_enter(".get_link : ndev(%s)\n", netdev_name_safe(ndev));    
    ret = lp->link_active;
    sdummy_debug_exit(".get_link : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#if 0

static int sdummy_ethtools_get_eeprom_len(struct net_device *ndev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_eeprom_len : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_eeprom_len is under construction !!!\n");    
    sdummy_debug_exit(".get_eeprom_len : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_get_eeprom(struct net_device *ndev, struct ethtool_eeprom *eeprom, u8 *value)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_eeprom : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_eeprom is under construction !!!\n");    
    sdummy_debug_exit(".get_eeprom : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_eeprom(struct net_device *ndev, struct ethtool_eeprom *eeprom, u8 *value)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_eeprom : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_eeprom is under construction !!!\n");    
    sdummy_debug_exit(".set_eeprom : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_get_coalesce(struct net_device *ndev, struct ethtool_coalesce *coalesce)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_coalesce is under construction !!!\n");    
    sdummy_debug_exit(".get_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_coalesce(struct net_device *ndev, struct ethtool_coalesce *coalesce)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_coalesce is under construction !!!\n");    
    sdummy_debug_exit(".set_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static void sdummy_ethtools_get_ringparam(struct net_device *ndev, struct ethtool_ringparam *ringparam)
{
    sdummy_debug_enter(".get_ringparam : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_ringparam is under construction !!!\n");    
    sdummy_debug_exit(".get_ringparam : ndev(%s)\n", netdev_name_safe(ndev));
}

static int sdummy_ethtools_set_ringparam(struct net_device *ndev, struct ethtool_ringparam *ringparam)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_ringparam : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_ringparam is under construction !!!\n");    
    sdummy_debug_exit(".set_ringparam : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static void sdummy_ethtools_get_pauseparam(struct net_device *ndev, struct ethtool_pauseparam *pauseparam)
{
    sdummy_debug_enter(".get_pauseparam : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_pauseparam is under construction !!!\n");    
    sdummy_debug_exit(".get_pauseparam : ndev(%s)\n", netdev_name_safe(ndev));
}

static int sdummy_ethtools_set_pauseparam(struct net_device *ndev, struct ethtool_pauseparam *pauseparam)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_pauseparam : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_pauseparam is under construction !!!\n");    
    sdummy_debug_exit(".set_pauseparam : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#endif


static void sdummy_ethtools_self_test(struct net_device *ndev, struct ethtool_test *tst, u64 *value)
{
    sdummy_debug_enter(".self_test : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".self_test is under construction !!!\n");    
    /* TODO BEGIN */

    /* TODO END   */
    sdummy_debug_exit(".self_test : ndev(%s)\n", netdev_name_safe(ndev));
}

static void sdummy_ethtools_get_strings(struct net_device *ndev, u32 stringset, u8 *value)
{
    sdummy_debug_enter(".get_strings : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_strings is under construction !!!\n");    
    /* TODO BEGIN */

    /* TODO END   */
    sdummy_debug_exit(".get_strings : ndev(%s)\n", netdev_name_safe(ndev));
}


static int sdummy_ethtools_set_phys_id(struct net_device *ndev, enum ethtool_phys_id_state phys_id_state)
{
    int ret = -ENOTSUPP;

    sdummy_debug_enter(".set_phys_id : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_phys_id is under construction !!!\n");    
    /* TODO BEGIN */

    /* TODO END   */
    sdummy_debug_exit(".set_phys_id : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}


static void sdummy_ethtools_get_ethtool_stats(struct net_device *ndev, struct ethtool_stats *stats, u64 *data)
{
    struct sdummy_local *lp = netdev_priv(ndev);
    const struct sdummy_stats_info *stat_info;
    int i;
    char *p = NULL;

    sdummy_debug_enter(".get_ethtool_stats : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_update_stats(ndev);    

    for (i = 0; i < SDUMMY_STATS_LEN; i++) {
        stat_info = &sdummy_gstrings_stats_tbl[i];
        p = (char *)&lp->stats + stat_info->offset_stat;
        if(stat_info->sizeof_stat == sizeof(u64)) {
            data[i] = *((u64 *)p);
        }
        else if(stat_info->sizeof_stat == sizeof(u32)) {
            data[i] = (u64)(*((u32 *)p));
        }      
    }
    
    sdummy_debug_exit(".get_ethtool_stats : ndev(%s)\n", netdev_name_safe(ndev));

}

#if 0
static int sdummy_ethtools_begin(struct net_device *ndev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".begin : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".begin is under construction !!!\n");    
    sdummy_debug_exit(".begin : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static void sdummy_ethtools_complete(struct net_device *ndev)
{
    sdummy_debug_enter(".complete : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".complete is under construction !!!\n");    
    sdummy_debug_exit(".complete : ndev(%s)\n", netdev_name_safe(ndev));
}

static u32 sdummy_ethtools_get_priv_flags(struct net_device *ndev)
{
    u32 ret = 0;
    sdummy_debug_enter(".get_priv_flags : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_priv_flags is under construction !!!\n");    
    sdummy_debug_exit(".get_priv_flags : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_priv_flags(struct net_device *ndev, u32 value)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_priv_flags : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_priv_flags is under construction !!!\n");    
    sdummy_debug_exit(".set_priv_flags : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

static int sdummy_ethtools_get_sset_count(struct net_device *ndev, int sset)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_sset_count : ndev(%s)\n", netdev_name_safe(ndev));
    
	switch (sset) {
	case ETH_SS_STATS:
		return SDUMMY_STATS_LEN;
	default:
		return -EOPNOTSUPP;
	}
   
    sdummy_debug_exit(".get_sset_count : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#if 0

static int sdummy_ethtools_get_rxnfc(struct net_device *ndev, struct ethtool_rxnfc *rxnfc, u32 *rule_locs)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_rxnfc : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_rxnfc is under construction !!!\n");    
    sdummy_debug_exit(".get_rxnfc : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_rxnfc(struct net_device *ndev, struct ethtool_rxnfc *rxnfc)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_rxnfc : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_rxnfc is under construction !!!\n");    
    sdummy_debug_exit(".set_rxnfc : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static int sdummy_ethtools_flash_device(struct net_device *ndev, struct ethtool_flash *flash)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".flash_device : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".flash_device is under construction !!!\n");    
    sdummy_debug_exit(".flash_device : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

static int sdummy_ethtools_reset(struct net_device *ndev, u32 *value)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".reset : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".reset is under construction !!!\n");    
    sdummy_debug_exit(".reset : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#if 0

static u32 sdummy_ethtools_get_rxfh_key_size(struct net_device *ndev)
{
    u32 ret = 0;
    sdummy_debug_enter(".get_rxfh_key_size : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_rxfh_key_size is under construction !!!\n");    
    sdummy_debug_exit(".get_rxfh_key_size : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static u32 sdummy_ethtools_get_rxfh_indir_size(struct net_device *ndev)
{
    u32 ret = 0;
    sdummy_debug_enter(".get_rxfh_indir_size : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_rxfh_indir_size is under construction !!!\n");    
    sdummy_debug_exit(".get_rxfh_indir_size : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_get_rxfh(struct net_device *ndev, u32 *indir, u8 *key, u8 *hfunc)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_rxfh : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_rxfh is under construction !!!\n");    
    sdummy_debug_exit(".get_rxfh : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_rxfh(struct net_device *ndev, const u32 *indir, const u8 *key, const u8 hfunc)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_rxfh : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_rxfh is under construction !!!\n");    
    sdummy_debug_exit(".set_rxfh : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_get_rxfh_context(struct net_device *ndev, u32 *indir, u8 *key, u8 *hfunc, u32 rss_context)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_rxfh_context : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_rxfh_context is under construction !!!\n");    
    sdummy_debug_exit(".get_rxfh_context : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_rxfh_context(struct net_device *ndev, const u32 *indir, const u8 *key, const u8 hfunc, u32 *rss_context, bool delete)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_rxfh_context : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_rxfh_context is under construction !!!\n");    
    sdummy_debug_exit(".set_rxfh_context : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#endif

static void sdummy_ethtools_get_channels(struct net_device *ndev, struct ethtool_channels *chan)
{
    sdummy_debug_enter(".get_channels : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_channels is under construction !!!\n");    
    sdummy_debug_exit(".get_channels : ndev(%s)\n", netdev_name_safe(ndev));
}

static int sdummy_ethtools_set_channels(struct net_device *ndev, struct ethtool_channels *chan)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_channels : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_channels is under construction !!!\n");    
    sdummy_debug_exit(".set_channels : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#if 0
static int sdummy_ethtools_get_dump_flag(struct net_device *ndev, struct ethtool_dump *dump)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_dump_flag : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_dump_flag is under construction !!!\n");    
    sdummy_debug_exit(".get_dump_flag : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_get_dump_data(struct net_device *ndev, struct ethtool_dump *dump, void *p)
{
    int ret = -ENOTSUPP;

    const char *ndev_name = netdev_name_safe(ndev);
    sdummy_debug_enter(".get_dump_data : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_dump_data is under construction !!!\n");    
    sdummy_debug_exit(".get_dump_data : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}

static int sdummy_ethtools_set_dump(struct net_device *ndev, struct ethtool_dump *dump)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_dump : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_dump is under construction !!!\n");    
    sdummy_debug_exit(".set_dump : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static int sdummy_ethtools_get_ts_info(struct net_device *ndev, struct ethtool_ts_info *ts_info)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_ts_info : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_ts_info is under construction !!!\n");    
    sdummy_debug_exit(".get_ts_info : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static int sdummy_ethtools_get_module_info(struct net_device *ndev, struct ethtool_modinfo *modinfo)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_module_info : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_module_info is under construction !!!\n");    
    sdummy_debug_exit(".get_module_info : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_get_module_eeprom(struct net_device *ndev, struct ethtool_eeprom *eeprom, u8 *value)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_module_eeprom : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_module_eeprom is under construction !!!\n");    
    sdummy_debug_exit(".get_module_eeprom : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

/*
    Energy Efficient Ethernet information
*/
static int sdummy_ethtools_get_eee(struct net_device *ndev, struct ethtool_eee *eee)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_eee : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_eee is under construction !!!\n");    
    sdummy_debug_exit(".get_eee : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_eee(struct net_device *ndev, struct ethtool_eee *eee)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_eee : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_eee is under construction !!!\n");    
    sdummy_debug_exit(".set_eee : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static int sdummy_ethtools_get_tunable(struct net_device *ndev, const struct ethtool_tunable *tunable, void *p)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_tunable : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_tunable is under construction !!!\n");    
    sdummy_debug_exit(".get_tunable : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_tunable(struct net_device *ndev, const struct ethtool_tunable *tunable, const void *p)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_tunable : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_tunable is under construction !!!\n");    
    sdummy_debug_exit(".set_tunable : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static int sdummy_ethtools_get_per_queue_coalesce(struct net_device *ndev, u32 value, struct ethtool_coalesce *coalesce)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_per_queue_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_per_queue_coalesce is under construction !!!\n");    
    sdummy_debug_exit(".get_per_queue_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_per_queue_coalesce(struct net_device *ndev, u32 value, struct ethtool_coalesce *coalesce)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_per_queue_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_per_queue_coalesce is under construction !!!\n");    
    sdummy_debug_exit(".set_per_queue_coalesce : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#endif

static int sdummy_ethtools_get_link_ksettings(struct net_device *ndev, struct ethtool_link_ksettings *cmd)
{
    int ret = -ENOTSUPP;

    sdummy_debug_enter(".get_link_ksettings : ndev(%s)\n", netdev_name_safe(ndev));
    
#ifdef    REF_CODE   
    phy_ethtool_get_link_ksettings(ndev, cmd);
#endif /* REF_CODE */

    sdummy_err(ndev, ".get_link_ksettings is under construction !!!\n");    
    sdummy_debug_exit(".get_link_ksettings : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}

static int sdummy_ethtools_set_link_ksettings(struct net_device *ndev, const struct ethtool_link_ksettings *cmd)
{
    int ret = -ENOTSUPP;

    sdummy_debug_enter(".set_link_ksettings : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_link_ksettings is under construction !!!\n"); 

#ifdef    REF_CODE    
    phy_ethtool_set_link_ksettings(ndev, cmd);
#endif /* REF_CODE */

    sdummy_debug_exit(".set_link_ksettings : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}

#if 0
static int sdummy_ethtools_get_fecparam(struct net_device *ndev, struct ethtool_fecparam *fecparam)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".get_fecparam : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_fecparam is under construction !!!\n");    
    sdummy_debug_exit(".get_fecparam : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_ethtools_set_fecparam(struct net_device *ndev, struct ethtool_fecparam *fecparam)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".set_fecparam : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".set_fecparam is under construction !!!\n");    
    sdummy_debug_exit(".set_fecparam : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

static void sdummy_ethtools_get_ethtool_phy_stats(struct net_device *ndev, struct ethtool_stats *stats, u64 *value)
{
    sdummy_debug_enter(".get_ethtool_phy_stats : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".get_ethtool_phy_stats is under construction !!!\n");    
    sdummy_debug_exit(".get_ethtool_phy_stats : ndev(%s)\n", netdev_name_safe(ndev));
}


static int sdummy_update_stats_sw(struct net_device *ndev, const struct sdummy_stats_info *stats_info)
{
    struct sdummy_local *lp = netdev_priv(ndev);
    struct sdummy_stats *stats;
    int ret = 0;
    
    if((stats_info->type_flag & SDUMMY_STATS_SW) == SDUMMY_STATS_SW) {    
        stats = &lp->stats;
        switch(stats_info->stat_id) {
        case SDUMMY_RX_ERRORS_STAT_ID:
            stats->rx_errors = stats->rx_errors + 1;    
            break;      
        case SDUMMY_TX_ERRORS_STAT_ID:
            stats->tx_errors = stats->tx_errors + 1;    
            break;

        default:
            break;
        }
    }
        
    return ret;
}

static int sdummy_update_netdev_stats(struct net_device *ndev)
{
    struct sdummy_local *lp = netdev_priv(ndev);

    u64 *src = &lp->stats.rx_packets;
    u64 *end = &lp->stats.rx_nohandler;
    unsigned long *dst = (unsigned long *)&lp->netdev_stat.rx_packets;

    for(; src < end; src++, dst++) {
        *dst = (unsigned long)(*src);        
    }

    return 0;
}

static int sdummy_update_netlink_stats(struct net_device *ndev)
{
    struct sdummy_local *lp = netdev_priv(ndev);
    u64 *src = &lp->stats.rx_packets;
    u64 *end = &lp->stats.rx_nohandler;
    u64 *dst = (u64 *)&lp->netlink_stat64.rx_packets;

    for(; src <= end; src++, dst++) {
        *dst = *src;        
    }

    return 0;
}


/* End of SOLID_DUMMY_ETHTOOL_Private_Functions */
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_ETHTOOL_Exported_Functions
  * @{
  */

void sdummy_update_stats(struct net_device *ndev)
{

    struct sdummy_local *lp = netdev_priv(ndev);
    struct sdummy_stats *stats;
    const struct sdummy_stats_info *stat_info;
    char *p;
    int i;
 
    sdummy_debug_enter("sdummy_update_stats : ndev(%s)\n", netdev_name_safe(ndev));

    stats = &lp->stats;
	spin_lock(&lp->stats64_lock);

	for (i = 0; i < SDUMMY_STATS_LEN; i++) {
        stat_info = &sdummy_gstrings_stats_tbl[i];        
        if(stat_info->type_flag & SDUMMY_STATS_HW) {           
			p = (char *)stats + stat_info->offset_stat;
            if (stat_info->sizeof_stat == sizeof(u64)) {
                if(lp && lp->sdummy_reg_read_u64) {
                    if(lp->sdummy_reg_read_u64(ndev, stat_info->reg_offset, (u64 *)p) != 0) {
                        /* Error */

                    }
                }
                else {
                    /* Error */
                }            
            }
            else {
                if(lp && lp->sdummy_reg_read_u32) {
                    if(lp->sdummy_reg_read_u32(ndev, stat_info->reg_offset, (u32 *)p) != 0) {
                        /* Error */
                    }
                }
                else {
                    /* Error */
                } 
            }
        }   
        else if(stat_info->type_flag & SDUMMY_STATS_SW) {            
            sdummy_update_stats_sw(ndev, stat_info);            
        }
	}

#ifdef    SDUMMY_STATICS_TEST

    stats->rx_packets           = stats->rx_packets + 1;          
    stats->tx_packets           = stats->tx_packets + 1;          
   
    stats->rx_bytes             = stats->rx_bytes + 100;        
    stats->tx_bytes             = stats->tx_bytes + 100;      

    stats->rx_errors            = stats->rx_errors + 1;           
    stats->tx_errors            = stats->tx_errors + 1;           

    stats->rx_dropped           = stats->rx_dropped + 1;          
    stats->tx_dropped           = stats->tx_dropped + 1;          
    stats->multicast            = stats->multicast + 1;           
    stats->collisions           = stats->collisions + 1;
    
    stats->rx_length_errors     = stats->rx_length_errors + 1;
    stats->rx_over_errors       = stats->rx_over_errors + 1;      
    stats->rx_crc_errors        = stats->rx_crc_errors + 1;       
    stats->rx_frame_errors      = stats->rx_frame_errors + 1;     
    stats->rx_fifo_errors       = stats->rx_fifo_errors + 1;      
    stats->rx_missed_errors     = stats->rx_missed_errors + 1;    
    
    stats->tx_aborted_errors    = stats->tx_aborted_errors + 1;
    stats->tx_carrier_errors    = stats->tx_carrier_errors + 1;
    stats->tx_fifo_errors       = stats->tx_fifo_errors + 1;
    stats->tx_heartbeat_errors  = stats->tx_heartbeat_errors + 1;
    stats->tx_window_errors     = stats->tx_window_errors + 1;
    
    stats->rx_compressed        = stats->rx_compressed + 1;
    stats->tx_compressed        = stats->tx_compressed + 1;
    
    stats->rx_nohandler         = stats->rx_nohandler + 1;        
    
    stats->rx_early             = stats->rx_early + 1;            
    stats->rx_late              = stats->rx_late + 1;             
      
#endif /* SDUMMY_STATICS_TEST */    

    sdummy_update_netdev_stats(ndev);
    sdummy_update_netlink_stats(ndev);
	spin_unlock(&lp->stats64_lock);

    sdummy_debug_exit("sdummy_update_stats : ndev(%s)\n", netdev_name_safe(ndev));

}

void sdummy_set_ethtool_ops(struct net_device *netdev)
{
	netdev->ethtool_ops = &sdummy_ethtool_ops;
}


/* End of SOLID_DUMMY_ETHTOOL_Exported_Functions */
/**
  * @}
  */

/* End of SOLID_DUMMY_ETHTOOL */
/**
  * @}
  */


