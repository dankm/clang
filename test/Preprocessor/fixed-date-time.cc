// RUN: %clang_cc1 -ffixed-date-time=2008-09-02T14:30:27 -std=c++11 %s -verify
// RUN: not %clang_cc1 -ffixed-date-time=2008-09-02T14:30:27asdf -std=c++11 %s 2>&1 | FileCheck %s
// expected-no-diagnostics

// CHECK: error: invalid value '2008-09-02T14:30:27asdf' in '-ffixed-date-time=2008-09-02T14:30:27asdf'

constexpr int constexpr_strcmp(const char *p, const char *q) {
  return *p != *q ? *p - *q : !*p ? 0 : constexpr_strcmp(p + 1, q + 1);
}

static_assert(!constexpr_strcmp(__DATE__, "Sep  2 2008"), "");
static_assert(!constexpr_strcmp(__TIME__, "14:30:27"), "");
static_assert(!constexpr_strcmp(__TIMESTAMP__, "Tue Sep  2 14:30:27 2008"), "");
