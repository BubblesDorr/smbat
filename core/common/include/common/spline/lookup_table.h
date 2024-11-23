#ifndef _CORE_COMMON_INCLUDE_COMMON_SPLINE_LOOKUP_TABLE_H_
#define _CORE_COMMON_INCLUDE_COMMON_SPLINE_LOOKUP_TABLE_H_

#include "common/basics/basics.h"
#include "common/math/calculations.h"

#include <map>

namespace common {

/**
 * @brief compute the mapping matrix (from coeff to derivative) inverse
 * @note  this is for monotonic basis
 */
MatNf<6> GetAInverse(decimal_t t);

extern std::map<decimal_t, MatNf<6>, std::less<decimal_t>,
                Eigen::aligned_allocator<std::pair<const decimal_t, MatNf<6>>>>
    kTableAInverse;

} // namespace common

#endif // _CORE_COMMON_INCLUDE_COMMON_SPLINE_LOOKUP_TABLE_H_