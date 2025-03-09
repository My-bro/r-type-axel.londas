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

#ifndef INCLUDED_ParsingTcp_HPP
    #define INCLUDED_ParsingTcp_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <exception>

/**
 * @class ParsingTcp
 * @brief A class to handle ParsingTcp of configuration files and command-line arguments.
 *
 * This class parses and stores server and client settings from a configuration file or command-line arguments.
 */
class ParsingTcp
{
private:
    /**
     * @brief Stores server settings as key-value pairs.
     */
    std::unordered_map<std::string, std::string> serverSettings;

    /**
     * @brief Stores client settings as key-value pairs.
     */
    std::unordered_map<std::string, std::string> clientSettings;

    /**
     * @brief Parses command-line arguments to extract server or client settings.
     * @param av Command-line arguments.
     */
    void getArgs(char **av);

    /**
     * @brief Parses a configuration file to extract settings.
     * @param filename The path to the configuration file.
     */
    void getFileInfos(std::string& filename);

protected:

public:
    /**
     * @brief Default constructor.
     */
    ParsingTcp();

    /**
     * @brief Constructor that initializes the ParsingTcp class with command-line arguments.
     * @param ac Argument count.
     * @param av Argument values.
     */
    ParsingTcp(int ac, char** av);

    /**
     * @brief Default destructor.
     */
    ~ParsingTcp() = default;

    /**
     * @brief Retrieves the server settings.
     * @return A map containing server settings as key-value pairs.
     */
    std::unordered_map<std::string, std::string> getServerSettings() const;

    /**
     * @brief Retrieves the client settings.
     * @return A map containing client settings as key-value pairs.
     */
    std::unordered_map<std::string, std::string> getClientSettings() const;
};

#endif
