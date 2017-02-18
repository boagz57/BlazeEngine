#pragma once

/*Components are attached to entities via the bitwise operations below. Every
Entity bitmask will be set by these operations and that will determine an 
Entity's properties. So an Entity with a PostionComponent attached would have
a bitmask of .....0001, and an Entity with Position and velocity would have
a bitmask of .....0101. Then every system will compare an entity's bitmask 
to the system's bitmask. If a match is found then the system will except 
that entity and work with the needed components.
*/

enum Component
{
	NoComponents = 0,
	PositionComponent = 1 << 0,
	AppearanceComponent = 1 << 1,
	VelocityComponent = 1 << 2,
	AABBComponent = 1 << 3
};