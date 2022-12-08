#include "mpcoordconv_test.h"
#include "valuetester.h"
#include <string>
#include <vector>
#include "oxfloat.h"
#include "oxmath.h"

using namespace std;

namespace OX {
	namespace Test {

		namespace {
			float esp = 0.00001f;
			void quaternionTest( vector< string >& errs ) {
				// クォータニオン定義
				//  quaternion definition
				{
					Quaternion qX = Quaternion::getRotX( Math::toRad( 45.0f ) );
					equal( "QT rotX.x", qX.x, 0.3826835f, errs, esp );
					equal( "QT rotX.y", qX.y, 0.0f, errs, esp );
					equal( "QT rotX.z", qX.z, 0.0f, errs, esp );
					equal( "QT rotX.w", qX.w, 0.9238795f, errs, esp );

					Quaternion qY = Quaternion::getRotY( Math::toRad( 45.0f ) );
					equal( "QT rotY.x", qY.x, 0.0f, errs, esp );
					equal( "QT rotY.y", qY.y, 0.3826835f, errs, esp );
					equal( "QT rotY.z", qY.z, 0.0f, errs, esp );
					equal( "QT rotY.w", qY.w, 0.9238795f, errs, esp );

					Quaternion qZ = Quaternion::getRotZ( Math::toRad( 45.0f ) );
					equal( "QT rotZ.x", qZ.x, 0.0f, errs, esp );
					equal( "QT rotZ.y", qZ.y, 0.0f, errs, esp );
					equal( "QT rotZ.z", qZ.z, 0.3826835f, errs, esp );
					equal( "QT rotZ.w", qZ.w, 0.9238795f, errs, esp );
				}
				// クォータニオンの積
				//  quaternion production
				{
					Quaternion qX = Quaternion::getRotX( Math::toRad( 45.0f ) );
					Quaternion qY = Quaternion::getRotY( Math::toRad( 45.0f ) );
					Quaternion qZ = Quaternion::getRotZ( Math::toRad( 45.0f ) );

					Quaternion qXZ = qZ * qX;
					equal( "QT qXZ.x", qXZ.x, 0.3535534f, errs, esp );
					equal( "QT qXZ.y", qXZ.y, 0.1464466f, errs, esp );
					equal( "QT qXZ.z", qXZ.z, 0.3535534f, errs, esp );
					equal( "QT qXZ.w", qXZ.w, 0.8535534f, errs, esp );

					Quaternion qXY = qY * qX;
					equal( "QT qXY.x", qXY.x, 0.3535534f, errs, esp );
					equal( "QT qXY.y", qXY.y, 0.3535534f, errs, esp );
					equal( "QT qXY.z", qXY.z, -0.1464466f, errs, esp );
					equal( "QT qXY.w", qXY.w, 0.8535534f, errs, esp );

					Quaternion qYZ = qZ * qY;
					equal( "QT qYZ.x", qYZ.x, -0.1464466f, errs, esp );
					equal( "QT qYZ.y", qYZ.y, 0.3535534f, errs, esp );
					equal( "QT qYZ.z", qYZ.z, 0.3535534f, errs, esp );
					equal( "QT qYZ.w", qYZ.w, 0.8535534f, errs, esp );

					Quaternion qXYZ = qZ * qY * qX;
					equal( "QT qXYZ.x", qXYZ.x, 0.1913417f, errs, esp );
					equal( "QT qXYZ.y", qXYZ.y, 0.4619398f, errs, esp );
					equal( "QT qXYZ.z", qXYZ.z, 0.1913417f, errs, esp );
					equal( "QT qXYZ.w", qXYZ.w, 0.8446231f, errs, esp );
				}
			}
		}

		void MPCoordConv_Test::run() {
			vector< string > errs;

			quaternionTest( errs );

			testResult( errs );
		}
	}
}


