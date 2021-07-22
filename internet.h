//
// Created by Mikhail Grubov on 09.07.2021.
//

#ifndef INTERNET_MODEL_VEBGRATH_INTERNET_H
#define INTERNET_MODEL_VEBGRATH_INTERNET_H

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cmath>
#include <algorithm>
#include <climits>

namespace internet{
    class model_Barabashi_Alberta{
    public:
        explicit model_Barabashi_Alberta(unsigned int n, unsigned int m);
        unsigned int shortest_path_search_algorithm();
        static unsigned int random_path(const std::vector<std::set<unsigned int>>& intermediate_graph, std::vector<unsigned int>& degrees_of_vertices);
        std::vector<std::vector<int>> transform_to_adjacency_matrix();
        [[maybe_unused]] [[nodiscard]] unsigned int getDiam() const;
        void show();
        ~model_Barabashi_Alberta();
    private:
        std::vector<std::set<unsigned int>> veb_grath;
        unsigned int diameter;
    };
}

#endif //INTERNET_MODEL_VEBGRATH_INTERNET_H
