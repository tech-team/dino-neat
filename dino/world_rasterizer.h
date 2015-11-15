#ifndef WORLD_RASTERIZER_H
#define WORLD_RASTERIZER_H

#include <vector>

class World;

using PlainWorld = std::vector<double>;

class WorldRasterizer {
public:
    WorldRasterizer(World& world);
    PlainWorld rasterize();

    int scaleFactor() const;

    int to1d(int x, int y);

private:

    int rasterWidth_ = 18;
    World& world_;
    int scaleFactor_;
};

#endif // WORLD_RASTERIZER_H
