#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "mur.hpp"
#include "melangeur.hpp"
#include "site.hpp"
#include "liste.hpp"
#include "unionfind.hpp"
#include "direction.hpp"

#include <fstream>
#include <string>
#include <vector>

namespace MMaze {
  class Tuile {

    public:
    
      Tuile(int id = 0, bool depart = false);

      //indique si deux cases voisines sont separees par un mur
      bool mur(Mur m) const;

      //indique si une case est accessible depuis les portes ou non
      bool accessible(Case c) const;

      //affichage
      friend std::ostream& operator<<(std::ostream& out, const Tuile& t);
      void afficher();

      void modifier_site(unsigned int pos, const Type & t, const Couleur & c);
      void placer_autre_site(const Type & t, const Couleur & c);
      void sauver_dans_fichier(std::string nom);
      void lire_dans_fichier(std::string nom);

      void rotation_gauche();
      void rotation_droite();

      void construire_graphe();

    private:
      std::vector<Site> vec_sites;
      std::vector<bool> vec_murs;
      int id_tuile;

      //affichage
      void afficher_horizontal(std::ostream& out, unsigned int i) const;
      void afficher_vertical(std::ostream& out, unsigned int i) const;
      void detruire_murs();
      void relier_sites(UnionFind& uf, std::vector<int> sites);
      void eliminer_impasses(UnionFind& uf, std::vector<int> sites);
      void reset_tuile();
      std::vector<int> reste_impasses();

  };

} //end of namespace MMaze

#endif
