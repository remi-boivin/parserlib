#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <array.hpp>
#include "../../pal/iparser.hpp"

class Parser : public cp::iparser::IParser
{

public:
    Parser(const std::vector<std::string> autorizedArgs);
    Parser();
    virtual ~Parser();
    void args(int argc, char **argv) const override;
    std::vector<std::string> get() const override;

private:
    const std::vector<std::string> m_autorizedArgs;
    mutable std::vector<std::string> m_args;
};

#endif // PARSER_HPP