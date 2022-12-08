#pragma once

// 値テスト
//  引数のテスト値と正解値を比較して、異なっていた場合に失敗文字列を返す

#include <string>
#include <vector>
#include "oxfloat.h"

namespace OX {

	// テスト結果出力
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