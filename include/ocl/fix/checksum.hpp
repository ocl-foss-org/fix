/*
 * File: fix/checksum.hpp
 * Purpose: Financial Information Exchange checksum in C++
 * Author: Amlal El Mahrouss (amlal@nekernel.org)
 * Copyright 2025-2026, Amlal El Mahrouss, licensed under the Boost Software License.
 */

#ifndef OCL_FIX_CHECKSUM
#define OCL_FIX_CHECKSUM

#include <ocl/fix/detail/config.hpp>
#include <ocl/fix/parser.hpp>
#include <boost/core/detail/string_view.hpp>

namespace ocl::fix
{

	/// \brief Returns the checksum index of a FIX message.
	/// \param range the range_buffer containing the message.
	/// \throws runtime_error if the FIX message is invalid (missing tag "8").
	std::string try_index_checksum(range_buffer& fix);

	/// \brief FIX message operators namespace.
	namespace operators
	{

		using checksum_type = long long;

		/// \brief Calculates the FIX protocol checksum for a message.
		/// \param in_ Pointer to the message buffer.
		/// \param len Length of the message in bytes.
		/// \return The checksum value (sum of all bytes modulo 256).
		checksum_type
		checksum(const boost::string_view& in_) noexcept;

	} // namespace operators

} // namespace ocl::fix

#endif
