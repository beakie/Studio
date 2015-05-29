#include "bodyrender.h"
#include "core.h"
#include "common.h"
#include "kinematics.h"
#include "movement.h"
#include "picture.h"
#include "picture-qt.h"
#include "render3d.h"
#include "skeletals.h"
#include "space2d.h"
#include "space3d.h"

/*******************
Core		 -	
Common		 -	Core
Space2d		 -	Common
Space3d		 -	Common
Movement	 -	Space2d, Space3d
Render3d	 -	Space2d, Space3d
Picture		 -	Common
Picture-Qt	 -	Picture
BodyRender	 -	Movement
Kinematics -	Movement
*******************/
