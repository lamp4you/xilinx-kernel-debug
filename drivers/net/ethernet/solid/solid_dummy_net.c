/**
  ******************************************************************************
  * @file    solid_dummy_net.c
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

#include "solid_dummy_net.h"

/** @addtogroup SOLID_DUMMY_NET
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NET_Private_Macros
  * @{
  */

/* Must be shorter than length of ethtool_drvinfo.driver field to fit */
#define DRIVER_NAME		    "sdummy_net"
#define DRIVER_DESCRIPTION	"SOLiD Dummy net driver"
#define DRIVER_VERSION		"1.00a"

/* End of SOLID_DUMMY_NET_Private_Macros */
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NET_Private_Types
  * @{
  */
/* End of SOLID_DUMMY_NET_Private_Types */
/**
  * @}
  */

/* Private functions Prototype ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NET_Private_Functions
  * @{
  */

static int sdummy_net_probe(struct platform_device *pdev);
static int sdummy_net_remove(struct platform_device *pdev);

/* 
    sdummy_net_netdev_ops 
*/
static int sdummy_net_open(struct net_device *ndev);

/* 
    struct ethtool_ops 
*/
static void sdummy_net_ethtools_get_drvinfo(struct net_device *ndev, struct ethtool_drvinfo *ed);

/* End of SOLID_DUMMY_NET_Private_Functions */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NET_Private_Variables
  * @{
  */

static const struct net_device_ops sdummy_net_netdev_ops = {

#if 1
	.ndo_open = sdummy_net_open,

#else
	.ndo_stop = dummy_net_stop,
	.ndo_start_xmit = dummy_net_start_xmit,
	.ndo_change_mtu	= dummy_net_change_mtu,
	.ndo_set_mac_address = netdev_set_mac_address,
	.ndo_validate_addr = eth_validate_addr,
	.ndo_set_rx_mode = dummy_net_set_multicast_list,
	.ndo_do_ioctl = dummy_net_ioctl,
#ifdef CONFIG_NET_POLL_CONTROLLER
	.ndo_poll_controller = dummy_net_poll_controller,
#endif

    .ndo_open = axienet_open,
    .ndo_stop = axienet_stop,
    .ndo_start_xmit = axienet_start_xmit,
    .ndo_change_mtu = axienet_change_mtu,
    .ndo_set_mac_address = netdev_set_mac_address,
    .ndo_validate_addr = eth_validate_addr,
    .ndo_set_rx_mode = axienet_set_multicast_list,
    .ndo_do_ioctl = axienet_ioctl,
#ifdef CONFIG_NET_POLL_CONTROLLER
    .ndo_poll_controller = axienet_poll_controller,
#endif

#endif

};


static const struct ethtool_ops sdummy_net_ethtool_ops = {

#if 1

	.get_drvinfo    = sdummy_net_ethtools_get_drvinfo,

#else
    .get_ethtool_stats = dummy_net_get_stats,

	.get_regs_len   = dummy_net_ethtools_get_regs_len,
	.get_regs       = dummy_net_ethtools_get_regs,
	.get_link       = ethtool_op_get_link,
	.get_pauseparam = dummy_net_ethtools_get_pauseparam,
	.set_pauseparam = dummy_net_ethtools_set_pauseparam,
	.get_coalesce   = dummy_net_ethtools_get_coalesce,
	.set_coalesce   = dummy_net_ethtools_set_coalesce,
	.get_link_ksettings = phy_ethtool_get_link_ksettings,
	.set_link_ksettings = phy_ethtool_set_link_ksettings,

    .get_drvinfo    = axienet_ethtools_get_drvinfo,
    .get_regs_len   = axienet_ethtools_get_regs_len,
    .get_regs       = axienet_ethtools_get_regs,
    .get_link       = ethtool_op_get_link,
    .get_pauseparam = axienet_ethtools_get_pauseparam,
    .set_pauseparam = axienet_ethtools_set_pauseparam,
    .get_coalesce   = axienet_ethtools_get_coalesce,
    .set_coalesce   = axienet_ethtools_set_coalesce,
#if defined (CONFIG_XILINX_AXI_EMAC_HWTSTAMP) || defined (CONFIG_XILINX_TSN_PTP)
    .get_ts_info    = axienet_ethtools_get_ts_info,
#endif
    .get_link_ksettings = phy_ethtool_get_link_ksettings,
    .set_link_ksettings = phy_ethtool_set_link_ksettings,
#ifdef CONFIG_AXIENET_HAS_MCDMA
    .get_sset_count  = axienet_sset_count,
    .get_ethtool_stats = axienet_get_stats,
    .get_strings = axienet_strings,
#endif


#endif

};

static const struct sdummy_net_config_s sdummy_net_cfg = 
{
	.mactype = SDUMMY_ENET_VLAN
};

/* Match table for of_platform binding */
static const struct of_device_id sdummy_net_of_match[] = {
	{ .compatible = "solid,sdummy-net-1.00.a", .data = &sdummy_net_cfg},
	{}
};

MODULE_DEVICE_TABLE(of, sdummy_net_of_match);

static struct platform_driver sdummy_net_driver = {
	.probe = sdummy_net_probe,
	.remove = sdummy_net_remove,
	.driver = {
		 .name = "solid_dummy_net",
		 .of_match_table = sdummy_net_of_match,
	},
};

/* End of SOLID_DUMMY_NET_Private_Variables */
/**
  * @}
  */

/* Exported variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NET_Exported_Variables
  * @{
  */
/* End of SOLID_DUMMY_NET_Exported_Variables */
/**
  * @}
  */

/* Private functions ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NET_Private_Functions
  * @{
  */

static int sdummy_net_open(struct net_device *ndev)
{
    int ret = 0;
	struct sdummy_net_local *lp = netdev_priv(ndev);

    eth_debug_enter("sdummy_net_open : net_dev(%s), dev(%s)\n", ndev->name, dev_name(lp->dev));

// _done:
    eth_debug_exit("sdummy_net_open : net_dev(%s), dev(%s)\n", ndev->name, dev_name(lp->dev)); 
    return ret;
    
}


static void sdummy_net_ethtools_get_drvinfo(struct net_device *ndev, struct ethtool_drvinfo *ed)
{
	strlcpy(ed->driver, DRIVER_NAME, sizeof(ed->driver));
	strlcpy(ed->version, DRIVER_VERSION, sizeof(ed->version));
}


static int sdummy_net_probe(struct platform_device *pdev)
{
    int ret = 0;

    struct sdummy_net_local *lp;
    struct net_device *ndev;
    const void *mac_addr;
    struct resource *ethres;
    u16 num_queues = XAE_MAX_QUEUES;

    const char *pdev_name = get_platform_device_name(pdev);
    eth_debug_enter("axienet_probe : pdev(%s)\n", pdev_name);

    num_queues = SOLID_DUMMY_MAX_QUEUES;

    eth_debug_msg("alloc_etherdev_mq\n");
    ndev = alloc_etherdev_mq(sizeof(*lp), num_queues);
    if (!ndev) {
        ret = -ENOMEM; goto _done; // return -ENOMEM;
    }
    eth_debug_msg("ndev = 0x%016llx, size = 0x%08lx, ALIGN(sizeof(struct net_device), NETDEV_ALIGN) = 0x%08lx\n", 
        ptr2uint64_t(ndev), sizeof(struct net_device), ALIGN(sizeof(struct net_device), NETDEV_ALIGN));

    platform_set_drvdata(pdev, ndev);

    SET_NETDEV_DEV(ndev, &pdev->dev);
    ndev->flags &= ~IFF_MULTICAST;  /* clear multicast */
    ndev->features = NETIF_F_SG;

    ndev->netdev_ops = &sdummy_net_netdev_ops;
    ndev->ethtool_ops = &sdummy_net_ethtool_ops;

    /* MTU range: 64 - 9000 */
    ndev->min_mtu = 64;
    ndev->max_mtu = XAE_JUMBO_MTU;

    lp = netdev_priv(ndev);
    lp->ndev = ndev;
    lp->dev = &pdev->dev;   
    lp->options = XAE_OPTION_DEFAULTS;
    lp->num_tx_queues = num_queues;
    lp->num_rx_queues = num_queues;

    eth_debug_msg("lp = 0x%016llx\n", ptr2uint64_t(lp));

    /* Map device registers */
    eth_debug_msg("pdev = 0x%016llx, pdev->num_resources = %d\n", ptr2uint64_t(pdev), pdev->num_resources);
    ethres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    lp->regs = devm_ioremap_resource(&pdev->dev, ethres);
    eth_debug_msg("ethres = %pR, lp->regs = 0x%016llx\n", ethres, ptr2uint64_t(lp->regs));
    if (IS_ERR(lp->regs)) {
        ret = PTR_ERR(lp->regs);
        goto free_netdev;
    }

    /* Retrieve the MAC address */
    eth_debug_msg("of_get_mac_address\n");
    mac_addr = of_get_mac_address(pdev->dev.of_node);
    if (!mac_addr) {
        dev_err(&pdev->dev, "could not find MAC address\n");
        goto _free_netdev;
    }
    sdummy_net_set_mac_address(ndev, mac_addr);

    eth_debug_msg("register_netdev : lp->ndev(%s)\n", lp->ndev->name);
    ret = register_netdev(lp->ndev);
    if (ret) {
        dev_err(lp->dev, "register_netdev() error (%i)\n", ret);
        goto _free_netdev;
    }
    eth_debug_msg("register_netdev : lp->ndev(%s) : DONE\n", lp->ndev->name);
    goto _done; // return 0;

_free_netdev:
    free_netdev(ndev);

_done:
    eth_debug_exit("axienet_probe : pdev(%s)\n", pdev_name);
    return ret;
}

static int sdummy_net_remove(struct platform_device *pdev)
{
    int ret = 0;
	struct net_device *ndev = platform_get_drvdata(pdev);
	// struct sdummy_net_local *lp = netdev_priv(ndev);

    free_netdev(ndev);
    
	return ret;
}

/* End of SOLID_DUMMY_NET_Private_Functions */
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NET_Exported_Functions
  * @{
  */

void sdummy_net_set_mac_address(struct net_device *ndev, const void *address)
{
	struct axienet_local *lp = netdev_priv(ndev);

    eth_debug_enter("dummy_net_set_mac_address : ndev(%s)\n", ndev->name);
	if (address) {
		ether_addr_copy(ndev->dev_addr, address);
    }
	if (!is_valid_ether_addr(ndev->dev_addr)) {
		eth_hw_addr_random(ndev);
    }

_done:
    eth_debug_exit("dummy_net_set_mac_address : ndev(%s)\n", ndev->name);

}

/* End of SOLID_DUMMY_NET_Exported_Functions */
/**
  * @}
  */

module_platform_driver(sdummy_net_driver);

MODULE_DESCRIPTION("SOLiD Dummy net driver");
MODULE_AUTHOR("SOLiD");
MODULE_LICENSE("GPL");


/* End of SOLID_DUMMY_NET */
/**
  * @}
  */


