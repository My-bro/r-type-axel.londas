/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Dec, 2024                                                     *
 * Title           - R-type                                                             *
 * Description     -                                                                    *
 *     ParsingTcp                                                                          *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

/**
 * @file ParsingTcp.cpp
 * @brief Implementation of the ParsingTcp class methods.
 */

#include "ParsingTcp.hpp"

/**
 * @brief Default constructor implementation.
 */
ParsingTcp::ParsingTcp() {}

/**
 * @brief Constructor that initializes the ParsingTcp class with command-line arguments.
 * @param ac Argument count.
 * @param av Argument values.
 */
ParsingTcp::ParsingTcp(int ac, char** av)
{
    if (ac == 1) {
        std::string filename = "configuration_files/server.ini";
        getFileInfos(filename);
    } else if (ac == 2) {
        std::string filename = std::string(av[1]);
        getFileInfos(filename);
    } else {
        getArgs(av);
    }
}

/**
 * @brief Parses command-line arguments to extract server or client settings.
 * @param av Command-line arguments.
 */
void ParsingTcp::getArgs(char **av)
{
    std::size_t cpt = 1;
    std::string current_argument = std::string(av[0]);
    std::string next_argument;

    if (current_argument == "r-type_server") {
        while (av[cpt]) {
            current_argument = std::string(av[cpt]);
            if (!av[cpt + 1]) {
                throw std::exception();
            }
            next_argument = std::string(av[cpt + 1]);
            serverSettings[current_argument.substr(2)] = next_argument;
            cpt += 2;
        }
    } else {
        while (av[cpt]) {
            current_argument = std::string(av[cpt]);
            if (!av[cpt + 1]) {
                throw std::exception();
            }
            next_argument = std::string(av[cpt + 1]);
            clientSettings[current_argument.substr(2)] = next_argument;
            cpt += 2;
        }
    }
}

/**
 * @brief Parses a configuration file to extract settings.
 * @param filename The path to the configuration file.
 */
void ParsingTcp::getFileInfos(std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::exception();
    }

    std::string line;
    std::string currentSection;

    while (std::getline(file, line)) {
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);
        if (line.empty() || line[0] == ';' || line[0] == '#') {
            continue;
        }
        if (line.front() == '[' && line.back() == ']') {
            currentSection = line.substr(1, line.size() - 2);
        } else {
            auto delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos && delimiterPos < line.size() - 1) {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);

                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);

                if (currentSection == "server") {
                    serverSettings[key] = value;
                } else if (currentSection == "client") {
                    clientSettings[key] = value;
                }
            }
        }
    }
}

/**
 * @brief Retrieves the server settings.
 * @return A map containing server settings as key-value pairs.
 */
std::unordered_map<std::string, std::string> ParsingTcp::getServerSettings() const
{
    return serverSettings;
}

/**
 * @brief Retrieves the client settings.
 * @return A map containing client settings as key-value pairs.
 */
std::unordered_map<std::string, std::string> ParsingTcp::getClientSettings() const
{
    return clientSettings;
}
