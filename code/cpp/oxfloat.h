#ifndef IKD_OX_BASIC_OXFLOAT_H
#define IKD_OX_BASIC_OXFLOAT_H

// 浮動小数点基本クラス群

// v1.0
// ・初出。基本機能を実装。

#include <float.h>
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <limits.h>


namespace OX {
	///////////////////////////
	// Float2
	////
	class Float2 {
	public:
		union {
			struct {float x, y;};
			struct {float r, g;};
			float v[2];
		};

		Float2() : x(), y() {}
		Float2(float x, float y) : x(x), y(y) {}

		// 演算子
		float &operator [](int e) {
			return v[e];
		}
		float operator [](int e) const {
			return v[e];
		}
		Float2 operator +(const Float2 &src) {
			Float2 out;
			out.x = x + src.x; out.y = y + src.y;
			return out;
		}
		friend Float2 operator +(const Float2 &l, const Float2 &r) {
			return Float2(l.x + r.x, l.y + r.y);
		}
		Float2 &operator +=(const Float2 &src) {
			x += src.x; y += src.y;
			return *this;
		}
		Float2 operator -(const Float2 &src) {
			Float2 out;
			out.x = x - src.x; out.y = y - src.y;
			return out;
		}
		friend Float2 operator -(const Float2 &l, const Float2 &r) {
			return Float2(l.x - r.x, l.y - r.y);
		}
		Float2 &operator -=(const Float2 &src) {
			x -= src.x; y -= src.y;
			return *this;
		}
		Float2 operator *(const Float2 &src) {
			Float2 out;
			out.x = x * src.x; out.y = y * src.y;
			return out;
		}
		Float2 operator *(float &src) {
			Float2 out;
			out.x = x * src; out.y = y * src;
			return out;
		}
		friend Float2 operator *(const Float2 &l, const float &r) {
			return Float2(l.x * r, l.y * r);
		}
		friend Float2 operator *(const float l, const Float2 &r) {
			return Float2(r.x * l, r.y * l);
		}
		Float2 &operator *=(const Float2 &src) {
			x *= src.x; y *= src.y;
			return *this;
		}
		Float2 operator /(const Float2 &src) {
			Float2 out;
			out.x = (src.x == 0.0f) ? FLT_MAX : x / src.x;
			out.y = (src.y == 0.0f) ? FLT_MAX : y / src.y;
			return out;
		}
		Float2 &operator /=(const Float2 &src) {
			x = (src.x == 0.0f) ? FLT_MAX : x / src.x;
			y = (src.y == 0.0f) ? FLT_MAX : y / src.y;
			return *this;
		}
		Float2 &operator /=(const float &val) {
			if (val == 0.0f) {
				x = FLT_MAX;
				y = FLT_MAX;
			} else {
				x /= val;
				y /= val;
			}
			return *this;
		}

		///////////////////////////////
		// メソッド

		// ゼロクリア
		void zero() {
			x = y = 0.0f;
		}

		// 長さ
		float length() const {
			return sqrtf(lengthSq());
		}

		// べき乗長さ
		float lengthSq() const {
			return x*x + y*y;
		}

		// 正規化
		Float2 &normalize() {
			float len = length();
			x /= len;
			y /= len;
			return *this;
		}

		// 非破壊正規化
		Float2 normalizeND() const {
			float len = length();
			return Float2(x/len, y/len);
		}

		// ベクトル反転
		void inv() {
			x *= -1.0f;
			y *= -1.0f;
		}

		// 非破壊ベクトル反転
		Float2 invND() const {
			return Float2(-x, -y);
		}

		// 内積
		float dot(const Float2 &r) const {
			return x * r.x + y * r.y;
		}

		// 外積
		float cross(const Float2 &r) const {
			return x * r.y - y * r.x;
		}
	};

	///////////////////////////
	// Float3
	////
	struct Float3 {
		union {
			struct{ float x, y, z;};
			struct{ float r, g, b;};
			float v[3];
		};

		Float3() : x(), y(), z() {}
		Float3(float x, float y, float z) : x(x), y(y), z(z) {}
		Float3(const Float2 &xy, float z) : x(xy.x), y(xy.y), z(z) {}

		// 演算子
		float &operator [](int e) {
			return v[e];
		}
		float operator [](int e) const {
			return v[e];
		}
		Float3 operator +(const Float3 &src) {
			Float3 out;
			out.x = x + src.x; out.y = y + src.y; out.z = z + src.z;
			return out;
		}
		friend Float3 operator +(const Float3 &l, const Float3 &r) {
			return Float3(l.x + r.x, l.y + r.y, l.z + r.z);
		}
		Float3 &operator +=(const Float3 &src) {
			x += src.x; y += src.y; z += src.z;
			return *this;
		}
		Float3 operator -( const Float3& src ) {
			Float3 out;
			out.x = x - src.x; out.y = y - src.y; out.z = z - src.z;
			return out;
		}
		Float3 operator -() {
			return *this * -1.0f;
		}
		friend Float3 operator -(const Float3 &l, const Float3 &r) {
			return Float3(l.x - r.x, l.y - r.y, l.z - r.z);
		}
		Float3 &operator -=(const Float3 &src) {
			x -= src.x; y -= src.y; z -= src.z;
			return *this;
		}
		Float3 operator *(const Float3 &src) {
			Float3 out;
			out.x = x * src.x; out.y = y * src.y; out.z = z * src.z;
			return out;
		}
		friend Float3 operator *(const Float3 &l, const Float3 &r) {
			return Float3(l.x * r.x, l.y * r.y, l.z * r.z);
		}
		Float3 operator *(float &src) {
			Float3 out;
			out.x = x * src; out.y = y * src; out.z = z * src;
			return out;
		}
		friend Float3 operator *(const Float3 &l, const float &r) {
			return Float3(l.x * r, l.y * r, l.z * r);
		}
		friend Float3 operator *(const float l, const Float3 &r) {
			return Float3(r.x * l, r.y * l, r.z * l);
		}
		Float3 &operator *=(const Float3 &src) {
			x *= src.x; y *= src.y; z *= src.z;
			return *this;
		}
		Float3 &operator *=(const float &src) {
			x *= src; y *= src; z *= src;
			return *this;
		}
		Float3 operator /(const Float3 &src) {
			Float3 out;
			out.x = (src.x == 0.0f) ? FLT_MAX : x / src.x;
			out.y = (src.y == 0.0f) ? FLT_MAX : y / src.y;
			out.z = (src.z == 0.0f) ? FLT_MAX : z / src.z;
			return out;
		}
		Float3 operator /(const float &src) {
			if (src == 0.0f) {
				return Float3(FLT_MAX, FLT_MAX, FLT_MAX);
			}
			return Float3(x/src, y/src, z/src);
		}
		Float3 &operator /=(const Float3 &src) {
			x = (src.x == 0.0f) ? FLT_MAX : x / src.x;
			y = (src.y == 0.0f) ? FLT_MAX : y / src.y;
			z = (src.z == 0.0f) ? FLT_MAX : z / src.z;
			return *this;
		}
		Float3 &operator /=(const float &val) {
			if (val == 0.0f) {
				x = FLT_MAX; y = FLT_MAX; z = FLT_MAX;
			} else {
				x /= val; y /= val; z /= val;
			}
			return *this;
		}
		bool operator ==( const Float3& r ) const {
			return !( x != r.x || y != r.y || z != r.z );
		}
		bool operator !=( const Float3& r ) const {
			return !( *this == r );
		}

		///////////////////////////////
		// メソッド

		// ゼロベクトル取得
		static const Float3 &getZero() {
			static const Float3 zero(0.0f, 0.0f, 0.0f);
			return zero;
		}

		// 1ベクトル取得
		static const Float3 &getOne() {
			static const Float3 one( 1.0f, 1.0f, 1.0f );
			return one;
		}

		// ゼロクリア
		void zero() {
			x = y = z = 0.0f;
		}

		// ゼロ？
		bool isZero() const {
			return !( x != 0.0f || y != 0.0f || z != 0.0f );
		}

		// 長さ
		float length() const {
			return sqrtf(lengthSq());
		}

		// べき乗長さ
		float lengthSq() const {
			return x*x + y*y + z*z;
		}

		// 正規化
		Float3 &normalize() {
			float len = length();
			if ( len == 0.0f )
				return *this;
			x /= len;
			y /= len;
			z /= len;
			return *this;
		}

		// 非破壊正規化
		Float3 normalizeND() const {
			float len = length();
			if ( len < 0.0000001f ) {
				return getZero();	// ゼロベクトルとする
			}
			return Float3(x/len, y/len, z/len);
		}

		// ベクトル反転
		void inv() {
			x *= -1.0f;
			y *= -1.0f;
			z *= -1.0f;
		}

		// 非破壊ベクトル反転
		Float3 invND() const {
			return Float3(-x, -y, -z);
		}

		// 内積
		float dot(const Float3 &r) const {
			return x * r.x + y * r.y + z * r.z;
		}

		// 外積
		Float3 cross(const Float3 &r) const {
			return Float3(
				y * r.z - z * r.y,
				z * r.x - x * r.z,
				x * r.y - y * r.x);
		}
	};


	///////////////////////////
	// Float4
	////
	struct Float4 {
		union {
			struct{ float x, y, z, w; };
			struct{ float r, g, b, a; };
			float v[4];
		};

		Float4() : x(), y(), z(), w() {}
		Float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		Float4(const Float3 &xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

		// 演算子
		float &operator [](int e) {
			return v[e];
		}
		Float4 operator +(const Float4 &src) {
			Float4 out;
			out.x = x + src.x; out.y = y + src.y; out.z = z + src.z; out.w = w + src.w;
			return out;
		}
		friend Float4 operator +(const Float4 &l, const Float4 &r) {
			return Float4(l.x + r.x, l.y + r.y, l.z + r.z, l.w + r.w);
		}
		Float4 &operator +=(const Float4 &src) {
			x += src.x; y += src.y; z += src.z; w += src.w;
			return *this;
		}
		Float4 operator -(const Float4 &src) {
			Float4 out;
			out.x = x - src.x; out.y = y - src.y; out.z = z - src.z; out.w = w - src.w;
			return out;
		}
		friend Float4 operator -(const Float4 &l, const Float4 &r) {
			return Float4(l.x - r.x, l.y - r.y, l.z - r.z, l.w - r.w);
		}
		Float4 &operator -=(const Float4 &src) {
			x -= src.x; y -= src.y; z -= src.z; w -= src.w;
			return *this;
		}
		Float4 operator *(const Float4 &src) {
			Float4 out;
			out.x = x * src.x; out.y = y * src.y; out.z = z * src.z; out.w = w * src.w;
			return out;
		}
		Float4 &operator *=(const Float4 &src) {
			x *= src.x; y *= src.y; z *= src.z;  w *= src.w;
			return *this;
		}
		Float4 operator *(const float &src) {
			Float4 out;
			out.x = x * src; out.y = y * src; out.z = z * src; out.w = w * src;
			return out;
		}
		friend Float4 operator *(const Float4 &l, const float &r) {
			return Float4(l.x * r, l.y * r, l.z * r, l.w * r);
		}
		friend Float4 operator *(const float l, const Float4 &r) {
			return Float4(r.x * l, r.y * l, r.z * l, r.w * l);
		}
		Float4 &operator *=(const float &src) {
			x *= src; y *= src; z *= src;  w *= src;
			return *this;
		}
		Float4 operator /(const Float4 &src) {
			Float4 out;
			out.x = (src.x == 0.0f) ? FLT_MAX : x / src.x;
			out.y = (src.y == 0.0f) ? FLT_MAX : y / src.y;
			out.z = (src.z == 0.0f) ? FLT_MAX : z / src.z;
			out.w = (src.w == 0.0f) ? FLT_MAX : w / src.w;
			return out;
		}
		Float4 operator /(const float &src) {
			if (src == 0.0f)
				return Float4(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX);
			return Float4(x/src, y/src, z/src, w/src);
		}
		Float4 &operator /=(const Float4 &src) {
			x = (src.x == 0.0f) ? FLT_MAX : x / src.x;
			y = (src.y == 0.0f) ? FLT_MAX : y / src.y;
			z = (src.z == 0.0f) ? FLT_MAX : z / src.z;
			w = (src.w == 0.0f) ? FLT_MAX : w / src.w;
			return *this;
		}
		Float4 &operator /=(const float &val) {
			if (val == 0.0f) {
				x = FLT_MAX; y = FLT_MAX; z = FLT_MAX; w = FLT_MAX;
			} else {
				x /= val; y /= val; z /= val; w /= val;
			}
			return *this;
		}

		Float4 &operator =(const Float3 &r) {
			x = r.x;
			y = r.y;
			z = r.z;
			return *this;
		}

		///////////////////////////////
		// メソッド

		// ゼロクリア
		void zero() {
			x = y = z = w = 0.0f;
		}

		// 長さ
		float length() const {
			return sqrtf(lengthSq());
		}

		// べき乗長さ
		float lengthSq() const {
			return x*x + y*y + z*z + w*w;
		}

		// 正規化
		Float4 &normalize() {
			float len = length();
			x /= len;
			y /= len;
			z /= len;
			w /= len;
			return *this;
		}

		// 非破壊正規化
		Float4 normalizeND() const {
			float len = length();
			return Float4(x/len, y/len, z/len, w/len);
		}

		// ベクトル反転
		void inv() {
			x *= -1.0f;
			y *= -1.0f;
			z *= -1.0f;
			w *= -1.0f;
		}

		// 非破壊ベクトル反転
		Float4 invND() const {
			return Float4(-x, -y, -z, -w);
		}

		// 内積
		float dot(const Float4 &r) const {
			return x * r.x + y * r.y + z * r.z + w * r.w;
		}

		// Float3へ
		Float3 toFloat3() const {
			return Float3(x, y, z);
		}
	};


	////////////////////////////
	// Float4x4
	//////
	class Float4x4 {
		void _swap(float &a, float &b) {float t = a; a = b; b = t;}

	public:
		union {
			float v[16];
			float r[4][4];
			struct { float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44; };
			struct { Float4 f4[4]; };
		};
		Float4x4() {
			memset( this, 0, sizeof( Float4x4 ) );
		}
		Float4x4( int init ) {
			memset( v, 0, sizeof( v ) );
			if ( init == 1 ) {
				v[ 0 ] = v[ 5 ] = v[ 10 ] = v[ 15 ] = 1.0f;
			}
		}
		Float4x4(const float _v[16]) {
			memcpy(v, _v, sizeof(float) * 16);
		}
		Float4x4(const Float4 &r1, const Float4 &r2, const Float4 &r3, const Float4 &r4) {
			f4[0] = r1; f4[1] = r2; f4[2] = r3; f4[3] = r4;
		}
		Float4x4(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44) :
			m11(m11), m12(m12), m13(m13), m14(m14),
			m21(m21), m22(m22), m23(m23), m24(m24),
			m31(m31), m32(m32), m33(m33), m34(m34),
			m41(m41), m42(m42), m43(m43), m44(m44) {}

		// []
		float& operator[](int e) {
			return v[e];
		}

		// ()
		float& operator()(int _r, int _c) {
			return r[_r][_c];
		}
		// *
		friend Float4x4 operator *(const Float4x4 &l, const Float4x4 &r) {
			Float4x4 res;
			res.m11 = l.m11 * r.m11 + l.m12 * r.m21 + l.m13 * r.m31 + l.m14 * r.m41;
			res.m12 = l.m11 * r.m12 + l.m12 * r.m22 + l.m13 * r.m32 + l.m14 * r.m42;
			res.m13 = l.m11 * r.m13 + l.m12 * r.m23 + l.m13 * r.m33 + l.m14 * r.m43;
			res.m14 = l.m11 * r.m14 + l.m12 * r.m24 + l.m13 * r.m34 + l.m14 * r.m44;

			res.m21 = l.m21 * r.m11 + l.m22 * r.m21 + l.m23 * r.m31 + l.m24 * r.m41;
			res.m22 = l.m21 * r.m12 + l.m22 * r.m22 + l.m23 * r.m32 + l.m24 * r.m42;
			res.m23 = l.m21 * r.m13 + l.m22 * r.m23 + l.m23 * r.m33 + l.m24 * r.m43;
			res.m24 = l.m21 * r.m14 + l.m22 * r.m24 + l.m23 * r.m34 + l.m24 * r.m44;

			res.m31 = l.m31 * r.m11 + l.m32 * r.m21 + l.m33 * r.m31 + l.m34 * r.m41;
			res.m32 = l.m31 * r.m12 + l.m32 * r.m22 + l.m33 * r.m32 + l.m34 * r.m42;
			res.m33 = l.m31 * r.m13 + l.m32 * r.m23 + l.m33 * r.m33 + l.m34 * r.m43;
			res.m34 = l.m31 * r.m14 + l.m32 * r.m24 + l.m33 * r.m34 + l.m34 * r.m44;

			res.m41 = l.m41 * r.m11 + l.m42 * r.m21 + l.m43 * r.m31 + l.m44 * r.m41;
			res.m42 = l.m41 * r.m12 + l.m42 * r.m22 + l.m43 * r.m32 + l.m44 * r.m42;
			res.m43 = l.m41 * r.m13 + l.m42 * r.m23 + l.m43 * r.m33 + l.m44 * r.m43;
			res.m44 = l.m41 * r.m14 + l.m42 * r.m24 + l.m43 * r.m34 + l.m44 * r.m44;

			return res;
		}
		Float4x4 operator *(const Float4x4 &r) {
			Float4x4 res;
			res.m11 = m11 * r.m11 + m12 * r.m21 + m13 * r.m31 + m14 * r.m41;
			res.m12 = m11 * r.m12 + m12 * r.m22 + m13 * r.m32 + m14 * r.m42;
			res.m13 = m11 * r.m13 + m12 * r.m23 + m13 * r.m33 + m14 * r.m43;
			res.m14 = m11 * r.m14 + m12 * r.m24 + m13 * r.m34 + m14 * r.m44;

			res.m21 = m21 * r.m11 + m22 * r.m21 + m23 * r.m31 + m24 * r.m41;
			res.m22 = m21 * r.m12 + m22 * r.m22 + m23 * r.m32 + m24 * r.m42;
			res.m23 = m21 * r.m13 + m22 * r.m23 + m23 * r.m33 + m24 * r.m43;
			res.m24 = m21 * r.m14 + m22 * r.m24 + m23 * r.m34 + m24 * r.m44;

			res.m31 = m31 * r.m11 + m32 * r.m21 + m33 * r.m31 + m34 * r.m41;
			res.m32 = m31 * r.m12 + m32 * r.m22 + m33 * r.m32 + m34 * r.m42;
			res.m33 = m31 * r.m13 + m32 * r.m23 + m33 * r.m33 + m34 * r.m43;
			res.m34 = m31 * r.m14 + m32 * r.m24 + m33 * r.m34 + m34 * r.m44;

			res.m41 = m41 * r.m11 + m42 * r.m21 + m43 * r.m31 + m44 * r.m41;
			res.m42 = m41 * r.m12 + m42 * r.m22 + m43 * r.m32 + m44 * r.m42;
			res.m43 = m41 * r.m13 + m42 * r.m23 + m43 * r.m33 + m44 * r.m43;
			res.m44 = m41 * r.m14 + m42 * r.m24 + m43 * r.m34 + m44 * r.m44;

			return res;
		}
		Float4x4 operator *(const float &r) {
			Float4x4 res;
			res.m11 = m11 * r;
			res.m12 = m12 * r;
			res.m13 = m13 * r;
			res.m14 = m14 * r;

			res.m21 = m21 * r;
			res.m22 = m22 * r;
			res.m23 = m23 * r;
			res.m24 = m24 * r;

			res.m31 = m31 * r;
			res.m32 = m32 * r;
			res.m33 = m33 * r;
			res.m34 = m34 * r;

			res.m41 = m41 * r;
			res.m42 = m42 * r;
			res.m43 = m43 * r;
			res.m44 = m44 * r;

			return res;
		}
		friend Float4x4 operator *(const float &l, const Float4x4 &r) {
			Float4x4 res;
			res.m11 = r.m11 * l;
			res.m12 = r.m12 * l;
			res.m13 = r.m13 * l;
			res.m14 = r.m14 * l;

			res.m21 = r.m21 * l;
			res.m22 = r.m22 * l;
			res.m23 = r.m23 * l;
			res.m24 = r.m24 * l;

			res.m31 = r.m31 * l;
			res.m32 = r.m32 * l;
			res.m33 = r.m33 * l;
			res.m34 = r.m34 * l;

			res.m41 = r.m41 * l;
			res.m42 = r.m42 * l;
			res.m43 = r.m43 * l;
			res.m44 = r.m44 * l;

			return res;
		}
		friend Float4 operator *(const Float4 &l, const Float4x4 &r) {
			return Float4(
				l.x * r.m11 + l.y * r.m21 + l.z * r.m31 + l.w * r.m41,
				l.x * r.m12 + l.y * r.m22 + l.z * r.m32 + l.w * r.m42,
				l.x * r.m13 + l.y * r.m23 + l.z * r.m33 + l.w * r.m43,
				l.x * r.m14 + l.y * r.m24 + l.z * r.m34 + l.w * r.m44
			);
		}

		// *=
		Float4x4 &operator *=(const Float4x4 &r) {
			*this = *this * r;
			return *this;
		}
		Float4x4 &operator *=(const float &r) {
			*this = *this * r;
			return *this;
		}

		// ==
		bool operator ==( const Float4x4 &r ) const {
			return memcmp( this, &r, sizeof( Float4x4 ) ) == 0;
		}

		//////////////////////////
		// メソッド

		// 単位行列取得
		static const Float4x4 &getIdentity() {
			static const Float4x4 idm(
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
			return idm;
		}

		// 単位行列化
		Float4x4 &identity() {
			memcpy(v, &getIdentity(), sizeof(float) * 16);
			return *this;
		}

		// ゼロ行列取得
		static const Float4x4 &getZero() {
			static const Float4x4 m0(
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f);
			return m0;
		}

		// ゼロ化
		Float4x4 &zero() {
			memcpy(v, &getZero(), sizeof(float) * 16);
			return *this;
		}

		// 転置
		Float4x4 &trans() {
			_swap(m12, m21);
			_swap(m13, m31);
			_swap(m14, m41);
			_swap(m23, m32);
			_swap(m24, m42);
			_swap(m34, m43);
			return *this;
		}

		// 非破壊転置
		Float4x4 transND() const {
			return Float4x4(
				m11, m21, m31, m41,
				m12, m22, m32, m42,
				m13, m23, m33, m43,
				m14, m24, m34, m44
			);
		}

		// 行列式取得
		float det() const {
			return m11 * m22 * m33 * m44 + m11 * m23 * m34 * m42 + m11 * m24 * m32 * m43
				+  m12 * m21 * m34 * m43 + m12 * m23 * m31 * m44 + m12 * m24 * m33 * m41
				+  m13 * m21 * m32 * m44 + m13 * m22 * m34 * m41 + m13 * m24 * m31 * m42
				+  m14 * m21 * m33 * m42 + m14 * m22 * m31 * m43 + m14 * m23 * m32 * m41
				-  m11 * m22 * m34 * m43 - m11 * m23 * m32 * m44 - m11 * m24 * m33 * m42
				-  m12 * m21 * m33 * m44 - m12 * m23 * m34 * m41 - m12 * m24 * m31 * m43
				-  m13 * m21 * m34 * m42 - m13 * m22 * m31 * m44 - m13 * m24 * m32 * m41
				-  m14 * m21 * m32 * m43 - m14 * m22 * m33 * m41 - m14 * m23 * m31 * m42;
		}

		// 逆行列化
		Float4x4 &inv() {
			float d = det();
			if (d == 0.0f)
				return *this;
			float b11 = m22 * m33 * m44 + m23 * m34 * m42 + m24 * m32 * m43 - m22 * m34 * m43 - m23 * m32 * m44 - m24 * m33 * m42;
			float b12 = m12 * m34 * m43 + m13 * m32 * m44 + m14 * m33 * m42 - m12 * m33 * m44 - m13 * m34 * m42 - m14 * m32 * m43;
			float b13 = m12 * m23 * m44 + m13 * m24 * m42 + m14 * m22 * m43 - m12 * m24 * m43 - m13 * m22 * m44 - m14 * m23 * m42;
			float b14 = m12 * m24 * m33 + m13 * m22 * m34 + m14 * m23 * m32 - m12 * m23 * m34 - m13 * m24 * m32 - m14 * m22 * m33;
			float b21 = m21 * m34 * m43 + m23 * m31 * m44 + m24 * m33 * m41 - m21 * m33 * m44 - m23 * m34 * m41 - m24 * m31 * m43;
			float b22 = m11 * m33 * m44 + m13 * m34 * m41 + m14 * m31 * m43 - m11 * m34 * m43 - m13 * m31 * m44 - m14 * m33 * m41;
			float b23 = m11 * m24 * m43 + m13 * m21 * m44 + m14 * m23 * m41 - m11 * m23 * m44 - m13 * m24 * m41 - m14 * m21 * m43;
			float b24 = m11 * m23 * m34 + m13 * m24 * m31 + m14 * m21 * m33 - m11 * m24 * m33 - m13 * m21 * m34 - m14 * m23 * m31;
			float b31 = m21 * m32 * m44 + m22 * m34 * m41 + m24 * m31 * m42 - m21 * m34 * m42 - m22 * m31 * m44 - m24 * m32 * m41;
			float b32 = m11 * m34 * m42 + m12 * m31 * m44 + m14 * m32 * m41 - m11 * m32 * m44 - m12 * m34 * m41 - m14 * m31 * m42;
			float b33 = m11 * m22 * m44 + m12 * m24 * m41 + m14 * m21 * m42 - m11 * m24 * m42 - m12 * m21 * m44 - m14 * m22 * m41;
			float b34 = m11 * m24 * m32 + m12 * m21 * m34 + m14 * m22 * m31 - m11 * m22 * m34 - m12 * m24 * m31 - m14 * m21 * m32;
			float b41 = m21 * m33 * m42 + m22 * m31 * m43 + m23 * m32 * m41 - m21 * m32 * m43 - m22 * m33 * m41 - m23 * m31 * m42;
			float b42 = m11 * m32 * m43 + m12 * m33 * m41 + m13 * m31 * m42 - m11 * m33 * m42 - m12 * m31 * m43 - m13 * m32 * m41;
			float b43 = m11 * m23 * m42 + m12 * m21 * m43 + m13 * m22 * m41 - m11 * m22 * m43 - m12 * m23 * m41 - m13 * m21 * m42;
			float b44 = m11 * m22 * m33 + m12 * m23 * m31 + m13 * m21 * m32 - m11 * m23 * m32 - m12 * m21 * m33 - m13 * m22 * m31;

			m11 = b11/d; m12 = b12/d; m13 = b13/d; m14 = b14/d;
			m21 = b21/d; m22 = b22/d; m23 = b23/d; m24 = b24/d;
			m31 = b31/d; m32 = b32/d; m33 = b33/d; m34 = b34/d;
			m41 = b41/d; m42 = b42/d; m43 = b43/d; m44 = b44/d;

			return *this;
		}

		// 非破壊逆行列
		Float4x4 invND() const {
			Float4x4 out;
			float d = det();
			if (d == 0.0f)
				return *this;
			out.m11 = m22 * m33 * m44 + m23 * m34 * m42 + m24 * m32 * m43 - m22 * m34 * m43 - m23 * m32 * m44 - m24 * m33 * m42;
			out.m12 = m12 * m34 * m43 + m13 * m32 * m44 + m14 * m33 * m42 - m12 * m33 * m44 - m13 * m34 * m42 - m14 * m32 * m43;
			out.m13 = m12 * m23 * m44 + m13 * m24 * m42 + m14 * m22 * m43 - m12 * m24 * m43 - m13 * m22 * m44 - m14 * m23 * m42;
			out.m14 = m12 * m24 * m33 + m13 * m22 * m34 + m14 * m23 * m32 - m12 * m23 * m34 - m13 * m24 * m32 - m14 * m22 * m33;
			out.m21 = m21 * m34 * m43 + m23 * m31 * m44 + m24 * m33 * m41 - m21 * m33 * m44 - m23 * m34 * m41 - m24 * m31 * m43;
			out.m22 = m11 * m33 * m44 + m13 * m34 * m41 + m14 * m31 * m43 - m11 * m34 * m43 - m13 * m31 * m44 - m14 * m33 * m41;
			out.m23 = m11 * m24 * m43 + m13 * m21 * m44 + m14 * m23 * m41 - m11 * m23 * m44 - m13 * m24 * m41 - m14 * m21 * m43;
			out.m24 = m11 * m23 * m34 + m13 * m24 * m31 + m14 * m21 * m33 - m11 * m24 * m33 - m13 * m21 * m34 - m14 * m23 * m31;
			out.m31 = m21 * m32 * m44 + m22 * m34 * m41 + m24 * m31 * m42 - m21 * m34 * m42 - m22 * m31 * m44 - m24 * m32 * m41;
			out.m32 = m11 * m34 * m42 + m12 * m31 * m44 + m14 * m32 * m41 - m11 * m32 * m44 - m12 * m34 * m41 - m14 * m31 * m42;
			out.m33 = m11 * m22 * m44 + m12 * m24 * m41 + m14 * m21 * m42 - m11 * m24 * m42 - m12 * m21 * m44 - m14 * m22 * m41;
			out.m34 = m11 * m24 * m32 + m12 * m21 * m34 + m14 * m22 * m31 - m11 * m22 * m34 - m12 * m24 * m31 - m14 * m21 * m32;
			out.m41 = m21 * m33 * m42 + m22 * m31 * m43 + m23 * m32 * m41 - m21 * m32 * m43 - m22 * m33 * m41 - m23 * m31 * m42;
			out.m42 = m11 * m32 * m43 + m12 * m33 * m41 + m13 * m31 * m42 - m11 * m33 * m42 - m12 * m31 * m43 - m13 * m32 * m41;
			out.m43 = m11 * m23 * m42 + m12 * m21 * m43 + m13 * m22 * m41 - m11 * m22 * m43 - m12 * m23 * m41 - m13 * m21 * m42;
			out.m44 = m11 * m22 * m33 + m12 * m23 * m31 + m13 * m21 * m32 - m11 * m23 * m32 - m12 * m21 * m33 - m13 * m22 * m31;
			
			return out * (1.0f / d);
		}

		// 平行移動
		Float4x4& trans( float x, float y, float z ) {
			m41 += x; m42 += y; m43 += z;
			return *this;
		}
		static Float4x4 getTrans( float x, float y, float z ) {
			return Float4x4( 1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  x, y, z, 1 );
		}
		// スケール
		Float4x4& scale( float x, float y, float z ) {
			m11 *= x; m12 *= y; m13 *= z;
			m21 *= x; m22 *= y; m23 *= z;
			m31 *= x; m32 *= y; m33 *= z;
			m41 *= x; m42 *= y; m43 *= z;
			return *this;
		}
		static Float4x4 getScale( float x, float y, float z ) {
			return Float4x4( x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1 );
		}
		// 回転
		static Float4x4 getRotZ( float rad ) {
			return Float4x4(
				cosf( rad ), -sinf( rad ), 0, 0,
				sinf( rad ), cosf( rad ), 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			);
		}
		Float4x4& rotZ( float rad ) {
			*this = *this * getRotZ( rad );
			return *this;
		}
		static Float4x4 getRotY( float rad ) {
			return Float4x4(
				cosf( rad ), 0, sinf( rad ), 0,
				0, 1, 0, 0,
				-sinf( rad ), 0, cosf( rad ), 0,
				0, 0, 0, 1
			);
		}
		Float4x4& rotY( float rad ) {
			*this = *this * getRotY( rad );
			return *this;
		}
		// 点を変換
		void mul( float& x, float& y, float& z, float& w ) const {
			const float tx = x, ty = y, tz = z, tw = w;
			x = tx * m11 + ty * m21 + tz * m31 + tw * m41;
			y = tx * m12 + ty * m22 + tz * m32 + tw * m42;
			z = tx * m13 + ty * m23 + tz * m33 + tw * m43;
			w = tx * m14 + ty * m24 + tz * m34 + tw * m44;
		}
	};


	////////////////////////////
	// Float4x3
	//////
	class Float4x3 {
		void _swap(float &a, float &b) {float t = a; a = b; b = t;}

	public:
		union {
			float v[12];
			float r[4][3];
			struct { float m11, m12, m13, m21, m22, m23, m31, m32, m33, m41, m42, m43; };
			struct { Float3 f3[4]; };
		};
		Float4x3() {
			memset( this, 0, sizeof(Float4x3) );
		}

		Float4x3(const float _v[12]) {
			memcpy(v, _v, sizeof(float) * 12);
		}
		Float4x3(const Float3 &r1, const Float3 &r2, const Float3 &r3, const Float3 &r4) {
			f3[0] = r1; f3[1] = r2; f3[2] = r3; f3[3] = r4;
		}
		Float4x3(
			float m11, float m12, float m13,
			float m21, float m22, float m23,
			float m31, float m32, float m33,
			float m41, float m42, float m43) :
			m11(m11), m12(m12), m13(m13),
			m21(m21), m22(m22), m23(m23),
			m31(m31), m32(m32), m33(m33),
			m41(m41), m42(m42), m43(m43) {}

		// []
		float& operator[](int e) {
			return v[e];
		}

		// ()
		float& operator()(int _r, int _c) {
			return r[_r][_c];
		}
		// 純粋掛け算
		friend Float4x3 operator *(const Float4x4 &l, const Float4x3 &r) {
			Float4x3 res;
			res.m11 = l.m11 * r.m11 + l.m12 * r.m21 + l.m13 * r.m31 + l.m14 * r.m41;
			res.m12 = l.m11 * r.m12 + l.m12 * r.m22 + l.m13 * r.m32 + l.m14 * r.m42;
			res.m13 = l.m11 * r.m13 + l.m12 * r.m23 + l.m13 * r.m33 + l.m14 * r.m43;

			res.m21 = l.m21 * r.m11 + l.m22 * r.m21 + l.m23 * r.m31 + l.m24 * r.m41;
			res.m22 = l.m21 * r.m12 + l.m22 * r.m22 + l.m23 * r.m32 + l.m24 * r.m42;
			res.m23 = l.m21 * r.m13 + l.m22 * r.m23 + l.m23 * r.m33 + l.m24 * r.m43;

			res.m31 = l.m31 * r.m11 + l.m32 * r.m21 + l.m33 * r.m31 + l.m34 * r.m41;
			res.m32 = l.m31 * r.m12 + l.m32 * r.m22 + l.m33 * r.m32 + l.m34 * r.m42;
			res.m33 = l.m31 * r.m13 + l.m32 * r.m23 + l.m33 * r.m33 + l.m34 * r.m43;

			res.m41 = l.m41 * r.m11 + l.m42 * r.m21 + l.m43 * r.m31 + l.m44 * r.m41;
			res.m42 = l.m41 * r.m12 + l.m42 * r.m22 + l.m43 * r.m32 + l.m44 * r.m42;
			res.m43 = l.m41 * r.m13 + l.m42 * r.m23 + l.m43 * r.m33 + l.m44 * r.m43;

			return res;
		}
		// 自身及び引数の4列目が0,0,0,1と仮定した掛け算
		Float4x3 operator *(const Float4x3 &r) const {
			return multAs4x4(r);
		}
		Float4x3 operator *=(const Float4x3 &r) {
			*this = multAs4x4(r);
			return *this;
		}
		Float4x3 operator *(const float &r) {
			Float4x3 res;
			res.m11 = m11 * r;
			res.m12 = m12 * r;
			res.m13 = m13 * r;

			res.m21 = m21 * r;
			res.m22 = m22 * r;
			res.m23 = m23 * r;

			res.m31 = m31 * r;
			res.m32 = m32 * r;
			res.m33 = m33 * r;

			res.m41 = m41 * r;
			res.m42 = m42 * r;
			res.m43 = m43 * r;

			return res;
		}
		friend Float4x3 operator *(const float &l, const Float4x3 &r) {
			Float4x3 res;
			res.m11 = r.m11 * l;
			res.m12 = r.m12 * l;
			res.m13 = r.m13 * l;

			res.m21 = r.m21 * l;
			res.m22 = r.m22 * l;
			res.m23 = r.m23 * l;

			res.m31 = r.m31 * l;
			res.m32 = r.m32 * l;
			res.m33 = r.m33 * l;

			res.m41 = r.m41 * l;
			res.m42 = r.m42 * l;
			res.m43 = r.m43 * l;

			return res;
		}
		friend Float3 operator *(const Float4 &l, const Float4x3 &r) {
			return Float3(
				l.x * r.m11 + l.y * r.m21 + l.z * r.m31 + l.w * r.m41,
				l.x * r.m12 + l.y * r.m22 + l.z * r.m32 + l.w * r.m42,
				l.x * r.m13 + l.y * r.m23 + l.z * r.m33 + l.w * r.m43
			);
		}

		Float4x3 &operator *=(const float &r) {
			*this = *this * r;
			return *this;
		}

		//////////////////////////
		// メソッド

		// 対角単位行列取得
		static const Float4x3 &getIdentity() {
			static const Float4x3 idm4x3(
				1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 1.0f,
				0.0f, 0.0f, 0.0f);
			return idm4x3;
		}

		// 対角単位行列化
		Float4x3 &identity() {
			memcpy(v, &getIdentity(), sizeof(float) * 12);
			return *this;
		}

		// ゼロ行列取得
		const Float4x3 &getZero() {
			static const Float4x3 m04x3(
				0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f);
			return m04x3;
		}

		// ゼロ化
		Float4x3 &zero() {
			memcpy(v, &getZero(), sizeof(float) * 12);
			return *this;
		}

		// float[16]へ4列目が0,0,0,1なFloat4x4として値をコピー
		float* as4x4f(float *ary) {
			memcpy(&ary[0], &f3[0], sizeof(float) * 3);
			memcpy(&ary[4], &f3[1], sizeof(float) * 3);
			memcpy(&ary[8], &f3[2], sizeof(float) * 3);
			memcpy(&ary[12], &f3[3], sizeof(float) * 3);
			ary[3] = ary[7] = ary[11] = 0.0f;
			ary[15] = 1.0f;
			return ary;
		}

		// Float4x4へ4列目が0,0,0,1なFloat4x4として値をコピー
		Float4x4 &as4x4M(Float4x4 &out) const {
			memcpy(&out.f4[0], &f3[0], sizeof(float) * 3);
			memcpy(&out.f4[1], &f3[1], sizeof(float) * 3);
			memcpy(&out.f4[2], &f3[2], sizeof(float) * 3);
			memcpy(&out.f4[3], &f3[3], sizeof(float) * 3);
			out.v[3] = out.v[7] = out.v[11] = 0.0f;
			out.v[15] = 1.0f;
			return out;
		}

		// float[16]へ4列目が0,0,0,1なFloat4x4として値をコピー
		void copyAs4x4(float ary[16]) {
			memcpy(&ary[0], &f3[0], sizeof(float) * 3);
			memcpy(&ary[4], &f3[1], sizeof(float) * 3);
			memcpy(&ary[8], &f3[2], sizeof(float) * 3);
			memcpy(&ary[12], &f3[3], sizeof(float) * 3);
			ary[3] = ary[7] = ary[11] = 0.0f;
			ary[15] = 1.0f;
		}

		// 4列目を0,0,0,1と仮定し引数を右から掛け算
		Float4x3 multAs4x4(const Float4x4 &r) {
			Float4x3 res;
			res.m11 = m11 * r.m11 + m12 * r.m21 + m13 * r.m31;
			res.m12 = m11 * r.m12 + m12 * r.m22 + m13 * r.m32;
			res.m13 = m11 * r.m13 + m12 * r.m23 + m13 * r.m33;

			res.m21 = m21 * r.m11 + m22 * r.m21 + m23 * r.m31;
			res.m22 = m21 * r.m12 + m22 * r.m22 + m23 * r.m32;
			res.m23 = m21 * r.m13 + m22 * r.m23 + m23 * r.m33;

			res.m31 = m31 * r.m11 + m32 * r.m21 + m33 * r.m31;
			res.m32 = m31 * r.m12 + m32 * r.m22 + m33 * r.m32;
			res.m33 = m31 * r.m13 + m32 * r.m23 + m33 * r.m33;

			res.m41 = m41 * r.m11 + m42 * r.m21 + m43 * r.m31 + r.m41;
			res.m42 = m41 * r.m12 + m42 * r.m22 + m43 * r.m32 + r.m42;
			res.m43 = m41 * r.m13 + m42 * r.m23 + m43 * r.m33 + r.m43;

			return res;
		}

		// 4列目を0,0,0,1と仮定し引数を右から掛け算。引数の4列目も同様と仮定。
		Float4x3 multAs4x4(const Float4x3 &r) const {
			Float4x3 res;
			res.m11 = m11 * r.m11 + m12 * r.m21 + m13 * r.m31;
			res.m12 = m11 * r.m12 + m12 * r.m22 + m13 * r.m32;
			res.m13 = m11 * r.m13 + m12 * r.m23 + m13 * r.m33;

			res.m21 = m21 * r.m11 + m22 * r.m21 + m23 * r.m31;
			res.m22 = m21 * r.m12 + m22 * r.m22 + m23 * r.m32;
			res.m23 = m21 * r.m13 + m22 * r.m23 + m23 * r.m33;

			res.m31 = m31 * r.m11 + m32 * r.m21 + m33 * r.m31;
			res.m32 = m31 * r.m12 + m32 * r.m22 + m33 * r.m32;
			res.m33 = m31 * r.m13 + m32 * r.m23 + m33 * r.m33;

			res.m41 = m41 * r.m11 + m42 * r.m21 + m43 * r.m31 + r.m41;
			res.m42 = m41 * r.m12 + m42 * r.m22 + m43 * r.m32 + r.m42;
			res.m43 = m41 * r.m13 + m42 * r.m23 + m43 * r.m33 + r.m43;

			return res;
		}

		// 4列目を0,0,0,1、引数をFloat4(r, 1.0f)として掛け算
		Float3 multAs4x4(const Float3 &r) const {
			return Float4(r, 1.0f) * *this;
		}

		// 4列目を0,0,0,1とした行列式取得
		float detAs4x4() const {
			return m11 * m22 * m33
				+  m12 * m23 * m31
				+  m13 * m21 * m32
				-  m11 * m23 * m32
				-  m12 * m21 * m33
				-  m13 * m22 * m31;
		}

		// 4列目を0,0,0,1とした逆行列化
		Float4x3 &invAs4x4() {
			float d = detAs4x4();
			if (d == 0.0f)
				return *this;
			float b11 = m22 * m33 - m23 * m32;
			float b12 = m13 * m32 - m12 * m33;
			float b13 = m12 * m23 - m13 * m22;
			float b21 = m23 * m31 - m21 * m33;
			float b22 = m11 * m33 - m13 * m31;
			float b23 = m13 * m21 - m11 * m23;
			float b31 = m21 * m32 - m22 * m31;
			float b32 = m12 * m31 - m11 * m32;
			float b33 = m11 * m22 - m12 * m21;
			float b41 = m21 * m33 * m42 + m22 * m31 * m43 + m23 * m32 * m41 - m21 * m32 * m43 - m22 * m33 * m41 - m23 * m31 * m42;
			float b42 = m11 * m32 * m43 + m12 * m33 * m41 + m13 * m31 * m42 - m11 * m33 * m42 - m12 * m31 * m43 - m13 * m32 * m41;
			float b43 = m11 * m23 * m42 + m12 * m21 * m43 + m13 * m22 * m41 - m11 * m22 * m43 - m12 * m23 * m41 - m13 * m21 * m42;

			m11 = b11/d; m12 = b12/d; m13 = b13/d;
			m21 = b21/d; m22 = b22/d; m23 = b23/d;
			m31 = b31/d; m32 = b32/d; m33 = b33/d;
			m41 = b41/d; m42 = b42/d; m43 = b43/d;

			return *this;
		}

		// 4列目を0,0,0,1とした非破壊逆行列
		Float4x3 invND() const {
			Float4x3 out;
			float d = detAs4x4();
			if (d == 0.0f)
				return *this;
			out.m11 = m22 * m33 - m23 * m32;
			out.m12 = m13 * m32 - m12 * m33;
			out.m13 = m12 * m23 - m13 * m22;
			out.m21 = m23 * m31 - m21 * m33;
			out.m22 = m11 * m33 - m13 * m31;
			out.m23 = m13 * m21 - m11 * m23;
			out.m31 = m21 * m32 - m22 * m31;
			out.m32 = m12 * m31 - m11 * m32;
			out.m33 = m11 * m22 - m12 * m21;
			out.m41 = m21 * m33 * m42 + m22 * m31 * m43 + m23 * m32 * m41 - m21 * m32 * m43 - m22 * m33 * m41 - m23 * m31 * m42;
			out.m42 = m11 * m32 * m43 + m12 * m33 * m41 + m13 * m31 * m42 - m11 * m33 * m42 - m12 * m31 * m43 - m13 * m32 * m41;
			out.m43 = m11 * m23 * m42 + m12 * m21 * m43 + m13 * m22 * m41 - m11 * m22 * m43 - m12 * m23 * m41 - m13 * m21 * m42;
			
			return out * (1.0f / d);
		}
	};



	/////////////////////////////////
	// クォータニオン
	/////
	class Quaternion {
	public:
		union {
			struct {Float4 v;};
			struct {float x, y, z, w;};
			struct {Float3 e; float s;};
		};

	public:
		Quaternion() : x(), y(), z(), w(1.0f) {}
		Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		Quaternion(const Float3 &e, float s) : e(e), s(s) {}
		Quaternion(const Float4 &v) : v(v) {}
		~Quaternion() {}

		// 積 *
		Quaternion operator *(const Quaternion &r) {
			return Quaternion(w * r.e + r.w * e + e.cross(r.e), w * r.w - e.dot(r.e));
		}


		////////////////////////////
		// メソッド
		////////
		// X軸回転クォータニオンを取得
		static Quaternion getRotX( float rad ) {
			Quaternion q;
			q.setAsRot( Float3( 1.0f, 0.0f, 0.0f ), rad );
			return q;
		}

		// Y軸回転クォータニオンを取得
		static Quaternion getRotY( float rad ) {
			Quaternion q;
			q.setAsRot( Float3( 0.0f, 1.0f, 0.0f ), rad );
			return q;
		}

		// Z軸回転クォータニオンを取得
		static Quaternion getRotZ( float rad ) {
			Quaternion q;
			q.setAsRot( Float3( 0.0f, 0.0f, 1.0f ), rad );
			return q;
		}

		// 単位クォータニオン
		void identity() {
			x = y = z = 0.0f;
			w = 1.0f;
		}

		// 回転クォータニオン化
		Quaternion &setAsRot(const Float3 &axis, float rad) {
			float sn = sinf(rad / 2.0f);
			e = axis.normalizeND() * sn;
			s = cosf(rad / 2.0f);
			return *this;
		}
		Quaternion& setAsRotDeg( const Float3& axis, float deg );

		// 共役クォータニオン取得
		Quaternion conj() {
			return Quaternion(-x, -y, -z, w);
		}

		// 点を回転
		Float3 rot(const Float3 &in) {
			Quaternion P(in, 0.0f);
			return (this->conj() * P * (*this)).e;
		}
	};




	///////////////////////////
	// Int2
	////
	struct Int2 {
		union {
			struct { int32_t x, y; };
			struct { int32_t r, g; };
			int32_t v[ 2 ];
		};

		Int2() : x(), y() {}
		Int2( int32_t x, int32_t y ) : x( x ), y( y ) {}

		// 演算子
		int32_t& operator []( int e ) {
			return v[ e ];
		}
		Int2 operator +( const Int2& src ) {
			Int2 out;
			out.x = x + src.x; out.y = y + src.y;
			return out;
		}
		friend Int2 operator +( const Int2& l, const Int2& r ) {
			return Int2( l.x + r.x, l.y + r.y );
		}
		Int2& operator +=( const Int2& src ) {
			x += src.x; y += src.y;
			return *this;
		}
		Int2 operator -( const Int2& src ) {
			Int2 out;
			out.x = x - src.x; out.y = y - src.y;
			return out;
		}
		friend Int2 operator -( const Int2& l, const Int2& r ) {
			return Int2( l.x - r.x, l.y - r.y );
		}
		Int2& operator -=( const Int2& src ) {
			x -= src.x; y -= src.y;
			return *this;
		}
		Int2 operator *( const Int2& src ) {
			Int2 out;
			out.x = x * src.x; out.y = y * src.y;
			return out;
		}
		Int2& operator *=( const Int2& src ) {
			x *= src.x; y *= src.y;
			return *this;
		}
		Int2 operator *( const int32_t& src ) {
			Int2 out;
			out.x = x * src; out.y = y * src;
			return out;
		}
		friend Int2 operator *( const Int2& l, const int32_t& r ) {
			return Int2( l.x * r, l.y * r );
		}
		friend Int2 operator *( const uint32_t l, const Int2& r ) {
			return Int2( r.x * l, r.y * l );
		}
		Int2& operator *=( const uint32_t& src ) {
			x *= src; y *= src;
			return *this;
		}
		Int2 operator /( const Int2& src ) {
			Int2 out;
			out.x = ( src.x == 0 ) ? INT_MAX : x / src.x;
			out.y = ( src.y == 0 ) ? INT_MAX : y / src.y;
			return out;
		}
		Int2 operator /( const int32_t& src ) {
			if ( src == 0 )
				return Int2( INT_MAX, INT_MAX );
			return Int2( x / src, y / src );
		}
		Int2& operator /=( const Int2& src ) {
			x = ( src.x == 0 ) ? INT_MAX : x / src.x;
			y = ( src.y == 0 ) ? INT_MAX : y / src.y;
			return *this;
		}
		Int2& operator /=( const int32_t& val ) {
			if ( val == 0 ) {
				x = INT_MAX; y = INT_MAX;
			}
			else {
				x /= val; y /= val;
			}
			return *this;
		}

		operator Float2() {
			return Float2( (float)x, (float)y );
		}

		///////////////////////////////
		// メソッド

		// ゼロクリア
		void zero() {
			x = y = 0;
		}

		// 長さ
		float length() const {
			return sqrtf( lengthSq() );
		}

		// べき乗長さ
		float lengthSq() const {
			return (float)( x * x + y * y );
		}

		// ベクトル反転
		void inv() {
			x *= -1;
			y *= -1;
		}

		// 非破壊ベクトル反転
		Int2 invND() const {
			return Int2( -x, -y );
		}

		// 内積
		int32_t dot( const Int2& r ) const {
			return x * r.x + y * r.y;
		}

		// Float2へ
		Float2 toFloat2() const {
			return Float2( (float)x, (float)y );
		}
	};



	///////////////////////////
	// Int3
	////
	struct Int3 {
		union {
			struct { int32_t x, y, z; };
			struct { int32_t r, g, b; };
			int32_t v[ 3 ];
		};

		Int3() : x(), y(), z() {}
		Int3( int32_t x, int32_t y, int32_t z ) : x( x ), y( y ), z( z ) {}

		// 演算子
		int32_t& operator []( int e ) {
			return v[ e ];
		}
		Int3 operator +( const Int3& src ) {
			Int3 out;
			out.x = x + src.x; out.y = y + src.y; out.z = z + src.z;
			return out;
		}
		friend Int3 operator +( const Int3& l, const Int3& r ) {
			return Int3( l.x + r.x, l.y + r.y, l.z + r.z );
		}
		Int3& operator +=( const Int3& src ) {
			x += src.x; y += src.y; z += src.z;
			return *this;
		}
		Int3 operator -( const Int3& src ) {
			Int3 out;
			out.x = x - src.x; out.y = y - src.y; out.z = z - src.z;
			return out;
		}
		friend Int3 operator -( const Int3& l, const Int3& r ) {
			return Int3( l.x - r.x, l.y - r.y, l.z - r.z );
		}
		Int3& operator -=( const Int3& src ) {
			x -= src.x; y -= src.y; z -= src.z;
			return *this;
		}
		Int3 operator *( const Int3& src ) {
			Int3 out;
			out.x = x * src.x; out.y = y * src.y; out.z = z * src.z;
			return out;
		}
		Int3& operator *=( const Int3& src ) {
			x *= src.x; y *= src.y; z *= src.z;
			return *this;
		}
		Int3 operator *( const int32_t& src ) {
			Int3 out;
			out.x = x * src; out.y = y * src; out.z = z * src;
			return out;
		}
		friend Int3 operator *( const Int3& l, const int32_t& r ) {
			return Int3( l.x * r, l.y * r, l.z * r );
		}
		friend Int3 operator *( const uint32_t l, const Int3& r ) {
			return Int3( r.x * l, r.y * l, r.z * l );
		}
		Int3& operator *=( const uint32_t& src ) {
			x *= src; y *= src;; z *= src;
			return *this;
		}
		Int3 operator /( const Int3& src ) {
			Int3 out;
			out.x = ( src.x == 0 ) ? INT_MAX : x / src.x;
			out.y = ( src.y == 0 ) ? INT_MAX : y / src.y;
			out.z = ( src.z == 0 ) ? INT_MAX : z / src.z;
			return out;
		}
		Int3 operator /( const int32_t& src ) {
			if ( src == 0 )
				return Int3( INT_MAX, INT_MAX, INT_MAX );
			return Int3( x / src, y / src, z / src );
		}
		Int3& operator /=( const Int3& src ) {
			x = ( src.x == 0 ) ? INT_MAX : x / src.x;
			y = ( src.y == 0 ) ? INT_MAX : y / src.y;
			z = ( src.z == 0 ) ? INT_MAX : z / src.z;
			return *this;
		}
		Int3& operator /=( const int32_t& val ) {
			if ( val == 0 ) {
				x = INT_MAX; y = INT_MAX; z = INT_MAX;
			}
			else {
				x /= val; y /= val; z /= val;
			}
			return *this;
		}

		bool operator ==( const Int3& r ) const {
			return !( x != r.x || y != r.y || z != r.z );
		}

		bool operator !=( const Int3& r ) const {
			return !( *this == r );
		}

		operator Float3() {
			return Float3( ( float )x, ( float )y, ( float )z );
		}

		///////////////////////////////
		// メソッド

		// ゼロクリア
		void zero() {
			x = y = z = 0;
		}

		// ゼロ取得
		static const Int3& getZero() {
			static const Int3 zero( 0, 0, 0 );
			return zero;
		}

		// 1取得
		static const Int3& getOne() {
			static const Int3 one( 1, 1, 1 );
			return one;
		}

		// 長さ
		float length() const {
			return sqrtf( lengthSq() );
		}

		// べき乗長さ
		float lengthSq() const {
			return ( float )( x * x + y * y + z * z );
		}

		// ベクトル反転
		void inv() {
			x *= -1;
			y *= -1;
			z *= -1;
		}

		// 非破壊ベクトル反転
		Int3 invND() const {
			return Int3( -x, -y, -z );
		}

		// 内積
		int32_t dot( const Int3& r ) const {
			return x * r.x + y * r.y + z * r.z;
		}

		// Float3へ
		Float3 toFloat3() const {
			return Float3( ( float )x, ( float )y, ( float )z );
		}
	};




	///////////////////////////
	// Int4
	////
	struct Int4 {
		union {
			struct { int32_t x, y, z, w; };
			struct { int32_t r, g, b, a; };
			int32_t v[ 4 ];
		};

		Int4() : x(), y(), z(), w() {}
		Int4( int32_t x, int32_t y, int32_t z, int32_t w ) : x( x ), y( y ), z( z ), w( w ) {}

		// 演算子
		int32_t& operator []( int e ) {
			return v[ e ];
		}
		Int4 operator +( const Int4& src ) {
			Int4 out;
			out.x = x + src.x; out.y = y + src.y; out.z = z + src.z; out.w = w + src.w;
			return out;
		}
		friend Int4 operator +( const Int4& l, const Int4& r ) {
			return Int4( l.x + r.x, l.y + r.y, l.z + r.z, l.w + r.w );
		}
		Int4& operator +=( const Int4& src ) {
			x += src.x; y += src.y; z += src.z; w += src.w;
			return *this;
		}
		Int4 operator -( const Int4& src ) {
			Int4 out;
			out.x = x - src.x; out.y = y - src.y; out.z = z - src.z; out.w = w - src.w;
			return out;
		}
		friend Int4 operator -( const Int4& l, const Int4& r ) {
			return Int4( l.x - r.x, l.y - r.y, l.z - r.z, l.w - r.w );
		}
		Int4& operator -=( const Int4& src ) {
			x -= src.x; y -= src.y; z -= src.z; w -= src.w;
			return *this;
		}
		Int4 operator *( const Int4& src ) {
			Int4 out;
			out.x = x * src.x; out.y = y * src.y; out.z = z * src.z; out.w = w * src.w;
			return out;
		}
		Int4& operator *=( const Int4& src ) {
			x *= src.x; y *= src.y; z *= src.z;  w *= src.w;
			return *this;
		}
		Int4 operator *( const int32_t& src ) {
			Int4 out;
			out.x = x * src; out.y = y * src; out.z = z * src; out.w = w * src;
			return out;
		}
		friend Int4 operator *( const Int4& l, const int32_t& r ) {
			return Int4( l.x * r, l.y * r, l.z * r, l.w * r );
		}
		friend Int4 operator *( const uint32_t l, const Int4& r ) {
			return Int4( r.x * l, r.y * l, r.z * l, r.w * l );
		}
		Int4& operator *=( const uint32_t& src ) {
			x *= src; y *= src; z *= src;  w *= src;
			return *this;
		}
		Int4 operator /( const Int4& src ) {
			Int4 out;
			out.x = ( src.x == 0 ) ? INT_MAX : x / src.x;
			out.y = ( src.y == 0 ) ? INT_MAX : y / src.y;
			out.z = ( src.z == 0 ) ? INT_MAX : z / src.z;
			out.w = ( src.w == 0 ) ? INT_MAX : w / src.w;
			return out;
		}
		Int4 operator /( const int32_t& src ) {
			if ( src == 0 )
				return Int4( INT_MAX, INT_MAX, INT_MAX, INT_MAX );
			return Int4( x / src, y / src, z / src, w / src );
		}
		Int4& operator /=( const Int4& src ) {
			x = ( src.x == 0 ) ? INT_MAX : x / src.x;
			y = ( src.y == 0 ) ? INT_MAX : y / src.y;
			z = ( src.z == 0 ) ? INT_MAX : z / src.z;
			w = ( src.w == 0 ) ? INT_MAX : w / src.w;
			return *this;
		}
		Int4& operator /=( const int32_t& val ) {
			if ( val == 0 ) {
				x = INT_MAX; y = INT_MAX; z = INT_MAX; w = INT_MAX;
			}
			else {
				x /= val; y /= val; z /= val; w /= val;
			}
			return *this;
		}

		operator Float4() {
			return Float4( (float)x, (float)y, (float)z, (float)w );
		}

		///////////////////////////////
		// メソッド

		// ゼロクリア
		void zero() {
			x = y = z = w = 0;
		}

		// 長さ
		float length() const {
			return sqrtf( lengthSq() );
		}

		// べき乗長さ
		float lengthSq() const {
			return (float)( x * x + y * y + z * z + w * w );
		}

		// ベクトル反転
		void inv() {
			x *= -1;
			y *= -1;
			z *= -1;
			w *= -1;
		}

		// 非破壊ベクトル反転
		Int4 invND() const {
			return Int4( -x, -y, -z, -w );
		}

		// 内積
		int32_t dot( const Int4& r ) const {
			return x * r.x + y * r.y + z * r.z + w * r.w;
		}

		// Float4へ
		Float4 toFloat4() const {
			return Float4( (float)x, (float)y, (float)z, (float)w );
		}
	};
}

#endif