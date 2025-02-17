#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

// Fonction pour vérifier si une chaîne de caractères est un nombre positif valide
bool isValidNumber(const std::string &str) {
    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (!std::isdigit(c) && c != '.' && c != '-') {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Ouvrir le fichier CSV (base de données des prix du Bitcoin)
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, float> bitcoinPrices;

    // Lire le fichier de données CSV et le stocker dans la map
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;
        float value;

        // Lire une ligne et séparer date et valeur
        std::getline(ss, date, '|');
        std::getline(ss, valueStr);

        // Supprimer les espaces autour des chaînes
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        // Vérifier si la valeur est valide
        if (isValidNumber(valueStr)) {
            value = std::stof(valueStr);
            // Ajouter la date et la valeur dans la map
            bitcoinPrices[date] = value;
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    file.close();

    // Ouvrir le fichier d'entrée (input.txt)
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Lire les lignes du fichier d'entrée et traiter chaque ligne
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;
        float value;

        // Lire la date et la valeur
        std::getline(ss, date, '|');
        std::getline(ss, valueStr);

        // Supprimer les espaces autour des chaînes
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        // Vérifier la validité de la valeur
        if (isValidNumber(valueStr)) {
            value = std::stof(valueStr);
            // Vérifier si la valeur est dans la plage valide
            if (value <= 0 || value > 1000) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            // Chercher la date la plus proche dans la base de données
            std::map<std::string, float>::iterator it = bitcoinPrices.lower_bound(date);
            if (it == bitcoinPrices.begin() && it->first != date) {
                std::cerr << "Error: bad input => " << line << std::endl;
            } else {
                if (it == bitcoinPrices.end() || it->first != date) {
                    --it;  // Prendre la date précédente si la date exacte n'existe pas
                }
                // Calculer le résultat
                std::cout << date << " => " << value << " = " << value * it->second << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    inputFile.close();

    return 0;
}

