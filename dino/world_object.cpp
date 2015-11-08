#include "world_object.h"
#include "world.h"

WorldObject::WorldObject(World& world, TileType tile_type)
    : world_(world),
      tile_type_(tile_type) {

}

