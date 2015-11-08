#ifndef WORLDRASTERIZER_H
#define WORLDRASTERIZER_H

#include <vector>

class World;

using PlainWorld = std::vector<int>;

class WorldRasterizer {
public:
    WorldRasterizer(World& world);
    PlainWorld rasterize();

    int scaleFactor() const;

    int to1d(int x, int y);

private:

    int rasterWidth_ = 8;
    World& world_;
    int scaleFactor_;
};

#endif // WORLDRASTERIZER_H
