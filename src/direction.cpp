#include "direction.hpp"

namespace MMaze {

  Direction tourne(Direction d, int r) {
    return (Direction) ((((int) d) + r) & 3);
  }

  Direction opposee(Direction d) {
    return tourne(d, 2);
  }

  const char* nom(Direction d) {
    static const char* noms[4] {
      "bas", "droite", "haut", "gauche"
    };
    return noms[(int) d];
  }

} //end of namespace MMaze
