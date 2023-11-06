#include "pac_utils.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

char* copy_string(const char* s) {
    char* c = new char[strlen(s) + 1];
    strcpy(c, s);
    return c;
}

namespace {

const char* do_fmt(const char* format, va_list ap) {
    static char buf[1024];
    vsnprintf(buf, sizeof(buf), format, ap);
    return buf;
}

} // namespace

string strfmt(const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    const char* r = do_fmt(format, ap);
    va_end(ap);
    return string(r);
}

char* nfmt(const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    const char* r = do_fmt(format, ap);
    va_end(ap);
    return copy_string(r);
}
