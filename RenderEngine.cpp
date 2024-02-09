#include "RenderEngine.h"

RenderEngine::RenderEngine()
{
}

void RenderEngine::draw(TFT_eSprite &sprite)
{
    sprite.fillRect(0, 0, 158, 128, TFT_BLACK);
    for (Renderable *renderable : renderables)
    {
        renderable->draw(sprite);
    }
}

void RenderEngine::addRenderable(Renderable *renderable)
{
    renderables.push_back(renderable);
}

void RenderEngine::removeRenderable(Renderable *renderable)
{
    // Assuming you have a way to identify and remove the renderable.
    // Implementation depends on your specific requirements.
    // This might involve searching and erasing from the vector.
}
