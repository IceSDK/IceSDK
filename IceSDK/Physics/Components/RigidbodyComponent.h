#pragma once

#include <box2d/box2d.h>

namespace IceSDK::Components
{
	struct RigidbodyComponent
	{
		b2BodyDef body_def;
        b2Body* body;
        b2PolygonShape shape;
	};
} // namespace IceSDK::Components