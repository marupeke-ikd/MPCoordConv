#include "valuetester.h"
#include <stdarg.h>
#include <math.h>

namespace {
	std::string printStr( const char* format, ... ) {
		char buf[ 1024 ];
		va_list ap;
		va_start( ap, format );
		vsprintf_s( buf, 1024, format, ap );
		va_end( ap );
		return buf;
	}
}

namespace OX {

	// テスト結果出力
	void testResult( std::vector< std::string >& errs ) {
		printf_s( "-------------------------------\n" );
		printf_s( "Test Result: " );
		if ( errs.size() == 0 ) {
			printf_s( "No error\n" );
		}
		else {
			printf_s( "%d error(s)\n", ( int )errs.size() );
			printf_s( "---------------------------\n" );
			for ( auto e : errs ) {
				printf_s( "  %s\n", e.c_str() );
			}
		}
		printf_s( "-------------------------------\n" );
	}

	// int
	bool equal( const char* name, const int est, const int trueVal, std::vector< std::string >& errs ) {
		if ( est != trueVal ) {
			errs.push_back( printStr( "%s: Not equal: true = %d  ->  est = %d", name, trueVal, est ) );
			return false;
		}
		return true;
	}

	// float
	bool equal( const char* name, const float est, const float trueVal, std::vector< std::string >& errs, float eps ) {
		if ( fabsf( est - trueVal ) > eps ) {
			errs.push_back( printStr( "%s: Not equal: true = %f  ->  est = %f", name, trueVal, est ) );
			return false;
		}
		return true;
	}

	// uint
	bool equal( const char* name, const unsigned int est, const unsigned int trueVal, std::vector< std::string >& errs ) {
		if ( est != trueVal ) {
			errs.push_back( printStr( "%s: Not equal: true = %u  ->  est = %u", name, trueVal, est ) );
			return false;
		}
		return true;
	}

	// bool
	bool equal( const char* name, const bool est, const bool trueVal, std::vector< std::string >& errs ) {
		if ( est != trueVal ) {
			errs.push_back( printStr( "%s: Not equal: true = %s  ->  est = %s", name, trueVal ? "t" : "f", est ? "t" : "f" ) );
			return false;
		}
		return true;
	}

	// Float3
	bool equal( const char* name, const Float3& est, const Float3& trueVal, std::vector< std::string >& errs, float eps ) {
		if ( 
			fabsf( est.x - trueVal.x ) > eps ||
			fabsf( est.y - trueVal.y ) > eps ||
			fabsf( est.z - trueVal.z ) > eps
		) {
			errs.push_back( printStr( "%s: Not equal: true = (%f, %f, %f)  ->  est = (%f, %f, %f)",
				name,
				trueVal.x, trueVal.y, trueVal.z,
				est.x, est.y, est.z
			) );
			return false;
		}
		return true;
	}

	// Int3
	bool equal( const char* name, const Int3& est, const Int3& trueVal, std::vector< std::string >& errs ) {
		if ( est != trueVal ) {
			errs.push_back( printStr( "%s: Not equal: true = (%d, %d, %d)  ->  est = (%d, %d, %d)",
				name,
				trueVal.x, trueVal.y, trueVal.z,
				est.x, est.y, est.z
			) );
			return false;
		}
		return true;
	}
}