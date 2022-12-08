#ifndef IKD_OX_BASIC_OXMATH_H
#define IKD_OX_BASIC_OXMATH_H

// 数学関数群
#include <math.h>
#include <stdint.h>
#include "oxfloat.h"


namespace OX {
	class Math {
	public:
		static const float pi;		// π
		static const float inv_pi;	// 1/π
		static const float _2pi;	// 2π
		static const float inv_2pi;	// 1/2π

		// 絶対値
		static float fabs(float v) {
			// 浮動小数点は最上位ビットで符号判断
			unsigned res = (*reinterpret_cast<unsigned*>(&v) & 0x7fffffff);
			return *reinterpret_cast<float*>(&res);
		}

		// 点間の距離のべき乗
		template<class T>
		static float lengthSq(const T& p1, const T& p2) {
			return (p1 - p2).lengthSq();
		}
		static float lengthSq(const float& p1, const float& p2) {
			return (p1 - p2) * (p1 - p2);
		}

		// べき乗
		static float pow2(float v) {
			return v * v;
		}

		// クランプ
		//  l～rの間にクランプ
		static float clamp(float v, float l, float r) {
			return v < l ? l : (v > r ? r : v);
		}
		static int32_t clamp( int32_t v, int32_t l, int32_t r ) {
			return v < l ? l : ( v > r ? r : v );
		}
		static Int2 clamp( const Int2& v, const Int2& l, const Int2& r ) {
			return Int2(
				clamp( v.x, l.x, r.x ),
				clamp( v.y, l.y, r.y )
			);
		}
		static Int2 clamp( const Int2& v, int32_t l, int32_t r ) {
			return Int2(
				clamp( v.x, l, r ),
				clamp( v.y, l, r )
			);
		}
		static Int3 clamp( const Int3& v, const Int3& l, const Int3& r ) {
			return Int3(
				clamp( v.x, l.x, r.x ),
				clamp( v.y, l.y, r.y ),
				clamp( v.z, l.z, r.z )
				);
		}
		static Int3 clamp( const Int3& v, int32_t l, int32_t r ) {
			return Int3(
				clamp( v.x, l, r ),
				clamp( v.y, l, r ),
				clamp( v.z, l, r )
			);
		}
		static Float3 clamp( const Float3& v, const Float3& l, const Float3& r ) {
			return Float3(
				clamp( v.x, l.x, r.x ),
				clamp( v.y, l.y, r.y ),
				clamp( v.z, l.z, r.z )
			);
		}
		static Float3 clamp( const Float3& v, float l, float r ) {
			return Float3(
				clamp( v.x, l, r ),
				clamp( v.y, l, r ),
				clamp( v.z, l, r )
			);
		}

		// ラジアンをデグリーに
		template<class T>
		static T toDeg(const T &rad) {
			return T(toDeg(rad.x), toDeg(rad.y), toDeg(rad.z));
		}
		static float toDeg( const float rad ) {
			return 360.0f / _2pi * rad;
		}

		// デグリーをラジアンに
		static float toRad(float deg) {
			return deg * _2pi / 360.0f;
		}
		template<class T>
		static T toRad(const T &deg) {
			return T(toRad(deg.x), toRad(deg.y), toRad(deg.z));
		}

		// 線形補間
		template<class T>
		static T linear(const T& v1, const T& v2, float t) {
			return (1.0f - t) * v1 + t * v2;
		}

		// cot
		static float cotf(float v) {
			return 1.0f / tanf(v);
		}

		// sin, cos, tan（デグリー角）
		static float sinD( float deg ) {
			return sinf( toRad( deg ) );
		}
		static float cosD( float deg ) {
			return cosf( toRad( deg ) );
		}
		static float tanD( float deg ) {
			return tanf( toRad( deg ) );
		}
		static float asosD( float v ) {
			return toDeg( asinf( v ) );
		}
		static float acosD( float v ) {
			return toDeg( acosf( v ) );
		}
		static float atanD( float v ) {
			return toDeg( atanf( v ) );
		}
		static float atan2D( float y, float x ) {
			return toDeg( atan2f( y, x ) );
		}

		// min, max
		static float min2( float v0, float v1 ) {
			return v0 < v1;
		}
		static float miax2( float v0, float v1 ) {
			return v0 > v1;
		}

		// 3つのmin
		static float min3( float v0, float v1, float v2 ) {
			if ( v0 < v1 && v0 < v2 ) return v0;
			if ( v1 < v2 ) return v1;
			return v2;
		}

		// 3つのmax
		static float max3( float v0, float v1, float v2 ) {
			if ( v0 > v1 && v0 > v2 ) return v0;
			if ( v1 > v2 ) return v1;
			return v2;
		}
	};
}

#endif
