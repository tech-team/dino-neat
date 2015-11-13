#include "world_object.h"

#include "exceptions/not_implemented_exception.h"
#include "world.h"

WorldObject::WorldObject(World& world, TileType tile_type)
    : world_(world),
      tile_type_(tile_type) {

}

bool WorldObject::collidesWith(const WorldObject& object) const {
    NOT_IMPLEMENTED();
}

bool WorldObject::collidesWith(const RectangularObject& object) const {
    NOT_IMPLEMENTED();
}
