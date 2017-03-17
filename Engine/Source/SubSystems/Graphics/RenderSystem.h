#pragma once
#include "Graphics/Sprite.h"
#include "Character.h"

namespace RenderSystem
{
	void Initialize();
	//Load verts so renderer has them loaded at start and data is only sent down once. Return 
	//unique ID that we can use to attach to a Character later
	uint16 LoadSprite(BGraphics::Sprite sprite);
	//Use unique ID from before which will represent a sprite and attache to character
	void AttachSprite(/* SpriteID, Character */);
	void RenderCharacter(Character* character);
}
