/*
 * File: fix/checksum.cpp
 * Purpose: Financial Information Exchange parser in C++
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2026, Amlal El Mahrouss, licensed under the Boost Software License.
 */

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
