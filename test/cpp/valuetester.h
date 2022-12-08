#pragma once

// �l�e�X�g
//  �����̃e�X�g�l�Ɛ���l���r���āA�قȂ��Ă����ꍇ�Ɏ��s�������Ԃ�

#include <string>
#include <vector>
#include "oxfloat.h"

namespace OX {

	// �e�X�g���ʏo��
	void testResult( std::vector< std::string > &errs );

	// int
	bool equal( const char* name, const int est, const int trueVal, std::vector< std::string >& errs );

	// float
	bool equal( const char* name, const float est, const float trueVal, std::vector< std::string >& errs, float eps = 0.0f );

	// uint
	bool equal( const char* name, const unsigned int est, const unsigned int trueVal, std::vector< std::string >& errs );

	// bool
	bool equal( const char* name, const bool est, const bool trueVal, std::vector< std::string >& errs );

	// Float3
	bool equal( const char* name, const Float3 &est, const Float3 &trueVal, std::vector< std::string >& errs, float eps = 0.0f );

	// Int3
	bool equal( const char* name, const Int3& est, const Int3& trueVal, std::vector< std::string >& errs );
}