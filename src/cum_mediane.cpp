#include <set>
#include <iterator>
#include "cum_mediane.h"

int cum_mediane
(const double* donnees_ptr, const int taille,
 // entrées en haut, sorties en bas
 double* sortie_ptr){
  std::set<double> triees;
  std::set<double>::iterator med;
  for(int i = 0; i < taille; i++){
    double nouvelle = donnees_ptr[i];
    std::pair<std::set<double>::iterator, bool> insertion = triees.insert(nouvelle);
    if(!insertion.second){
      return ERROR_DONNEES_REPETEES;
    }
    int n = i + 1;
    if(n == 1){
      med = insertion.first;
    }else if(n % 2 == 0){
      if(nouvelle < *med) med--;
    }else{
      if(nouvelle > *med) med++;
    }
    if(n % 2 == 1){
      sortie_ptr[i] = *med;
    }else{
      sortie_ptr[i] = (*med + *std::next(med)) / 2;
    }
  }
  return SUCCESS;
}