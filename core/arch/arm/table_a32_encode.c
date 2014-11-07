/* **********************************************************
 * Copyright (c) 2014 Google, Inc.  All rights reserved.
 * **********************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Google, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL VMWARE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#include "../globals.h" /* need this to include decode.h (uint, etc.) */
#include "arch.h"    /* need this to include decode.h (byte, etc. */
#include "decode.h"
#include "decode_private.h"

const instr_info_t * const op_instr_A32[] = {
    /* OP_INVALID */   NULL,
    /* OP_UNDECODED */ NULL,
    /* OP_CONTD   */   NULL,
    /* OP_LABEL   */   NULL,

    /* OP_adc            */ &A32_pred_opc8[0x2a],
    /* OP_adcs           */ &A32_pred_opc8[0x2b],
    /* OP_add            */ &A32_pred_opc8[0x28],
    /* OP_adds           */ &A32_pred_opc8[0x29],
    /* OP_and            */ &A32_pred_opc8[0x20],
    /* OP_ands           */ &A32_pred_opc8[0x21],
    /* OP_asr            */ &A32_ext_opc4[4][0x04],
    /* OP_asrs           */ &A32_ext_opc4[5][0x04],
    /* OP_bfc            */ &A32_ext_bit4[8][0x01],
    /* OP_bfi            */ &A32_ext_RDPC[0][0x00],
    /* OP_bic            */ &A32_pred_opc8[0x3c],
    /* OP_bics           */ &A32_pred_opc8[0x3d],
    /* OP_bkpt           */ &A32_ext_opc4[1][0x07],
    /* OP_b              */ &A32_pred_opc8[0xa0],
    /* OP_bl             */ &A32_pred_opc8[0xb0],
    /* OP_blx            */ NULL /* FIXME: add non-pred instrs */,
    /* OP_blx_ind        */ &A32_ext_opc4[1][0x03],
    /* OP_bx             */ &A32_ext_opc4[1][0x01],
    /* OP_bxj            */ &A32_ext_opc4[1][0x02],
    /* OP_cdp            */ &A32_ext_bit4[9][0x00],
    /* OP_clz            */ &A32_ext_opc4[3][0x01],
    /* OP_cmn            */ &A32_pred_opc8[0x37],
    /* OP_cmp            */ &A32_pred_opc8[0x35],
    /* OP_crc32          */ &A32_ext_bit9[1][0x00],
    /* OP_crc32c         */ &A32_ext_bit9[1][0x01],
    /* OP_dbg            */ &A32_ext_opc4[6][0x0f],
    /* OP_eor            */ &A32_pred_opc8[0x22],
    /* OP_eors           */ &A32_pred_opc8[0x23],
    /* OP_eret           */ &A32_ext_opc4[3][0x06],
    /* OP_hlt            */ &A32_ext_opc4[0][0x07],
    /* OP_hvc            */ &A32_ext_opc4[2][0x07],
    /* OP_lda            */ &A32_ext_bits8[1][0x00],
    /* OP_ldab           */ &A32_ext_bits8[5][0x00],
    /* OP_ldaex          */ &A32_ext_bits8[1][0x02],
    /* OP_ldaexb         */ &A32_ext_bits8[5][0x02],
    /* OP_ldaexd         */ &A32_ext_bits8[3][0x02],
    /* OP_ldaexh         */ &A32_ext_bits8[7][0x02],
    /* OP_ldah           */ &A32_ext_bits8[7][0x00],
    /* OP_ldc            */ &A32_ext_fp[23][0x02],
    /* OP_ldcl           */ &A32_ext_fp[27][0x02],
    /* OP_ldm            */ &A32_pred_opc8[0x9d],
    /* OP_ldm_priv       */ &A32_pred_opc8[0x8d],
    /* OP_ldmda          */ &A32_pred_opc8[0x81],
    /* OP_ldmda_priv     */ &A32_pred_opc8[0x85],
    /* OP_ldmdb          */ &A32_pred_opc8[0x91],
    /* OP_ldmdb_priv     */ &A32_pred_opc8[0x95],
    /* OP_ldmia_priv     */ &A32_pred_opc8[0x8f],
    /* OP_ldmib          */ &A32_pred_opc8[0x99],
    /* OP_ldr            */ &A32_pred_opc8[0x59],
    /* OP_ldrb           */ &A32_pred_opc8[0x5d],
    /* OP_ldrbt          */ &A32_pred_opc8[0x4f],
    /* OP_ldrd           */ &A32_ext_opc4x[22][0x04],
    /* OP_ldrex          */ &A32_ext_bits8[1][0x03],
    /* OP_ldrexd         */ &A32_ext_bits8[3][0x03],
    /* OP_ldrexh         */ &A32_ext_bits8[7][0x03],
    /* OP_ldrh           */ &A32_ext_opc4x[23][0x03],
    /* OP_ldrht          */ &A32_ext_opc4x[15][0x03],
    /* OP_ldrsb          */ &A32_ext_opc4x[23][0x04],
    /* OP_ldrsbt         */ &A32_ext_opc4x[15][0x04],
    /* OP_ldrsh          */ &A32_ext_opc4x[23][0x05],
    /* OP_ldrsht         */ &A32_ext_opc4x[15][0x05],
    /* OP_ldrt           */ &A32_pred_opc8[0x4b],
    /* OP_lsl            */ &A32_ext_opc4[4][0x08],
    /* OP_lsls           */ &A32_ext_opc4[5][0x08],
    /* OP_lsr            */ &A32_ext_opc4[4][0x02],
    /* OP_lsrs           */ &A32_ext_opc4[5][0x02],
    /* OP_mcr            */ &A32_ext_bit4[9][0x01],
    /* OP_mcrr           */ &A32_ext_fp[2][0x02],
    /* OP_mla            */ &A32_ext_opc4x[2][0x02],
    /* OP_mlas           */ &A32_ext_opc4x[3][0x02],
    /* OP_mls            */ &A32_ext_opc4x[6][0x02],
    /* OP_mov            */ &A32_pred_opc8[0x3a],
    /* OP_movs           */ &A32_pred_opc8[0x3b],
    /* OP_movt           */ &A32_pred_opc8[0x34],
    /* OP_movw           */ &A32_pred_opc8[0x30],
    /* OP_mrc            */ &A32_ext_bit4[10][0x01],
    /* OP_mrrc           */ &A32_ext_fp[3][0x02],
    /* OP_mrs            */ &A32_ext_bit9[0][0x01],
    /* OP_msr            */ &A32_pred_opc8[0x36],
    /* OP_mul            */ &A32_ext_opc4x[0][0x02],
    /* OP_muls           */ &A32_ext_opc4x[1][0x02],
    /* OP_mvn            */ &A32_pred_opc8[0x3e],
    /* OP_mvns           */ &A32_pred_opc8[0x3f],
    /* OP_nop            */ &A32_ext_bits0[0][0x00],
    /* OP_orr            */ &A32_pred_opc8[0x38],
    /* OP_orrs           */ &A32_pred_opc8[0x39],
    /* OP_pkhbt          */ &A32_ext_opc4y[6][0x01],
    /* OP_qadd           */ &A32_ext_opc4[0][0x05],
    /* OP_qadd16         */ &A32_ext_opc4y[1][0x01],
    /* OP_qadd8          */ &A32_ext_opc4y[1][0x05],
    /* OP_qasx           */ &A32_ext_opc4y[1][0x02],
    /* OP_qdadd          */ &A32_ext_opc4[2][0x05],
    /* OP_qdsub          */ &A32_ext_opc4[3][0x05],
    /* OP_qsax           */ &A32_ext_opc4y[1][0x03],
    /* OP_qsub           */ &A32_ext_opc4[1][0x05],
    /* OP_qsub16         */ &A32_ext_opc4y[1][0x04],
    /* OP_qsub8          */ &A32_ext_opc4y[1][0x08],
    /* OP_rbit           */ &A32_ext_opc4y[11][0x02],
    /* OP_rev            */ &A32_ext_opc4y[8][0x02],
    /* OP_rev16          */ &A32_ext_opc4y[8][0x06],
    /* OP_revsh          */ &A32_ext_opc4y[11][0x06],
    /* OP_ror            */ &A32_ext_opc4[4][0x0e],
    /* OP_rors           */ &A32_ext_opc4[5][0x0e],
    /* OP_rrx            */ &A32_ext_imm5[1][0x00],
    /* OP_rrxs           */ &A32_ext_imm5[3][0x00],
    /* OP_rsb            */ &A32_pred_opc8[0x26],
    /* OP_rsbs           */ &A32_pred_opc8[0x27],
    /* OP_rsc            */ &A32_pred_opc8[0x2e],
    /* OP_rscs           */ &A32_pred_opc8[0x2f],
    /* OP_sadd16         */ &A32_ext_opc4y[0][0x01],
    /* OP_sadd8          */ &A32_ext_opc4y[0][0x05],
    /* OP_sasx           */ &A32_ext_opc4y[0][0x02],
    /* OP_sbc            */ &A32_pred_opc8[0x2c],
    /* OP_sbcs           */ &A32_pred_opc8[0x2d],
    /* OP_sbfx           */ &A32_ext_bit4[3][0x01],
    /* OP_sdiv           */ &A32_ext_bit4[0][0x01],
    /* OP_sel            */ &A32_ext_opc4y[6][0x06],
    /* OP_sev            */ &A32_ext_bits0[0][0x04],
    /* OP_sevl           */ &A32_ext_bits0[0][0x05],
    /* OP_shadd16        */ &A32_ext_opc4y[2][0x01],
    /* OP_shadd8         */ &A32_ext_opc4y[2][0x05],
    /* OP_shasx          */ &A32_ext_opc4y[2][0x02],
    /* OP_shsax          */ &A32_ext_opc4y[2][0x03],
    /* OP_shsub16        */ &A32_ext_opc4y[2][0x04],
    /* OP_shsub8         */ &A32_ext_opc4y[2][0x08],
    /* OP_smlabb         */ &A32_ext_opc4[0][0x08],
    /* OP_smlabt         */ &A32_ext_opc4[0][0x0a],
    /* OP_smlad          */ &A32_ext_opc4y[12][0x01],
    /* OP_smladx         */ &A32_ext_opc4y[12][0x02],
    /* OP_smlal          */ &A32_ext_opc4x[14][0x02],
    /* OP_smlalbb        */ &A32_ext_opc4[2][0x08],
    /* OP_smlalbt        */ &A32_ext_opc4[2][0x0a],
    /* OP_smlald         */ &A32_ext_opc4y[13][0x01],
    /* OP_smlaldx        */ &A32_ext_opc4y[13][0x02],
    /* OP_smlals         */ &A32_ext_opc4x[15][0x02],
    /* OP_smlaltb        */ &A32_ext_opc4[2][0x0c],
    /* OP_smlaltt        */ &A32_ext_opc4[2][0x0e],
    /* OP_smlatb         */ &A32_ext_opc4[0][0x0c],
    /* OP_smlatt         */ &A32_ext_opc4[0][0x0e],
    /* OP_smlawb         */ &A32_ext_opc4[1][0x08],
    /* OP_smlawt         */ &A32_ext_opc4[1][0x0c],
    /* OP_smlsd          */ &A32_ext_opc4y[12][0x03],
    /* OP_smlsdx         */ &A32_ext_opc4y[12][0x04],
    /* OP_smlsld         */ &A32_ext_opc4y[13][0x03],
    /* OP_smlsldx        */ &A32_ext_opc4y[13][0x04],
    /* OP_smmla          */ &A32_ext_opc4y[14][0x01],
    /* OP_smmls          */ &A32_ext_opc4y[14][0x07],
    /* OP_smmlsr         */ &A32_ext_opc4y[14][0x08],
    /* OP_smulbb         */ &A32_ext_opc4[3][0x08],
    /* OP_smulbt         */ &A32_ext_opc4[3][0x0a],
    /* OP_smull          */ &A32_ext_opc4x[12][0x02],
    /* OP_smulls         */ &A32_ext_opc4x[13][0x02],
    /* OP_smultb         */ &A32_ext_opc4[3][0x0c],
    /* OP_smultt         */ &A32_ext_opc4[3][0x0e],
    /* OP_smulwb         */ &A32_ext_opc4[1][0x0a],
    /* OP_smulwt         */ &A32_ext_opc4[1][0x0e],
    /* OP_ssat           */ &A32_ext_opc4y[7][0x01],
    /* OP_ssat16         */ &A32_ext_opc4y[7][0x02],
    /* OP_ssax           */ &A32_ext_opc4y[0][0x03],
    /* OP_ssub16         */ &A32_ext_opc4y[0][0x04],
    /* OP_ssub8          */ &A32_ext_opc4y[0][0x08],
    /* OP_stc            */ &A32_ext_fp[22][0x02],
    /* OP_stcl           */ &A32_ext_fp[26][0x02],
    /* OP_stl            */ &A32_ext_bits8[0][0x00],
    /* OP_stlb           */ &A32_ext_bits8[4][0x00],
    /* OP_stlex          */ &A32_ext_bits8[0][0x02],
    /* OP_stlexb         */ &A32_ext_bits8[4][0x02],
    /* OP_stlexd         */ &A32_ext_bits8[2][0x02],
    /* OP_stlexh         */ &A32_ext_bits8[6][0x02],
    /* OP_stlh           */ &A32_ext_bits8[6][0x00],
    /* OP_stm            */ &A32_pred_opc8[0x9c],
    /* OP_stm_priv       */ &A32_pred_opc8[0x8c],
    /* OP_stmda          */ &A32_pred_opc8[0x80],
    /* OP_stmda_priv     */ &A32_pred_opc8[0x84],
    /* OP_stmdb          */ &A32_pred_opc8[0x90],
    /* OP_stmdb_priv     */ &A32_pred_opc8[0x94],
    /* OP_stmib          */ &A32_pred_opc8[0x98],
    /* OP_str            */ &A32_pred_opc8[0x58],
    /* OP_strb           */ &A32_pred_opc8[0x5c],
    /* OP_strbt          */ &A32_pred_opc8[0x4e],
    /* OP_strd           */ &A32_ext_opc4x[22][0x05],
    /* OP_strex          */ &A32_ext_bits8[0][0x03],
    /* OP_strexb         */ &A32_ext_bits8[4][0x03],
    /* OP_strexd         */ &A32_ext_bits8[2][0x03],
    /* OP_strexh         */ &A32_ext_bits8[6][0x03],
    /* OP_strh           */ &A32_ext_opc4x[22][0x03],
    /* OP_strht          */ &A32_ext_opc4x[14][0x03],
    /* OP_strt           */ &A32_pred_opc8[0x4a],
    /* OP_sub            */ &A32_pred_opc8[0x24],
    /* OP_subs           */ &A32_pred_opc8[0x25],
    /* OP_svc            */ &A32_pred_opc8[0xf0],
    /* OP_sxtab          */ &A32_ext_opc4y[7][0x04],
    /* OP_sxtab16        */ &A32_ext_opc4y[6][0x04],
    /* OP_sxtah          */ &A32_ext_opc4y[8][0x04],
    /* OP_teq            */ &A32_pred_opc8[0x33],
    /* OP_tst            */ &A32_pred_opc8[0x31],
    /* OP_uadd16         */ &A32_ext_opc4y[3][0x01],
    /* OP_uadd8          */ &A32_ext_opc4y[3][0x05],
    /* OP_uasx           */ &A32_ext_opc4y[3][0x02],
    /* OP_ubfx           */ &A32_ext_bit4[5][0x01],
    /* OP_udiv           */ &A32_ext_bit4[1][0x01],
    /* OP_uhadd16        */ &A32_ext_opc4y[5][0x01],
    /* OP_uhadd8         */ &A32_ext_opc4y[5][0x05],
    /* OP_uhasx          */ &A32_ext_opc4y[5][0x02],
    /* OP_uhsax          */ &A32_ext_opc4y[5][0x03],
    /* OP_uhsub16        */ &A32_ext_opc4y[5][0x04],
    /* OP_uhsub8         */ &A32_ext_opc4y[5][0x08],
    /* OP_umaal          */ &A32_ext_opc4x[4][0x02],
    /* OP_umlal          */ &A32_ext_opc4x[10][0x02],
    /* OP_umlals         */ &A32_ext_opc4x[11][0x02],
    /* OP_umull          */ &A32_ext_opc4x[8][0x02],
    /* OP_umulls         */ &A32_ext_opc4x[9][0x02],
    /* OP_uqadd16        */ &A32_ext_opc4y[4][0x01],
    /* OP_uqadd8         */ &A32_ext_opc4y[4][0x05],
    /* OP_uqasx          */ &A32_ext_opc4y[4][0x02],
    /* OP_uqsax          */ &A32_ext_opc4y[4][0x03],
    /* OP_uqsub16        */ &A32_ext_opc4y[4][0x04],
    /* OP_uqsub8         */ &A32_ext_opc4y[4][0x08],
    /* OP_usada8         */ &A32_ext_bit4[2][0x01],
    /* OP_usat           */ &A32_ext_opc4y[10][0x01],
    /* OP_usat16         */ &A32_ext_opc4y[10][0x02],
    /* OP_usax           */ &A32_ext_opc4y[3][0x03],
    /* OP_usub16         */ &A32_ext_opc4y[3][0x04],
    /* OP_usub8          */ &A32_ext_opc4y[3][0x08],
    /* OP_uxtab          */ &A32_ext_opc4y[10][0x04],
    /* OP_uxtab16        */ &A32_ext_opc4y[9][0x04],
    /* OP_uxtah          */ &A32_ext_opc4y[11][0x04],
    /* OP_vabs_f32       */ &A32_ext_bits16[1][0x00],
    /* OP_vabs_f64       */ &A32_ext_bits16[3][0x00],
    /* OP_vadd_f32       */ &A32_ext_opc4fpA[3][0x00],
    /* OP_vadd_f64       */ &A32_ext_opc4fpB[3][0x00],
    /* OP_vcmpe_f32      */ &A32_ext_bits16[1][0x05],
    /* OP_vcmpe_f64      */ &A32_ext_bits16[3][0x05],
    /* OP_vcmp_f32       */ &A32_ext_opc4[7][0x08],
    /* OP_vcmp_f64       */ &A32_ext_opc4[8][0x08],
    /* OP_vcvt_f32_f64   */ &A32_ext_bits16[3][0x07],
    /* OP_vcvt_f32_s16   */ &A32_ext_bits16[0][0x0a],
    /* OP_vcvt_f32_s32   */ &A32_ext_bits16[1][0x0a],
    /* OP_vcvt_f32_u16   */ &A32_ext_bits16[0][0x0b],
    /* OP_vcvt_f32_u32   */ &A32_ext_bits16[1][0x0b],
    /* OP_vcvt_f64_f32   */ &A32_ext_bits16[1][0x07],
    /* OP_vcvt_f64_s16   */ &A32_ext_bits16[2][0x0a],
    /* OP_vcvt_f64_s32   */ &A32_ext_bits16[3][0x0a],
    /* OP_vcvt_f64_u16   */ &A32_ext_bits16[2][0x0b],
    /* OP_vcvt_f64_u32   */ &A32_ext_bits16[3][0x0b],
    /* OP_vcvtr_s32_f32  */ &A32_ext_bits16[0][0x0d],
    /* OP_vcvtr_s32_f64  */ &A32_ext_bits16[2][0x0d],
    /* OP_vcvtr_u32_f32  */ &A32_ext_bits16[0][0x0c],
    /* OP_vcvtr_u32_f64  */ &A32_ext_bits16[2][0x0c],
    /* OP_vcvt_s16_f32   */ &A32_ext_bits16[0][0x0e],
    /* OP_vcvt_s16_f64   */ &A32_ext_bits16[2][0x0e],
    /* OP_vcvt_s32_f32   */ &A32_ext_bits16[1][0x0e],
    /* OP_vcvt_s32_f64   */ &A32_ext_bits16[3][0x0e],
    /* OP_vcvt_u16_f32   */ &A32_ext_bits16[0][0x0f],
    /* OP_vcvt_u16_f64   */ &A32_ext_bits16[2][0x0f],
    /* OP_vcvt_u32_f32   */ &A32_ext_bits16[1][0x0f],
    /* OP_vcvt_u32_f64   */ &A32_ext_bits16[3][0x0f],
    /* OP_vdiv_f32       */ &A32_ext_opc4fpA[8][0x00],
    /* OP_vdiv_f64       */ &A32_ext_opc4fpB[8][0x00],
    /* OP_vdup_16        */ &A32_ext_opc4fpB[8][0x03],
    /* OP_vdup_32        */ &A32_ext_opc4fpB[8][0x01],
    /* OP_vdup_8         */ &A32_ext_opc4fpB[11][0x01],
    /* OP_vfma_f32       */ &A32_ext_opc4fpA[10][0x00],
    /* OP_vfma_f64       */ &A32_ext_opc4fpB[10][0x00],
    /* OP_vfms_f32       */ &A32_ext_opc4fpA[10][0x02],
    /* OP_vfms_f64       */ &A32_ext_opc4fpB[10][0x04],
    /* OP_vfnma_f32      */ &A32_ext_opc4fpA[9][0x00],
    /* OP_vfnma_f64      */ &A32_ext_opc4fpB[9][0x00],
    /* OP_vfnms_f32      */ &A32_ext_opc4fpA[9][0x02],
    /* OP_vfnms_f64      */ &A32_ext_opc4fpB[9][0x04],
    /* OP_vldmdb         */ &A32_ext_fp[17][0x00],
    /* OP_vldmia         */ &A32_ext_fp[9][0x00],
    /* OP_vldr           */ &A32_ext_fp[15][0x00],
    /* OP_vmla_f32       */ &A32_ext_opc4fpA[0][0x00],
    /* OP_vmla_f64       */ &A32_ext_opc4fpB[0][0x00],
    /* OP_vmls_f32       */ &A32_ext_opc4fpA[0][0x02],
    /* OP_vmls_f64       */ &A32_ext_opc4fpB[0][0x04],
    /* OP_vmov           */ &A32_ext_fp[2][0x00],
    /* OP_vmov_16        */ &A32_ext_opc4fpB[0][0x03],
    /* OP_vmov_32        */ &A32_ext_opc4fpB[0][0x01],
    /* OP_vmov_8         */ &A32_ext_opc4fpB[4][0x01],
    /* OP_vmov_f32       */ &A32_ext_opc4[7][0x00],
    /* OP_vmov_f64       */ &A32_ext_opc4[8][0x00],
    /* OP_vmov_s16       */ &A32_ext_opc4fpB[1][0x03],
    /* OP_vmov_s8        */ &A32_ext_opc4fpB[5][0x01],
    /* OP_vmov_u16       */ &A32_ext_opc4[8][0x03],
    /* OP_vmov_u8        */ &A32_ext_opc4[10][0x01],
    /* OP_vmrs           */ &A32_ext_RBPC[0][0x00],
    /* OP_vmrs_apsr      */ &A32_ext_RBPC[0][0x01],
    /* OP_vmsr           */ &A32_ext_opc4fpA[13][0x01],
    /* OP_vmul_f32       */ &A32_ext_opc4fpA[2][0x00],
    /* OP_vmul_f64       */ &A32_ext_opc4fpB[2][0x00],
    /* OP_vneg_f32       */ &A32_ext_bits16[0][0x01],
    /* OP_vneg_f64       */ &A32_ext_bits16[2][0x01],
    /* OP_vnmla_f32      */ &A32_ext_opc4fpA[1][0x02],
    /* OP_vnmla_f64      */ &A32_ext_opc4fpB[1][0x04],
    /* OP_vnmls_f32      */ &A32_ext_opc4fpA[1][0x00],
    /* OP_vnmls_f64      */ &A32_ext_opc4fpB[1][0x00],
    /* OP_vnmul_f32      */ &A32_ext_opc4fpA[2][0x02],
    /* OP_vnmul_f64      */ &A32_ext_opc4fpB[2][0x04],
    /* OP_vrintr_f32     */ &A32_ext_bits16[0][0x06],
    /* OP_vrintr_f64     */ &A32_ext_bits16[2][0x06],
    /* OP_vrintx_f32     */ &A32_ext_bits16[0][0x07],
    /* OP_vrintx_f64     */ &A32_ext_bits16[2][0x07],
    /* OP_vrintz_f32     */ &A32_ext_bits16[1][0x06],
    /* OP_vrintz_f64     */ &A32_ext_bits16[3][0x06],
    /* OP_vsqrt_f32      */ &A32_ext_bits16[1][0x01],
    /* OP_vsqrt_f64      */ &A32_ext_bits16[3][0x01],
    /* OP_vstmdb         */ &A32_ext_fp[16][0x00],
    /* OP_vstmia         */ &A32_ext_fp[8][0x00],
    /* OP_vstr           */ &A32_ext_fp[14][0x00],
    /* OP_vsub_f32       */ &A32_ext_opc4fpA[3][0x02],
    /* OP_vsub_f64       */ &A32_ext_opc4fpB[3][0x04],
    /* OP_wfe            */ &A32_ext_bits0[0][0x02],
    /* OP_wfi            */ &A32_ext_bits0[0][0x03],
    /* OP_yield          */ &A32_ext_bits0[0][0x01],

};
