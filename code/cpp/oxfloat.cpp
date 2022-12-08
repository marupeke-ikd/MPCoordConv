#include "oxfloat.h"
#include "oxmath.h"


// oxmath.h���̊֐����g���Ă���ꍇ�͂������

namespace OX {

	Quaternion& Quaternion::setAsRotDeg( const Float3& axis, float deg ) {
		return setAsRot( axis, OX::Math::toRad( deg ) );
	}

}