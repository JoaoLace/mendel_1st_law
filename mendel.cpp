#include <iostream>
#include <set>
#include <vector>

std::vector<char> getGametes (std::string genes){
    std::vector<char> temp;
    temp.push_back(genes[0]);
    temp.push_back(genes[1]);
    

    return temp;
}

std::vector<std::string> off_springs (std::vector<char> mothers_gametes, std::vector<char> fathers_gametes) {
    std::vector<std::string> temp;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            std::string m(1, mothers_gametes[i]);
            std::string f(1,fathers_gametes[j]);
            std::string off_spring =  m + f;
            temp.push_back(off_spring);
        }
    }

    return temp;
}

std::vector <std::string> getPairs(std::string genes) {
    std::vector<std::string> output;
    for (int i = 1; i < genes.length(); i+=2){
        std::string x(1, genes[i - 1]);
        std::string y(1, genes[i]);
        output.push_back(x + y);
    }

    return output;
}
std::set<std::string> combineAll(const std::vector<std::vector<std::string>>& all_combinations) {
    std::set<std::string> result_set;

    for (const auto& combination : all_combinations[0]) {
        result_set.insert(combination);
    }

    for (size_t i = 1; i < all_combinations.size(); ++i) {
        std::set<std::string> new_set;

        for (const auto& existing : result_set) {
            for (const auto& new_combination : all_combinations[i]) {
                new_set.insert(existing + new_combination);
            }
        }

        result_set = new_set;
    }

    return result_set;
}
int main ()
{
    std::vector<std::vector<std::string>> test;

    std::string father_genes, mother_genes;
    
    std::cout << "Father's genes: ";
    std::cin >> father_genes;
    
    std::cout << "Mother's genes: ";
    std::cin >> mother_genes;

    std::vector<std::string> fathers_genes_vector = getPairs(father_genes);
    std::vector<std::string> mothers_genes_vector = getPairs(mother_genes);


    for (int i = 0; i < fathers_genes_vector.size() ; i++){
        std::vector<std::string> result = off_springs(getGametes(fathers_genes_vector[i]), getGametes(mothers_genes_vector[i]));
        test.push_back(result);
    }
    std::set<std::string> unique_combinations = combineAll(test);

    for (const std::string& comb : unique_combinations) {
        std::cout << comb << " ";
    }
    std::cout << "\n";

    return 0;
}