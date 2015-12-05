#include "world_rasterizer.h"

#include <iostream>

#include "world.h"
#include "obstacle.h"
#include "player.h"


WorldRasterizer::WorldRasterizer(World& world)
    : world_(world),
      scaleFactor_(world.size_.x / rasterWidth_) {

}

PlainWorld WorldRasterizer::rasterize() {
    PlainWorld raster(rasterWidth_ * (rasterWidth_ / int(world_.size_.x / world_.size_.y)));

    for (auto& obstacle: world_.obstables_) {
        obstacle->rasterize(raster, *this);
    }

    //world_.player_->rasterize(raster, *this);

    return raster;
}

int WorldRasterizer::scaleFactor() const {
    return scaleFactor_;
}


int WorldRasterizer::to1d(int x, int y) {

    int new_y = y / scaleFactor_ * world_.size_.x / scaleFactor_;
    int new_x = x / scaleFactor_;
//    std::cout << "(" << x << "; " << y << ") => ("
//              << new_x << "; " << y / scaleFactor_ << "). "
//              << new_y + new_x;
    return new_y + new_x;
}
