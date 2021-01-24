/* -*- mode: C -*-  */
/*
   IGraph library.
   Copyright (C) 2009-2012  Gabor Csardi <csardi.gabor@gmail.com>
   334 Harvard street, Cambridge, MA 02139 USA

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301 USA

*/

#ifndef IGRAPH_CONSTRUCTORS_H
#define IGRAPH_CONSTRUCTORS_H

#include "igraph_decls.h"
#include "igraph_constants.h"
#include "igraph_types.h"
#include "igraph_matrix.h"
#include "igraph_datatype.h"
#include "igraph_graphicality.h"

__BEGIN_DECLS

/* -------------------------------------------------- */
/* Constructors, deterministic                        */
/* -------------------------------------------------- */

DECLDIR igraph_long_t igraph_create(igraph_t *graph, const igraph_vector_t *edges, igraph_long_t n,
                          igraph_bool_t directed);
DECLDIR igraph_long_t igraph_small(igraph_t *graph, igraph_long_t n, igraph_bool_t directed,
                         ...);
DECLDIR igraph_long_t igraph_adjacency(igraph_t *graph, igraph_matrix_t *adjmatrix,
                             igraph_adjacency_t mode);
DECLDIR igraph_long_t igraph_weighted_adjacency(igraph_t *graph, igraph_matrix_t *adjmatrix,
                                      igraph_adjacency_t mode, const char* attr,
                                      igraph_bool_t loops);
DECLDIR igraph_long_t igraph_star(igraph_t *graph, igraph_long_t n, igraph_star_mode_t mode,
                        igraph_long_t center);
DECLDIR igraph_long_t igraph_lattice(igraph_t *graph, const igraph_vector_t *dimvector, igraph_long_t nei,
                           igraph_bool_t directed, igraph_bool_t mutual, igraph_bool_t circular);
DECLDIR igraph_long_t igraph_ring(igraph_t *graph, igraph_long_t n, igraph_bool_t directed,
                        igraph_bool_t mutual, igraph_bool_t circular);
DECLDIR igraph_long_t igraph_tree(igraph_t *graph, igraph_long_t n, igraph_long_t children,
                        igraph_tree_mode_t type);
DECLDIR igraph_long_t igraph_from_prufer(igraph_t *graph, const igraph_vector_long_t *prufer);
DECLDIR igraph_long_t igraph_full(igraph_t *graph, igraph_long_t n, igraph_bool_t directed, igraph_bool_t loops);
DECLDIR igraph_long_t igraph_full_citation(igraph_t *graph, igraph_long_t n,
                                 igraph_bool_t directed);
DECLDIR igraph_long_t igraph_atlas(igraph_t *graph, igraph_long_t number);
DECLDIR igraph_long_t igraph_extended_chordal_ring(igraph_t *graph, igraph_long_t nodes,
        const igraph_matrix_t *W, igraph_bool_t directed);
DECLDIR igraph_long_t igraph_linegraph(const igraph_t *graph, igraph_t *linegraph);

DECLDIR igraph_long_t igraph_de_bruijn(igraph_t *graph, igraph_long_t m, igraph_long_t n);
DECLDIR igraph_long_t igraph_kautz(igraph_t *graph, igraph_long_t m, igraph_long_t n);
DECLDIR igraph_long_t igraph_famous(igraph_t *graph, const char *name);
DECLDIR igraph_long_t igraph_lcf_vector(igraph_t *graph, igraph_long_t n,
                              const igraph_vector_t *shifts,
                              igraph_long_t repeats);
DECLDIR igraph_long_t igraph_lcf(igraph_t *graph, igraph_long_t n, ...);
DECLDIR igraph_long_t igraph_realize_degree_sequence(igraph_t *graph,
                                           const igraph_vector_t *outdeg, const igraph_vector_t *indeg,
                                           igraph_edge_type_sw_t allowed_edge_types,
                                           igraph_realize_degseq_t method);

__END_DECLS

#endif
