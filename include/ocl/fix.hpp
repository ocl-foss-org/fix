// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/fix

#ifndef OCL_FIX_HPP
#define OCL_FIX_HPP

#include <ocl/fix/detail/config.hpp>
#include <ocl/fix/checksum.hpp>
#include <ocl/fix/parser.hpp>

namespace ocl::fix
{

	template <typename It, class Pred>
	Pred find(It begin, It end, Pred callable);

	template <typename It, class Pred>
	Pred find_if(It begin, It end, Pred callable);

	template <typename It, class Pred>
	typename Pred::size_type erase(It begin, It end, Pred callable);

	template <typename It, class Pred>
	typename Pred::size_type erase_if(It begin, It end, Pred callable);

} // namespace ocl::fix

#include "fix.inl"

#endif
