// Copyright 2022 arkworks contributors
// Use of this source code is governed by a MIT/Apache-2.0 style license that
// can be found in the LICENSE-MIT.arkworks and the LICENCE-APACHE.arkworks
// file.

#ifndef TACHYON_MATH_FINITE_FIELDS_FP6_H_
#define TACHYON_MATH_FINITE_FIELDS_FP6_H_

#include "tachyon/math/finite_fields/cubic_extension_field.h"
#include "tachyon/math/finite_fields/fp6_forward.h"
#include "tachyon/math/finite_fields/quadratic_extension_field.h"

namespace tachyon::math {

template <typename Config>
class Fp6<Config, std::enable_if_t<Config::kDegreeOverBaseField == 2>>
    : public QuadraticExtensionField<Fp6<Config>> {
 public:
  using BaseField = typename Config::BaseField;

  using CpuField = Fp6<Config>;
  // TODO(chokobole): Implements Fp6Gpu
  using GpuField = Fp6<Config>;

  using QuadraticExtensionField<Fp6<Config>>::QuadraticExtensionField;

  static_assert(BaseField::ExtensionDegree() == 3);

  constexpr static uint64_t kDegreeOverBasePrimeField = 6;

  static void Init() { Config::Init(); }
};

template <typename Config>
class Fp6<Config, std::enable_if_t<Config::kDegreeOverBaseField == 3>>
    : public CubicExtensionField<Fp6<Config>> {
 public:
  using BaseField = typename Config::BaseField;

  using CpuField = Fp6<Config>;
  // TODO(chokobole): Implements Fp6Gpu
  using GpuField = Fp6<Config>;

  using CubicExtensionField<Fp6<Config>>::CubicExtensionField;

  static_assert(BaseField::ExtensionDegree() == 2);

  constexpr static uint64_t kDegreeOverBasePrimeField = 6;

  static void Init() { Config::Init(); }
};

}  // namespace tachyon::math

#endif  // TACHYON_MATH_FINITE_FIELDS_FP6_H_