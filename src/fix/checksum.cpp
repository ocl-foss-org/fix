// SPDX-License-Identifier: BSL-1.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/fix

#include <ocl/fix/checksum.hpp>

namespace ocl::fix
{

	std::string try_index_checksum(range_buffer& fix)
	{
		if (fix.is_valid())
			return fix["10"];
		else
			detail::throw_runtime_error();

		detail::unreachable();

		return {};
	}

	namespace operators
	{

		checksum_type
		checksum(const boost::string_view& in_) noexcept
		{
			checksum_type cks{};

			for (std::size_t idx{};
				 idx < in_.size(); ++idx)
				cks += static_cast<uint8_t>(in_[idx]);

			// add \0
			cks += 1;
			return cks % 256;
		}

	} // namespace operators

} // namespace ocl::fix
