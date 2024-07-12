#!/bin/sh

awk '
BEGIN {
    print("/* automatically generated, do not edit */") > "wolfssl/debug-trace-error-codes.h";
    print("#ifndef WOLFSSL_DEBUG_TRACE_ERROR_CODES_H") >> "wolfssl/debug-trace-error-codes.h";
    print("#define WOLFSSL_DEBUG_TRACE_ERROR_CODES_H") >> "wolfssl/debug-trace-error-codes.h";
    print("") >> "wolfssl/debug-trace-error-codes.h";

    print("/* automatically generated, do not edit */") > "wolfssl/debug-untrace-error-codes.h";
    print("#ifdef WOLFSSL_DEBUG_TRACE_ERROR_CODES_H") >> "wolfssl/debug-untrace-error-codes.h";
    print("#undef WOLFSSL_DEBUG_TRACE_ERROR_CODES_H") >> "wolfssl/debug-untrace-error-codes.h";
}
{
    if (match($0, "^[[:space:]]+([A-Z][A-Z0-9_]+)[[:space:]]*=[[:space:]]*(-[0-9]+)[,[:space:]]", errcode_a)) {
        if ((errcode_a[1] == "MIN_CODE_E") ||
            (errcode_a[1] == "WC_LAST_E") ||
            (errcode_a[1] == "MAX_CODE_E"))
        {
            next;
        }
        printf("#define %s WC_ERR_TRACE(%s)\n#define CONST_NUM_ERR_%s (%s)\n", errcode_a[1], errcode_a[1], errcode_a[1], errcode_a[2]) >> "wolfssl/debug-trace-error-codes.h";
        printf("#undef %s\n#undef CONST_NUM_ERR_%s\n", errcode_a[1], errcode_a[1]) >> "wolfssl/debug-untrace-error-codes.h";
    }
}
END {
    print("") >> "wolfssl/debug-trace-error-codes.h";
    print("#endif /* WOLFSSL_DEBUG_TRACE_ERROR_CODES_H */") >> "wolfssl/debug-trace-error-codes.h";

    print("") >> "wolfssl/debug-untrace-error-codes.h";
    print("#endif /* WOLFSSL_DEBUG_TRACE_ERROR_CODES_H */") >> "wolfssl/debug-untrace-error-codes.h";
}' wolfssl/wolfcrypt/error-crypt.h wolfssl/error-ssl.h
