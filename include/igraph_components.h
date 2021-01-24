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

#ifndef IGRAPH_COMPONENTS_H
#define IGRAPH_COMPONENTS_H

#include "igraph_decls.h"
#include "igraph_constants.h"
#include "igraph_types.h"
#include "igraph_vector.h"
#include "igraph_vector_ptr.h"
#include "igraph_datatype.h"

__BEGIN_DECLS

/* -------------------------------------------------- */
/* Components                                         */
/* -------------------------------------------------- */

DECLDIR igraph_long_t igraph_clusters(const igraph_t *graph, igraph_vector_t *membership,
                            igraph_vector_t *csize, igraph_long_t *no,
                            igraph_connectedness_t mode);
DECLDIR igraph_long_t igraph_is_connected(const igraph_t *graph, igraph_bool_t *res,
                                igraph_connectedness_t mode);
DECLDIR void igraph_decompose_destroy(igraph_vector_ptr_t *complist);
DECLDIR igraph_long_t igraph_decompose(const igraph_t *graph, igraph_vector_ptr_t *components,
                             igraph_connectedness_t mode,
                             igraph_long_t maxcompno, igraph_long_t minelements);
DECLDIR igraph_long_t igraph_articulation_points(const igraph_t *graph,
                                       igraph_vector_t *res);
DECLDIR igraph_long_t igraph_biconnected_components(const igraph_t *graph,
        igraph_long_t *no,
        igraph_vector_ptr_t *tree_edges,
        igraph_vector_ptr_t *component_edges,
        igraph_vector_ptr_t *components,
        igraph_vector_t *articulation_points);
DECLDIR igraph_long_t igraph_bridges(const igraph_t *graph, igraph_vector_t *bridges);

__END_DECLS

#endif
