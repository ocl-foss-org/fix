// SPDX-License-Identifier: BSL-1.0
// Copyright 2025-2026, Amlal El Mahrouss (amlal@nekernel.org)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// Official repository: https://github.com/ocl-foss-org/fix

#define OCL_FIX_HAS_IMPL

#include <ocl/fix/parser.hpp>

#define BOOST_TEST_MODULE parser_test
#include <boost/test/included/unit_test.hpp>

/// @brief default fix packet
constexpr char const default_fix[] = {
	'8', '=', 'F', 'I', 'X', '.', '4', '.', '2', 0x01,
	'9', '=', '8', '7', 0x01, // BodyLength = 87
	'3', '5', '=', 'A', 0x01,
	'4', '9', '=', 'S', 'E', 'R', 'V', 'E', 'R', 0x01,
	'5', '6', '=', 'C', 'L', 'I', 'E', 'N', 'T', 0x01,
	'3', '4', '=', '1', '7', '7', 0x01,
	'5', '2', '=', '2', '0', '0', '9', '0', '1', '0', '7', '-', '1', '8', ':', '1', '5', ':', '1', '6', 0x01,
	'9', '8', '=', '0', 0x01,
	'1', '0', '8', '=', '3', '0', 0x01,
	'1', '0', '=', '6', '0', 0x01, 0x00 // CheckSum = 143
};

BOOST_AUTO_TEST_CASE(test_lookup_not_empty)
{

	ocl::fix::visitor	   basic_visitor;
	ocl::fix::range_buffer fix = basic_visitor.visit(default_fix);
    
    ocl::io::print(":key=35\n");
	ocl::io::print(":value=", fix["35"], "\n");

    BOOST_TEST(fix["35"].empty() == false);
}
