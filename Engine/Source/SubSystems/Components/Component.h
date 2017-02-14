#pragma once

enum Component
{
	NoComponentMask = 0,
	PositionComponentMask = 1 << 0,
	AppearanceComponentMask = 1 << 1,
	VelocityComponentMask = 1 << 2,
	AABBComponentMask = 1 << 3
};