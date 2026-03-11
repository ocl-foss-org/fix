// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/fix

#ifndef OCL_FIX_CONFIG
#define OCL_FIX_CONFIG

#include <ocl/detail/config.hpp>
#include <ocl/crc_hash.hpp>
#include <ocl/print.hpp>

namespace ocl::fix::detail
{

	inline void throw_runtime_error(const boost::source_location& location = BOOST_CURRENT_LOCATION)
	{
		throw std::runtime_error(location.to_string());
	}

	inline void unreachable() noexcept
	{
#if defined(__GNUC__) || defined(__clang__)
		__builtin_unreachable();
#elif defined(_MSC_VER)
		__assume(false);
#else
		std::abort();
#endif
	}

} // namespace ocl::fix::detail

#endif
