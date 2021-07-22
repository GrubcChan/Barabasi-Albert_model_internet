//
// Created by Mikhail Grubov on 09.07.2021.
//

#include "internet.h"

internet::model_Barabashi_Alberta::model_Barabashi_Alberta(unsigned int n, unsigned int m){
    srand(static_cast<unsigned int>(time(nullptr))); // NOLINT(cert-msc51-cpp)
    std::vector<std::set<unsigned int>> primary_graph;
    std::vector<unsigned int> degrees_of_vertices;
    // Создание случайного графа
    for(unsigned int i = 0; i < (n * m); i += m){
        std::set<unsigned int> all_group_paths;
        // Создается группа по m элементов с всеми путями вершин, которые в неё входят
        for(unsigned int group_counter = i; group_counter < (i+m); ++group_counter) {
            std::set<unsigned int> path_of_individual_peaks;
            primary_graph.push_back(path_of_individual_peaks);
            unsigned int path = random_path(primary_graph, degrees_of_vertices);
            primary_graph[group_counter].insert(path);
            std::cout << group_counter << ": " << path << "\n"; 
            degrees_of_vertices.push_back(1);
            degrees_of_vertices[path]++;
            all_group_paths.insert(path / m);
        }
        veb_grath.push_back(all_group_paths);
    }
    // Инициализация диаметра Веб-графа
    diameter = shortest_path_search_algorithm();
}

unsigned int internet::model_Barabashi_Alberta::shortest_path_search_algorithm(){
    // Алгоритм Флойда-Уоршола для поска кратчайших путей между всеми возможными вершинами в графе
    std::vector<std::vector<int>> adjacency_matrix_veb_grath;
    adjacency_matrix_veb_grath = transform_to_adjacency_matrix();
    unsigned int maximum_path = 1;
    for(unsigned int A = 0; A < adjacency_matrix_veb_grath.size(); ++A) {
        for (unsigned int B = 0; B < adjacency_matrix_veb_grath.size(); ++B) {
            if (adjacency_matrix_veb_grath[A][B] != INT_MAX) {
                for (unsigned int C = 0; C < adjacency_matrix_veb_grath.size(); ++C) {
                    if (adjacency_matrix_veb_grath[B][C] != INT_MAX) {
                        if (adjacency_matrix_veb_grath[A][C] >
                            (adjacency_matrix_veb_grath[A][B] + adjacency_matrix_veb_grath[B][C])) {
                            adjacency_matrix_veb_grath[A][C] = (adjacency_matrix_veb_grath[A][B] +
                                                                adjacency_matrix_veb_grath[B][C]);
                            if (adjacency_matrix_veb_grath[A][C] > maximum_path)
                                maximum_path = adjacency_matrix_veb_grath[A][C];
                        }
                    }
                }
            }
        }
    }
    return maximum_path;
}

std::vector<std::vector<int>> internet::model_Barabashi_Alberta::transform_to_adjacency_matrix(){
    std::vector<std::vector<int>> adjacency_matrix;
    for(auto &vertice: veb_grath){
        std::vector<int> all_paths;
        all_paths.resize(veb_grath.size(), INT_MAX);
        for(auto &this_path: vertice){
            all_paths[this_path] = 1;
        }
        adjacency_matrix.push_back(all_paths);
    }
    return adjacency_matrix;
}

void internet::model_Barabashi_Alberta::show(){
    unsigned int i = 0;
    for(auto &vertice: veb_grath){
        std::cout << i++ << ": ";
        for(auto &path: vertice){
            std::cout << path << " ";
        }
        std::cout << "\n";
    }
}

unsigned int internet::model_Barabashi_Alberta::getDiam() const{ return diameter; }

unsigned int internet::model_Barabashi_Alberta::random_path(const std::vector<std::set<unsigned int>>& intermediate_graph, std::vector<unsigned int>& degrees_of_vertices) {
    // Случайным образом получаем велечину от 0 до 1
    double random_point = ((double) rand())/ RAND_MAX; // NOLINT(cert-msc50-cpp)
    // Расчет знаменателя для получения вероятностей
    double denominator = ((double)((2 * (intermediate_graph.size())) - 1));
    double probability_counter = 0;
    for (unsigned int count = 0; count < intermediate_graph.size()-1; ++count) {
        probability_counter += (((double)degrees_of_vertices[count]) / denominator);
        if(random_point <= probability_counter) return count;
    }
    // Если выхода из цикла не было значит обрзуется петля на новой вершине
    return intermediate_graph.size()-1; // NOLINT(cppcoreguidelines-narrowing-conversions)
}

internet::model_Barabashi_Alberta::~model_Barabashi_Alberta(){
    for(auto &vertice: veb_grath){
        vertice.clear();
    }
    veb_grath.clear();
}
