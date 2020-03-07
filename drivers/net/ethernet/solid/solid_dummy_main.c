/**
  ******************************************************************************
  * @file    solid_dummy_main.c
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


/** @addtogroup SOLID_DUMMY_MAIN
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_MAIN_Private_Macros
  * @{
  */

/* Must be shorter than length of ethtool_drvinfo.driver field to fit */
#define DRIVER_NAME		    "sdummy_net"
#define DRIVER_DESCRIPTION	"SOLiD Dummy net driver"
#define DRIVER_VERSION		"1.00a"

/* End of SOLID_DUMMY_MAIN_Private_Macros */
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_MAIN_Private_Types
  * @{
  */
/* End of SOLID_DUMMY_MAIN_Private_Types */
/**
  * @}
  */

/* Private functions Prototype ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_MAIN_Private_Functions
  * @{
  */

static int sdummy_probe(struct platform_device *pdev);
static int sdummy_remove(struct platform_device *pdev);
static const char *sdummy_dev_name(const struct net_device *ndev);

#ifdef    DEBUG_SDUMMY
#ifndef   DEBUG_DEVICE_DRIVER
static char *sdummy_blank(int depth);
static const char *sdummy_base_file_name(const char *file_name);
static void __sdummy_debug_printk(const char *file_name, int line_no, int depth, const char *hdr,	struct va_format *vaf);

#endif /* DEBUG_DEVICE_DRIVER */
#endif /* DEBUG_SDUMMY */



/* End of SOLID_DUMMY_MAIN_Private_Functions */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_MAIN_Private_Variables
  * @{
  */


#ifdef    DEBUG_SDUMMY
#ifndef   DEBUG_DEVICE_DRIVER

static int sdummy_debug_depth = -1;
static char dev_debug_skip_str[MAX_DEBUG_DEPTH * NUM_OF_BLANK_PER_DEPTH + 1];

#endif /* DEBUG_DEVICE_DRIVER */
#endif /* DEBUG_SDUMMY */

static const struct sdummy_config_s sdummy_cfg = 
{
	.name = "sdummy-config"
};

/* Match table for of_platform binding */
static const struct of_device_id sdummy_of_match[] = {
	{ .compatible = "solid,sdummy-1.00.a", .data = &sdummy_cfg },
	{}
};

MODULE_DEVICE_TABLE(of, sdummy_of_match);

static struct platform_driver sdummy_driver = {
	.probe = sdummy_probe,
	.remove = sdummy_remove,
	.driver = {
		 .name = "sdummy",
		 .of_match_table = sdummy_of_match,
	},
};


/* End of SOLID_DUMMY_MAIN_Private_Variables */
/**
  * @}
  */

/* Exported variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_MAIN_Exported_Variables
  * @{
  */
/* End of SOLID_DUMMY_MAIN_Exported_Variables */
/**
  * @}
  */

/* Private functions ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_MAIN_Private_Functions
  * @{
  */

static int sdummy_probe(struct platform_device *pdev)
{
    int ret = 0;

    struct sdummy_local *lp;
    struct net_device *ndev;
    const void *mac_addr;
    struct resource *ethres;

    const char *pdev_name = get_platform_device_name(pdev);
    sdummy_debug_enter("sdummy_probe : pdev(%s)\n", pdev_name);

    sdummy_debug_msg("alloc_etherdev_mq\n");
    // ndev = alloc_etherdev_mq(sizeof(*lp), num_queues);
    
    ndev = alloc_netdev_mqs(sizeof(*lp), "sdummy%d", NET_NAME_UNKNOWN,	ether_setup, 1, 1);
    if (!ndev) {
        ret = -ENOMEM; goto _done; // return -ENOMEM;
    }
    sdummy_debug_msg("ndev = 0x%016llx, size = 0x%08lx, ALIGN(sizeof(struct net_device), NETDEV_ALIGN) = 0x%08lx\n", 
        ptr2uint64_t(ndev), sizeof(struct net_device), ALIGN(sizeof(struct net_device), NETDEV_ALIGN));

    platform_set_drvdata(pdev, ndev);

    SET_NETDEV_DEV(ndev, &pdev->dev);
    ndev->flags &= ~IFF_MULTICAST;  /* clear multicast */
    ndev->features = 0;

    sdummy_set_netdev_ops(ndev);
    sdummy_set_ethtool_ops(ndev);

    /* MTU range: 64 - 9000 */
    ndev->min_mtu = 64;
    ndev->max_mtu = SDUMMY_JUMBO_MTU;
	ndev->features = NETIF_F_HW_VLAN_CTAG_FILTER;

    lp = netdev_priv(ndev);
    lp->ndev = ndev;
    lp->dev = &pdev->dev;   
    lp->options = SDUMMY_OPTION_DEFAULTS;
    lp->features = NETIF_F_HW_VLAN_CTAG_FILTER;

	spin_lock_init(&lp->stats64_lock);
    
    sdummy_debug_msg("lp = 0x%016llx\n", ptr2uint64_t(lp));

    /* Map device registers */
    sdummy_debug_msg("pdev = 0x%016llx, pdev->num_resources = %d\n", ptr2uint64_t(pdev), pdev->num_resources);
    ethres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    lp->regs = devm_ioremap_resource(&pdev->dev, ethres);
    sdummy_debug_msg("ethres = %pR, lp->regs = 0x%016llx\n", ethres, ptr2uint64_t(lp->regs));
    if (IS_ERR(lp->regs)) {
        ret = PTR_ERR(lp->regs);
        goto _free_netdev;
    }

    /* Retrieve the MAC address */
    sdummy_debug_msg("of_get_mac_address\n");
    mac_addr = of_get_mac_address(pdev->dev.of_node);
    if (!mac_addr) {
        dev_err(&pdev->dev, "could not find MAC address\n");
        goto _free_netdev;
    }

    if(ndev->netdev_ops->ndo_set_mac_address) {
        ndev->netdev_ops->ndo_set_mac_address(ndev, (void *)mac_addr);
    }
    else {
        sdummy_debug_msg("Driver has no set_mac_address function\n");
        goto _free_netdev;
    }

    sdummy_debug_msg("register_netdev : ndev(%s)\n", sdummy_dev_name(lp->ndev));
    ret = register_netdev(lp->ndev);
    if (ret) {
        dev_err(lp->dev, "register_netdev() error (%i)\n", ret);
        goto _free_netdev;
    }
    sdummy_debug_msg("register_netdev : lp->ndev(%s) : DONE\n", lp->ndev->name);
    goto _done; // return 0;

_free_netdev:
    free_netdev(ndev);

_done:
    sdummy_debug_exit("sdummy_probe : pdev(%s)\n", pdev_name);
    return ret;
}

static int sdummy_remove(struct platform_device *pdev)
{
    int ret = 0;
	struct net_device *ndev = platform_get_drvdata(pdev);
	// struct sdummy_netdev_local *lp = netdev_priv(ndev);

    free_netdev(ndev);
    
	return ret;
}



#ifdef    DEBUG_SDUMMY
#ifndef   DEBUG_DEVICE_DRIVER

static char *sdummy_blank(int depth)
{
    if(depth > 0 && depth <= MAX_DEBUG_DEPTH) {
        memset(dev_debug_skip_str, ' ', depth * NUM_OF_BLANK_PER_DEPTH);
        dev_debug_skip_str[depth * NUM_OF_BLANK_PER_DEPTH] = 0;
    }
    else {
        dev_debug_skip_str[0] = 0;
    }  
    return dev_debug_skip_str;    
}

static const char *sdummy_base_file_name(const char *file_name)
{
    char *base_file_name;
    
    base_file_name = strrchr(file_name, '/');
    if(base_file_name == NULL) {
        base_file_name = strrchr(file_name, '\\');
        if(base_file_name == NULL) {
            base_file_name = (char *)file_name;
        }
        else {
            base_file_name++;
        }
    }
    else {
        base_file_name++;
    }
    
    return (const char *)base_file_name;
}

static void __sdummy_debug_printk(const char *file_name, int line_no, int depth, const char *hdr,	struct va_format *vaf)
{
    const char *base_file_name = sdummy_base_file_name(file_name);
    if(hdr) {
        printk("[%-25s:%5d] %s%s : %pV", base_file_name, line_no, sdummy_blank(depth), hdr, vaf);
    }
    else {
        printk("[%-25s:%5d] %s%pV", base_file_name, line_no, sdummy_blank(depth), vaf);
    }
}

#endif /* DEBUG_DEVICE_DRIVER */
#endif /* DEBUG_SDUMMY */


/* End of SOLID_DUMMY_MAIN_Private_Functions */
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_MAIN_Exported_Functions
  * @{
  */

void sdummy_get_driver_info(struct net_device *ndev, struct ethtool_drvinfo *drvinfo)
{

#ifdef    REF_CODE
    struct ethtool_drvinfo {
        __u32   cmd;
        char    driver[32];
        char    version[32];
        char    fw_version[ETHTOOL_FWVERS_LEN];
        char    bus_info[ETHTOOL_BUSINFO_LEN];
        char    erom_version[ETHTOOL_EROMVERS_LEN];
        char    reserved2[12];
        __u32   n_priv_flags;
        __u32   n_stats;
        __u32   testinfo_len;
        __u32   eedump_len;
        __u32   regdump_len;
    };
#endif /* REF_CODE */

	strlcpy(drvinfo->driver, DRIVER_NAME, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, DRIVER_VERSION, sizeof(drvinfo->version));
    
}

#ifdef    DEBUG_SDUMMY
#ifndef   DEBUG_DEVICE_DRIVER

int sdummy_inc_debug_depth(void)
{
    if(sdummy_debug_depth < 0) {
        sdummy_debug_depth = 0;
    }    
    sdummy_debug_depth++;
    if(sdummy_debug_depth >= MAX_DEBUG_DEPTH) {
        sdummy_debug_depth = MAX_DEBUG_DEPTH;
    }    
    return sdummy_debug_depth;
}

int sdummy_dec_debug_depth(void)
{
    if(sdummy_debug_depth < 0) {
        sdummy_debug_depth = 1;
    }    
    sdummy_debug_depth--;
    return sdummy_debug_depth;
}

int sdummy_get_debug_depth(void)
{
    return sdummy_debug_depth;
}
void sdummy_debug_printk(const char *file_name, int line_no, int depth, const char *hdr, const char *fmt, ...)
{
	struct va_format vaf;
	va_list args;

	va_start(args, fmt);

	vaf.fmt = fmt;
	vaf.va = &args;

	__sdummy_debug_printk(file_name, line_no, depth, hdr, &vaf);

	va_end(args);
}

#endif /* DEBUG_DEVICE_DRIVER */
#endif /* DEBUG_SDUMMY */

/* End of SOLID_DUMMY_MAIN_Exported_Functions */
/**
  * @}
  */


module_platform_driver(sdummy_driver);

MODULE_DESCRIPTION("SOLiD Dummy net driver");
MODULE_AUTHOR("SOLiD");
MODULE_LICENSE("GPL");


/* End of SOLID_DUMMY_MAIN */
/**
  * @}
  */


