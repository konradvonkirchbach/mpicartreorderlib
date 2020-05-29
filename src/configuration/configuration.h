#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>
#include <string>
#include <mpi.h>
#include <vector>
#include <array>
#include <memory>
#include <utility>

#include "definitions.h"
#include "reordering_algorithms/include_reodering_schemes.h"
#include "Stencils/Stencil_Creater.h"
#include "spdlog/spdlog.h"

/*
#ifdef __cplusplus
extern "C" {
#endif
int MPIX_Cart_comm_stencil(MPI_Comm comm_old, int ndims, const int dims[],
						   const int periods[], int reorder, const int stencil[],
						   const int n_neighbors, MPI_Comm *comm_cart);

void MPIX_Internode_cost_stencil(MPI_Comm cart_comm, int* total, int* max, int stencil[], int n_neighbors);
void MPIX_Internode_cost(MPI_Comm cart_comm, int* total, int* max);
#ifdef __cplusplus
}
#endif
*/

namespace mpireorderinglib {
class Configuration {
private:
  std::string str_alg;
  std::string str_stencil;
  std::string str_node_scheme;
  static const std::string env_alg;
  static const std::string env_stencil;
  static const std::string env_node_scheme;
  static const std::array<std::unique_ptr<mpireorderinglib::ReorderingScheme>, 3> reorder_schemes;
public:
  Configuration();
  std::string get_str_stencil() const;
  int perform_reordering(MPI_Comm old_comm, const int ndims, const int dims[], const int periods[],
						 const int stencil[], const int n_neighbors, MPI_Comm *cart_comm) const;
};
}

#endif
