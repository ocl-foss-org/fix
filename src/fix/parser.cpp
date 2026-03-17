// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/fix

#define OCL_FIX_HAS_IMPL
#include <ocl/fix/parser.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>

namespace ocl::fix
{

	namespace detail
	{

		inline boost::string_view& begin_fix() noexcept
		{
			static boost::string_view begin_fix{"FIX.4.2"};
			return begin_fix;
		}

	} // namespace detail

	boost::string_view& range_buffer::begin = detail::begin_fix();

	struct visitor::impl final
	{
	public:
		static constexpr int	  soh  = '\x01';
		static constexpr char	  eq   = '=';
		static constexpr unsigned base = 10U;

		explicit impl() = default;
		~impl()			= default;

		impl& operator=(const impl&) = delete;
		impl(const impl&)			 = delete;

		/// @brief Visits a FIX message and parse it into a range_buffer object.
		/// @param in The input FIX message as a string.
		/// @warning This function may throw exceptions.
		range_buffer visit(const boost::string_view& in)
		{
			range_buffer ret{};

			if (in.empty())
				return ret;

			std::string key, tag, value;
			std::size_t off		= 0UL;
			std::size_t soh_pos = 0UL;

			while (off < in.size())
			{
				std::size_t eq_pos = in.find(eq, off);
				if (eq_pos == std::string::npos)
					break;

				tag = in.substr(off, eq_pos - off).to_string();

				soh_pos = in.find(soh, eq_pos + 1);
				if (soh_pos == std::string::npos)
					soh_pos = in.size();

				value = in.substr(eq_pos + 1, soh_pos - eq_pos - 1).to_string();

				if (ret.magic_.empty())
				{
					ret.magic_	   = value;
					ret.magic_len_ = value.size();
				}

				ret.message_[tag] = value;

				off = soh_pos + 1;
			}

			return ret;
		}
	};

	visitor::visitor()	= default;
	visitor::~visitor() = default;

	/// @brief Alias of visit.
	range_buffer visitor::operator()(const std::string& in)
	{
		return impl_->visit(in.data());
	}

	/// @brief Visits a FIX message and parse it into a range_buffer object.
	/// @param in The input FIX message as a string.
	/// @warning This function may throw exceptions.
	range_buffer visitor::visit(const std::string& in)
	{
		return impl_->visit(in.data());
	}

} // namespace ocl::fix
