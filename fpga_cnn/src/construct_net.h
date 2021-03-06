#ifndef _CONSTRUCT_NET_H_
#define _CONSTRUCT_NET_H_

//#include "/opt/Xilinx/Vivado/2018.1/include/mpfr.h"
//#include "/opt/Xilinx/Vivado/2018.1/include/gmp.h"
//#include "/opt/Xilinx/Vivado/2018.1/include/mpfr.h"
//#include "/opt/Xilinx/Vivado/2018.1/include/gmp.h"

#include "config.h"
#include <iostream>
#include <ap_fixed.h>
#include "acc_instance.h"
using namespace std;

void sub_net_0(
				Tparam param_port[1024],
//				ap_fixed<32,26> bias_in[4096],
				data_type_itf weight_in[131072],
				data_type_itf data_in_0[65536],
				data_type_itf data_out_0[32768],
				data_type_itf data_in_1[32768],
				data_type_itf data_out_1[4096],
				int select
   )
{

#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=select bundle=CRTL_BUS

#pragma HLS INTERFACE s_axilite port=param_port bundle=CRTL_BUS
#pragma HLS INTERFACE m_axi port=param_port offset=slave depth=1024 bundle=PARAM_IN
//#pragma HLS INTERFACE s_axilite port=bias_in bundle=CRTL_BUS
//#pragma HLS INTERFACE m_axi port=bias_in offset=slave depth=4096 		bundle=BIAS_IN
#pragma HLS INTERFACE s_axilite port=weight_in bundle=CRTL_BUS
#pragma HLS INTERFACE m_axi port=weight_in offset=slave depth=131072 	bundle=WEIGHT_IN

#pragma HLS INTERFACE s_axilite port=data_in_0 bundle=CRTL_BUS
#pragma HLS INTERFACE m_axi port=data_in_0 offset=slave depth=65536 	bundle=DATA_IN

#pragma HLS INTERFACE ap_memory port=data_out_0 latency=3
#pragma HLS INTERFACE ap_memory port=data_in_1 latency=3
#pragma HLS INTERFACE bram port=data_out_1


	int acc0_mem_inport_offset = 0;
	int acc0_mem_outport_offset = 0;
	int acc1_mem_inport_offset = 0;
	int acc1_mem_outport_offset = 0;


	if (select == 0)
	{
		acc0_mem_inport_offset = 0;
		acc0_mem_outport_offset = 0;
		acc1_mem_inport_offset = 16384;
		acc1_mem_outport_offset = 2048;
	}
	else
	{
		acc0_mem_inport_offset = 16384;
		acc0_mem_outport_offset = 16384;
		acc1_mem_inport_offset = 0;
		acc1_mem_outport_offset = 0;
	}

    conv_pool_acc_0(param_port,       bias_in,     weight_in, data_in_0 + acc0_mem_inport_offset, data_out_0 + acc0_mem_outport_offset);
    conv_pool_acc_1(param_port + 256, bias_in+256, weight_in, data_in_1 + acc1_mem_inport_offset, data_out_1 + acc1_mem_outport_offset);

};


void sub_net_1(
				Tparam param_port[1024],
				ap_fixed<32,26> bias_in[4096],
				data_type_itf weight_in[131072],
				data_type_itf data_in_0[65536],
				data_type_itf data_out_0[32768],
				data_type_itf data_in_1[32768],
				data_type_itf data_out_1[4096],
				int select
   )
{

#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=select bundle=CRTL_BUS

#pragma HLS INTERFACE s_axilite port=param_port bundle=CRTL_BUS
#pragma HLS INTERFACE m_axi port=param_port offset=slave depth=1024 bundle=PARAM_IN
//#pragma HLS INTERFACE s_axilite port=bias_in bundle=CRTL_BUS
//#pragma HLS INTERFACE m_axi port=bias_in offset=slave depth=4096 		bundle=BIAS_IN
#pragma HLS INTERFACE s_axilite port=weight_in bundle=CRTL_BUS
#pragma HLS INTERFACE m_axi port=weight_in offset=slave depth=131072 	bundle=WEIGHT_IN

#pragma HLS INTERFACE s_axilite port=data_in_0 bundle=CRTL_BUS
#pragma HLS INTERFACE m_axi port=data_in_0 offset=slave depth=65536 	bundle=DATA_IN

#pragma HLS INTERFACE ap_memory port=data_out_0 latency=3
#pragma HLS INTERFACE ap_memory port=data_in_1 latency=3
#pragma HLS INTERFACE bram port=data_out_1


	int acc0_mem_inport_offset = 0;
	int acc0_mem_outport_offset = 0;
	int acc1_mem_inport_offset = 0;
	int acc1_mem_outport_offset = 0;


	if (select == 0)
	{
		acc0_mem_inport_offset = 0;
		acc0_mem_outport_offset = 0;
		acc1_mem_inport_offset = 16384;
		acc1_mem_outport_offset = 2048;
	}
	else
	{
		acc0_mem_inport_offset = 16384;
		acc0_mem_outport_offset = 16384;
		acc1_mem_inport_offset = 0;
		acc1_mem_outport_offset = 0;
	}

    conv_pool_acc_0(param_port,       bias_in,     weight_in, data_in_0 + acc0_mem_inport_offset, data_out_0 + acc0_mem_outport_offset);
    conv_pool_acc_1(param_port + 256, bias_in+256, weight_in, data_in_1 + acc1_mem_inport_offset, data_out_1 + acc1_mem_outport_offset);

};



#endif
