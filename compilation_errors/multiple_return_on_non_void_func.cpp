/*
 * Trompeloeil C++ mocking framework
 *
 * Copyright Björn Fahller 2014,2017
 *
 *  Use, modification and distribution is subject to the
 *  Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 *
 * Project home: https://github.com/rollbear/trompeloeil
 */

//Multiple RETURN does not make sense

#include <trompeloeil.hpp>

struct MS
{
  MAKE_MOCK0(f, int());
};

int main()
{
  MS obj;

#if (TROMPELOEIL_CPLUSPLUS == 201103L)

  using m_t = NAMED_MOCK_TYPE(obj, f());
  REQUIRE_CALL(obj, f())
    .RETURN_TYPE(m_t, 1)
    .RETURN_TYPE(m_t, 2);

#else /* (TROMPELOEIL_CPLUSPLUS == 201103L) */

  REQUIRE_CALL(obj, f())
    .RETURN(1)
    .RETURN(2);

#endif /* !(TROMPELOEIL_CPLUSPLUS == 201103L) */
}
