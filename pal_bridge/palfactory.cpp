#include "./palfactory.hpp"
#include "../include/parser.hpp"

namespace cp
{
    namespace parser
    {
        std::shared_ptr<iparser::IParser> PALFactory::createParser(std::vector<std::string> authorizedArgs) const
        {
            // create and return a shared_ptr to a Parser object
            return std::make_shared<Parser>(authorizedArgs);
        }
    }
}