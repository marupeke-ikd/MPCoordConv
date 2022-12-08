#include "oxfloat.h"
#include "oxmath.h"


// oxmath.h“à‚ÌŠÖ”‚ğg‚Á‚Ä‚¢‚éê‡‚Í‚±‚¿‚ç‚Ö

namespace OX {

	Quaternion& Quaternion::setAsRotDeg( const Float3& axis, float deg ) {
		return setAsRot( axis, OX::Math::toRad( deg ) );
	}

}