/* asn1.h
 *
 * Copyright (C) 2006-2024 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* asn1.h for openssl */

#ifndef WOLFSSL_ASN1_H_
#define WOLFSSL_ASN1_H_

#include <wolfssl/openssl/ssl.h>

#define ASN1_STRING_new       wolfSSL_ASN1_STRING_new
#define ASN1_STRING_type_new  wolfSSL_ASN1_STRING_type_new
#define ASN1_STRING_type      wolfSSL_ASN1_STRING_type
#define ASN1_STRING_set       wolfSSL_ASN1_STRING_set
#define ASN1_OCTET_STRING_set wolfSSL_ASN1_STRING_set
#define ASN1_STRING_free      wolfSSL_ASN1_STRING_free

#define ASN1_get_object       wolfSSL_ASN1_get_object
#define d2i_ASN1_OBJECT       wolfSSL_d2i_ASN1_OBJECT
#define c2i_ASN1_OBJECT       wolfSSL_c2i_ASN1_OBJECT

#define V_ASN1_INTEGER                   0x02
#define V_ASN1_NEG                       0x100
#define V_ASN1_NEG_INTEGER               (2 | V_ASN1_NEG)
#define V_ASN1_NEG_ENUMERATED            (10 | V_ASN1_NEG)

/* Type for ASN1_print_ex */
# define ASN1_STRFLGS_ESC_2253           1
# define ASN1_STRFLGS_ESC_CTRL           2
# define ASN1_STRFLGS_ESC_MSB            4
# define ASN1_STRFLGS_ESC_QUOTE          8
# define ASN1_STRFLGS_UTF8_CONVERT       0x10
# define ASN1_STRFLGS_IGNORE_TYPE        0x20
# define ASN1_STRFLGS_SHOW_TYPE          0x40
# define ASN1_STRFLGS_DUMP_ALL           0x80
# define ASN1_STRFLGS_DUMP_UNKNOWN       0x100
# define ASN1_STRFLGS_DUMP_DER           0x200
# define ASN1_STRFLGS_RFC2253            (ASN1_STRFLGS_ESC_2253 | \
                                          ASN1_STRFLGS_ESC_CTRL | \
                                          ASN1_STRFLGS_ESC_MSB | \
                                          ASN1_STRFLGS_UTF8_CONVERT | \
                                          ASN1_STRFLGS_DUMP_UNKNOWN | \
                                          ASN1_STRFLGS_DUMP_DER)

#define MBSTRING_UTF8                    0x1000
#define MBSTRING_ASC                     0x1001
#define MBSTRING_BMP                     0x1002
#define MBSTRING_UNIV                    0x1004

#define ASN1_UTCTIME_print              wolfSSL_ASN1_UTCTIME_print
#define ASN1_TIME_check                 wolfSSL_ASN1_TIME_check
#define ASN1_TIME_diff                  wolfSSL_ASN1_TIME_diff
#define ASN1_TIME_compare               wolfSSL_ASN1_TIME_compare
#define ASN1_TIME_set                   wolfSSL_ASN1_TIME_set

#define V_ASN1_EOC                      0
#define V_ASN1_BOOLEAN                  1
#define V_ASN1_OCTET_STRING             4
#define V_ASN1_NULL                     5
#define V_ASN1_OBJECT                   6
#define V_ASN1_UTF8STRING               12
#define V_ASN1_SEQUENCE                 16
#define V_ASN1_SET                      17
#define V_ASN1_PRINTABLESTRING          19
#define V_ASN1_T61STRING                20
#define V_ASN1_IA5STRING                22
#define V_ASN1_UTCTIME                  23
#define V_ASN1_GENERALIZEDTIME          24
#define V_ASN1_UNIVERSALSTRING          28
#define V_ASN1_BMPSTRING                30


#define V_ASN1_CONSTRUCTED              0x20

#define ASN1_STRING_FLAG_BITS_LEFT       0x008
#define ASN1_STRING_FLAG_NDEF            0x010
#define ASN1_STRING_FLAG_CONT            0x020
#define ASN1_STRING_FLAG_MSTRING         0x040
#define ASN1_STRING_FLAG_EMBED           0x080

/* X.509 PKI size limits from RFC2459 (appendix A) */
/* internally our limit is CTC_NAME_SIZE (64) - overridden with WC_CTC_NAME_SIZE */
#define ub_name                    CTC_NAME_SIZE /* 32768 */
#define ub_common_name             CTC_NAME_SIZE /* 64 */
#define ub_locality_name           CTC_NAME_SIZE /* 128 */
#define ub_state_name              CTC_NAME_SIZE /* 128 */
#define ub_organization_name       CTC_NAME_SIZE /* 64 */
#define ub_organization_unit_name  CTC_NAME_SIZE /* 64 */
#define ub_title                   CTC_NAME_SIZE /* 64 */
#define ub_email_address           CTC_NAME_SIZE /* 128 */


WOLFSSL_API WOLFSSL_ASN1_INTEGER *wolfSSL_BN_to_ASN1_INTEGER(
    const WOLFSSL_BIGNUM *bn, WOLFSSL_ASN1_INTEGER *ai);

WOLFSSL_API void wolfSSL_ASN1_TYPE_set(WOLFSSL_ASN1_TYPE *a, int type, void *value);
WOLFSSL_API int wolfSSL_ASN1_TYPE_get(const WOLFSSL_ASN1_TYPE *a);

WOLFSSL_API int wolfSSL_ASN1_get_object(const unsigned char **in, long *len, int *tag,
                                        int *cls, long inLen);

WOLFSSL_API WOLFSSL_ASN1_OBJECT *wolfSSL_c2i_ASN1_OBJECT(WOLFSSL_ASN1_OBJECT **a,
        const unsigned char **pp, long len);

#ifdef OPENSSL_ALL
/* IMPLEMENT_ASN1_FUNCTIONS is strictly for external use only. Internally
 * we don't use this. Some projects use OpenSSL to implement ASN1 types and
 * this section is only to provide those projects with ASN1 functionality. */

typedef void* (*WolfsslAsn1NewCb)(void);
typedef void (*WolfsslAsn1FreeCb)(void*);
typedef int (*WolfsslAsn1i2dCb)(const void*, unsigned char**);
typedef void* (*WolfsslAsn1d2iCb)(void**, const byte **, long);

struct WOLFSSL_ASN1_TEMPLATE {
    /* Type functions */
    WolfsslAsn1NewCb new_func;
    WolfsslAsn1FreeCb free_func;
    WolfsslAsn1i2dCb i2d_func;
    WolfsslAsn1d2iCb d2i_func;
    /* Member info */
    size_t offset;              /* Offset of this field in structure */
    /* DER info */
    int tag;
    byte first_byte;            /* First expected byte. Required for
                                 * IMPLICIT types. */
    byte ex:1;                  /* explicit, name conflicts with C++ keyword */
    byte sequence:1;
};

enum WOLFSSL_ASN1_TYPES {
    WOLFSSL_ASN1_SEQUENCE = 0,
    WOLFSSL_ASN1_CHOICE,
    WOLFSSL_ASN1_OBJECT_TYPE,
};

struct WOLFSSL_ASN1_ITEM {
    enum WOLFSSL_ASN1_TYPES type;
    const struct WOLFSSL_ASN1_TEMPLATE* members; /* If SEQUENCE or CHOICE this
                                                  * contains the contents */
    size_t mcount;                          /* Number of members if SEQUENCE
                                             * or CHOICE */
    size_t size;                            /* Structure size */
    size_t toffset;                         /* Type offset */
};

typedef struct WOLFSSL_ASN1_TEMPLATE WOLFSSL_ASN1_TEMPLATE;
typedef struct WOLFSSL_ASN1_ITEM WOLFSSL_ASN1_ITEM;

#define ASN1_BIT_STRING_FIRST_BYTE ASN_BIT_STRING
#define ASN1_TFLG_EXPLICIT      (0x1 << 0)
#define ASN1_TFLG_SEQUENCE_OF   (0x1 << 1)
#define ASN1_TFLG_IMPTAG        (0x1 << 2)
#define ASN1_TFLG_EXPTAG        (0x1 << 3)

#define ASN1_TFLG_TAG_MASK      (ASN1_TFLG_IMPTAG|ASN1_TFLG_EXPTAG)

#define ASN1_ITEM_TEMPLATE(mtype) \
        static const WOLFSSL_ASN1_TEMPLATE mtype##_member_data

#define ASN1_ITEM_TEMPLATE_END(mtype) \
    ; \
    const WOLFSSL_ASN1_ITEM mtype##_template_data = { \
            WOLFSSL_ASN1_OBJECT_TYPE, \
            &mtype##_member_data, \
            1, \
            0, \
            0 \
    };

#define ASN1_SEQUENCE(mtype) \
    static const WOLFSSL_ASN1_TEMPLATE mtype##_member_data[]

#define ASN1_SEQUENCE_END(mtype) \
    ; \
    const WOLFSSL_ASN1_ITEM mtype##_template_data = { \
            WOLFSSL_ASN1_SEQUENCE, \
            mtype##_member_data, \
            sizeof(mtype##_member_data) / sizeof(WOLFSSL_ASN1_TEMPLATE), \
            sizeof(mtype), \
            0 \
    }; \
    static WC_MAYBE_UNUSED const byte mtype##_FIRST_BYTE = \
        ASN_CONSTRUCTED | ASN_SEQUENCE;

/* This is what a ASN1_CHOICE type should look like
 *      typedef struct {
 *              int type;
 *              union {
 *                      ASN1_SOMETHING *opt1;
 *                      ASN1_SOMEOTHER *opt2;
 *              } value;
 *      } chname;
 */

#define ASN1_CHOICE(mtype) \
    static const WOLFSSL_ASN1_TEMPLATE mtype##_member_data[]

#define ASN1_CHOICE_END(mtype) \
    ; \
    const WOLFSSL_ASN1_ITEM mtype##_template_data = { \
            WOLFSSL_ASN1_CHOICE, \
            mtype##_member_data, \
            sizeof(mtype##_member_data) / sizeof(WOLFSSL_ASN1_TEMPLATE), \
            sizeof(mtype) ,\
            OFFSETOF(mtype, type) \
    };

#define ASN1_TYPE(type, member, tag, first_byte, exp, seq) \
    OFFSETOF(type, member), tag, first_byte, exp, seq

/* Function callbacks need to be defined immediately otherwise we will
 * incorrectly expand the type. Ex: ASN1_INTEGER -> WOLFSSL_ASN1_INTEGER */

#define ASN1_SIMPLE(type, member, member_type) \
    { (WolfsslAsn1NewCb)member_type##_new, \
      (WolfsslAsn1FreeCb)member_type##_free, \
      (WolfsslAsn1i2dCb)i2d_##member_type, \
      (WolfsslAsn1d2iCb)d2i_##member_type, \
      ASN1_TYPE(type, member, -1, 0, 0, 0) }

#define ASN1_IMP(type, member, member_type, tag) \
    { (WolfsslAsn1NewCb)member_type##_new, \
      (WolfsslAsn1FreeCb)member_type##_free, \
      (WolfsslAsn1i2dCb)i2d_##member_type, \
      (WolfsslAsn1d2iCb)d2i_##member_type, \
      ASN1_TYPE(type, member, tag, member_type##_FIRST_BYTE, 0, 0) }

#define ASN1_EXP(type, member, member_type, tag) \
    { (WolfsslAsn1NewCb)member_type##_new, \
      (WolfsslAsn1FreeCb)member_type##_free, \
      (WolfsslAsn1i2dCb)i2d_##member_type, \
      (WolfsslAsn1d2iCb)d2i_##member_type, \
      ASN1_TYPE(type, member, tag, 0, 1, 0) }

#define ASN1_SEQUENCE_OF(type, member, member_type) \
    { (WolfsslAsn1NewCb)member_type##_new, \
      (WolfsslAsn1FreeCb)member_type##_free, \
      (WolfsslAsn1i2dCb)i2d_##member_type, \
      (WolfsslAsn1d2iCb)d2i_##member_type, \
      ASN1_TYPE(type, member, -1, 0, 0, 1) }

#define ASN1_EXP_SEQUENCE_OF(type, member, member_type, tag) \
    { (WolfsslAsn1NewCb)member_type##_new, \
      (WolfsslAsn1FreeCb)member_type##_free, \
      (WolfsslAsn1i2dCb)i2d_##member_type, \
      (WolfsslAsn1d2iCb)d2i_##member_type, \
      ASN1_TYPE(type, member, tag, 0, 1, 1) }

#define ASN1_EX_TEMPLATE_TYPE(flags, tag, name, member_type) \
    { (WolfsslAsn1NewCb)member_type##_new, \
      (WolfsslAsn1FreeCb)member_type##_free, \
      (WolfsslAsn1i2dCb)i2d_##member_type, \
      (WolfsslAsn1d2iCb)d2i_##member_type, \
      0, (flags) & ASN1_TFLG_TAG_MASK ? (tag) : -1, 0, \
      !!((flags) & ASN1_TFLG_EXPLICIT), TRUE }

WOLFSSL_API void *wolfSSL_ASN1_item_new(const WOLFSSL_ASN1_ITEM *tpl);
WOLFSSL_API void wolfSSL_ASN1_item_free(void *obj,
        const WOLFSSL_ASN1_ITEM *item);
WOLFSSL_API int wolfSSL_ASN1_item_i2d(const void *src, byte **dest,
                                      const WOLFSSL_ASN1_ITEM *tpl);
WOLFSSL_API void* wolfSSL_ASN1_item_d2i(void** dst, const byte **src, long len,
        const WOLFSSL_ASN1_ITEM* item);

/* Need function declaration otherwise compiler complains */
/* // NOLINTBEGIN(readability-named-parameter,bugprone-macro-parentheses) */
#define IMPLEMENT_ASN1_FUNCTIONS(type) \
    type *type##_new(void); \
    type *type##_new(void){ \
        return (type*)wolfSSL_ASN1_item_new(&type##_template_data); \
    } \
    void type##_free(type *t); \
    void type##_free(type *t){ \
        wolfSSL_ASN1_item_free(t, &type##_template_data); \
    } \
    int i2d_##type(type *src, byte **dest); \
    int i2d_##type(type *src, byte **dest) \
    { \
        return wolfSSL_ASN1_item_i2d(src, dest, &type##_template_data); \
    } \
    type* d2i_##type(type **dst, const byte **src, long len); \
    type* d2i_##type(type **dst, const byte **src, long len) \
    { \
        return (type*)wolfSSL_ASN1_item_d2i((void**)dst, src, len, \
                &type##_template_data); \
    }
/* // NOLINTEND(readability-named-parameter,bugprone-macro-parentheses) */

#endif /* OPENSSL_ALL */

#define BN_to_ASN1_INTEGER          wolfSSL_BN_to_ASN1_INTEGER
#define ASN1_TYPE_set               wolfSSL_ASN1_TYPE_set
#define ASN1_TYPE_get               wolfSSL_ASN1_TYPE_get
#define ASN1_TYPE_new               wolfSSL_ASN1_TYPE_new
#define ASN1_TYPE_free              wolfSSL_ASN1_TYPE_free
#define i2d_ASN1_TYPE               wolfSSL_i2d_ASN1_TYPE

#endif /* WOLFSSL_ASN1_H_ */
