#ifndef IPARSER_HPP
#define IPARSER_HPP

#include <string>
#include <vector>

namespace cp
{
    namespace iparser
    {

        class IParser
        {
        public:
            virtual void args(int argc, char **argv) const = 0;
            virtual std::vector<std::string> get() const = 0;
        };
    }
}
#endif // IPARSER_HPP