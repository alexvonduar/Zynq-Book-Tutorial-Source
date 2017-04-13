/*
 * File Name:         hdl_prj\ipcore\lms_pcore_v1_00_a\include\lms_pcore_addr.h
 * Description:       C Header File
 * Created:           2015-06-19 16:39:46
*/

#ifndef LMS_PCORE_H_
#define LMS_PCORE_H_

#define  IPCore_Reset_lms_pcore    0x0  //write 0x1 to bit 0 to reset IP core
#define  IPCore_Enable_lms_pcore   0x4  //enabled (by default) when bit 0 is 0x1
#define  IPCore_Strobe_lms_pcore   0x8  //write 1 to bit 0 after write all input data
#define  IPCore_Ready_lms_pcore    0xC  //wait until bit 0 is 1 before read output data
#define  x_k__Data_lms_pcore       0x100  //data register for port x(k)
#define  d_k__Data_lms_pcore       0x104  //data register for port d(k)
#define  e_k__Data_lms_pcore       0x108  //data register for port e(k)

#endif /* LMS_PCORE_H_ */
