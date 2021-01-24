/* -*- mode: C -*-  */
/*
   IGraph library.
   Copyright (C) 2006-2012  Gabor Csardi <csardi.gabor@gmail.com>
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

#include <igraph.h>

void print_vector(igraph_vector_t *v) {
    igraph_long_t i, n = igraph_vector_size(v);
    for (i = 0; i < n; i++) {
        printf(" %li", (igraph_long_t) VECTOR(*v)[i]);
    }
    printf("\n");
}

igraph_long_t main() {

    igraph_t g;
    igraph_real_t result;
    igraph_long_t from, to;
    igraph_vector_t path;

    igraph_barabasi_game(&g, 30, /*power=*/ 1, 30, 0, 0, /*A=*/ 1,
                         IGRAPH_DIRECTED, IGRAPH_BARABASI_BAG,
                         /*start_from=*/ 0);
    igraph_diameter(&g, &result, 0, 0, 0, IGRAPH_UNDIRECTED, 1);

    /*   printf("Diameter: %li\n", (igraph_long_t) result); */

    igraph_destroy(&g);

    igraph_ring(&g, 10, IGRAPH_DIRECTED, 0, 0);
    igraph_vector_init(&path, 0);
    igraph_diameter(&g, &result, &from, &to, &path, IGRAPH_DIRECTED, 1);
    printf("diameter: %li, from %li to %li\n", (igraph_long_t) result,
           (igraph_long_t) from, (igraph_long_t) to);
    print_vector(&path);

    igraph_vector_destroy(&path);
    igraph_destroy(&g);

    return 0;
}
