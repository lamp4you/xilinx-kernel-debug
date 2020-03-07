/**
  ******************************************************************************
  * @file    solid_dummy_netdev.c
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

/** @addtogroup SOLID_DUMMY_NETDEV
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NETDEV_Private_Macros
  * @{
  */
/* End of SOLID_DUMMY_NETDEV_Private_Macros */
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NETDEV_Private_Types
  * @{
  */
/* End of SOLID_DUMMY_NETDEV_Private_Types */
/**
  * @}
  */

/* Private functions Prototype ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NETDEV_Private_Functions
  * @{
  */

/* 
    sdummy_netdev_netdev_ops 
*/

#if 0
static int sdummy_netdev_init(struct net_device *ndev);
static void sdummy_netdev_uninit(struct net_device *ndev);
#endif

static int sdummy_netdev_open(struct net_device *ndev);
static int sdummy_netdev_stop(struct net_device *ndev);

static netdev_tx_t sdummy_netdev_start_xmit(struct sk_buff *skb,struct net_device *ndev);

#if 0
static netdev_features_t sdummy_netdev_features_check(struct sk_buff *skb, struct net_device *ndev, netdev_features_t features);
static u16 sdummy_netdev_select_queue(struct net_device *ndev, struct sk_buff *skb, struct net_device *sb_dev, select_queue_fallback_t fallback);
static void sdummy_netdev_change_rx_flags(struct net_device *ndev, int flags);
#endif

static void sdummy_netdev_set_rx_mode(struct net_device *ndev);

static int sdummy_netdev_set_mac_address(struct net_device *ndev, void *addr);
static int sdummy_netdev_validate_addr(struct net_device *ndev);

static int sdummy_netdev_do_ioctl(struct net_device *ndev, struct ifreq *ifr, int cmd);

#if 0
static int sdummy_netdev_set_config(struct net_device *ndev, struct ifmap *map);
#endif

static int sdummy_netdev_change_mtu(struct net_device *ndev, int new_mtu);

#if 0
static int sdummy_netdev_neigh_setup(struct net_device *ndev, struct neigh_parms *params);
#endif

static void sdummy_netdev_tx_timeout(struct net_device *ndev);
static void sdummy_netdev_get_stats64(struct net_device *ndev, struct rtnl_link_stats64 *stats);

#if 0
static bool sdummy_netdev_has_offload_stats(const struct net_device *ndev, int attr_id);
static int sdummy_netdev_get_offload_stats(int attr_id, const struct net_device *ndev, void *attr_data);
#endif

static struct net_device_stats* sdummy_netdev_get_stats(struct net_device *ndev);
static int sdummy_netdev_vlan_rx_add_vid(struct net_device *ndev, __be16 proto, u16 vid);
static int sdummy_netdev_vlan_rx_kill_vid(struct net_device *ndev, __be16 proto, u16 vid);

#ifdef CONFIG_NET_POLL_CONTROLLER
static void sdummy_netdev_poll_controller(struct net_device *ndev);
#if 0
static int sdummy_netdev_netpoll_setup(struct net_device *ndev, struct netpoll_info *info);
static void sdummy_netdev_netpoll_cleanup(struct net_device *ndev);
#endif
#endif

#if 0
static int sdummy_netdev_set_vf_mac(struct net_device *ndev, int queue, u8 *mac);
static int sdummy_netdev_set_vf_vlan(struct net_device *ndev, int queue, u16 vlan, u8 qos, __be16 proto);
static int sdummy_netdev_set_vf_rate(struct net_device *ndev, int vf, int min_tx_rate, int max_tx_rate);
static int sdummy_netdev_set_vf_spoofchk(struct net_device *ndev, int vf, bool setting);
static int sdummy_netdev_set_vf_trust(struct net_device *ndev, int vf, bool setting);
static int sdummy_netdev_get_vf_config(struct net_device *ndev, int vf, struct ifla_vf_info *ivf);
static int sdummy_netdev_set_vf_link_state(struct net_device *ndev, int vf, int link_state);
static int sdummy_netdev_get_vf_stats(struct net_device *ndev, int vf, struct ifla_vf_stats *vf_stats);
static int sdummy_netdev_set_vf_port(struct net_device *ndev, int vf, struct nlattr *port[]);
static int sdummy_netdev_get_vf_port(struct net_device *ndev, int vf, struct sk_buff *skb);
static int sdummy_netdev_set_vf_guid(struct net_device *ndev, int vf, u64 guid, int guid_type);
static int sdummy_netdev_set_vf_rss_query_en(struct net_device *ndev, int vf, bool setting);

static int sdummy_netdev_setup_tc(struct net_device *ndev, enum tc_setup_type type, void *type_data);

#if IS_ENABLED(CONFIG_FCOE)
static int sdummy_netdev_fcoe_enable(struct net_device *ndev);
static int sdummy_netdev_fcoe_disable(struct net_device *ndev);
static int sdummy_netdev_fcoe_ddp_setup(struct net_device *ndev, u16 xid, struct scatterlist *sgl, unsigned int sgc);
static int sdummy_netdev_fcoe_ddp_done(struct net_device *ndev, u16 xid);
static int sdummy_netdev_fcoe_ddp_target(struct net_device *ndev, u16 xid, struct scatterlist *sgl, unsigned int sgc);
static int sdummy_netdev_fcoe_get_hbainfo(struct net_device *ndev, struct netdev_fcoe_hbainfo *hbainfo);
#endif
#if IS_ENABLED(CONFIG_LIBFCOE)
static int sdummy_netdev_fcoe_get_wwn(struct net_device *ndev, u64 *wwn, int type);
#endif

#ifdef CONFIG_RFS_ACCEL
static int sdummy_netdev_rx_flow_steer(struct net_device *ndev, const struct sk_buff *skb, u16 rxq_index, u32 flow_id);
#endif

static int sdummy_netdev_add_slave(struct net_device *ndev, struct net_device *slave_dev, struct netlink_ext_ack *extack);
static int sdummy_netdev_del_slave(struct net_device *ndev, struct net_device *slave_dev);
#endif

static netdev_features_t sdummy_netdev_fix_features(struct net_device *ndev, netdev_features_t features);
static int sdummy_netdev_set_features(struct net_device *ndev, netdev_features_t features);

#if 0
static int sdummy_netdev_neigh_construct(struct net_device *ndev, struct neighbour *n);
static void sdummy_netdev_neigh_destroy(struct net_device *ndev, struct neighbour *n);
static int sdummy_netdev_fdb_add(struct ndmsg *ndm, struct nlattr *tb[], struct net_device *ndev, const unsigned char *addr, u16 vid, u16 flags);
static int sdummy_netdev_fdb_del(struct ndmsg *ndm, struct nlattr *tb[], struct net_device *ndev, const unsigned char *addr, u16 vid);
static int sdummy_netdev_fdb_dump(struct sk_buff *skb, struct netlink_callback *cb, struct net_device *ndev, struct net_device *filter_dev, int *idx);
static int sdummy_netdev_bridge_setlink(struct net_device *ndev, struct nlmsghdr *nlh, u16 flags);
static int sdummy_netdev_bridge_getlink(struct sk_buff *skb, u32 pid, u32 seq, struct net_device *ndev, u32 filter_mask, int nlflags);
static int sdummy_netdev_bridge_dellink(struct net_device *ndev, struct nlmsghdr *nlh, u16 flags);
static int sdummy_netdev_change_carrier(struct net_device *ndev, bool new_carrier);

static int sdummy_netdev_get_phys_port_id(struct net_device *ndev, struct netdev_phys_item_id *ppid);
static int sdummy_netdev_get_phys_port_name(struct net_device *ndev, char *name, size_t len);

static void sdummy_netdev_udp_tunnel_add(struct net_device *ndev, struct udp_tunnel_info *ti);
static void sdummy_netdev_udp_tunnel_del(struct net_device *ndev, struct udp_tunnel_info *ti);
static void* sdummy_netdev_dfwd_add_station(struct net_device *pdev, struct net_device *ndev);
static void sdummy_netdev_dfwd_del_station(struct net_device *pdev, void *priv);
static int sdummy_netdev_get_lock_subclass(struct net_device *ndev);
static int sdummy_netdev_set_tx_maxrate(struct net_device *ndev, int queue_index, u32 maxrate);

static int sdummy_netdev_get_iflink(const struct net_device *ndev);

static int sdummy_netdev_change_proto_down(struct net_device *ndev, bool proto_down);
static int sdummy_netdev_fill_metadata_dst(struct net_device *ndev, struct sk_buff *skb);
static void sdummy_netdev_set_rx_headroom(struct net_device *ndev, int needed_headroom);

static int sdummy_netdev_bpf(struct net_device *ndev, struct netdev_bpf *bpf);

static int sdummy_netdev_xdp_xmit(struct net_device *ndev, int n, struct xdp_frame **xdp, u32 flags);
static int sdummy_netdev_xsk_async_xmit(struct net_device *ndev, u32 queue_id);

#endif

/* End of SOLID_DUMMY_NETDEV_Private_Functions */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NETDEV_Private_Variables
  * @{
  */

static const struct net_device_ops sdummy_netdev_ops = {

    // Don't need to implement : .ndo_init                              = sdummy_netdev_init,
    // Don't need to implement : .ndo_uninit                            = sdummy_netdev_uninit,
    .ndo_open                              = sdummy_netdev_open,
    .ndo_stop                              = sdummy_netdev_stop,
    .ndo_start_xmit                        = sdummy_netdev_start_xmit,
    // Don't need to implement : .ndo_features_check                    = sdummy_netdev_features_check,
    // Don't need to implement : .ndo_select_queue                      = sdummy_netdev_select_queue,
    // Don't need to implement : .ndo_change_rx_flags                   = sdummy_netdev_change_rx_flags,

    .ndo_set_rx_mode                       = sdummy_netdev_set_rx_mode,
    .ndo_set_mac_address                   = sdummy_netdev_set_mac_address,

    .ndo_validate_addr                     = sdummy_netdev_validate_addr,
    .ndo_do_ioctl                          = sdummy_netdev_do_ioctl,
    // Don't need to implement : .ndo_set_config                        = sdummy_netdev_set_config,
    .ndo_change_mtu                        = sdummy_netdev_change_mtu,
    // Don't need to implement : .ndo_neigh_setup                       = sdummy_netdev_neigh_setup,
    .ndo_tx_timeout                        = sdummy_netdev_tx_timeout,
    .ndo_get_stats64                       = sdummy_netdev_get_stats64,
    // Don't need to implement : .ndo_has_offload_stats                 = sdummy_netdev_has_offload_stats,
    // Don't need to implement : .ndo_get_offload_stats                 = sdummy_netdev_get_offload_stats,
    .ndo_get_stats                         = sdummy_netdev_get_stats,
    .ndo_vlan_rx_add_vid                   = sdummy_netdev_vlan_rx_add_vid,
    .ndo_vlan_rx_kill_vid                  = sdummy_netdev_vlan_rx_kill_vid,
    
#ifdef CONFIG_NET_POLL_CONTROLLER
    .ndo_poll_controller                   = sdummy_netdev_poll_controller,
    // Don't need to implement : .ndo_netpoll_setup                     = sdummy_netdev_netpoll_setup,
    // Don't need to implement : .ndo_netpoll_cleanup                   = sdummy_netdev_netpoll_cleanup,
#endif
    // Don't need to implement : .ndo_set_vf_mac                        = sdummy_netdev_set_vf_mac,
    // Don't need to implement : .ndo_set_vf_vlan                       = sdummy_netdev_set_vf_vlan,
    // Don't need to implement : .ndo_set_vf_rate                       = sdummy_netdev_set_vf_rate,
    // Don't need to implement : .ndo_set_vf_spoofchk                   = sdummy_netdev_set_vf_spoofchk,
    // Don't need to implement : .ndo_set_vf_trust                      = sdummy_netdev_set_vf_trust,
    // Don't need to implement : .ndo_get_vf_config                     = sdummy_netdev_get_vf_config,
    // Don't need to implement : .ndo_set_vf_link_state                 = sdummy_netdev_set_vf_link_state,
    // Don't need to implement : .ndo_get_vf_stats                      = sdummy_netdev_get_vf_stats,
    // Don't need to implement : .ndo_set_vf_port                       = sdummy_netdev_set_vf_port,
    // Don't need to implement : .ndo_get_vf_port                       = sdummy_netdev_get_vf_port,
    // Don't need to implement : .ndo_set_vf_guid                       = sdummy_netdev_set_vf_guid,
    // Don't need to implement : .ndo_set_vf_rss_query_en               = sdummy_netdev_set_vf_rss_query_en,
    // Don't need to implement : .ndo_setup_tc                          = sdummy_netdev_setup_tc,

#if IS_ENABLED(CONFIG_FCOE)
    // Don't need to implement : .ndo_fcoe_enable                       = sdummy_netdev_fcoe_enable,
    // Don't need to implement : .ndo_fcoe_disable                      = sdummy_netdev_fcoe_disable,
    // Don't need to implement : .ndo_fcoe_ddp_setup                    = sdummy_netdev_fcoe_ddp_setup,
    // Don't need to implement : .ndo_fcoe_ddp_done                     = sdummy_netdev_fcoe_ddp_done,
    // Don't need to implement : .ndo_fcoe_ddp_target                   = sdummy_netdev_fcoe_ddp_target,
    // Don't need to implement : .ndo_fcoe_get_hbainfo                  = sdummy_netdev_fcoe_get_hbainfo,
#endif

#if IS_ENABLED(CONFIG_LIBFCOE)
    // Don't need to implement : .ndo_fcoe_get_wwn                      = sdummy_netdev_fcoe_get_wwn,
#endif
#ifdef CONFIG_RFS_ACCEL
    // Don't need to implement : .ndo_rx_flow_steer                     = sdummy_netdev_rx_flow_steer,
#endif

    // Don't need to implement : .ndo_add_slave                         = sdummy_netdev_add_slave,
    // Don't need to implement : .ndo_del_slave                         = sdummy_netdev_del_slave,

    .ndo_fix_features                      = sdummy_netdev_fix_features,
    .ndo_set_features                      = sdummy_netdev_set_features,

    // Don't need to implement : .ndo_neigh_construct                   = sdummy_netdev_neigh_construct,
    // Don't need to implement : .ndo_neigh_destroy                     = sdummy_netdev_neigh_destroy,

    // Don't need to implement : .ndo_fdb_add                           = sdummy_netdev_fdb_add,
    // Don't need to implement : .ndo_fdb_del                           = sdummy_netdev_fdb_del,
    // Don't need to implement : .ndo_fdb_dump                          = sdummy_netdev_fdb_dump,

    // Don't need to implement : .ndo_bridge_setlink                    = sdummy_netdev_bridge_setlink,
    // Don't need to implement : .ndo_bridge_getlink                    = sdummy_netdev_bridge_getlink,
    // Don't need to implement : .ndo_bridge_dellink                    = sdummy_netdev_bridge_dellink,

    // Don't need to implement : .ndo_change_carrier                    = sdummy_netdev_change_carrier,

    // Don't need to implement : .ndo_get_phys_port_id                  = sdummy_netdev_get_phys_port_id,
    // Don't need to implement : .ndo_get_phys_port_name                = sdummy_netdev_get_phys_port_name,
    
    // Don't need to implement : .ndo_udp_tunnel_add                    = sdummy_netdev_udp_tunnel_add,
    // Don't need to implement : .ndo_udp_tunnel_del                    = sdummy_netdev_udp_tunnel_del,
    
    // Don't need to implement : .ndo_dfwd_add_station                  = sdummy_netdev_dfwd_add_station,
    // Don't need to implement : .ndo_dfwd_del_station                  = sdummy_netdev_dfwd_del_station,

    // Don't need to implement : .ndo_get_lock_subclass                 = sdummy_netdev_get_lock_subclass,
    // Don't need to implement : .ndo_set_tx_maxrate                    = sdummy_netdev_set_tx_maxrate,

    // Don't need to implement : .ndo_get_iflink                        = sdummy_netdev_get_iflink,

    // Don't need to implement : .ndo_change_proto_down                 = sdummy_netdev_change_proto_down,
    // Don't need to implement : .ndo_fill_metadata_dst                 = sdummy_netdev_fill_metadata_dst,
    // Don't need to implement : .ndo_set_rx_headroom                   = sdummy_netdev_set_rx_headroom,    
    // Don't need to implement : .ndo_bpf                               = sdummy_netdev_bpf,
    // Don't need to implement : .ndo_xdp_xmit                          = sdummy_netdev_xdp_xmit,
    // Don't need to implement : .ndo_xsk_async_xmit                    = sdummy_netdev_xsk_async_xmit
};


/* End of SOLID_DUMMY_NETDEV_Private_Variables */
/**
  * @}
  */

/* Exported variables ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NETDEV_Exported_Variables
  * @{
  */
/* End of SOLID_DUMMY_NETDEV_Exported_Variables */
/**
  * @}
  */

/* Private functions ------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NETDEV_Private_Functions
  * @{
  */

#if 0
static int sdummy_netdev_init(struct net_device *ndev)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_init : ndev(%s)\n", netdev_name_safe(ndev));

#if 0
	ndev->dstats = netdev_alloc_pcpu_stats(struct pcpu_dstats);
	if (!ndev->dstats) {
		ret = -ENOMEM;
    }
#endif

    sdummy_debug_exit(".ndo_init : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static void sdummy_netdev_uninit(struct net_device *ndev)
{
    sdummy_debug_enter(".ndo_uninit : ndev(%s)\n", netdev_name_safe(ndev));

    free_percpu(ndev->dstats);
    
    sdummy_debug_exit(".ndo_uninit : ndev(%s)\n", netdev_name_safe(ndev));
}

#endif

static int sdummy_netdev_open(struct net_device *ndev)
{
    int ret = 0;
    const char *ndev_name = sdummy_dev_name(ndev);
    sdummy_debug_enter(".ndo_open : ndev(%s), dev(%s)\n", ndev_name);

    sdummy_debug_exit(".ndo_open : ndev(%s), dev(%s)\n", ndev_name); 
    return ret;
}


static int sdummy_netdev_stop(struct net_device *ndev)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_stop : ndev(%s)\n", netdev_name_safe(ndev));

    sdummy_debug_exit(".ndo_stop : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static netdev_tx_t sdummy_netdev_start_xmit(struct sk_buff *skb,struct net_device *ndev)
{
    netdev_tx_t ret = NETDEV_TX_OK;
    sdummy_debug_enter(".ndo_start_xmit : ndev(%s)\n", netdev_name_safe(ndev));

    sdummy_debug_exit(".ndo_start_xmit : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#if 0
static netdev_features_t sdummy_netdev_features_check(struct sk_buff *skb, struct net_device *ndev, netdev_features_t features)
{
    netdev_features_t ret = 0;
    sdummy_debug_enter(".ndo_features_check : ndev(%s)\n", netdev_name_safe(ndev));

    ret = features;
    sdummy_debug_exit(".ndo_features_check : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
    
}

static u16 sdummy_netdev_select_queue(struct net_device *ndev, struct sk_buff *skb, struct net_device *sb_dev, select_queue_fallback_t fallback)
{
    u16  ret = 0;
    sdummy_debug_enter(".ndo_select_queue : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_select_queue is under construction !!!\n"); 
    sdummy_debug_exit(".ndo_select_queue : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static void sdummy_netdev_change_rx_flags(struct net_device *ndev, int flags)
{
    sdummy_debug_enter(".ndo_change_rx_flags : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_change_rx_flags is under construction !!!\n"); 
    
    sdummy_debug_exit(".ndo_change_rx_flags : ndev(%s)\n", netdev_name_safe(ndev));
}
#endif

static void sdummy_netdev_set_rx_mode(struct net_device *ndev)
{
    sdummy_debug_enter(".ndo_set_rx_mode : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_rx_mode is under construction !!!\n");

    sdummy_debug_exit(".ndo_set_rx_mode : ndev(%s)\n", netdev_name_safe(ndev));
}

static int sdummy_netdev_set_mac_address(struct net_device *ndev, void *addr)
{
    int ret = 0;
   
    sdummy_debug_enter(".ndo_set_mac_address : ndev(%s)\n", netdev_name_safe(ndev));

    if (addr) {
        ether_addr_copy(ndev->dev_addr, addr);
    }
    if (!is_valid_ether_addr(ndev->dev_addr)) {
        eth_hw_addr_random(ndev);
    }
    
    sdummy_debug_exit(".ndo_set_mac_address : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_validate_addr(struct net_device *ndev)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_validate_addr : ndev(%s)\n", netdev_name_safe(ndev));
    ret = eth_validate_addr(ndev);
    sdummy_debug_exit(".ndo_validate_addr : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_do_ioctl(struct net_device *ndev, struct ifreq *ifr, int cmd)
{
    int ret = 0;
    
    sdummy_debug_enter(".ndo_do_ioctl : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_do_ioctl is under construction !!!\n");

    switch(cmd) {
    case SIOCADDRT:         // 0x890B  /* add routing table entry */
    case SIOCDELRT:         // 0x890C  /* delete routing table entry */
    case SIOCRTMSG:         // 0x890D  /* unused   */
        
         /* Socket configuration controls. */
    case SIOCGIFNAME:             /* 0x8910 */ /* get iface name  */
    case SIOCSIFLINK:             /* 0x8911 */ /* set iface channel  */
    case SIOCGIFCONF:             /* 0x8912 */ /* get iface list  */
    case SIOCGIFFLAGS:            /* 0x8913 */ /* get flags   */
    case SIOCSIFFLAGS:            /* 0x8914 */ /* set flags   */
    case SIOCGIFADDR:             /* 0x8915 */ /* get PA address  */
    case SIOCSIFADDR:             /* 0x8916 */ /* set PA address  */
    case SIOCGIFDSTADDR:          /* 0x8917 */ /* get remote PA address */
    case SIOCSIFDSTADDR:          /* 0x8918 */ /* set remote PA address */
    case SIOCGIFBRDADDR:          /* 0x8919 */ /* get broadcast PA address */
    case SIOCSIFBRDADDR:          /* 0x891a */ /* set broadcast PA address */
    case SIOCGIFNETMASK:          /* 0x891b */ /* get network PA mask  */
    case SIOCSIFNETMASK:          /* 0x891c */ /* set network PA mask  */
    case SIOCGIFMETRIC:           /* 0x891d */ /* get metric   */
    case SIOCSIFMETRIC:           /* 0x891e */ /* set metric   */
    case SIOCGIFMEM:              /* 0x891f */ /* get memory address (BSD) */
    case SIOCSIFMEM:              /* 0x8920 */ /* set memory address (BSD) */
    case SIOCGIFMTU:              /* 0x8921 */ /* get MTU size   */
    case SIOCSIFMTU:              /* 0x8922 */ /* set MTU size   */
    case SIOCSIFNAME:             /* 0x8923 */ /* set interface name */
    case SIOCSIFHWADDR:           /* 0x8924 */ /* set hardware address  */
    case SIOCGIFENCAP:            /* 0x8925 */ /* get/set encapsulations       */
    case SIOCSIFENCAP:            /* 0x8926 */ 
    case SIOCGIFHWADDR:           /* 0x8927 */ /* Get hardware address  */
    case SIOCGIFSLAVE:            /* 0x8929 */ /* Driver slaving support */
    case SIOCSIFSLAVE:            /* 0x8930 */
    case SIOCADDMULTI:            /* 0x8931 */ /* Multicast address lists */
    case SIOCDELMULTI:            /* 0x8932 */
    case SIOCGIFINDEX:            /* 0x8933 */ /* name -> if_index mapping */
    // case SIOGIFINDEX:             /*        */ /* misprint compatibility :-) */
    case SIOCSIFPFLAGS:           /* 0x8934 */ /* set/get extended flags set */
    case SIOCGIFPFLAGS:           /* 0x8935 */
    case SIOCDIFADDR:             /* 0x8936 */ /* delete PA address  */
    case SIOCSIFHWBROADCAST:      /* 0x8937 */ /* set hardware broadcast addr */
    case SIOCGIFCOUNT:            /* 0x8938 */ /* get number of devices */
    							  
    case SIOCGIFBR:               /* 0x8940 */ /* Bridging support  */
    case SIOCSIFBR:               /* 0x8941 */ /* Set bridging options  */
    							  
    case SIOCGIFTXQLEN:           /* 0x8942 */ /* Get the tx queue length */
    case SIOCSIFTXQLEN:           /* 0x8943 */ /* Set the tx queue length  */
    							   
    case SIOCETHTOOL:             /* 0x8946 */ /* Ethtool interface  */
    							   
    case SIOCGMIIPHY:             /* 0x8947 */ /* Get address of MII PHY in use. */
    case SIOCGMIIREG:             /* 0x8948 */ /* Read MII PHY register. */
    case SIOCSMIIREG:             /* 0x8949 */ /* Write MII PHY register. */
    							   
    case SIOCWANDEV:              /* 0x894A */ /* get/set netdev parameters */
    							  
    case SIOCOUTQNSD:             /* 0x894B */ /* output queue size (not sent only) */
    case SIOCGSKNS:               /* 0x894C */ /* get socket network namespace */
        
        /* ARP cache control calls. */
    case SIOCDARP:                /* 0x8953 */ /* delete ARP table entry */
    case SIOCGARP:                /* 0x8954 */ /* get ARP table entry  */
    case SIOCSARP:                /* 0x8955 */ /* set ARP table entry  */
        
        /* RARP cache control calls. */
    case SIOCDRARP:               /* 0x8960 */ /* delete RARP table entry */
    case SIOCGRARP:               /* 0x8961 */ /* get RARP table entry  */
    case SIOCSRARP:               /* 0x8962 */ /* set RARP table entry  */
        
    	/* Driver configuration calls */    
    case SIOCGIFMAP:              /* 0x8970 */ /* Get device parameters */
    case SIOCSIFMAP:              /* 0x8971 */ /* Set device parameters */
        
        /* DLCI configuration calls */    
    case SIOCADDDLCI:             /* 0x8980 */ /* Create new DLCI device */
    case SIOCDELDLCI:             /* 0x8981 */ /* Delete DLCI device  */
    							  
    case SIOCGIFVLAN:             /* 0x8982 */ /* 802.1Q VLAN support  */
    case SIOCSIFVLAN:             /* 0x8983 */ /* Set 802.1Q VLAN options  */
    							  
        /* bonding calls */        
    case SIOCBONDENSLAVE:         /* 0x8990 */ /* enslave a device to the bond */
    case SIOCBONDRELEASE:         /* 0x8991 */ /* release a slave from the bond*/
    case SIOCBONDSETHWADDR:       /* 0x8992 */ /* set the hw addr of the bond  */
    case SIOCBONDSLAVEINFOQUERY:  /* 0x8993 */ /* rtn info about slave state   */
    case SIOCBONDINFOQUERY:       /* 0x8994 */ /* rtn info about bond state    */
    case SIOCBONDCHANGEACTIVE:    /* 0x8995 */ /* update to a new active slave */
    							  
    	/* bridge calls */        
    case SIOCBRADDBR:             /* 0x89a0 */ /* create new bridge device     */
    case SIOCBRDELBR:             /* 0x89a1 */ /* remove bridge device         */
    case SIOCBRADDIF:             /* 0x89a2 */ /* add interface to bridge      */
    case SIOCBRDELIF:             /* 0x89a3 */ /* remove interface from bridge */
        
         /* hardware time stamping: parameters in linux/net_tstamp.h */
    case SIOCSHWTSTAMP:           /* 0x89b0 */ /* set and get config  */
    case SIOCGHWTSTAMP:           /* 0x89b1 */ /* get config   */
        
        /* Device private ioctl calls */    
        /*
         *  These 16 ioctls are available to devices via the do_ioctl() device
         *  vector. Each device should include this file and redefine these names
         *  as their own. Because these are device dependent it is a good idea
         *  _NOT_ to issue them to random objects and hope.
         *
         *  THESE IOCTLS ARE _DEPRECATED_ AND WILL DISAPPEAR IN 2.5.X -DaveM
         */
         
    case SIOCDEVPRIVATE: /* 0x89F0 to 89FF */
        
        /*
         *  These 16 ioctl calls are protocol private
         */     
    case SIOCPROTOPRIVATE: /* 0x89E0 to 89EF */

        break;

    default:
        break;

    }
 
   
    sdummy_debug_exit(".ndo_do_ioctl : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}


#if 0

static int sdummy_netdev_set_config(struct net_device *ndev, struct ifmap *map)
{
    int ret = 0;
    
    sdummy_debug_enter(".ndo_set_config : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_config is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_config : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}

#endif

static int sdummy_netdev_change_mtu(struct net_device *ndev, int new_mtu)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_change_mtu : ndev(%s)\n", netdev_name_safe(ndev));
	ndev->mtu = new_mtu;
    sdummy_info(ndev, "MTU : %d\n", ndev->mtu);
    sdummy_debug_exit(".ndo_change_mtu : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#if 0
static int sdummy_netdev_neigh_setup(struct net_device *ndev, struct neigh_parms *params)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_neigh_setup : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_neigh_setup is under construction !!!\n");  
    sdummy_debug_exit(".ndo_neigh_setup : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

static void sdummy_netdev_tx_timeout(struct net_device *ndev)
{
    sdummy_debug_enter(".ndo_tx_timeout : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_tx_timeout is under construction !!!\n");  
    sdummy_debug_exit(".ndo_tx_timeout : ndev(%s)\n", netdev_name_safe(ndev));
}

static void sdummy_netdev_get_stats64(struct net_device *ndev, struct rtnl_link_stats64 *stats)
{
    struct sdummy_local *lp = netdev_priv(ndev);

    sdummy_debug_enter(".ndo_get_stats64 : ndev(%s)\n", netdev_name_safe(ndev));

    sdummy_update_stats(ndev);    
    memcpy(stats, &lp->netlink_stat64, sizeof(struct rtnl_link_stats64));

#ifdef    SDUMMY_STATICS_TEST    
    sdummy_debug_msg("stats->rx_packets = %lld\n", stats->rx_packets);
    sdummy_debug_msg("stats->tx_packets = %lld\n", stats->tx_packets);    
#endif /* SDUMMY_STATICS_TEST */
    
    sdummy_debug_exit(".ndo_get_stats64 : ndev(%s)\n", netdev_name_safe(ndev));
    
}

#if 0
static bool sdummy_netdev_has_offload_stats(const struct net_device *ndev, int attr_id)
{
    bool ret = false;
    sdummy_debug_enter(".ndo_has_offload_stats : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_has_offload_stats is under construction !!!\n");  
    sdummy_debug_exit(".ndo_has_offload_stats : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_get_offload_stats(int attr_id, const struct net_device *ndev, void *attr_data)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_get_offload_stats : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_get_offload_stats is under construction !!!\n");  
    sdummy_debug_exit(".ndo_get_offload_stats : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

static struct net_device_stats* sdummy_netdev_get_stats(struct net_device *ndev)
{
    struct sdummy_local *lp = netdev_priv(ndev);
    struct net_device_stats *nstat = &lp->ndev->stats;

    sdummy_debug_enter(".ndo_get_stats : ndev(%s)\n", netdev_name_safe(ndev));

    sdummy_update_stats(ndev);

    sdummy_debug_exit(".ndo_get_stats : ndev(%s)\n", netdev_name_safe(ndev));
    
    return nstat;
}

#ifdef REF_CODE

static int e1000_vlan_rx_add_vid(struct net_device *netdev, __be16 proto, u16 vid)
{
    struct e1000_adapter *adapter = netdev_priv(netdev);
    struct e1000_hw *hw = &adapter->hw;
    u32 vfta, index;

    if ((hw->mng_cookie.status &
         E1000_MNG_DHCP_COOKIE_STATUS_VLAN_SUPPORT) &&
        (vid == adapter->mng_vlan_id))
        return 0;

    if (!e1000_vlan_used(adapter))
        e1000_vlan_filter_on_off(adapter, true);

    /* add VID to filter table */
    index = (vid >> 5) & 0x7F;
    vfta = E1000_READ_REG_ARRAY(hw, VFTA, index);
    vfta |= (1 << (vid & 0x1F));
    e1000_write_vfta(hw, index, vfta);

    set_bit(vid, adapter->active_vlans);

    return 0;
}

#endif  


static int sdummy_netdev_vlan_rx_add_vid(struct net_device *ndev, __be16 proto, u16 vid)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_vlan_rx_add_vid : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_vlan_rx_add_vid is under construction !!!\n");  
    
    sdummy_debug_exit(".ndo_vlan_rx_add_vid : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
    
static int sdummy_netdev_vlan_rx_kill_vid(struct net_device *ndev, __be16 proto, u16 vid)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_vlan_rx_kill_vid : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_vlan_rx_kill_vid is under construction !!!\n"); 
    sdummy_debug_exit(".ndo_vlan_rx_kill_vid : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


#ifdef CONFIG_NET_POLL_CONTROLLER

static void sdummy_netdev_poll_controller(struct net_device *ndev)
{
    sdummy_debug_enter(".ndo_poll_controller : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_poll_controller is under construction !!!\n");  
    sdummy_debug_exit(".ndo_poll_controller : ndev(%s)\n", netdev_name_safe(ndev));
}

#if 0

static int sdummy_netdev_netpoll_setup(struct net_device *ndev, struct netpoll_info *info)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_netpoll_setup : ndev(%s)\n", netdev_name_safe(ndev));

    sdummy_debug_exit(".ndo_netpoll_setup : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static void sdummy_netdev_netpoll_cleanup(struct net_device *ndev)
{
    sdummy_debug_enter(".ndo_netpoll_cleanup : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_netpoll_cleanup is under construction !!!\n");  

    sdummy_debug_exit(".ndo_netpoll_cleanup : ndev(%s)\n", netdev_name_safe(ndev));
}
#endif

#endif /* CONFIG_NET_POLL_CONTROLLER */

#if 0
static int sdummy_netdev_set_vf_mac(struct net_device *ndev, int queue, u8 *mac)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_set_vf_mac : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_mac is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_mac : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_vlan(struct net_device *ndev, int queue, u16 vlan, u8 qos, __be16 proto)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_set_vf_vlan : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_vlan is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_vlan : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_rate(struct net_device *ndev, int vf, int min_tx_rate, int max_tx_rate)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_set_vf_rate : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_rate is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_rate : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_spoofchk(struct net_device *ndev, int vf, bool setting)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_set_vf_spoofchk : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_spoofchk is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_spoofchk : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_trust(struct net_device *ndev, int vf, bool setting)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_set_vf_trust : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_trust is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_trust : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_get_vf_config(struct net_device *ndev, int vf, struct ifla_vf_info *ivf)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_get_vf_config : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_get_vf_config is under construction !!!\n");  
    sdummy_debug_exit(".ndo_get_vf_config : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_link_state(struct net_device *ndev, int vf, int link_state)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_set_vf_link_state : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_link_state is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_link_state : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_get_vf_stats(struct net_device *ndev, int vf, struct ifla_vf_stats *vf_stats)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_get_vf_stats : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_get_vf_stats is under construction !!!\n");  
    sdummy_debug_exit(".ndo_get_vf_stats : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_port(struct net_device *ndev, int vf, struct nlattr *port[])
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_set_vf_port : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_port is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_port : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_get_vf_port(struct net_device *ndev, int vf, struct sk_buff *skb)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_get_vf_port : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_get_vf_port is under construction !!!\n");  
    sdummy_debug_exit(".ndo_get_vf_port : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_guid(struct net_device *ndev, int vf, u64 guid, int guid_type)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_set_vf_guid : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_guid is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_guid : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_set_vf_rss_query_en(struct net_device *ndev, int vf, bool setting)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_set_vf_rss_query_en : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_vf_rss_query_en is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_vf_rss_query_en : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_setup_tc(struct net_device *ndev, enum tc_setup_type type, void *type_data)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_setup_tc : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_setup_tc is under construction !!!\n");  
    sdummy_debug_exit(".ndo_setup_tc : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

#if IS_ENABLED(CONFIG_FCOE)

static int sdummy_netdev_fcoe_enable(struct net_device *ndev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fcoe_enable : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fcoe_enable is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fcoe_enable : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_fcoe_disable(struct net_device *ndev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fcoe_disable : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fcoe_disable is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fcoe_disable : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static int sdummy_netdev_fcoe_ddp_setup(struct net_device *ndev, u16 xid, struct scatterlist *sgl, unsigned int sgc)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fcoe_ddp_setup : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fcoe_ddp_setup is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fcoe_ddp_setup : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_fcoe_ddp_done(struct net_device *ndev, u16 xid)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fcoe_ddp_done : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fcoe_ddp_done is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fcoe_ddp_done : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_fcoe_ddp_target(struct net_device *ndev, u16 xid, struct scatterlist *sgl, unsigned int sgc)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fcoe_ddp_target : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fcoe_ddp_target is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fcoe_ddp_target : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_fcoe_get_hbainfo(struct net_device *ndev, struct netdev_fcoe_hbainfo *hbainfo)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fcoe_get_hbainfo : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fcoe_get_hbainfo is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fcoe_get_hbainfo : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

#if IS_ENABLED(CONFIG_LIBFCOE)

static int sdummy_netdev_fcoe_get_wwn(struct net_device *ndev, u64 *wwn, int type)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fcoe_get_wwn : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fcoe_get_wwn is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fcoe_get_wwn : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

#ifdef CONFIG_RFS_ACCEL
static int sdummy_netdev_rx_flow_steer(struct net_device *ndev, const struct sk_buff *skb, u16 rxq_index, u32 flow_id)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_rx_flow_steer : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_rx_flow_steer is under construction !!!\n");  
    sdummy_debug_exit(".ndo_rx_flow_steer : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}
#endif

static int sdummy_netdev_add_slave(struct net_device *ndev, struct net_device *slave_dev, struct netlink_ext_ack *extack)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_add_slave : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_add_slave is under construction !!!\n");  
    sdummy_debug_exit(".ndo_add_slave : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_del_slave(struct net_device *ndev, struct net_device *slave_dev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_del_slave : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_del_slave is under construction !!!\n");  
    sdummy_debug_exit(".ndo_del_slave : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

#endif

static netdev_features_t sdummy_netdev_fix_features(struct net_device *ndev, netdev_features_t features)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fix_features : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_debug_msg(".ndo_fix_features - features = %016llx\n", (u64)features);
    ret = features;
    sdummy_debug_exit(".ndo_fix_features : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}


static int sdummy_netdev_set_features(struct net_device *ndev, netdev_features_t features)
{
    int ret = 0;
    sdummy_debug_enter(".ndo_set_features : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_debug_msg(".ndo_set_features - features = %016llx\n", (u64)features);
    sdummy_debug_exit(".ndo_set_features : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#if 0
static int sdummy_netdev_neigh_construct(struct net_device *ndev, struct neighbour *n)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_neigh_construct : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_neigh_construct is under construction !!!\n");  
    sdummy_debug_exit(".ndo_neigh_construct : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}

static void sdummy_netdev_neigh_destroy(struct net_device *ndev, struct neighbour *n)
{
    sdummy_debug_enter(".ndo_neigh_destroy : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_neigh_destroy is under construction !!!\n");  
    sdummy_debug_exit(".ndo_neigh_destroy : ndev(%s)\n", netdev_name_safe(ndev));
}

/* Filtering Database */
static int sdummy_netdev_fdb_add(struct ndmsg *ndm, struct nlattr *tb[], struct net_device *ndev, const unsigned char *addr, u16 vid, u16 flags)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fdb_add : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fdb_add is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fdb_add : ndev(%s)\n", netdev_name_safe(ndev));

    return ret;
}

static int sdummy_netdev_fdb_del(struct ndmsg *ndm, struct nlattr *tb[], struct net_device *ndev, const unsigned char *addr, u16 vid)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fdb_del : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fdb_del is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fdb_del : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_fdb_dump(struct sk_buff *skb, struct netlink_callback *cb, struct net_device *ndev, struct net_device *filter_dev, int *idx)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fdb_dump : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fdb_dump is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fdb_dump : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_bridge_setlink(struct net_device *ndev, struct nlmsghdr *nlh, u16 flags)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_bridge_setlink : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_bridge_setlink is under construction !!!\n");  
    sdummy_debug_exit(".ndo_bridge_setlink : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_bridge_getlink(struct sk_buff *skb, u32 pid, u32 seq, struct net_device *ndev, u32 filter_mask, int nlflags)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_bridge_getlink : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_bridge_getlink is under construction !!!\n");  
    sdummy_debug_exit(".ndo_bridge_getlink : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_bridge_dellink(struct net_device *ndev, struct nlmsghdr *nlh, u16 flags)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_bridge_dellink : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_bridge_dellink is under construction !!!\n");  
    sdummy_debug_exit(".ndo_bridge_dellink : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_change_carrier(struct net_device *ndev, bool new_carrier)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_change_carrier : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_change_carrier is under construction !!!\n");  
    sdummy_debug_exit(".ndo_change_carrier : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_get_phys_port_id(struct net_device *ndev, struct netdev_phys_item_id *ppid)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_get_phys_port_id : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_get_phys_port_id is under construction !!!\n");  
    sdummy_debug_exit(".ndo_get_phys_port_id : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_get_phys_port_name(struct net_device *ndev, char *name, size_t len)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_get_phys_port_name : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_get_phys_port_name is under construction !!!\n");  
    sdummy_debug_exit(".ndo_get_phys_port_name : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static void sdummy_netdev_udp_tunnel_add(struct net_device *ndev, struct udp_tunnel_info *ti)
{
    sdummy_debug_enter(".ndo_udp_tunnel_add : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_udp_tunnel_add is under construction !!!\n");  
    sdummy_debug_exit(".ndo_udp_tunnel_add : ndev(%s)\n", netdev_name_safe(ndev));
}

static void sdummy_netdev_udp_tunnel_del(struct net_device *ndev, struct udp_tunnel_info *ti)
{
    sdummy_debug_enter(".ndo_udp_tunnel_del : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_udp_tunnel_del is under construction !!!\n");  
    sdummy_debug_exit(".ndo_udp_tunnel_del : ndev(%s)\n", netdev_name_safe(ndev));
}

static void* sdummy_netdev_dfwd_add_station(struct net_device *pdev, struct net_device *ndev)
{
    void *ret = NULL;
    sdummy_debug_enter(".ndo_dfwd_add_station : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_dfwd_add_station is under construction !!!\n");  
    sdummy_debug_exit(".ndo_dfwd_add_station : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static void sdummy_netdev_dfwd_del_station(struct net_device *ndev, void *priv)
{
    sdummy_debug_enter(".ndo_dfwd_del_station : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_dfwd_del_station is under construction !!!\n");  
    sdummy_debug_exit(".ndo_dfwd_del_station : ndev(%s)\n", netdev_name_safe(ndev));
}

static int sdummy_netdev_get_lock_subclass(struct net_device *ndev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_get_lock_subclass : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_get_lock_subclass is under construction !!!\n");  
    sdummy_debug_exit(".ndo_get_lock_subclass : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_set_tx_maxrate(struct net_device *ndev, int queue_index, u32 maxrate)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_set_tx_maxrate : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_tx_maxrate is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_tx_maxrate : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_get_iflink(const struct net_device *ndev)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_get_iflink : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_debug_exit(".ndo_get_iflink : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_change_proto_down(struct net_device *ndev, bool proto_down)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_change_proto_down : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_change_proto_down is under construction !!!\n");  
    sdummy_debug_exit(".ndo_change_proto_down : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static int sdummy_netdev_fill_metadata_dst(struct net_device *ndev, struct sk_buff *skb)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_fill_metadata_dst : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_fill_metadata_dst is under construction !!!\n");  
    sdummy_debug_exit(".ndo_fill_metadata_dst : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

static void sdummy_netdev_set_rx_headroom(struct net_device *ndev, int needed_headroom)
{
    sdummy_debug_enter(".ndo_set_rx_headroom : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_set_rx_headroom is under construction !!!\n");  
    sdummy_debug_exit(".ndo_set_rx_headroom : ndev(%s)\n", netdev_name_safe(ndev));
}

/* bpf : Berkeley Packet Filtering */
static int sdummy_netdev_bpf(struct net_device *ndev, struct netdev_bpf *bpf)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_bpf : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_bpf is under construction !!!\n");  
    sdummy_debug_exit(".ndo_bpf : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

/* eXpress Data Path */
static int sdummy_netdev_xdp_xmit(struct net_device *ndev, int n, struct xdp_frame **xdp, u32 flags)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_xdp_xmit : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_xdp_xmit is under construction !!!\n");  
    sdummy_debug_exit(".ndo_xdp_xmit : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;

}

static int sdummy_netdev_xsk_async_xmit(struct net_device *ndev, u32 queue_id)
{
    int ret = -ENOTSUPP;
    sdummy_debug_enter(".ndo_xsk_async_xmit : ndev(%s)\n", netdev_name_safe(ndev));
    sdummy_err(ndev, ".ndo_xsk_async_xmit is under construction !!!\n");  
    sdummy_debug_exit(".ndo_xsk_async_xmit : ndev(%s)\n", netdev_name_safe(ndev));
    return ret;
}

#endif


/* End of SOLID_DUMMY_NETDEV_Private_Functions */
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @addtogroup SOLID_DUMMY_NETDEV_Exported_Functions
  * @{
  */

void sdummy_set_netdev_ops(struct net_device *netdev)
{
	netdev->netdev_ops = &sdummy_netdev_ops;
}


/* End of SOLID_DUMMY_NETDEV_Exported_Functions */
/**
  * @}
  */

/* End of SOLID_DUMMY_NETDEV */
/**
  * @}
  */


