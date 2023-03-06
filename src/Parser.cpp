#include "../include/parser.hpp"

Parser::Parser(const std::vector<std::string> autorizedArgs) : m_autorizedArgs(autorizedArgs) {}
Parser::Parser() {}

void Parser::args(int argc, char** argv) const {
    for (int i = 1; i < argc; ++i) {
        if (in_array(static_cast<std::string>(argv[i]), m_autorizedArgs) == true) {
            m_args.push_back(argv[i]);
        } else {
            throw std::runtime_error("Invalid command line argument");
        }
    }
}

std::vector<std::string> Parser::get() const {
    return (m_args);
}

Parser::~Parser() {
}