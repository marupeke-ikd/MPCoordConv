#include "oxfloat.h"
#include "oxmath.h"


// oxmath.h内の関数を使っている場合はこちらへ

namespace OX {

	Quaternion& Quaternion::setAsRotDeg( const Float3& axis, float deg ) {
		return setAsRot( axis, OX::Math::toRad( deg ) );
	}

}