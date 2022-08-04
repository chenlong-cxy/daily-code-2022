struct sk_buff {
#ifdef __GENKSYMS__
	/* These two members must be first. */
	struct sk_buff          *next;
	struct sk_buff          *prev;
	ktime_t         tstamp;
#else
	union {
		struct {
			/* These two members must be first. */
			struct sk_buff          *next;
			struct sk_buff          *prev;

			union {
				ktime_t         tstamp;
				struct skb_mstamp skb_mstamp;
				__RH_KABI_CHECK_SIZE_ALIGN(ktime_t a,
				struct skb_mstamp b);
			};
		};
		struct rb_node  rbnode; /* used in netem, ip4 defrag, and tcp stack */
	};
#endif
	struct sock             *sk;
	struct net_device       *dev;

	/*
	* This is the control buffer. It is free to use for every
	* layer. Please put your private variables there. If you
	* want to keep them across layers you have to do a skb_clone()
	* first. This is owned by whoever has the skb queued ATM.
	*/
	char                    cb[48] __aligned(8);

	unsigned long           _skb_refdst;
#ifdef CONFIG_XFRM
	struct  sec_path        *sp;
#endif
	unsigned int            len,
		data_len;
	__u16                   mac_len,
		hdr_len;
	union {
		__wsum          csum;
		struct {
			__u16   csum_start;
			__u16   csum_offset;
		};
	};
	__u32                   priority;
	kmemcheck_bitfield_begin(flags1);
	__u8                    RH_KABI_RENAME(local_df, ignore_df) :1,
	cloned : 1,
		 ip_summed : 2,
				 nohdr : 1,
					 nfctinfo : 3;
	__u8                    pkt_type : 3,
	fclone : 2,
		 ipvs_property : 1,
					 peeked : 1,
						  nf_trace : 1;
	kmemcheck_bitfield_end(flags1);
	__be16                  protocol;

	void(*destructor)(struct sk_buff *skb);
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
	struct nf_conntrack     *nfct;
#endif
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
	struct nf_bridge_info   *nf_bridge;
#endif

	/* fields enclosed in headers_start/headers_end are copied
	* using a single memcpy() in __copy_skb_header()
	*/
	/* private: */
	RH_KABI_EXTEND(__u32    headers_start[0])
		/* public: */

		int                     skb_iif;

	RH_KABI_REPLACE(__u32   rxhash,
		__u32   hash)

		__be16                  vlan_proto;
	__u16                   vlan_tci;

#ifdef CONFIG_NET_SCHED
	__u16                   tc_index;       /* traffic control index */
#ifdef CONFIG_NET_CLS_ACT
	__u16                   tc_verd;        /* traffic control verdict */
#endif
#endif

	__u16                   queue_mapping;
	kmemcheck_bitfield_begin(flags2);
#ifdef CONFIG_IPV6_NDISC_NODETYPE
	__u8                    ndisc_nodetype : 2;
#endif
	__u8                    pfmemalloc : 1;
	__u8                    ooo_okay : 1;
	__u8                    RH_KABI_RENAME(l4_rxhash, l4_hash) :1;
	__u8                    wifi_acked_valid : 1;
	__u8                    wifi_acked : 1;
	__u8                    no_fcs : 1;
	__u8                    head_frag : 1;
	/* Indicates the inner headers are valid in the skbuff. */
	__u8                    encapsulation : 1;
	RH_KABI_EXTEND(__u8                     encap_hdr_csum : 1)
		RH_KABI_EXTEND(__u8                     csum_valid : 1)
		RH_KABI_EXTEND(__u8                     csum_complete_sw : 1)
		RH_KABI_EXTEND(__u8                     xmit_more : 1)
		RH_KABI_EXTEND(__u8                     inner_protocol_type : 1)
		RH_KABI_EXTEND(__u8                     remcsum_offload : 1)
		/* 0/2 bit hole (depending on ndisc_nodetype presence) */
		kmemcheck_bitfield_end(flags2);

#if defined CONFIG_NET_DMA_RH_KABI || defined CONFIG_NET_RX_BUSY_POLL || defined CONFIG_XPS
	union {
		unsigned int    napi_id;
		RH_KABI_EXTEND(unsigned int     sender_cpu)
			RH_KABI_DEPRECATE(dma_cookie_t, dma_cookie)
	};
#endif
#ifdef CONFIG_NETWORK_SECMARK
	__u32                   secmark;
#endif
	union {
		__u32           mark;
		__u32           dropcount;
		__u32           reserved_tailroom;
	};

#ifdef __GENKSYMS__
	__be16                  inner_protocol;
#else
	union {
		__be16          inner_protocol;
		__u8            inner_ipproto;
	};
#endif

	__u16                   inner_transport_header;
	__u16                   inner_network_header;
	__u16                   inner_mac_header;
	__u16                   transport_header;
	__u16                   network_header;
	__u16                   mac_header;

	RH_KABI_EXTEND(kmemcheck_bitfield_begin(flags3))
		RH_KABI_EXTEND(__u8     csum_level : 2)
		RH_KABI_EXTEND(__u8     rh_csum_pad : 1)
		RH_KABI_EXTEND(__u8     rh_csum_bad_unused : 1) /* one bit hole */
		RH_KABI_EXTEND(__u8     offload_fwd_mark : 1)
		RH_KABI_EXTEND(__u8     sw_hash : 1)
		RH_KABI_EXTEND(__u8     csum_not_inet : 1)
		RH_KABI_EXTEND(__u8     dst_pending_confirm : 1)
		RH_KABI_EXTEND(__u8     offload_mr_fwd_mark : 1)
		/* 7 bit hole */
		RH_KABI_EXTEND(kmemcheck_bitfield_end(flags3))

		/* private: */
		RH_KABI_EXTEND(__u32    headers_end[0])
		/* public: */

		/* RHEL SPECIFIC
		*
		* The following padding has been inserted before ABI freeze to
		* allow extending the structure while preserve ABI. Feel free
		* to replace reserved slots with required structure field
		* additions of your backport, eventually moving the replaced slot
		* before headers_end, if it need to be copied by __copy_skb_header()
		*/
		u32                     rh_reserved1;
	u32                     rh_reserved2;
	u32                     rh_reserved3;
	u32                     rh_reserved4;
	union {
		unsigned int    napi_id;
		RH_KABI_EXTEND(unsigned int     sender_cpu)
			RH_KABI_DEPRECATE(dma_cookie_t, dma_cookie)
	};
#endif
#ifdef CONFIG_NETWORK_SECMARK
	__u32                   secmark;
#endif
	union {
		__u32           mark;
		__u32           dropcount;
		__u32           reserved_tailroom;
	};

#ifdef __GENKSYMS__
	__be16                  inner_protocol;
#else
	kmemcheck_bitfield_begin(flags1);
	__u8                    RH_KABI_RENAME(local_df, ignore_df) :1,
	cloned : 1,
		 ip_summed : 2,
				 nohdr : 1,
					 nfctinfo : 3;
	__u8                    pkt_type : 3,
	fclone : 2,
		 ipvs_property : 1,
					 peeked : 1,
						  nf_trace : 1;
	kmemcheck_bitfield_end(flags1);
	__be16                  protocol;

	void(*destructor)(struct sk_buff *skb);
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
	struct nf_conntrack     *nfct;
#endif
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
	struct nf_bridge_info   *nf_bridge;
#endif

	/* fields enclosed in headers_start/headers_end are copied
	* using a single memcpy() in __copy_skb_header()
	*/
	/* private: */
	/* private: */
	RH_KABI_EXTEND(__u32    headers_start[0])
		/* public: */

		int                     skb_iif;

	RH_KABI_REPLACE(__u32   rxhash,
		__u32   hash)


		__be16                  vlan_proto;
	__u16                   vlan_tci;

#ifdef CONFIG_NET_SCHED
	__u16                   tc_index;       /* traffic control index */
#ifdef CONFIG_NET_CLS_ACT
	__u16                   tc_verd;        /* traffic control verdict */
#endif
#endif

	__u16                   queue_mapping;
	kmemcheck_bitfield_begin(flags2);
#ifdef CONFIG_IPV6_NDISC_NODETYPE
	__u8                    ndisc_nodetype : 2;
#endif
	__u8                    pfmemalloc : 1;
	__u8                    ooo_okay : 1;
	__u8                    RH_KABI_RENAME(l4_rxhash, l4_hash) :1;
	__u8                    wifi_acked_valid : 1;
	__u8                    wifi_acked : 1;
	__u8                    no_fcs : 1;
	__u8                    head_frag : 1;
	/* Indicates the inner headers are valid in the skbuff. */
	__u8                    encapsulation : 1;
	RH_KABI_EXTEND(__u8                     encap_hdr_csum : 1)
		RH_KABI_EXTEND(__u8                     csum_valid : 1)
		RH_KABI_EXTEND(__u8                     csum_valid : 1)
		RH_KABI_EXTEND(__u8                     csum_complete_sw : 1)
		RH_KABI_EXTEND(__u8                     xmit_more : 1)
		RH_KABI_EXTEND(__u8                     inner_protocol_type : 1)
		RH_KABI_EXTEND(__u8                     remcsum_offload : 1)
		/* 0/2 bit hole (depending on ndisc_nodetype presence) */
		kmemcheck_bitfield_end(flags2);

#if defined CONFIG_NET_DMA_RH_KABI || defined CONFIG_NET_RX_BUSY_POLL || defined CONFIG_XPS
	union {
		unsigned int    napi_id;
		RH_KABI_EXTEND(unsigned int     sender_cpu)
			RH_KABI_DEPRECATE(dma_cookie_t, dma_cookie)
	};
#endif
#ifdef CONFIG_NETWORK_SECMARK
	__u32                   secmark;
#endif
	union {
		__u32           mark;
		__u32           dropcount;
		__u32           reserved_tailroom;
	};

#ifdef __GENKSYMS__
	__be16                  inner_protocol;
#else
	union {
		__be16          inner_protocol;
		__u8            inner_ipproto;
	};
#endif

	__u16                   inner_transport_header;
	__u16                   inner_network_header;
	__u16                   inner_mac_header;
	__u16                   transport_header;
	__u16                   network_header;
	__u16                   mac_header;

	RH_KABI_EXTEND(kmemcheck_bitfield_begin(flags3))
		RH_KABI_EXTEND(__u8     csum_level : 2)
		RH_KABI_EXTEND(__u8     rh_csum_pad : 1)
		RH_KABI_EXTEND(__u8     rh_csum_bad_unused : 1) /* one bit hole */
		RH_KABI_EXTEND(__u8     offload_fwd_mark : 1)
		RH_KABI_EXTEND(__u8     sw_hash : 1)
		RH_KABI_EXTEND(__u8     csum_not_inet : 1)
		RH_KABI_EXTEND(__u8     dst_pending_confirm : 1)
		RH_KABI_EXTEND(__u8     offload_mr_fwd_mark : 1)
		/* 7 bit hole */
		RH_KABI_EXTEND(kmemcheck_bitfield_end(flags3))

		/* private: */
		RH_KABI_EXTEND(__u32    headers_end[0])
		/* public: */

		/* RHEL SPECIFIC
		*
		* The following padding has been inserted before ABI freeze to
		* allow extending the structure while preserve ABI. Feel free
		* to replace reserved slots with required structure field
		* additions of your backport, eventually moving the replaced slot
		* before headers_end, if it need to be copied by __copy_skb_header()
		*/
		u32                     rh_reserved1;
	u32                     rh_reserved2;
	u32                     rh_reserved3;
	u32                     rh_reserved4;

	/* These elements must be at the end, see alloc_skb() for details.  */
	sk_buff_data_t          tail;
	sk_buff_data_t          end;
	unsigned char           *head,
		*data;
	unsigned int            truesize;
	atomic_t                users;
};
