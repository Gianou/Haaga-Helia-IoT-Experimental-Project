#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <vector>
#include "Renderable.h"

class RenderEngine : public Renderable
{
public:
    RenderEngine();
    void draw(TFT_eSPI &tft) override;
    void addRenderable(Renderable *renderable);
    void removeRenderable(Renderable *renderable);

private:
    std::vector<Renderable *> renderables;
};

#endif // RENDER_ENGINE_H
