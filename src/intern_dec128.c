#include <stdio.h>
#include <inttypes.h> // For PRIu64 and such
#include "intern/dec128.h"
#include "intern/impl_dec.h"
#include "intern/impl_dec_compare.h"
#include "intern/impl_dec_atan.h"
#include "intern/impl_dec_sqrt.h"
#include "intern/impl_dec_sincos.h"
#include "intern/impl_dec_asin.h"
#include "intern/impl_dec_acos.h"
#include "intern/impl_dec_log10.h"
#include "intern/impl_dec_exp10m1.h"

// 31415926535897932384626433832795028842e-37 (38 digits)
__IMPL_CONST_INTERN_DEC(dec128, pi, 0, 
                        ((__uint128_t)3141592653589793238ULL * 10000000000000000000ULL)
                        + 4626433832795028842ULL,
                        -I_dec128_MAX_DIGITS+1, DEC_NORMAL);
// 33219280948873623478703194294893901759e-37
__IMPL_CONST_INTERN_DEC(dec128, log2_10, 0, 
                        ((__uint128_t)3321928094887362347ULL * 10000000000000000000ULL)
                        + 8703194294893901759ULL,
                        -I_dec128_MAX_DIGITS+1, DEC_NORMAL);

__IMPL_CONST_INTERN_DEC(dec128, log_10, 0,
                        ((__uint128_t)2302585092994045684ULL * 10000000000000000000ULL)
                        +  179914546843642076ULL,
                        -I_dec128_MAX_DIGITS+1, DEC_NORMAL);

__IMPL_CONST_INTERN_DEC(dec128, log10_e, 0,
                        ((__uint128_t)4342944819032518276ULL * 10000000000000000000ULL)
                        +  5112891891660508229ULL,
                        -I_dec128_MAX_DIGITS, DEC_NORMAL);

__IMPL_CONST_INTERN_DEC(dec128, epsilon, 0, (__uint128_t)1ULL, -I_dec128_MAX_DIGITS, DEC_NORMAL);



void print_uint128(__uint128_t n) {
    if (n > UINT64_MAX) {
        print_uint128(n / 10);
        putchar((char)('0' + (n % 10)));
    } else {
        printf("%" PRIu64, (uint64_t)n);
    }
}

__IMPL_CONST_INTERN_DECS(dec128)
__IMPL_NORMALIZE_COEFF_EXP_DEC(dec128)
__IMPL_NORMALIZE_INTERN_DEC(dec128)
__IMPL_DEC_COMPARE(dec128)
__IMPL_INTERN_DEC_ATAN(dec128, 127)
__IMPL_INTERN_DEC_SQRT(dec128)
__IMPL_INTERN_DEC_MOD_2PI(dec128)
__IMPL_INTERN_DEC_SIN(dec128)
__IMPL_INTERN_DEC_COS(dec128)
__IMPL_INTERN_DEC_ASIN(dec128)
__IMPL_INTERN_DEC_ACOS(dec128)
__IMPL_INTERN_DEC_LOG10(dec128)
__IMPL_INTERN_DEC_LOG(dec128)
__INTF_INTERN_DEC_EXP10M1_REC(dec128);
__IMPL_INTERN_DEC_EXP10M1_REC(dec128)
__IMPL_INTERN_DEC_EXP10M1(dec128)
__IMPL_INTERN_DEC_EXPM1(dec128)
__IMPL_INTERN_DEC_SINH(dec128)
__IMPL_INTERN_DEC_COSH(dec128)
__IMPL_INTERN_DEC_TANH(dec128)
